#include "BuildMathModel.h"
using namespace BuildMathModel;

void CreateSketchKTY(RPArray<MbContour>& _arrContours, float RV, float LK, float B1)
{
    // ������ ������� - 8 �����
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(-LK + B1, 0));
    arrPnts.Add(MbCartPoint(-LK + B1, RV + 2 * B1));
    arrPnts.Add(MbCartPoint(LK - 3 * B1, RV + 2 * B1));
    arrPnts.Add(MbCartPoint(LK - 3 * B1, RV + RV * 0.20 + 3 * B1));
    arrPnts.Add(MbCartPoint(LK, RV + RV * 0.20 + 3 * B1));
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
void CreateSketchK1TY(RPArray<MbContour>& _arrContours, float H2, float Ry, float B2)
{
    // ������ ������� - 8 �����
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(Ry, H2 - 4 * Ry / 5));
    arrPnts.Add(MbCartPoint(Ry, H2));
    arrPnts.Add(MbCartPoint(Ry + B2, H2));
    arrPnts.Add(MbCartPoint(Ry + 2 * B2, H2 - Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + 4 * B2, H2 - Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + 4 * B2, H2 - 2 * Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + 2 * B2, H2 - 2 * Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + B2, H2 - 4 * Ry / 5));

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchK2TY(RPArray<MbContour>& _arrContours, float H2, float Ry, float B2)
{
    // ������ ������� - 8 �����
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(Ry, -H2 + 4 * Ry / 5));
    arrPnts.Add(MbCartPoint(Ry, -H2));
    arrPnts.Add(MbCartPoint(Ry + B2, -H2));
    arrPnts.Add(MbCartPoint(Ry + 2 * B2, -H2 + Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + 4 * B2, -H2 + Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + 4 * B2, -H2 + 2 * Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + 2 * B2, -H2 + 2 * Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + B2, -H2 + 4 * Ry / 5));

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

//����� �����������
void CreateSketchK3TY(RPArray<MbContour>& _arrContours, float RV, float LK, float B1, float B2)
{
    // ������ ������� - 4 �����
    SArray<MbCartPoint> arrPnts(4);
    arrPnts.Add(MbCartPoint(-LK + B1 - RV / 2 + B2, B1));
    arrPnts.Add(MbCartPoint(-LK + B1 - RV / 2 + B2, -B1));
    arrPnts.Add(MbCartPoint(LK - B1, -B1));
    arrPnts.Add(MbCartPoint(LK - B1, B1));

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

void CreateSketchCurveK(RPArray<MbContour>& _ptrContours, float RV, float LK, float B1, float B2)
{
    //������������ �������� �������
    MbContour* ptrContour = new MbContour();
    //���������� � ������ ���������

    MbCartPoint p1(-LK + B1, RV);
    MbCartPoint p2(-LK + B1, RV + 2 * B1);
    MbCartPoint p3(-LK + B1 - RV / 2, 0);
    MbCartPoint p4(-LK + B1 - RV / 2 + B2, 0);

    MbPlacement* plCurve = new MbPlacement(MbCartPoint(-LK + B1, 0), MbDirection(0.0));

    //������������ �������� �������� ��������
    MbLineSegment* Seg1 = new MbLineSegment(p1, p2);
    MbArc* Seg2 = new MbArc(-RV / 2, RV + 2 * B1, *plCurve, p2, p3, -1);
    MbLineSegment* Seg3 = new MbLineSegment(p3, p4);
    MbArc* Seg4 = new MbArc(-RV / 2 + B2, RV, *plCurve, p4, p1, 1);

    ptrContour->AddSegment(Seg1);
    ptrContour->AddSegment(Seg2);
    ptrContour->AddSegment(Seg3);
    ptrContour->AddSegment(Seg4);

    _ptrContours.push_back(ptrContour);
}

SPtr<MbSolid> ParametricModelCreator::Distribution_ChamberTY(BuildParams params)
{
    float DV = params.diam.toDouble(); //���������� �������
    float l = params.l.toDouble(); //�����
    float L = params.length.toDouble(); //�����
    float Dy = params.Dy.toDouble(); //������� ��������
    float H = params.height.toDouble(); //������ ��������
    float A1 = params.A.toDouble() / 2; //����� ������ (A)
    float l1 = params.l1.toDouble(); //����� �� ������� �������

    float RV = DV / 2; //���������� ������
    float h = floor((DV - 30) / 2 * sin(60 * M_PI / 180)); // ������ 6 ��������� (127)
    
    float LK1 = l1 + A1; //����� ������
    float LK = LK1 / 2; //����� ������ �������
    float LK2 = (L - LK1) / 2; //����� ������ �������
    
    float B1 = 5; //����� ������
    float B2 = 10; //������ ������
    float H2 = H / 2; //������ �������� �������
    float Ry = Dy / 2; //������� �������� �������

    // ��������� ��� �������������� ������� �������� �� �������� � �������
    const double DEG_TO_RAD = M_PI / 180.0;

    // ��������� �� (�� ��������� ��������� � ������� ��)
    MbPlacement3D pl, pl1, pl2;

    // ����� ������� ��� ���������� ���������� (�� ������� 6)
    RPArray<MbContour> arrContours, arrContours1, arrContours2, arrContours3, ptrContours;
    CreateSketchKTY(arrContours, RV, LK, B1);
    CreateSketchK1TY(arrContours1, H2, Ry, B2);
    CreateSketchK2TY(arrContours2, H2, Ry, B2);
    CreateSketchCurveK(ptrContours, RV, LK, B1, B2);
    CreateSketchK3TY(arrContours3, RV, LK, B1, B2);

    //for (int i = 0; i < arrContours1.size(); i++)
        //show(Style(1, RGB(0, 0, 255)), arrContours1[i], &pl);

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
    pntsCyl1.Add(MbCartPoint3D(0, 0, Ry + B2));
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
    pResSolid->Move(MbVector3D(-LK2 - LK - 8, 0, 0));

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