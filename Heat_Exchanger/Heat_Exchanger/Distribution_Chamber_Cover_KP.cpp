#include "BuildMathModel.h"
using namespace BuildMathModel;

// ��������������� ������� ��� ���������� ���������� � ���� �������� �� ������������.
void CreateSketchCCKP(RPArray<MbContour>& _arrContours)
{
    float DV,RV,DNK,L,B1;
    DNK = 663/2+12.5;//�������� ������� ������
    DV = 600; //���������� �������
    RV = DV/2; //���������� ������
    L = 40; //�����
    B1 = 7; //����� ������

    // ������ ������� - 8 �����
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(0, 0));
    arrPnts.Add(MbCartPoint(0, DNK));
    arrPnts.Add(MbCartPoint(3*B1, DNK));
    arrPnts.Add(MbCartPoint(3*B1, DNK-2*B1));
    arrPnts.Add(MbCartPoint(4*B1, DNK-2*B1));
    arrPnts.Add(MbCartPoint(4*B1, RV));
    arrPnts.Add(MbCartPoint(L, RV));
    arrPnts.Add(MbCartPoint(L, 0));



    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // ������� ���������� � �������������� ������� FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchCC1KP(RPArray<MbContour>& _arrContours)
{
    float DV,RV,DNK,L,B1;
    DNK = 663/2+12.5;//�������� ������� ������
    DV = 600; //���������� �������
    RV = DV/2; //���������� ������
    L = 40; //�����
    B1 = 7; //����� ������

    // ������ ������� - 4 �����
    SArray<MbCartPoint> arrPnts(4);
    arrPnts.Add(MbCartPoint(L-B1, -3));
    arrPnts.Add(MbCartPoint(L-B1, 3));
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
    // ��������� ��� �������������� ������� �������� �� �������� � �������
    const double DEG_TO_RAD = M_PI / 180.0;

    // ��������� �� (�� ��������� ��������� � ������� ��)
    MbPlacement3D pl;

    // ����� ������� ��� ���������� ���������� (�� ������� 6)
    RPArray<MbContour> arrContours,arrContours1;
    CreateSketchCCKP(arrContours);
    CreateSketchCC1KP(arrContours1);
    
    // ���������� ���������� ��� ������ ������� ���������� ���� ��������.
    // sweptData - ������, � ������� �������� �������� �� ����������.
    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0),MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, arrContours);
    MbSweptData sweptData1(*pPlaneXY, arrContours1);
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
    RevolutionValues revParms(360*DEG_TO_RAD, 0, 0);
    MbVector3D dir(0, 0, -1);
    ExtrusionValues extrusionParam(1000,1000);
    MbSNameMaker operBoolNames( ct_BooleanSolid, MbSNameMaker::i_SideNone ); 
    MbBooleanFlags flagsBool;
    flagsBool.InitBoolean(true);
    flagsBool.SetMergingFaces(true);
    flagsBool.SetMergingEdges(true);  

    // ����������� ��� �������� ���������� ���� �������� � ��� �������� ����������
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);
    MbSNameMaker plateNames( MbSNameMaker::i_SideNone); 
    // ��� �������� ��� ���������� ����:
    // ��� Y ������� �� ��������� �� -50 ������ ����� ��� X.
    MbAxis3D axis(pl.GetAxisX());
    //axis.Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(-50, 0, 0)));

    // ����� �������-������� ��� ���������� �������� ���� ��������
    MbSolid* pSolid = nullptr,*pPlate = nullptr;
    ::RevolutionSolid(sweptData, axis, revParms,operNames, cNames, pSolid);
    MbResultType res =::ExtrusionResult(*pSolid,cm_Same,sweptData1, dir, extrusionParam, bo_Difference, plateNames, NULL,pSolid);

    c3d::SolidSPtr MainSolid(pSolid);

    // ���������� ��������� ������ ������������ �������� ����
    ::DeleteItem(pSolid);

    return MainSolid;
}