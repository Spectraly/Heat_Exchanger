#include "BuildMathModel.h"

using namespace BuildMathModel;


float B1 = 5; //����� ������
float A2 = 230; //����� ������

void CreateSketch(RPArray<MbContour>& _arrContours,float RV,float L2, float DNK, float Ts)
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
    arrPnts.Add(MbCartPoint(L2 - 7 * B1, RV + 6 * Ts));//8
    arrPnts.Add(MbCartPoint(L2 - 3 * B1, RV + 6 * Ts));//9
    arrPnts.Add(MbCartPoint(L2 - 3 * B1, RV + 6 * Ts - 4 * B1));//10
    arrPnts.Add(MbCartPoint(L2, RV + 6 * Ts - 4 * B1));//11
    arrPnts.Add(MbCartPoint(L2, 0));//12

    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketch1(RPArray<MbContour>& _arrContours, float RV, float L2, float Dy, float Ts)
{
    float Ry = Dy / 2; //���������� �������
    float  S = -L2 + A2;
   
    // ������ ������� - 8 �����
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(S - Ry - Ts, RV + 70));
    arrPnts.Add(MbCartPoint(S - Ry - Ts - 10, RV + 70 + 25));
    arrPnts.Add(MbCartPoint(S - Dy, RV + 70 + 25));
    arrPnts.Add(MbCartPoint(S - Dy, RV + 70 + 40));
    arrPnts.Add(MbCartPoint(S - Ry - Ts - 10, RV + 70 + 40));
    arrPnts.Add(MbCartPoint(S - Ry - Ts, RV + 70 + 50));
    arrPnts.Add(MbCartPoint(S - Ry, RV + 70 + 50));
    arrPnts.Add(MbCartPoint(S - Ry, RV + 70));


    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

void CreateSketch2(RPArray<MbContour>& _arrContours, float RV, float L2,float A1, float Dy, float Ts)
{
    float Ry = Dy / 2; //���������� �������
    float S = -L2 + A2 + A1;

    // ������ ������� - 8 �����
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(S + Ry + Ts, -RV - 70));
    arrPnts.Add(MbCartPoint(S + Ry + Ts + 10, -RV - 70 - 25));
    arrPnts.Add(MbCartPoint(S + Dy, -RV - 70 - 25));
    arrPnts.Add(MbCartPoint(S + Dy, -RV - 70 - 40));
    arrPnts.Add(MbCartPoint(S + Ry + Ts + 10, -RV - 70 - 40));
    arrPnts.Add(MbCartPoint(S + Ry + Ts, -RV - 70 - 50));
    arrPnts.Add(MbCartPoint(S + Ry, -RV - 70 - 50));
    arrPnts.Add(MbCartPoint(S + Ry, -RV - 70));


    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

SPtr<MbSolid> ParametricModelCreator::Casing(BuildParams params)
{
    float DN = params.diam.toDouble(); //���������� �������
    float LK = params.length.toDouble(); //�����
    float A1 = params.A1.toDouble();; //����� ������
    float Dy = params.Dy.toDouble(); //���������� �������
    float Ry = Dy / 2; //���������� �������
    float DV = DN - 25;
    float RV = DV / 2; //���������� ������
    float L2 = LK / 2; //����� �������
    float Ts = (DN - DV) / 2;//������� ������
    float DNK = (DN+38) / 2 + 10;//�������� ������� ������

   
    // ��������� ��� �������������� ������� �������� �� �������� � �������
    const double DEG_TO_RAD = M_PI / 180.0;

    // ��������� �� (�� ��������� ��������� � ������� ��)
    MbPlacement3D pl,pl1,pl2;

    // ����� ������� ��� ���������� ���������� (�� ������� 6)
    RPArray<MbContour> arrContours,arrContours1,arrContours2;
    CreateSketch(arrContours,RV,L2,DNK,Ts);
    CreateSketch1(arrContours1, RV, L2,Dy,Ts);
    CreateSketch2(arrContours2, RV, L2, A1,Dy,Ts);

    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0),MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, arrContours);
    MbSweptData sweptData1(*pPlaneXY, arrContours1);
    MbSweptData sweptData2(*pPlaneXY, arrContours2);

    RevolutionValues revParms(360*DEG_TO_RAD, 0, 0);

    // ����������� ��� �������� ���������� ���� �������� � ��� �������� ����������
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);

    // ��� �������� ��� ���������� ����:
    MbAxis3D axis(pl.GetAxisX());
    MbAxis3D axis1(pl1.GetAxisY());
    MbAxis3D axis2(pl2.GetAxisY());
    axis1.Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(-L2+A2, 0, 0)));
    axis2.Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(-L2+A2+A1, 0, 0)));


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
    pntsCyl1.Add(MbCartPoint3D(-L2+A2, 0, 0));
    pntsCyl1.Add(MbCartPoint3D(-L2+A2, RV+70, 0));
    pntsCyl1.Add(MbCartPoint3D(-L2+A2, 0, Ry + Ts));
    // ���������� ������������� ���� - �������� - �� ���� ������
   ::ElementarySolid( pntsCyl1, et_Cylinder, cylNames, pCyl1 );
   
   SArray<MbCartPoint3D> pntsCyl2(3);
    pntsCyl2.Add(MbCartPoint3D(-L2+A2+A1, 0, 0));
    pntsCyl2.Add(MbCartPoint3D(-L2+A2+A1, -RV-70, 0));
    pntsCyl2.Add(MbCartPoint3D(-L2+A2+A1, 0, Ry + Ts));
    // ���������� ������������� ���� - �������� - �� ���� ������
   ::ElementarySolid( pntsCyl2, et_Cylinder, cylNames, pCyl2 );
   
    SArray<MbCartPoint3D> pntsCyl3(3);
    pntsCyl3.Add(MbCartPoint3D(-L2+A2, 0, 0));
    pntsCyl3.Add(MbCartPoint3D(-L2+A2, RV+70, 0));
    pntsCyl3.Add(MbCartPoint3D(-L2+A2, 0, Ry));  
    // ���������� ������������� ���� - �������� - �� ���� ������
   ::ElementarySolid( pntsCyl3, et_Cylinder, cylNames, pCyl3 );
   
    SArray<MbCartPoint3D> pntsCyl4(3);
    pntsCyl4.Add(MbCartPoint3D(-L2+A2+A1, 0, 0));
    pntsCyl4.Add(MbCartPoint3D(-L2+A2+A1, -RV-70, 0));
    pntsCyl4.Add(MbCartPoint3D(-L2+A2+A1, 0, Ry));  
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