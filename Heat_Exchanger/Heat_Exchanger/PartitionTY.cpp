#include "BuildMathModel.h"
using namespace BuildMathModel;

void CreateSketchPTY(RPArray<MbContour>& _arrContours, float S1, float RV)
{
    // ������ ������� - 4 �����
    SArray<MbCartPoint> arrPnts(4);
    arrPnts.Add(MbCartPoint(S1 / 2, 0));
    arrPnts.Add(MbCartPoint(S1 / 2, RV));

    arrPnts.Add(MbCartPoint(-S1 / 2, RV));
    arrPnts.Add(MbCartPoint(-S1 / 2, 0));

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

void CreateSketchPTY1(RPArray<MbContour>& _arrContoursH, float S1, float RV, float h3, bool slicePlace)
{
    int sliceSign;
    slicePlace ? sliceSign = 1 : sliceSign = -1;

    SArray<MbCartPoint> arrPnts(4);
    arrPnts.Add(MbCartPoint(S1 / 2, sliceSign * h3));
    arrPnts.Add(MbCartPoint(S1 / 2, sliceSign * RV));
    arrPnts.Add(MbCartPoint(-S1 / 2, sliceSign * RV));
    arrPnts.Add(MbCartPoint(-S1 / 2, sliceSign * h3));

    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[3], pContourPolyline);

    _arrContoursH.push_back(pContourPolyline);
}

SPtr<MbSolid> ParametricModelCreator::PartitionTU(BuildParams params)
{
    float DV = params.diam.toDouble(); //���������� �������
    if (DV == 325)
        DV = 300;
    float d = params.d.toDouble(); // D �����

    float offsets; //���������� ����� ������������
    if (d == 20)
        offsets = 6;
    else
        offsets = 7;
    float S = params.S.toDouble(); //������� �������
    float S1 = params.S1.toDouble(); //������� �����������
    float l3 = params.l3.toDouble(); //���������� ����� �������������
    float l4 = params.l4.toDouble(); //����� ���������� �����������
    float n1 = l4 / l3 + 1; //���-�� �����������
    float h3 = 68; // ������ �����������

    float RV = DV / 2; //���������� ������

    float bigD = DV - (DV / 100 * 9); // D ����������� ����������
    float t = (d + offsets); // ��� ����� ��������
    float n0 = floor(bigD / t); // ���-�� ��������� �� 0 ����
    float n = n0 + 3; // ���-�� ��������� �� 1 ����

    // ��������� ��� �������������� ������� �������� �� �������� � �������
    const double DEG_TO_RAD = M_PI / 180.0;
    float h = bigD / 2 * sin(60 * DEG_TO_RAD); // ������ 6 ���������
    bool slicePlace = false;

    // ��������� �� (�� ��������� ��������� � ������� ��)
    MbPlacement3D pl, pl1;

    // ����� ������� ��� ���������� ���������� (�� ������� 6)
    RPArray<MbContour> arrContours, arrContoursH;
    CreateSketchPTY(arrContours, S1, RV);

    // ���������� ���������� ��� ������ ������� ���������� ���� ��������.
    // sweptData - ������, � ������� �������� �������� �� ����������.
    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, arrContours);

    // ������ ���������� ��� �������� ���������� ���� ��������.
    RevolutionValues revParms(360 * DEG_TO_RAD, 0, 0);
    // ����������� ��� �������� ���������� ���� �������� � ��� �������� ����������
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);

    // ��� �������� ��� ���������� ����:
    MbAxis3D axisX(pl.GetAxisX());
    MbSNameMaker operBoolNames(ct_BooleanSolid, MbSNameMaker::i_SideNone);

    // �������������� ����
    MbSolid* pResSolid = NULL;
    ::RevolutionSolid(sweptData, axisX, revParms, operNames, cNames, pResSolid);

    MbSNameMaker cylNames(ct_ElementarySolid, MbSNameMaker::i_SideNone);

    MbBooleanFlags flagsBool;
    flagsBool.InitBoolean(true);
    flagsBool.SetMergingFaces(true);
    flagsBool.SetMergingEdges(true);

    RPArray<MbContour>* arrContoursCyl = new RPArray<MbContour>();

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            double x = (d + offsets) * n / 2 - d / 2 - i * t - cos(60 * M_PI / 180) * t * j - offsets / 2;
            double y = j * sin(60 * M_PI / 180) * t + t;

            double l = sqrt(pow(x, 2) + pow(y, 2));

            if (l + d / 2 < bigD / 2 && y < h)
            {
                MbArc* CirclePlus = new MbArc(MbCartPoint(x, y), d / 2);
                MbArc* CircleMinus = new MbArc(MbCartPoint(x, -y), d / 2);

                MbContour* arrContourCircleP = new MbContour();
                arrContourCircleP->AddSegment(CirclePlus);

                MbContour* arrContourCircleM = new MbContour();
                arrContourCircleM->AddSegment(CircleMinus);

                arrContoursCyl->Add(arrContourCircleP);
                arrContoursCyl->Add(arrContourCircleM);
            }
        }
    }

    MbSweptData sweptData1(*pPlaneXY, *arrContoursCyl);
    MbVector3D dir(0, 0, -1);
    ExtrusionValues extrusionParam(S1, S1);
    MbSolid* pCyl = NULL, * pRect = NULL;
    ::ExtrusionSolid(sweptData1, dir, nullptr, nullptr, false, extrusionParam, operNames, cNames, pCyl);

    MbAxis3D axisY(pl.GetAxisY());
    pCyl->Rotate(axisY, 90 * DEG_TO_RAD, nullptr);
    ::BooleanResult(*pResSolid, cm_Copy, *pCyl, cm_Copy, bo_Difference, flagsBool, operBoolNames, pResSolid);

    // ������������ ������� params � ����������� �������� ����������� �� �����
    // �������, ������������ ��� ����������� �����������
    MbVector3D vecDir1(1, 0, 0);
    DuplicationMeshValues paramsDP(false, vecDir1, l3, n1, vecDir1, NULL, NULL, nullptr);

    // ���������� ����, ���������� �� ����� �� �����
    MbSolid* pDuplSolid = NULL, * pResSolid1 = NULL, * pDuplSolid1 = NULL;
    MbSolid* pRes = NULL;
    MbSNameMaker namesDupl(ct_DuplicationSolid, MbSNameMaker::i_SideNone, 0);
    ::DuplicationSolid(*pResSolid, paramsDP, namesDupl, pDuplSolid);

    for (int i = 0; i < n1; i++)
    {
        RPArray<MbContour> arrContoursH;
        CreateSketchPTY1(arrContoursH, S1, RV, h3, slicePlace);
        MbPlacement3D* place = new MbPlacement3D(MbCartPoint3D(i * l3, 0, 0));
        MbPlane* ptrSurface = new MbPlane(*place);
        MbSweptData sweptData2(*ptrSurface, arrContoursH);
        ExtrusionValues extrusionParam1(RV, RV);
        ::ExtrusionSolid(sweptData2, dir, nullptr, nullptr, false, extrusionParam1, operNames, cNames, pRect);
        ::BooleanResult(*pDuplSolid, cm_Copy, *pRect, cm_Copy, bo_Difference, flagsBool, operBoolNames, pDuplSolid);
        slicePlace = !slicePlace;
    }

    c3d::SolidSPtr MainSolid(pDuplSolid);

    float Dy = params.Dy.toDouble(); //������� ��������
    float A1 = params.A.toDouble() / 2; //����� ������ (A)
    float l6 = A1 + Dy;

    pDuplSolid->Move(MbVector3D(l6+S, 0, 0));

    // ���������� ��������� ������ ������������ �������� ����
    ::DeleteItem(pCyl);
    ::DeleteItem(pRect);
    ::DeleteItem(pResSolid);
    ::DeleteItem(pDuplSolid);

    return MainSolid;
}