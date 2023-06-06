#include "BuildMathModel.h"
using namespace BuildMathModel;

void CreateSketchPGTY(RPArray<MbContour>& _arrContours, float RV, float B1, float S2)
{
    SArray<MbCartPoint> arrPnts(12);
    arrPnts.Add(MbCartPoint(-S2, 0));
    arrPnts.Add(MbCartPoint(-S2, RV - B1));
    arrPnts.Add(MbCartPoint(-S2 + B1, RV - B1));
    arrPnts.Add(MbCartPoint(-S2 + B1, RV + RV * 0.20));
    arrPnts.Add(MbCartPoint(-B1, RV + RV * 0.20));
    arrPnts.Add(MbCartPoint(-B1, RV + RV * 0.20 - 2 * B1));
    arrPnts.Add(MbCartPoint(B1, RV + RV * 0.20 - 2 * B1));
    arrPnts.Add(MbCartPoint(B1, RV + RV * 0.20));
    arrPnts.Add(MbCartPoint(S2 - B1, RV + RV * 0.20));
    arrPnts.Add(MbCartPoint(S2 - B1, RV - B1));
    arrPnts.Add(MbCartPoint(S2, RV - B1));
    arrPnts.Add(MbCartPoint(S2, 0));

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

SPtr<MbSolid> ParametricModelCreator::PipeGrideTU(BuildParams params)
{
    float DV = params.diam.toDouble(); //���������� �������
    if (DV == 325)
        DV = 300;
    float d = params.d.toDouble(); // D �����
    float S = params.S.toDouble(); //������� �������
    float S2 = S / 2;

    float offsets; //���������� ����� ������������
    if (d == 20)
        offsets = 6;
    else
        offsets = 7;
    
    float RV = DV / 2; //���������� ������
    float B1 = 5; //����� ������
    float B2 = 10; //������ ������

    float bigD = DV - (DV / 100 * 9); // D ����������� ����������
    float t = (d + offsets); // ��� ����� ��������
    float n0 = floor(bigD / t); // ���-�� ��������� �� 0 ����
    float n = n0 + 3; // ���-�� ��������� �� 1 ����

    // ��������� ��� �������������� ������� �������� �� �������� � �������
    const double DEG_TO_RAD = M_PI / 180.0;

    float h = bigD / 2 * sin(60 * DEG_TO_RAD); // ������ 6 ���������
    
    //�������� ��������� - ��� ��������� � ���������� XY ��������� ��
    MbPlacement3D* place = new MbPlacement3D();
    MbPlane* ptrSurface = new MbPlane(*place);

    RPArray<MbContour> arrContours;
    CreateSketchPGTY(arrContours, RV, B1, S2);
    //������, � ������� �������� �������� �� ����������
    MbSweptData* sweptData = new MbSweptData(*ptrSurface, arrContours);

    // ������ ���������� ��� ���������� ��� ��������.
    RevolutionValues revParms(360 * DEG_TO_RAD, 0, 0);

    //����������� ��� �������� ���������� ���� �������� � ��� �������� ����������
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    MbSNameMaker operBoolNames(ct_BooleanSolid, MbSNameMaker::i_SideNone);
    PArray<MbSNameMaker> cNames(0, 1, false);

    //��� �������� ��� ���������� ����
    MbAxis3D axis(place->GetAxisX());

    // ����� �������-������� ��� ���������� �������� ���� ��������
    MbSolid* pResSolid = nullptr;
    RevolutionSolid(*sweptData, axis, revParms, operNames, cNames, pResSolid);
    
    RPArray<MbContour>* arrContours1 = new RPArray<MbContour>();

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            double x = t * n / 2 - d / 2 - i * t - cos(60 * M_PI / 180) * t * j - offsets / 2;
            double y = j * sin(60 * M_PI / 180) * t + t;

            double l = sqrt(pow(x, 2) + pow(y, 2));

            if (l + d / 2 < bigD / 2 && y < h)
            {
                MbArc* Circle = new MbArc(MbCartPoint(x, y), d / 2);
                MbContour* arrContourCircle = new MbContour();
                arrContourCircle->AddSegment(Circle);
                arrContourCircle->Rotate(MbCartPoint(0, 0), MbDirection(90 * DEG_TO_RAD), nullptr, nullptr);
                arrContours1->Add(arrContourCircle);
                arrContourCircle->Clear();
            }
        }
    }

    MbPlacement3D pl1;
    pl1.Rotate(MbAxis3D(MbVector3D(1, 0, 0)), -90 * DEG_TO_RAD);
    MbPlane* pPlane = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(0, 1, 0), MbCartPoint3D(0, 0, 1));
    MbSweptData sweptData1(*pPlane, *arrContours1);
    MbSNameMaker plateNames(MbSNameMaker::i_SideNone);

    MbVector3D dir(1, 0, 0);
    ExtrusionValues extrusionParam(S2, S2);

    ::ExtrusionResult(*pResSolid, cm_Same, sweptData1, dir, extrusionParam, bo_Difference, plateNames, NULL, pResSolid);
    ::SymmetrySolid(*pResSolid, cm_Copy, pl1, operBoolNames, pResSolid);
    arrContours1->clear();

    // ���������� ��������� ������ ������������ �������� ����
    c3d::SolidSPtr MainSolid(pResSolid);
    ::DeleteItem(pResSolid);

    return MainSolid;
}