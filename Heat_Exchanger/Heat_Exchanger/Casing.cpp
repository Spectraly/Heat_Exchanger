#include "BuildMathModel.h"

using namespace BuildMathModel;





void CreateSketch(RPArray<MbContour>& _arrContours,float RV,float L2, float DNK, float Ts,float B1)
{

    // ������ ������� - 12 �����
    SArray<MbCartPoint> arrPnts(12);
    arrPnts.Add(MbCartPoint(-L2 + B1, 0));//1
    arrPnts.Add(MbCartPoint(-L2 + B1, DNK - 2 * B1));//2
    arrPnts.Add(MbCartPoint(-L2, DNK - 2 * B1));//3
    arrPnts.Add(MbCartPoint(-L2, DNK));//4
    arrPnts.Add(MbCartPoint(-L2 + 4.5 * B1, DNK));//5
    arrPnts.Add(MbCartPoint(-L2 + 4.5 * B1, RV + Ts));//6
    arrPnts.Add(MbCartPoint(L2 - 7 * B1, RV + Ts));//7
    arrPnts.Add(MbCartPoint(L2 - 7 * B1, RV + 2 * Ts + 8 * B1));//8
    arrPnts.Add(MbCartPoint(L2 - 3 * B1, RV + 2 * Ts + 8 * B1));//9
    arrPnts.Add(MbCartPoint(L2 - 3 * B1, RV + 2 * Ts + 4 * B1));//10
    arrPnts.Add(MbCartPoint(L2, RV + 2 * Ts + 4 * B1));//11
    arrPnts.Add(MbCartPoint(L2, 0));//12

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketch1(RPArray<MbContour>& _arrContours, float RV, float L2, float Dy, float Ts, float A,float H2)
{
    float Ry = Dy / 2; //���������� �������
    float  S = -L2 + A;
   
    // ������ ������� - 8 �����
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(S - Ry - Ts, H2));
    arrPnts.Add(MbCartPoint(S - Ry - Ts - 10, H2 + Ry/2));
    arrPnts.Add(MbCartPoint(S - Ry - Ts - Ry / 2, H2 + Ry/2));
    arrPnts.Add(MbCartPoint(S - Ry - Ts - Ry / 2, H2 + Ry * 4 / 5));
    arrPnts.Add(MbCartPoint(S - Ry - Ts - 10, H2 + Ry * 4 / 5));
    arrPnts.Add(MbCartPoint(S - Ry - Ts, H2 + Ry));
    arrPnts.Add(MbCartPoint(S - Ry, H2 + Ry));
    arrPnts.Add(MbCartPoint(S - Ry, H2));


    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

void CreateSketch2(RPArray<MbContour>& _arrContours, float RV, float L2,float A1, float A, float Dy, float Ts, float H2)
{
    float Ry = Dy / 2; //���������� �������
    float S = -L2 + A + A1;

    // ������ ������� - 8 �����
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(S + Ry + Ts, -H2));
    arrPnts.Add(MbCartPoint(S + Ry + Ts + 10, -H2 - Ry / 2));
    arrPnts.Add(MbCartPoint(S + Ry + Ts + Ry / 2, -H2 - Ry / 2));
    arrPnts.Add(MbCartPoint(S + Ry + Ts + Ry / 2, -H2 - Ry * 4 / 5));
    arrPnts.Add(MbCartPoint(S + Ry + Ts + 10, -H2 - Ry * 4 / 5));
    arrPnts.Add(MbCartPoint(S + Ry + Ts, -H2 - Ry));
    arrPnts.Add(MbCartPoint(S + Ry, -H2 - Ry));
    arrPnts.Add(MbCartPoint(S + Ry, -H2));


    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

void CreateSketch3(RPArray<MbContour>& _arrContours, float RV, float L2, float A, float Dy, float Ts)
{


    float Ry = Dy / 2;
    float S = -L2 + A;//������� ��� ����� �����
    // ������ ������� - 8 �����
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(S - Ry - Ts, RV - (RV / 100 * 9) - 5));
    arrPnts.Add(MbCartPoint(S - Ry - Ts, RV - (RV / 100 * 9)));
    arrPnts.Add(MbCartPoint(S + Ry + Ts, RV - (RV / 100 * 9)));
    arrPnts.Add(MbCartPoint(S + Ry + Ts, RV - (RV / 100 * 9) - 5));


    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

SPtr<MbSolid> ParametricModelCreator::Casing(BuildParams params)
{

    float DV = params.diam.toDouble();//�������� �������
    float L = params.length.toDouble(); //�����
    float A1 = params.A1.toDouble(); //����� ������
    float A = (params.A.toDouble()/100)*30; //����� ������
    float Dy = params.Dy.toDouble(); //���������� �������
    float H = params.height.toDouble(); //���������� �������
    float LK = (L/100) * 78.5; //�����
    float H2 = H/2 - Dy/2; //���������� �������
    float Ry = Dy / 2; //���������� �������
    float DN = DV + DV / 100 * 8; //���������� �������
    float RV = DV / 2; //���������� ������
    float L2 = LK / 2; //����� �������
    float Ts = (DN - DV) / 2;//������� ������
    float DNK = (DV + DV / 100 * 19.5) / 2 + 10;//�������� ������� ������
    float B1 = 5; //����� ������
   
    // ��������� ��� �������������� ������� �������� �� �������� � �������
    const double DEG_TO_RAD = M_PI / 180.0;

    // ��������� �� (�� ��������� ��������� � ������� ��)
    MbPlacement3D pl,pl1,pl2;

    // ����� ������� ��� ���������� ���������� (�� ������� 6)
    RPArray<MbContour> arrContours,arrContours1,arrContours2, arrContours3;
    CreateSketch(arrContours,RV,L2,DNK,Ts,B1);
    CreateSketch1(arrContours1, RV, L2,Dy,Ts,A,H2);
    CreateSketch2(arrContours2, RV, L2, A1,A,Dy,Ts,H2);
    CreateSketch3(arrContours3, RV, L2,A,Dy,Ts);

    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0),MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, arrContours);
    MbSweptData sweptData1(*pPlaneXY, arrContours1);
    MbSweptData sweptData2(*pPlaneXY, arrContours2);
    MbSweptData sweptData3(*pPlaneXY, arrContours3);

    RevolutionValues revParms(360*DEG_TO_RAD, 0, 0);

    // ����������� ��� �������� ���������� ���� �������� � ��� �������� ����������
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);

    // ��� �������� ��� ���������� ����:
    MbAxis3D axis(pl.GetAxisX());
    MbAxis3D axis1(pl1.GetAxisY());
    MbAxis3D axis2(pl2.GetAxisY());
    axis1.Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(-L2+A, 0, 0)));
    axis2.Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(-L2+A+A1, 0, 0)));


    // ����� �������-������� ��� ���������� �������� ���� ��������
    MbSolid *pCasing = nullptr,*pConnector1 = nullptr,*pConnector2 = nullptr;
    ::RevolutionSolid(sweptData, axis, revParms,operNames, cNames, pCasing);
    ::RevolutionSolid(sweptData1, axis1, revParms,operNames, cNames, pConnector1);
    ::RevolutionSolid(sweptData2, axis2, revParms,operNames, cNames, pConnector2);
     
     //---------------------------------------------------------//
     MbSNameMaker operBoolNames( ct_BooleanSolid, MbSNameMaker::i_SideNone ); 
        // �������� ���� - ��������
    MbSolid *pCyl1 = NULL, *pCyl2 = NULL, *pCyl3 = NULL, *pCyl4 = NULL, *pCyl5 = NULL;
    
    // ������-����������� ��� ���������� ��������� - ������������ ���
    MbSNameMaker cylNames(ct_ElementarySolid, MbSNameMaker::i_SideNone); 
    
    // ������ ����� ��� ���������� ������� ��������   
    SArray<MbCartPoint3D> pntsCyl1(3);
    pntsCyl1.Add(MbCartPoint3D(-L2+A, 0, 0));
    pntsCyl1.Add(MbCartPoint3D(-L2+A, H2, 0));
    pntsCyl1.Add(MbCartPoint3D(-L2+A, 0, Ry + Ts));
    // ���������� ������������� ���� - �������� - �� ���� ������
   ::ElementarySolid( pntsCyl1, et_Cylinder, cylNames, pCyl1 );
   
   SArray<MbCartPoint3D> pntsCyl2(3);
    pntsCyl2.Add(MbCartPoint3D(-L2+A+A1, 0, 0));
    pntsCyl2.Add(MbCartPoint3D(-L2+A+A1, -H2, 0));
    pntsCyl2.Add(MbCartPoint3D(-L2+A+A1, 0, Ry + Ts));
    // ���������� ������������� ���� - �������� - �� ���� ������
   ::ElementarySolid( pntsCyl2, et_Cylinder, cylNames, pCyl2 );
   
    SArray<MbCartPoint3D> pntsCyl3(3);
    pntsCyl3.Add(MbCartPoint3D(-L2+A, 0, 0));
    pntsCyl3.Add(MbCartPoint3D(-L2+A, H2, 0));
    pntsCyl3.Add(MbCartPoint3D(-L2+A, 0, Ry));  
    // ���������� ������������� ���� - �������� - �� ���� ������
   ::ElementarySolid( pntsCyl3, et_Cylinder, cylNames, pCyl3 );
   
    SArray<MbCartPoint3D> pntsCyl4(3);
    pntsCyl4.Add(MbCartPoint3D(-L2+A+A1, 0, 0));
    pntsCyl4.Add(MbCartPoint3D(-L2+A+A1, -H2, 0));
    pntsCyl4.Add(MbCartPoint3D(-L2+A+A1, 0, Ry));  
    // ���������� ������������� ���� - �������� - �� ���� ������
   ::ElementarySolid( pntsCyl4, et_Cylinder, cylNames, pCyl4 );
   
    SArray<MbCartPoint3D> pntsCyl5(3);
    pntsCyl5.Add(MbCartPoint3D(-L2, 0, 0));
    pntsCyl5.Add(MbCartPoint3D(L2, 0, 0));
    pntsCyl5.Add(MbCartPoint3D(-L2, RV, 0));  
    // ���������� ������������� ���� - �������� - �� ���� ������
   ::ElementarySolid( pntsCyl5, et_Cylinder, cylNames, pCyl5 );
   
    //---------------------------------------------------------//
    // ����� ������� ��������: ���������� ���������� ���� � ������������ �������� ������ � �����.
    MbBooleanFlags flagsBool;
    flagsBool.InitBoolean(true);
    flagsBool.SetMergingFaces(true);
    flagsBool.SetMergingEdges(true); 
    
    // �������������� ����
    MbSolid *pResSolid = NULL;

    ::BooleanResult( *pCasing, cm_Copy, *pCyl1, cm_Copy, bo_Union,flagsBool, operBoolNames, pResSolid );
    ::BooleanResult( *pResSolid, cm_Copy, *pCyl2, cm_Copy, bo_Union,flagsBool, operBoolNames, pResSolid );
    ::BooleanResult( *pResSolid, cm_Copy, *pCyl3, cm_Copy, bo_Difference,flagsBool, operBoolNames, pResSolid );
    ::BooleanResult( *pResSolid, cm_Copy, *pCyl4, cm_Copy, bo_Difference,flagsBool, operBoolNames, pResSolid );
    ::BooleanResult( *pResSolid, cm_Copy, *pCyl5, cm_Copy, bo_Difference,flagsBool, operBoolNames, pResSolid );
    ::BooleanResult( *pResSolid, cm_Copy, *pConnector1, cm_Copy, bo_Union,flagsBool, operBoolNames, pResSolid);
    ::BooleanResult( *pResSolid, cm_Copy, *pConnector2, cm_Copy, bo_Union,flagsBool, operBoolNames, pResSolid);

    MbVector3D dir(0, 0, -1);
    ExtrusionValues extrusionParam;
    extrusionParam.side1.way = sw_shell;
    extrusionParam.side2.way = sw_shell;
    MbSolid* pPlate = nullptr;

    ::ExtrusionSolid(sweptData3, dir, pResSolid, pResSolid, false, extrusionParam, operNames, cNames, pPlate);
    MbResultType res = ::BooleanResult(*pResSolid, cm_Copy, *pPlate, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);

    c3d::SolidSPtr MainSolid(pResSolid);
    // ���������� ��������� ������ ������������ �������� ����
    ::DeleteItem(pCyl1);
    ::DeleteItem(pCyl2);
    ::DeleteItem(pCyl3);
    ::DeleteItem(pCyl4);
    ::DeleteItem(pCyl5);
    ::DeleteItem(pCasing);
    ::DeleteItem(pConnector1);
    ::DeleteItem(pConnector2);
    ::DeleteItem(pResSolid);

    return MainSolid;
}