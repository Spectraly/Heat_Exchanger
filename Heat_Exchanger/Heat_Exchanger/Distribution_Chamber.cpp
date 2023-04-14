#include "BuildMathModel.h"
using namespace BuildMathModel;

void CreateSketchK(RPArray<MbContour>& _arrContours,float RV, float DNK, float Ts)
{
    float LK,L2,B1;
    LK = 430; //�����
    L2 = LK/2; //����� �������
    B1 = 5; //����� ������

    // ������ ������� - 12 �����
    SArray<MbCartPoint> arrPnts(12);
    arrPnts.Add(MbCartPoint(-L2 + B1, 0));
    arrPnts.Add(MbCartPoint(-L2 + B1, DNK - 2 * B1));
    arrPnts.Add(MbCartPoint(-L2, DNK - 2 * B1));
    arrPnts.Add(MbCartPoint(-L2, DNK));
    arrPnts.Add(MbCartPoint(-L2 + 2 * Ts, DNK));
    arrPnts.Add(MbCartPoint(-L2 + 2 * Ts, RV + Ts));
    arrPnts.Add(MbCartPoint(L2 - 3.5 * B1, RV + Ts));
    arrPnts.Add(MbCartPoint(L2 - 3.5 * B1, DNK));
    arrPnts.Add(MbCartPoint(L2, DNK));
    arrPnts.Add(MbCartPoint(L2, DNK - 2 * B1));
    arrPnts.Add(MbCartPoint(L2 - B1, DNK - 2 * B1));
    arrPnts.Add(MbCartPoint(L2 - B1, 0));

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // ������� ���������� � �������������� ������� FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchK1(RPArray<MbContour>& _arrContours, float RV, float Dy1, float Ts)
{
    float Ry1 = Dy1 / 2; //���������� �������
    // ������ ������� - 8 �����
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(Ry1 + Ts, RV + 70));
    arrPnts.Add(MbCartPoint(Ry1 + Ts + 10, RV + 70 + 25));
    arrPnts.Add(MbCartPoint(Dy1, RV + 70 + 25));
    arrPnts.Add(MbCartPoint(Dy1, RV + 70 + 40));
    arrPnts.Add(MbCartPoint(Ry1 + Ts + 10, RV + 70 + 40));
    arrPnts.Add(MbCartPoint(Ry1 + Ts, RV + 70 + 50));
    arrPnts.Add(MbCartPoint(Ry1, RV + 70 + 50));
    arrPnts.Add(MbCartPoint(Ry1, RV + 70));
    

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchK2(RPArray<MbContour>& _arrContours, float RV, float Dy1, float Ts)
{
    float Ry1 = Dy1 / 2; //���������� �������
    // ������ ������� - 8 �����
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(Ry1 + Ts, -RV - 70));
    arrPnts.Add(MbCartPoint(Ry1 + Ts + 10, -RV - 70 - 25));
    arrPnts.Add(MbCartPoint(Dy1, -RV - 70 - 25));
    arrPnts.Add(MbCartPoint(Dy1, -RV - 70 - 40));
    arrPnts.Add(MbCartPoint(Ry1 + Ts + 10, -RV - 70 - 40));
    arrPnts.Add(MbCartPoint(Ry1 + Ts, -RV - 70 - 50));
    arrPnts.Add(MbCartPoint(Ry1, -RV - 70 - 50));
    arrPnts.Add(MbCartPoint(Ry1, -RV - 70));
    

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchK3(RPArray<MbContour>& _arrContours)
{

    float LK, L2,B1;
    LK = 430; //�����
    L2 = LK / 2; //����� �������
    B1 = 5; //����� ������

    // ������ ������� - 8 �����
    SArray<MbCartPoint> arrPnts(20);
    arrPnts.Add(MbCartPoint(-L2 + 2 * B1, -10));
    arrPnts.Add(MbCartPoint(-L2 + 2 * B1, -35));
    arrPnts.Add(MbCartPoint(-L2, -35));
    arrPnts.Add(MbCartPoint(-L2, -30));
    arrPnts.Add(MbCartPoint(-L2 + B1, -30));
    arrPnts.Add(MbCartPoint(-L2 + B1, 30));
    arrPnts.Add(MbCartPoint(-L2, 30));
    arrPnts.Add(MbCartPoint(-L2, 35));
    arrPnts.Add(MbCartPoint(-L2 + 2 * B1, 35));
    arrPnts.Add(MbCartPoint(-L2 + 2 * B1, 10));

    arrPnts.Add(MbCartPoint(L2 - 2 * B1, 10));
    arrPnts.Add(MbCartPoint(L2 - 2 * B1, 35));
    arrPnts.Add(MbCartPoint(L2, 35));
    arrPnts.Add(MbCartPoint(L2, 30));
    arrPnts.Add(MbCartPoint(L2 - B1, 30));
    arrPnts.Add(MbCartPoint(L2 - B1, -30));
    arrPnts.Add(MbCartPoint(L2, -30));
    arrPnts.Add(MbCartPoint(L2, -35));
    arrPnts.Add(MbCartPoint(L2 - 2 * B1, -35));
    arrPnts.Add(MbCartPoint(L2 - 2 * B1, -10));



    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

SPtr<MbSolid> ParametricModelCreator::Distribution_Chamber(BuildParams params)
{
    float Dy = params.Dy1.toDouble(); //���������� �������
    float Ry = Dy / 2; //���������� �������
    float DN = params.diam.toDouble(); //���������� �������
    float DV = DN - 25;
    float LK = 430; //�����
    float L2 = LK/2; //�����
    float A1 = params.A.toDouble();; //����� ������
    float RV = DV / 2; //���������� ������
    float Ts = (DN - DV) / 2;//������� ������
    float DNK = 363 / 2 + 10;//�������� ������� ������
    // ��������� ��� �������������� ������� �������� �� �������� � �������
    const double DEG_TO_RAD = M_PI / 180.0;

    // ��������� �� (�� ��������� ��������� � ������� ��)
    MbPlacement3D pl, pl1, pl2, pl3;


    RPArray<MbContour> arrContours, arrContours1, arrContours2, arrContours3;

    CreateSketchK(arrContours, RV, DNK, Ts);

    CreateSketchK1(arrContours1, RV, Dy, Ts);

    CreateSketchK2(arrContours2, RV, Dy, Ts);

    // ���������� ���������� ��� ������ ������� ���������� ���� ��������.
    CreateSketchK3(arrContours3);




    // sweptData - ������, � ������� �������� �������� �� ����������.
    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, arrContours);
    MbSweptData sweptData1(*pPlaneXY, arrContours1);
    MbSweptData sweptData2(*pPlaneXY, arrContours2);
    MbSweptData sweptData3(*pPlaneXY, arrContours3);

    // ������ ���������� ��� �������� ���������� ���� ��������.
    // ������ ��� ��������� ������������ ������ ���� �������� � ������ � ��������
    // ����������� (�� ������� � ���������� ��� �������������� ���� �������).
    // � ������ ������� �������� �������������� �� 120 �������� � ������ �����������.
    // ������ �������� ������ ����� ��������� �������� ����.
    // ��� s = 0 �������� ���� � ���������� �����, ��� s = 1 - � ���������� ����.
    // ���� ���������� - ����������� ������, � ��� �������� ����� � ��������� ������,
    // �� ��� s = 0 ��� ���������� ���������� ����� ������������� �������� �� ���
    // ��������. � ������ ������� �������� ����� ���������� s ���, �.�. ����������
    // ����� ��� ���������� �������.
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
    pntsCyl1.Add(MbCartPoint3D(0, -RV - 70, 0));
    pntsCyl1.Add(MbCartPoint3D(0, RV + 70, 0));
    pntsCyl1.Add(MbCartPoint3D(0, 0, Ry + Ts));
    // ���������� ������������� ���� - �������� - �� ���� ������
    ::ElementarySolid(pntsCyl1, et_Cylinder, cylNames, pCyl1);

    SArray<MbCartPoint3D> pntsCyl2(3);
    pntsCyl2.Add(MbCartPoint3D(0, -RV - 70, 0));
    pntsCyl2.Add(MbCartPoint3D(0, RV + 70, 0));
    pntsCyl2.Add(MbCartPoint3D(0, 0, Ry));
    // ���������� ������������� ���� - �������� - �� ���� ������
    ::ElementarySolid(pntsCyl2, et_Cylinder, cylNames, pCyl2);

    SArray<MbCartPoint3D> pntsCyl3(3);
    pntsCyl3.Add(MbCartPoint3D(-L2, 0, 0));
    pntsCyl3.Add(MbCartPoint3D(L2, 0, 0));
    pntsCyl3.Add(MbCartPoint3D(-L2, RV, 0));
    // ���������� ������������� ���� - �������� - �� ���� ������
    ::ElementarySolid(pntsCyl3, et_Cylinder, cylNames, pCyl3);
    // ����� �������-������� ��� ���������� �������� ���� ��������

    MbBooleanFlags flagsBool;
    flagsBool.InitBoolean(true);
    flagsBool.SetMergingFaces(true);
    flagsBool.SetMergingEdges(true);

    // �������������� ����
    MbSolid* pResSolid = NULL, * pDistributionChamber = NULL, * pConnector1 = nullptr, * pConnector2 = nullptr;
    ::RevolutionSolid(sweptData, axis, revParms, operNames, cNames, pDistributionChamber);
    ::RevolutionSolid(sweptData1, axis1, revParms, operNames, cNames, pConnector1);
    ::RevolutionSolid(sweptData2, axis2, revParms, operNames, cNames, pConnector2);


    ::BooleanResult(*pDistributionChamber, cm_Copy, *pCyl1, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pCyl2, cm_Copy, bo_Difference, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pCyl3, cm_Copy, bo_Difference, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pConnector1, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pConnector2, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);

    // ������������ ������ ��� �������� ������������
    MbVector3D dir(0, 0, -1);

    
    ExtrusionValues extrusionParam(294, 294);
    
    MbSolid* pPlate = nullptr;
    /*::ExtrusionSolid(sweptData3, dir, nullptr, nullptr, false, extrusionParam, operNames, cNames, pPlate);
    ::BooleanResult( *pResSolid, cm_Copy, *pPlate, cm_Copy, bo_Union,flagsBool, operBoolNames, pResSolid );*/

    c3d::SolidSPtr MainSolid(pResSolid);

    // ���������� ��������� ������ ������������ �������� ����
    ::DeleteItem(pResSolid);
    ::DeleteItem(pDistributionChamber);
    ::DeleteItem(pCyl1);
    ::DeleteItem(pCyl2);
    ::DeleteItem(pCyl3);
    ::DeleteItem(pConnector1);
    ::DeleteItem(pConnector2);

    return MainSolid;
}