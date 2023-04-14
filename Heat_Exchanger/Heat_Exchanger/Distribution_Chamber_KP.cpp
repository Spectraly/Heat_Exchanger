#include "BuildMathModel.h"
using namespace BuildMathModel;

// ��������������� ������� ��� ���������� ���������� � ���� �������� �� ������������.
void CreateSketchCKP(RPArray<MbContour>& _arrContours)
{
    float DV,RV,DN,DNK,TS,LK,L2,B1;
    DV = 600; //���������� �������
    DNK = 663/2+12.5;//�������� ������� ������
    DN = DV + 30;//�������� �������
    TS = (DN-DV)/2;//������� ������
    RV = DV/2; //���������� ������
    LK = 518; //�����
    L2 = LK/2; //����� �������
    B1 = 7; //����� ������

    // ������ ������� - 12 �����
    SArray<MbCartPoint> arrPnts(12);
    arrPnts.Add(MbCartPoint(-L2+B1, 0));
    arrPnts.Add(MbCartPoint(-L2+B1, DNK-2*B1));
    arrPnts.Add(MbCartPoint(-L2,  DNK-2*B1));
    arrPnts.Add(MbCartPoint(-L2,  DNK));
    arrPnts.Add(MbCartPoint(-L2+2*TS,  DNK));
    arrPnts.Add(MbCartPoint(-L2+2*TS, RV+TS));
    
    arrPnts.Add(MbCartPoint(L2-3.5*B1, RV+TS));
    arrPnts.Add(MbCartPoint(L2-3.5*B1, DNK));
    arrPnts.Add(MbCartPoint(L2, DNK));
    arrPnts.Add(MbCartPoint(L2, DNK-2*B1));
    arrPnts.Add(MbCartPoint(L2-B1, DNK-2*B1));
    arrPnts.Add(MbCartPoint(L2-B1, 0));

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // ������� ���������� � �������������� ������� FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchCKP1(RPArray<MbContour>& _arrContours)
{
    float DV,RV,Dy1,Ry1,TS,DN;
    DV = 600; //���������� �������
    RV = DV/2; //���������� ������
    Dy1 = 200;
    Ry1 = Dy1/2;
    DN = DV + 30;//�������� �������
    TS = (DN-DV)/2;//������� ������
    // ������ ������� - 8 �����
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(Ry1+TS, RV+215));
    arrPnts.Add(MbCartPoint(Ry1+TS+10, RV+215+25));
    arrPnts.Add(MbCartPoint(Dy1, RV+215+25));
    arrPnts.Add(MbCartPoint(Dy1, RV+215+40));
    arrPnts.Add(MbCartPoint(Ry1+TS+10, RV+215+40));
    arrPnts.Add(MbCartPoint(Ry1+TS, RV+215+50));
    arrPnts.Add(MbCartPoint(Ry1, RV+215+50));
    arrPnts.Add(MbCartPoint(Ry1, RV+215));
    

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchCKP2(RPArray<MbContour>& _arrContours)
{
    
    float DV,RV,Dy1,Ry1,TS,DN;
    DV = 600; //���������� �������
    RV = DV/2; //���������� ������
    Dy1 = 200;
    Ry1 = Dy1/2;
    DN = DV + 30;//�������� �������
    TS = (DN-DV)/2;//������� ������
    // ������ ������� - 8 �����
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(Ry1+TS, -RV-215));
    arrPnts.Add(MbCartPoint(Ry1+TS+10, -RV-215-25));
    arrPnts.Add(MbCartPoint(Dy1, -RV-215-25));
    arrPnts.Add(MbCartPoint(Dy1, -RV-215-40));
    arrPnts.Add(MbCartPoint(Ry1+TS+10, -RV-215-40));
    arrPnts.Add(MbCartPoint(Ry1+TS, -RV-215-50));
    arrPnts.Add(MbCartPoint(Ry1, -RV-215-50));
    arrPnts.Add(MbCartPoint(Ry1, -RV-215));
    

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchCKP3(RPArray<MbContour>& _arrContours)
{
    float DV,RV,DN,DNK,TS,LK,L2,B1;
    DV = 600; //���������� �������
    DNK = 663/2+12.5;//�������� ������� ������
    DN = DV + 30;//�������� �������
    TS = (DN-DV)/2;//������� ������
    RV = DV/2; //���������� ������
    LK = 518; //�����
    L2 = LK/2; //����� �������
    B1 = 7; //����� ������
    
    // ������ ������� - 8 �����
    SArray<MbCartPoint> arrPnts(20);
    arrPnts.Add(MbCartPoint(-L2+2*B1, -10));
    arrPnts.Add(MbCartPoint(-L2+2*B1, -35));
    arrPnts.Add(MbCartPoint(-L2, -35));
    arrPnts.Add(MbCartPoint(-L2, -30));
    arrPnts.Add(MbCartPoint(-L2+B1, -30));
    arrPnts.Add(MbCartPoint(-L2+B1, 30));
    arrPnts.Add(MbCartPoint(-L2, 30));
    arrPnts.Add(MbCartPoint(-L2, 35));
    arrPnts.Add(MbCartPoint(-L2+2*B1, 35));
    arrPnts.Add(MbCartPoint(-L2+2*B1, 10));
    
    arrPnts.Add(MbCartPoint(L2-2*B1, 10));
    arrPnts.Add(MbCartPoint(L2-2*B1, 35));
    arrPnts.Add(MbCartPoint(L2, 35));
    arrPnts.Add(MbCartPoint(L2, 30));
    arrPnts.Add(MbCartPoint(L2-B1, 30));
    arrPnts.Add(MbCartPoint(L2-B1, -30));
    arrPnts.Add(MbCartPoint(L2, -30));
    arrPnts.Add(MbCartPoint(L2, -35));
    arrPnts.Add(MbCartPoint(L2-2*B1, -35));
    arrPnts.Add(MbCartPoint(L2-2*B1, -10));

    

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
SPtr<MbSolid> ParametricModelCreator::Distribution_Chamber_KP(BuildParams params)
{
    float DV,RV,DN,Dy,Ry,DNK,TS,LK,L2,B1;
    DV = 600; //���������� �������
    DNK = 663/2+12.5;//�������� ������� ������
    DN = DV + 30;//�������� �������
    TS = (DN-DV)/2;//������� ������
    RV = DV/2; //���������� ������
    Dy = 200;
    Ry = Dy/2;
    LK = 518; //�����
    L2 = LK/2; //����� �������
    // ��������� ��� �������������� ������� �������� �� �������� � �������
    const double DEG_TO_RAD = M_PI / 180.0;

    // ��������� �� (�� ��������� ��������� � ������� ��)
    MbPlacement3D pl,pl1,pl2,pl3;

    // ����� ������� ��� ���������� ���������� (�� ������� 6)
    RPArray<MbContour> arrContours,arrContours1,arrContours2,arrContours3;
    CreateSketchCKP(arrContours);
    CreateSketchCKP1(arrContours1);
    CreateSketchCKP2(arrContours2);
    CreateSketchCKP3(arrContours3);
    
    
    // sweptData - ������, � ������� �������� �������� �� ����������.
    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0),MbCartPoint3D(0, 1, 0));
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
    RevolutionValues revParms(360*DEG_TO_RAD, 0, 0);
    // ����������� ��� �������� ���������� ���� �������� � ��� �������� ����������
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);

    // ��� �������� ��� ���������� ����:
    // ��� Y ������� �� ��������� �� -50 ������ ����� ��� X.
    MbAxis3D axis(pl.GetAxisX());
    MbAxis3D axis1(pl1.GetAxisY());
    MbAxis3D axis2(pl2.GetAxisY());
    MbSNameMaker operBoolNames( ct_BooleanSolid, MbSNameMaker::i_SideNone ); 
    // �������� ���� - ��������
    MbSolid *pCyl1 = NULL, *pCyl2 = NULL, *pCyl3 = NULL;
    
    // ������-����������� ��� ���������� ��������� - ������������ ���
    MbSNameMaker cylNames(ct_ElementarySolid, MbSNameMaker::i_SideNone); 

    SArray<MbCartPoint3D> pntsCyl1(3);
    pntsCyl1.Add(MbCartPoint3D(0, -RV-215, 0));
    pntsCyl1.Add(MbCartPoint3D(0, RV+215, 0));
    pntsCyl1.Add(MbCartPoint3D(0, 0, Ry+TS));  
    // ���������� ������������� ���� - �������� - �� ���� ������
   ::ElementarySolid( pntsCyl1, et_Cylinder, cylNames, pCyl1 );
   
   SArray<MbCartPoint3D> pntsCyl2(3);
    pntsCyl2.Add(MbCartPoint3D(0, -RV-215, 0));
    pntsCyl2.Add(MbCartPoint3D(0, RV+215, 0));
    pntsCyl2.Add(MbCartPoint3D(0, 0, Ry));  
    // ���������� ������������� ���� - �������� - �� ���� ������
   ::ElementarySolid( pntsCyl2, et_Cylinder, cylNames, pCyl2 );
   
    SArray<MbCartPoint3D> pntsCyl3(3);
    pntsCyl3.Add(MbCartPoint3D(-L2, 0, 0));
    pntsCyl3.Add(MbCartPoint3D(L2, 0, 0));
    pntsCyl3.Add(MbCartPoint3D(-L2, RV, 0));  
    // ���������� ������������� ���� - �������� - �� ���� ������
   ::ElementarySolid( pntsCyl3, et_Cylinder, cylNames, pCyl3 );
    // ����� �������-������� ��� ���������� �������� ���� ��������
    
     MbBooleanFlags flagsBool;
    flagsBool.InitBoolean(true);
    flagsBool.SetMergingFaces(true);
    flagsBool.SetMergingEdges(true);  

    // �������������� ����
    MbSolid *pResSolid = NULL,* pDistributionChamber = NULL,*pConnector1 = nullptr,*pConnector2 = nullptr;
    ::RevolutionSolid(sweptData, axis, revParms,operNames, cNames, pDistributionChamber);
    ::RevolutionSolid(sweptData1, axis1, revParms,operNames, cNames, pConnector1);
    ::RevolutionSolid(sweptData2, axis2, revParms,operNames, cNames, pConnector2);
    
    
    ::BooleanResult( *pDistributionChamber, cm_Copy, *pCyl1, cm_Copy, bo_Union,flagsBool, operBoolNames, pResSolid );
    ::BooleanResult( *pResSolid, cm_Copy, *pCyl2, cm_Copy, bo_Difference,flagsBool, operBoolNames, pResSolid );
    ::BooleanResult( *pResSolid, cm_Copy, *pCyl3, cm_Copy, bo_Difference,flagsBool, operBoolNames, pResSolid );
    ::BooleanResult( *pResSolid, cm_Copy, *pConnector1, cm_Copy, bo_Union,flagsBool, operBoolNames, pResSolid );
    ::BooleanResult( *pResSolid, cm_Copy, *pConnector2, cm_Copy, bo_Union,flagsBool, operBoolNames, pResSolid );
    
    // ������������ ������ ��� �������� ������������
    MbVector3D dir(0, 0, -1);
    
    //���� ��� ����� ����������� �� � ���� � ����� �� 600 �������������� ��� �������� ������ ��������� � ���������� �� �����
    //�� ������ ������ � ��� ����� ��� �������� � �������� ������ ����� � �� �������� ������ ��� � � ���������� ������� ��� ��� ���� ����� ��� ������������ �� ���� ������ ���� ������ ��� ���� ���� ���� �� �������� �� ��� �������. ������ ������ ����
    // ��������� �������� ������������
    ExtrusionValues extrusionParam(600,600);
    // ������� �����������, �� ������� ����� ����������� ������������
    // � ������ �����������
    // �������� ������� ������������ � ������ ����������� - �� ����������� � ������������
    
    //-----------------���� ������ ���� ������ ����� ���� ��� ��� ��� ������ ����� ������ �������� ������������ �� ����. ��� ������ ���������� �� ����� �������� ���� ��� �� ��������. ������ ����
    //extrusionParam.side1.way = sw_shell;
    //extrusionParam.side2.way = swShell;
    
    //����� ������ ������ �������� ��� ������������ ������������ ���������� � ��� � ���� pPlate ����� ��������� �������� ��������� ��� ���� � ��������
    MbSolid* pPlate = nullptr;
    //MbResultType res =::ExtrusionSolid(sweptData3, dir, nullptr, nullptr, false, extrusionParam, operNames, cNames, pPlate);
    //::BooleanResult( *pResSolid, cm_Copy, *pPlate, cm_Copy, bo_Union,flagsBool, operBoolNames, pResSolid );
    

    c3d::SolidSPtr MainSolid(pResSolid);
    // ���������� ��������� ������ ������������ �������� ����
    ::DeleteItem(pDistributionChamber);
    ::DeleteItem(pCyl1);
    ::DeleteItem(pCyl2);
    ::DeleteItem(pCyl3);
    ::DeleteItem(pConnector1);
    ::DeleteItem(pConnector2);
    ::DeleteItem(pResSolid);

    return MainSolid;
}