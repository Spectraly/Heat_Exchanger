#include "BuildMathModel.h"
using namespace BuildMathModel;



SPtr<MbSolid> ParametricModelCreator::Stationary_Tube_Sheet(BuildParams params)
{
   float DV,RV,L,L2,DN,RN,D,R,B1;
    DV = 363; //���������� �������
    RV = DV/2; //���������� ������
    L = 40; //�����
    L2 = L/2; //�����
    DN = DV + 30;//�������� �������
    RN = DN/2;
    B1 = 5; //����� ������
    D = 295;
    R=D/2;
    
    const double DEG_TO_RAD = M_PI / 180.0;

    //�������� ��������� ����� �� ���� X � Y
   
    MbCartPoint p1(-L2, 0);
    MbCartPoint p2(-L2, R);
    MbCartPoint p3(-L2+B1, R);
    MbCartPoint p4(-L2+B1, RV);
    MbCartPoint p5(-L2+3*B1, RV);
    MbCartPoint p6(-L2+3*B1, R+4*B1);
    MbCartPoint p7(L2-3*B1, R+4*B1);
    MbCartPoint p8(L2-3*B1, RV);
    MbCartPoint p9(L2-B1, RV);
    MbCartPoint p10(L2-B1, R);
    MbCartPoint p11(L2, R);
    MbCartPoint p12(L2, 0);

    
    MbPlacement* pl = new MbPlacement();

    //������������ �������� �������� ��������
    MbLineSegment* Seg1 = new MbLineSegment(p1, p2);
    MbLineSegment* Seg2 = new MbLineSegment(p2, p3);
    MbLineSegment* Seg3 = new MbLineSegment(p3, p4);
    MbLineSegment* Seg4 = new MbLineSegment(p4, p5);
    MbLineSegment* Seg5 = new MbLineSegment(p5, p6);
    MbLineSegment* Seg6 = new MbLineSegment(p6, p7);
    MbLineSegment* Seg7 = new MbLineSegment(p7, p8);
    MbLineSegment* Seg8 = new MbLineSegment(p8, p9);
    MbLineSegment* Seg9 = new MbLineSegment(p9, p10);
    MbLineSegment* Seg10 = new MbLineSegment(p10, p11);
    MbLineSegment* Seg11 = new MbLineSegment(p11, p12);
    MbLineSegment* Seg12 = new MbLineSegment(p12, p1);



    //������������ �������� �������
    MbContour* ptrContour = new MbContour();
    
    ptrContour->AddSegment(Seg1);
    ptrContour->AddSegment(Seg2);
    ptrContour->AddSegment(Seg3);
    ptrContour->AddSegment(Seg4);
    ptrContour->AddSegment(Seg5);
    ptrContour->AddSegment(Seg6);
    ptrContour->AddSegment(Seg7);
    ptrContour->AddSegment(Seg8);
    ptrContour->AddSegment(Seg9);
    ptrContour->AddSegment(Seg10);
    ptrContour->AddSegment(Seg11);
    ptrContour->AddSegment(Seg12);
    
   

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
    MbResultType res = RevolutionSolid(*pCurves, axis, revParms, operNames, cNames, m_pResSolid);
    
    // ���������� ��������� ������ ������������ �������� ����
    c3d::SolidSPtr MainSolid(m_pResSolid);
    ::DeleteItem(m_pResSolid);

    return MainSolid;
}