#include "BuildMathModel.h"
using namespace BuildMathModel;


SPtr<MbSolid> ParametricModelCreator::Gasket_Floating_Head_HPG(BuildParams params)
{
    float DVP,RVP,DR,RR,B1;
    DVP = params.diam.toDouble(); //���������� �������
    B1 = 5; //����� ������
    DR = DVP - (DVP / 100 * 9);
    RR=DR/2;

    switch ((int)DVP)
    {
    case 325:
        RVP = (DVP - 3) / 2;
        break;
    case 400:
        RVP = (DVP - 2) / 2;
        break;
    case 500:
        RVP = (DVP - 2) / 2;
        break;
    case 600:
        RVP = (DVP - 4) / 2;
        break;
    case 700:
        RVP = (DVP - 5) / 2;
        break;
    case 800:
        RVP = (DVP - 5) / 2;
        break;
    case 900:
        RVP = (DVP - 5) / 2;
        break;
    case 1000:
        RVP = (DVP - 5) / 2;
        break;
    case 1200:
        RVP = (DVP - 5) / 2;
        break;
    default:
        if (DVP < 400)
        {
            RVP = (DVP - 3) / 2;
        }
        else if (DVP > 1200)
        {
            RVP = (DVP - 5) / 2;
        }
        break;
    }

    const double DEG_TO_RAD = M_PI / 180.0;

    //�������� ��������� ����� �� ���� X � Y
   
    MbCartPoint p1(B1/2, RR);
    MbCartPoint p2(-B1/2, RR);
    MbCartPoint p3(-B1/2, RVP);
    MbCartPoint p4(B1/2, RVP);

    MbPlacement* pl = new MbPlacement();

    //������������ �������� �������� ��������
    MbLineSegment* Seg1 = new MbLineSegment(p1, p2);
    MbLineSegment* Seg2 = new MbLineSegment(p2, p3);
    MbLineSegment* Seg3 = new MbLineSegment(p3, p4);
    MbLineSegment* Seg4 = new MbLineSegment(p4, p1);

    //������������ �������� �������
    MbContour* ptrContour = new MbContour();
    
    ptrContour->AddSegment(Seg1);
    ptrContour->AddSegment(Seg2);
    ptrContour->AddSegment(Seg3);
    ptrContour->AddSegment(Seg4);

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