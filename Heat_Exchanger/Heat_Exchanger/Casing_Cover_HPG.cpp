#include "BuildMathModel.h"
using namespace BuildMathModel;


SPtr<MbSolid> ParametricModelCreator::Casing_Cover_HPG(BuildParams params)
{
   float DV,RV,LC,L, DN, Ts,B1, Rb, Rm;
    DV = params.diam.toDouble() ;//�������� �������
    DN = DV + DV / 100 * 8; //���������� �������
    L = params.length.toDouble();
    RV = DV/2+30; //���������� ������
    if (DV < 600)
        LC = (L / 100) * 11.25;
    else if(DV >= 600 && DV <= 900)
        LC = (L / 100) * 8.25;
    else if (DV >= 900)
        LC = (L / 100) * 9.25;

    B1 = 5; //������ ������
    Ts = (DN - DV) / 2;//������� ������
    Rm = (L / 100) * 1.25;
    Rb = Rm + Ts;
    const double DEG_TO_RAD = M_PI / 180.0;

    //�������� ��������� ����� �� ��������� XY
    MbCartPoint p1(-LC + 2* B1, RV);
    MbCartPoint p2(-LC + 2* B1, RV + Ts + 3 * B1);
    MbCartPoint p3(-LC, RV + Ts + 3 * B1);
    MbCartPoint p4(-LC, RV + Ts * 1.5 + 6 * B1);
    MbCartPoint p5(-LC + Ts + 3 * B1, RV + Ts * 1.5 + 6 * B1);
    MbCartPoint p6(-LC + Ts + 3 * B1, RV + Ts);
    MbCartPoint p7(0, RV + Ts);
    MbCartPoint p8(Rb, 0);
    MbCartPoint p9(Rm, 0);
    MbCartPoint p10(0, RV);

    //�������� ��������� - ��� ��������� � ���������� XY ��������� ��
    MbPlacement* pl = new MbPlacement();

    //������������ �������� �������� ��������
    MbLineSegment* Seg1 = new MbLineSegment(p1, p2);
    MbLineSegment* Seg2 = new MbLineSegment(p2, p3);
    MbLineSegment* Seg3 = new MbLineSegment(p3, p4);
    MbLineSegment* Seg4 = new MbLineSegment(p4, p5);
    MbLineSegment* Seg5 = new MbLineSegment(p5, p6);
    MbLineSegment* Seg6 = new MbLineSegment(p6, p7);
    MbArc* Seg7 = new MbArc(Rb, RV + Ts, *pl, p7, p8, -1);
    MbLineSegment* Seg8 = new MbLineSegment(p8, p9);
    MbArc* Seg9 = new MbArc(Rm, RV, *pl, p9, p10, 1);
    MbLineSegment* Seg10 = new MbLineSegment(p10, p1);


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

    MbPlacement3D* place = new MbPlacement3D();
    MbPlane* ptrSurface = new MbPlane(*place);


    //�������� ���������� ��� ���� ��������
    RPArray<MbContour>* ptrContours = new RPArray<MbContour>();
    ptrContours->Add(ptrContour);

    //������, � ������� �������� �������� �� ����������
    MbSweptData* pCurves = new MbSweptData(*ptrSurface, *ptrContours);

    // ������ ���������� ��� ���������� ��� ��������.
    RevolutionValues revParms(360 * DEG_TO_RAD, 0, 0);

    //����������� ��� �������� ���������� ���� �������� � ��� �������� ����������
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);
    
    //��� �������� ��� ���������� ����
    MbAxis3D axis(place->GetAxisX());

    // ����� �������-������� ��� ���������� �������� ���� ��������
    MbSolid* m_pResSolid = nullptr;
    RevolutionSolid(*pCurves, axis, revParms, operNames, cNames, m_pResSolid);

    c3d::SolidSPtr MainSolid(m_pResSolid);

    ::DeleteItem(m_pResSolid);

    return MainSolid;
}