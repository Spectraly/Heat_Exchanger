#include "BuildMathModel.h"
using namespace BuildMathModel;

void CreateSketchKTY(RPArray<MbContour>& _arrContours, float RV, float LK, float B1, float Tss)
{
    // ������ ������� - 8 �����
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(-LK, 0));
    arrPnts.Add(MbCartPoint(-LK, RV + Tss));
    arrPnts.Add(MbCartPoint(LK - Tss, RV + Tss));
    arrPnts.Add(MbCartPoint(LK - Tss, RV + RV * 0.20 + Tss + B1));
    arrPnts.Add(MbCartPoint(LK, RV + RV * 0.20 + Tss + B1));
    arrPnts.Add(MbCartPoint(LK, RV + RV * 0.20));
    arrPnts.Add(MbCartPoint(LK - B1, RV + RV * 0.20));
    arrPnts.Add(MbCartPoint(LK - B1, 0));

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // ������� ���������� � �������������� ������� FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchK1TY(RPArray<MbContour>& _arrContours, float H2, float Ry, float B2, float Tss)
{
    // ������ ������� - 8 �����
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(Ry, H2 - 4 * Ry / 5));
    arrPnts.Add(MbCartPoint(Ry, H2));
    arrPnts.Add(MbCartPoint(Ry + Tss, H2));
    arrPnts.Add(MbCartPoint(Ry + Tss + 0.5 * B2, H2 - Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + Tss + 2.5 * B2, H2 - Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + Tss + 2.5 * B2, H2 - 2 * Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + Tss + 0.5 * B2, H2 - 2 * Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + Tss, H2 - 4 * Ry / 5));

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchK2TY(RPArray<MbContour>& _arrContours, float H2, float Ry, float B2, float Tss)
{
    // ������ ������� - 8 �����
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(Ry, -H2 + 4 * Ry / 5));
    arrPnts.Add(MbCartPoint(Ry, -H2));
    arrPnts.Add(MbCartPoint(Ry + Tss, -H2));
    arrPnts.Add(MbCartPoint(Ry + Tss + 0.5 * B2, -H2 + Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + Tss + 2.5 * B2, -H2 + Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + Tss + 2.5 * B2, -H2 + 2 * Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + Tss + 0.5 * B2, -H2 + 2 * Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + Tss, -H2 + 4 * Ry / 5));

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

//����� �����������
void CreateSketchK3TY(RPArray<MbContour>& _arrContours, float RV, float LK, float B1, float B2, float Hse, float Ts�)
{
    // ������ ������� - 4 �����
    SArray<MbCartPoint> arrPnts(4);
    arrPnts.Add(MbCartPoint(-LK - Hse + Ts�, B1));
    arrPnts.Add(MbCartPoint(-LK - Hse + Ts�, -B1));
    arrPnts.Add(MbCartPoint(LK - B1, -B1));
    arrPnts.Add(MbCartPoint(LK - B1, B1));

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

void CreateSketchCurveK(RPArray<MbContour>& _ptrContours, float RV, float LK, float B1, float Hse, float Tss, float Ts�)
{
    //������������ �������� �������
    MbContour* ptrContour = new MbContour();
    //���������� � ������ ���������

    MbCartPoint p1(-LK, RV);
    MbCartPoint p2(-LK, RV + Tss);
    MbCartPoint p3(-LK - Hse, 0);
    MbCartPoint p4(-LK - Hse + Ts�, 0);

    MbPlacement* plCurve = new MbPlacement(MbCartPoint(-LK, 0), MbDirection(0.0));

    //������������ �������� �������� ��������
    MbLineSegment* Seg1 = new MbLineSegment(p1, p2);
    MbArc* Seg2 = new MbArc(-Hse, RV + Tss, *plCurve, p2, p3, -1);
    MbLineSegment* Seg3 = new MbLineSegment(p3, p4);
    MbArc* Seg4 = new MbArc(-Hse + Ts�, RV, *plCurve, p4, p1, 1);

    ptrContour->AddSegment(Seg1);
    ptrContour->AddSegment(Seg2);
    ptrContour->AddSegment(Seg3);
    ptrContour->AddSegment(Seg4);

    _ptrContours.push_back(ptrContour);
}

SPtr<MbSolid> ParametricModelCreator::Distribution_ChamberTU(BuildParams params)
{
    float DV = params.diam.toDouble(); //���������� �������
    if (DV == 325)
        DV = 300;
    float l = params.l.toDouble(); //����� ����
    float L = params.length.toDouble(); //�����
    float Dy = params.Dy.toDouble(); //������� ��������
    float H = params.height.toDouble(); //������ ��������
    float A1 = params.A.toDouble() / 2; //����� ������ (A)
    float l1 = params.l1.toDouble(); //����� �� ������� �������
    float Tss = params.TsS;//������� ������
    float Ts� = params.TsE;//������� �����

    float LK1 = l1 + A1; //����� ������
    float LK = LK1 / 2; //����� ������ �������
    float LK2 = (L - LK1) / 2; //����� ������ �������
    float Hse = 0.25 * DV;

    float B1 = 5; //����� ������
    float B2 = 10; //������ ������
    float H2 = H / 2; //������ �������� �������
    float Ry = Dy / 2; //������� �������� �������
    float RV = DV / 2; //���������� ������

    // ��������� ��� �������������� ������� �������� �� �������� � �������
    const double DEG_TO_RAD = M_PI / 180.0;

    // ��������� �� (�� ��������� ��������� � ������� ��)
    MbPlacement3D pl, pl1, pl2;

    // ����� ������� ��� ���������� ���������� (�� ������� 6)
    RPArray<MbContour> arrContours, arrContours1, arrContours2, arrContours3, ptrContours;
    CreateSketchKTY(arrContours, RV, LK, B1, Tss);
    CreateSketchK1TY(arrContours1, H2, Ry, B2, Tss);
    CreateSketchK2TY(arrContours2, H2, Ry, B2, Tss);
    CreateSketchCurveK(ptrContours, RV, LK, B1, Hse, Tss, Ts�);
    CreateSketchK3TY(arrContours3, RV, LK, B1, B2, Hse, Ts�);

    // ���������� ���������� ��� ������ ������� ���������� ���� ��������.
    // sweptData - ������, � ������� �������� �������� �� ����������.
    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, arrContours);
    MbSweptData sweptData1(*pPlaneXY, arrContours1);
    MbSweptData sweptData2(*pPlaneXY, arrContours2);
    MbSweptData sweptData3(*pPlaneXY, ptrContours);
    MbSweptData sweptData4(*pPlaneXY, arrContours3);

    // ������ ���������� ��� �������� ���������� ���� ��������.
    RevolutionValues revParms(360 * DEG_TO_RAD, 0, 0);
    // ����������� ��� �������� ���������� ���� �������� � ��� �������� ����������
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);

    // ��� �������� ��� ���������� ����:
    // ��� Y ������� �� ��������� �� -50 ������ ����� ��� X.
    MbAxis3D axis(pl.GetAxisX());
    MbAxis3D axis1(pl1.GetAxisY());
    MbAxis3D axis2(pl2.GetAxisY());
    MbSNameMaker operBoolNames(ct_BooleanSolid, MbSNameMaker::i_SideNone);
    // �������� ���� - ��������
    MbSolid* pCyl1 = NULL, * pCyl2 = NULL, * pCyl3 = NULL;

    // ������-����������� ��� ���������� ��������� - ������������ ���
    MbSNameMaker cylNames(ct_ElementarySolid, MbSNameMaker::i_SideNone);

    SArray<MbCartPoint3D> pntsCyl1(3);
    pntsCyl1.Add(MbCartPoint3D(0, -H2, 0));
    pntsCyl1.Add(MbCartPoint3D(0, H2, 0));
    pntsCyl1.Add(MbCartPoint3D(0, 0, Ry + Tss));
    // ���������� ������������� ���� - �������� - �� ���� ������
    ::ElementarySolid(pntsCyl1, et_Cylinder, cylNames, pCyl1);

    SArray<MbCartPoint3D> pntsCyl2(3);
    pntsCyl2.Add(MbCartPoint3D(0, -H2, 0));
    pntsCyl2.Add(MbCartPoint3D(0, H2, 0));
    pntsCyl2.Add(MbCartPoint3D(0, 0, Ry));
    ::ElementarySolid(pntsCyl2, et_Cylinder, cylNames, pCyl2);

    SArray<MbCartPoint3D> pntsCyl3(3);
    pntsCyl3.Add(MbCartPoint3D(-LK, 0, 0));
    pntsCyl3.Add(MbCartPoint3D(LK, 0, 0));
    pntsCyl3.Add(MbCartPoint3D(-LK, RV, 0));
    ::ElementarySolid(pntsCyl3, et_Cylinder, cylNames, pCyl3);

    // ����� �������-������� ��� ���������� �������� ���� ��������
    MbBooleanFlags flagsBool;
    flagsBool.InitBoolean(true);
    flagsBool.SetMergingFaces(true);
    flagsBool.SetMergingEdges(true);

    // �������������� ����
    MbSolid* pResSolid = NULL, * pDistributionChamber = NULL, * pConnector1 = nullptr, * pConnector2 = nullptr, * pCurves = nullptr;
    ::RevolutionSolid(sweptData, axis, revParms, operNames, cNames, pDistributionChamber);
    ::RevolutionSolid(sweptData1, axis1, revParms, operNames, cNames, pConnector1);
    ::RevolutionSolid(sweptData2, axis2, revParms, operNames, cNames, pConnector2);
    ::RevolutionSolid(sweptData3, axis, revParms, operNames, cNames, pCurves);

    ::BooleanResult(*pDistributionChamber, cm_Copy, *pCyl1, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pCyl2, cm_Copy, bo_Difference, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pCyl3, cm_Copy, bo_Difference, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pConnector1, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pConnector2, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pCurves, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);

    // ������������ ������ ��� �������� ������������
    MbVector3D dir(0, 0, -1);

    ExtrusionValues extrusionParam(294, 294);
    extrusionParam.side1.way = sw_shell;
    extrusionParam.side2.way = sw_shell;

    MbSolid* pPlate = nullptr;
    ::ExtrusionSolid(sweptData4, dir, pResSolid, pResSolid, false, extrusionParam, operNames, cNames, pPlate);
    ::BooleanResult(*pResSolid, cm_Copy, *pPlate, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);

    c3d::SolidSPtr MainSolid(pResSolid);

    // ���������� ��������� ������ ������������ �������� ����
    ::DeleteItem(pResSolid);
    ::DeleteItem(pDistributionChamber);
    ::DeleteItem(pCyl1);
    ::DeleteItem(pCyl2);
    ::DeleteItem(pCyl3);
    ::DeleteItem(pConnector1);
    ::DeleteItem(pConnector2);
    ::DeleteItem(pCurves);

    return MainSolid;
}