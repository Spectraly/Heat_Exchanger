#include "BuildMathModel.h"
using namespace BuildMathModel;

// ��������������� ������� ��� ���������� ���������� � ���� �������� �� ������������.
void CreateSketchKK(RPArray<MbContour>& _arrContours)
{
    float DV,RV,L,B1;
    DV = 325; //���������� �������
    RV = DV/2; //���������� ������
    L = 35; //�����
    B1 = 5; //����� ������

    // ������ ������� - 10 �����
    SArray<MbCartPoint> arrPnts(10);
    arrPnts.Add(MbCartPoint(B1, 0));
    arrPnts.Add(MbCartPoint(L, 0));
    arrPnts.Add(MbCartPoint(L, RV+8*B1));
    arrPnts.Add(MbCartPoint(L-5*B1, RV+8*B1));
    arrPnts.Add(MbCartPoint(L-5*B1, RV+6.5*B1));
    arrPnts.Add(MbCartPoint(L-6*B1, RV+6.5*B1));
    arrPnts.Add(MbCartPoint(L-6*B1, RV+2*B1));
    arrPnts.Add(MbCartPoint(L-7*B1, RV+2*B1));
    arrPnts.Add(MbCartPoint(L-7*B1,2*B1));
    arrPnts.Add(MbCartPoint(B1,2*B1));


    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // ������� ���������� � �������������� ������� FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

SPtr<MbSolid> ParametricModelCreator::Distribution_Chamber_Cover()
{
    float LK;
    LK = 400;
    // ��������� ��� �������������� ������� �������� �� �������� � �������
    const double DEG_TO_RAD = M_PI / 180.0;

    // ��������� �� (�� ��������� ��������� � ������� ��)
    MbPlacement3D pl;

    // ����� ������� ��� ���������� ���������� (�� ������� 6)
    RPArray<MbContour> arrContours;
    CreateSketchKK(arrContours);

    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0),MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, arrContours);

    RevolutionValues revParms(360*DEG_TO_RAD, 0, 0);
    // ����������� ��� �������� ���������� ���� �������� � ��� �������� ����������
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);

    MbAxis3D axis(pl.GetAxisX());

    MbSolid* pSolid = nullptr;
    ::RevolutionSolid(sweptData, axis, revParms,operNames, cNames, pSolid);

    c3d::SolidSPtr MainSolid(pSolid);
    pSolid->Rotate(MbAxis3D(pl.GetAxisZ()), 180 * DEG_TO_RAD);
    pSolid->Move(MbVector3D(-2750 / 2 - LK+5, 0, 0));

    ::DeleteItem(pSolid);
    return MainSolid;
}