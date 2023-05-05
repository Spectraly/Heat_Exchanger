#include "BuildMathModel.h"
using namespace BuildMathModel;

void CreateSketchMoveSupTY(RPArray<MbContour>& _arrContours, float L2, float B1, float h)
{
    // ������ ������� - 10 �����
    SArray<MbCartPoint> arrPnts(10);
    arrPnts.Add(MbCartPoint(0, 0)); //(0, 0)
    arrPnts.Add(MbCartPoint(-L2, 0)); //(-120, 0)
    arrPnts.Add(MbCartPoint(-L2, B1)); //(-120, 5)
    arrPnts.Add(MbCartPoint(-L2 + 5, B1)); //(-115, 5)
    arrPnts.Add(MbCartPoint(-L2 + 5, h)); //(-115, 292)
    arrPnts.Add(MbCartPoint(-L2 + 10, h)); //(-110, 292)
    arrPnts.Add(MbCartPoint(-L2 + 10, B1)); //(-110, 5)
    arrPnts.Add(MbCartPoint(-2.5, B1)); //(-2.5, 5)
    arrPnts.Add(MbCartPoint(-2.5, h)); //(-2.5, 292)
    arrPnts.Add(MbCartPoint(0, h)); //(0, 292)

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[10], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

void CreateSketchMoveSupTY1(RPArray<MbContour>& _arrContours, float L2, float B1, float h)
{
    // ������ ������� - 4 �����
    SArray<MbCartPoint> arrPnts(4);
    arrPnts.Add(MbCartPoint(-2.5, B1)); //(, )
    arrPnts.Add(MbCartPoint(-L2 + 10, B1)); //(, )
    arrPnts.Add(MbCartPoint(-L2 + 10, h)); //(, )
    arrPnts.Add(MbCartPoint(-2.5, h)); //(, )

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[10], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

void CreateSketchMoveSupTYCurve(RPArray<MbContour>& _ptrContours, float DV, float h)
{
    float RV = DV / 2; //���������� ������

    //�������� ����� �������
    MbCartPoint p1(0, h - RV + 2.5);
    MbCartPoint p2(0, h - RV);
    MbCartPoint p3(-DV * sin(70 * M_PI / 180), DV * cos(70 * M_PI / 180)); // ������ � �����
    MbCartPoint p4(-DV * sin(70 * M_PI / 180), DV * cos(70 * M_PI / 180) + 2.5); // ������ � �����

    //������������ �������� �������� ��������
    MbLineSegment* Seg1 = new MbLineSegment(p1, p2);
    MbArc* Seg2 = new MbArc(MbCartPoint(0, h), RV, p2, p3, -1);
    MbArc* Seg4 = new MbArc(MbCartPoint(0, h + 2.5), RV, p4, p1, 1);
    MbCartPoint p5, p6;
    Seg2->GetEndPoint(p5);
    Seg4->GetStartPoint(p6);
    MbLineSegment* Seg3 = new MbLineSegment(p5, p6);

    //������������ �������� �������
    MbContour* ptrContour = new MbContour();

    //���������� � ������ ���������
    ptrContour->AddSegment(Seg1);
    ptrContour->AddSegment(Seg2);
    ptrContour->AddSegment(Seg3);
    ptrContour->AddSegment(Seg4);
    _ptrContours.push_back(ptrContour);
}

SPtr<MbSolid> ParametricModelCreator::MoveSupHETU(BuildParams params)
{
    float DV = params.diam.toDouble();//�������� �������
    float h = params.h.toDouble(); //������ ����� �� ������

    //float DN = DV + DV / 100 * 8; //���������� �������
    float RV = DV / 2; //���������� ������
    float L = DV / 100 * 80; //�����
    float L2 = L / 2; //����� �������
    float L1 = 250; //����� - ������� ����
    float B1 = 5; //����� ������

    float B;
    if (DV >= 325 || DV < 800)
        B = 180 / 2;
    else
        B = 250 / 2;

    // ��������� ��� �������������� ������� �������� �� �������� � �������
    const double DEG_TO_RAD = M_PI / 180.0;

    // ��������� �� (�� ��������� ��������� � ������� ��)
    MbPlacement3D pl, pl1;
    pl1.Rotate(MbAxis3D(MbVector3D(0, 1, 0)), 90 * DEG_TO_RAD);

    // ����� ������� ��� ���������� ���������� 
    RPArray<MbContour> arrContours, arrContours1, ptrContours;
    CreateSketchMoveSupTY(arrContours, L2, B1, h);
    CreateSketchMoveSupTY1(arrContours1, L2, B1, h);
    CreateSketchMoveSupTYCurve(ptrContours, DV, h);

    // ���������� ���������� ��� ������ ������� ���������� ���� ��������.
    // sweptData - ������, � ������� �������� �������� �� ����������.
    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, arrContours);
    MbSweptData sweptData1(*pPlaneXY, arrContours1);
    MbSweptData sweptData2(*pPlaneXY, ptrContours);

    // ������������ ������ ��� �������� ������������
    MbVector3D dir(0, 0, -1);

    // ������ ���������� ��� �������� ���������� ���� ��������.
    // ������ ��� ��������� ������������ ������ ���� �������� � ������ � ��������
    // ����������� (�� ������� � ���������� ��� �������������� ���� �������).
    // � ������ ������� �������� �������������� �� 360 �������� � ������ �����������.
    // ������ �������� ������ ����� ��������� �������� ����.
    // ��� s = 0 �������� ���� � ���������� �����, ��� s = 1 - � ���������� ����.
    // ���� ���������� - ����������� ������, � ��� �������� ����� � ��������� ������,
    // �� ��� s = 0 ��� ���������� ���������� ����� ������������� �������� �� ���
    // ��������. � ������ ������� �������� ����� ���������� s ���, �.�. ����������
    // ����� ��� ���������� �������.
    RevolutionValues revParms(360 * DEG_TO_RAD, 0, 0);

    MbSNameMaker operBoolNames(ct_BooleanSolid, MbSNameMaker::i_SideNone);

    // ����������� ��������� ������ �������� ���� � �������� ����������
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);

    // ��� �������� ��� ���������� ����:
    MbAxis3D axis(pl.GetAxisX());

    ExtrusionValues extrusionParams(B, B);
    ExtrusionValues extrusionParams1(B1, B1);
    ExtrusionValues extrusionParams2(B + 5 * B1, B + 5 * B1);

    // ����� �������-������� ��� ���������� �������� ���� ��������
    MbSolid* pSup = nullptr, * pSup1 = nullptr, * pSup2 = nullptr;
    ::ExtrusionSolid(sweptData, dir, nullptr, nullptr, false, extrusionParams, operNames, cNames, pSup);
    ::ExtrusionSolid(sweptData1, dir, nullptr, nullptr, false, extrusionParams1, operNames, cNames, pSup1);
    ::ExtrusionSolid(sweptData2, dir, nullptr, nullptr, false, extrusionParams2, operNames, cNames, pSup2);


    MbSNameMaker cylNames(ct_ElementarySolid, MbSNameMaker::i_SideNone);
    MbSolid* pCyl = NULL;
    // ���������� �������������� �������������� �����������
    SArray<MbCartPoint3D> pCylSurf(3);
    pCylSurf.Add(MbCartPoint3D(0, h, -B));
    pCylSurf.Add(MbCartPoint3D(0, h, B));
    pCylSurf.Add(MbCartPoint3D(0, h + RV, -B));
    ::ElementarySolid(pCylSurf, et_Cylinder, cylNames, pCyl);
    //show(Style(1, RGB(50, 200, 200)), pCyl);

    //---------------------------------------------------------//
    // ����� ������� ��������: ���������� ���������� ���� � ������������
    // �������� ������ � �����.
    MbBooleanFlags flagsBool;
    flagsBool.InitBoolean(true);
    flagsBool.SetMergingFaces(true);
    flagsBool.SetMergingEdges(true);

    // �������������� ����
    MbSolid* pResSolid = NULL;
    // ����� ������� �������� ��� ���������� �����������.
    // ��� ���������� ��������� ���� ������ ���� �������� bo_Union �������
    // �������� bo_Difference, ��� ����������� - �������� bo_Intersect.
    //---------------------------------------------------------//
    ::BooleanResult(*pSup, cm_Copy, *pSup1, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pCyl, cm_Copy, bo_Difference, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pSup2, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    ::SymmetrySolid(*pResSolid, cm_Copy, pl1, operBoolNames, pResSolid);
    // ����������� ������������ ����
    //if (res == rt_Success)
        //show(Style(1, LIGHTGRAY), pResSolid);

    MbAxis3D axisY(pl.GetAxisY());
    pResSolid->Rotate(axisY, 90 * DEG_TO_RAD, nullptr);

    float LO = params.length.toDouble(); //����� ��������

    float l1 = params.l1.toDouble(); //����� �� ������� �������
    float A1 = params.A.toDouble(); //����� ������ (A)
    float A2 = params.A1.toDouble(); //����� ������ (A1)
    float l2 = params.l2.toDouble(); //���������� �� ��������� �����
    float LK = (LO - l1 - A1/2) / 2; //����� ������ �������
    float LK1 = LK + l1 + A1 / 2; //����� ������ �������
    float LS = -LK1 + (l1 + A1 + A2) - l2; //���������� �� ����������� �����


    pResSolid->Move(MbVector3D(LS, -h - 3 * B1 - 2.5, 0));

    c3d::SolidSPtr MainSolid(pResSolid);

    // ���������� ��������� ������ ������������ �������� ����
    ::DeleteItem(pResSolid);

    return MainSolid;
}