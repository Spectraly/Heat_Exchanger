#include "BuildMathModel.h"
using namespace BuildMathModel;


SPtr<MbSolid> ParametricModelCreator::Floating_Head_Cover(BuildParams params)
{
   float DV,RV,B1;
    DV = params.diam.toDouble();//�������� �������
    B1 = 5; //����� ������

    switch ((int)DV)
    {
    case 325:
        RV = (DV - 3) / 2;
        break;
    case 400:
        RV = (DV - 2) / 2;
        break;
    case 500:
        RV = (DV - 2) / 2;
        break;
    case 600:
        RV = (DV - 4) / 2;
        break;
    case 700:
        RV = (DV - 5) / 2;
        break;
    case 800:
        RV = (DV - 5) / 2;
        break;
    case 900:
        RV = (DV - 5) / 2;
        break;
    case 1000:
        RV = (DV - 5) / 2;
        break;
    case 1200:
        RV = (DV - 5) / 2;
        break;
    default:
        if (DV < 400)
        {
            RV = (DV - 3) / 2;
        }
        else if (DV > 1200)
        {
            RV = (DV - 5) / 2;
        }
        break;
    }
    
    const double DEG_TO_RAD = M_PI / 180.0;

    //�������� ��������� ����� �� ���� X � Y
   
    MbCartPoint p1(-30,RV+3*B1);
    MbCartPoint p2(0,RV+3*B1); 
    
    MbCartPoint p3(0, RV+B1);
    MbCartPoint p4(65, 0);
    MbCartPoint p5(45, 0);
    MbCartPoint p6(-15, RV-3*B1);
    
    MbCartPoint p7(-15,RV);
    MbCartPoint p8(-30,RV);

    
    MbPlacement* pl = new MbPlacement();
    MbPlacement* pl1 = new MbPlacement(MbCartPoint(-15,0),MbDirection(0.0));

    //������������ �������� �������� ��������
    MbLineSegment* Seg1 = new MbLineSegment(p1, p2);
    MbLineSegment* Seg2 = new MbLineSegment(p2, p3);
 
    MbArc* Seg3 = new MbArc(65, RV+B1, *pl, p3, p4 ,-1);
    MbLineSegment* Seg4 = new MbLineSegment(p4, p5);
    MbArc* Seg5 = new MbArc(60, RV-3*B1, *pl1, p5, p6 ,1);
    MbLineSegment* Seg6 = new MbLineSegment(p6, p7);
    
    MbLineSegment* Seg7 = new MbLineSegment(p7, p8);
    MbLineSegment* Seg8 = new MbLineSegment(p8, p1);


    //������������ �������� �������
    MbContour* ptrContour = new MbContour();
    //���������� � ������ ���������
    
    ptrContour->AddSegment(Seg1);
    ptrContour->AddSegment(Seg2);
    ptrContour->AddSegment(Seg3);
    ptrContour->AddSegment(Seg4);
    ptrContour->AddSegment(Seg5);
    ptrContour->AddSegment(Seg6);
    ptrContour->AddSegment(Seg7);
    ptrContour->AddSegment(Seg8);

    
   

    // �������� ��������� - ��� ��������� � ���������� XY ��������� ��
    MbPlacement3D* place = new MbPlacement3D();
    MbPlane* ptrSurface = new MbPlane(*place);


    //�������� ���������� ��� ���� ��������
    RPArray<MbContour>* ptrContours = new RPArray<MbContour>();
    ptrContours->Add(ptrContour);

    //������, � ������� �������� �������� �� ����������
    MbSweptData* pCurves;
    pCurves = new MbSweptData(*ptrSurface, *ptrContours);

    // ������ ���������� ��� ���������� ��� ��������.
    RevolutionValues revParms(360 * DEG_TO_RAD, 0, 0);

    //����������� ��� �������� ���������� ���� �������� � ��� �������� ����������
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);
    
    //��� �������� ��� ���������� ����
    MbAxis3D axis(place->GetAxisX());

    // ����� �������-������� ��� ���������� �������� ���� ��������
    MbSolid* m_pResSolid = nullptr;
    ::RevolutionSolid(*pCurves, axis, revParms, operNames, cNames, m_pResSolid);

    // ���������� ��������� ������ ������������ �������� ����
    c3d::SolidSPtr MainSolid(m_pResSolid);
    ::DeleteItem(m_pResSolid);

    return MainSolid;
}