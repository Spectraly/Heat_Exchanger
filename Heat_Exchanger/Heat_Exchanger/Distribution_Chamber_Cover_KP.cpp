#include "BuildMathModel.h"
using namespace BuildMathModel;

// ��������������� ������� ��� ���������� ���������� � ���� �������� �� ������������.
void CreateSketchCCKP(RPArray<MbContour>& _arrContours, float L, float RV, float DNK, float Ts)
{
    float B1 = 5; //����� ������

    // ������ ������� - 10 �����
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(0, 0));
    arrPnts.Add(MbCartPoint(0, DNK));
    arrPnts.Add(MbCartPoint(L - 2 * B1, DNK));
    arrPnts.Add(MbCartPoint(L - 2 * B1, DNK - 4 * B1 - 0.3 * Ts));
    arrPnts.Add(MbCartPoint(L - B1, DNK - 4 * B1 - 0.3 * Ts));
    arrPnts.Add(MbCartPoint(L - B1, RV));
    arrPnts.Add(MbCartPoint(L, RV));
    arrPnts.Add(MbCartPoint(L, 0));



    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // ������� ���������� � �������������� ������� FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchCC1KP(RPArray<MbContour>& _arrContours, float L)
{
    float B1 = 5; //����� ������

    // ������ ������� - 4 �����
    SArray<MbCartPoint> arrPnts(4);
    arrPnts.Add(MbCartPoint(L - B1, -3));
    arrPnts.Add(MbCartPoint(L - B1, 3));
    arrPnts.Add(MbCartPoint(L, 3));
    arrPnts.Add(MbCartPoint(L, -3));


    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // ������� ���������� � �������������� ������� FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

SPtr<MbSolid> ParametricModelCreator::Distribution_Chamber_Cover_KP(BuildParams params)
{
    float DV, DN, DNK, RV, L, Ts;
    L = params.TsF; //�����
    DV = params.diam.toDouble();//�������� �������
    DN = DV + DV / 100 * 8; //���������� �������
    Ts = params.TsS;//������� ������
    DNK = (DV + DV / 100 * 19.5) / 2 + 20 + 0.3 * Ts;//�������� ������� ������
    RV = DV / 2; //���������� ������

    // ��������� ��� �������������� ������� �������� �� �������� � �������
    const double DEG_TO_RAD = M_PI / 180.0;

    // ��������� �� (�� ��������� ��������� � ������� ��)
    MbPlacement3D pl;

    // ����� ������� ��� ���������� ���������� (�� ������� 6)
    RPArray<MbContour> arrContours,arrContours1;
    CreateSketchCCKP(arrContours, L, RV, DNK, Ts);
    CreateSketchCC1KP(arrContours1, L);
    
    
    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0),MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, arrContours);
    MbSweptData sweptData1(*pPlaneXY, arrContours1);
   
    RevolutionValues revParms(360*DEG_TO_RAD, 0, 0);
    MbVector3D dir(0, 0, -1);
    ExtrusionValues extrusionParam(DN, DN);
    MbSNameMaker operBoolNames( ct_BooleanSolid, MbSNameMaker::i_SideNone ); 
    MbBooleanFlags flagsBool;
    flagsBool.InitBoolean(true);
    flagsBool.SetMergingFaces(true);
    flagsBool.SetMergingEdges(true);  

    // ����������� ��� �������� ���������� ���� �������� � ��� �������� ����������
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);
    MbSNameMaker plateNames( MbSNameMaker::i_SideNone); 
   
    MbAxis3D axis(pl.GetAxisX());


    // ����� �������-������� ��� ���������� �������� ���� ��������
    MbSolid* pSolid = nullptr,*pPlate = nullptr;
    ::RevolutionSolid(sweptData, axis, revParms, operNames, cNames, pSolid);
    ::ExtrusionResult(*pSolid, cm_Same, sweptData1, dir, extrusionParam, bo_Difference, plateNames, NULL, pSolid);

    c3d::SolidSPtr MainSolid(pSolid);

    // ���������� ��������� ������ ������������ �������� ����
    ::DeleteItem(pSolid);

    return MainSolid;
}