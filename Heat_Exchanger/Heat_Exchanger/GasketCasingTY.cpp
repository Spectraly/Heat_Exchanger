#include "BuildMathModel.h"
using namespace BuildMathModel;

SPtr<MbSolid> ParametricModelCreator::Gasket_CasingTU(BuildParams params)
{
    float B1 = 5;
    float DV = params.diam.toDouble();
    if (DV == 325)
        DV = 300;
    float RV = DV / 2;
    const double DEG_TO_RAD = M_PI / 180.0;

    //�������� ��������� ����� �� ���� X � Y
    MbCartPoint p1(0, RV - B1);
    MbCartPoint p2(-B1, RV - B1);
    MbCartPoint p3(-B1, RV + RV * 0.20);
    MbCartPoint p4(0, RV + RV * 0.20);

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

    //������ ���������� ��� ���������� ��� ��������.
    RevolutionValues revParms(360 * DEG_TO_RAD, 0, 0);

    //����������� ��� �������� ���������� ���� �������� � ��� �������� ����������
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);

    //��� �������� ��� ���������� ����
    MbAxis3D axis(place->GetAxisX());

    //����� �������-������� ��� ���������� �������� ���� ��������
    MbSolid* pResSolid = nullptr;
    MbResultType res = ::RevolutionSolid(*pCurves, axis, revParms, operNames, cNames, pResSolid);

    c3d::SolidSPtr MainSolid(pResSolid);

    // ���������� ��������� ������ ������������ �������� ����
    ::DeleteItem(pResSolid);

    return MainSolid;
}