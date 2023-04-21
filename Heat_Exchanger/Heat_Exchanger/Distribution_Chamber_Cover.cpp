#include "BuildMathModel.h"
using namespace BuildMathModel;

// ��������������� ������� ��� ���������� ���������� � ���� �������� �� ������������.
void CreateSketchKK(RPArray<MbContour>& _arrContours, float RV, float DNK)
{
    float L,B1;
    L = 25; //�����
    B1 = 5; //����� ������

    // ������ ������� - 10 �����
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(0, 0));
    arrPnts.Add(MbCartPoint(0, DNK));
    arrPnts.Add(MbCartPoint(3 * B1, DNK));
    arrPnts.Add(MbCartPoint(3 * B1, DNK - 2 * B1));
    arrPnts.Add(MbCartPoint(4 * B1, DNK - 2 * B1));
    arrPnts.Add(MbCartPoint(4 * B1, RV));
    arrPnts.Add(MbCartPoint(L, RV));
    arrPnts.Add(MbCartPoint(L, 0));


    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // ������� ���������� � �������������� ������� FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

SPtr<MbSolid> ParametricModelCreator::Distribution_Chamber_Cover(BuildParams params)
{

    float DV,DN,DNK,RV,LK;
    DN = params.diam.toDouble(); //���������� �������
    DV = DN - 25;//�������� �������
    DNK = (DN + 38) / 2 + 10;//�������� ������� ������
    RV = DV / 2; //���������� ������
    LK = 430;
    // ��������� ��� �������������� ������� �������� �� �������� � �������
    const double DEG_TO_RAD = M_PI / 180.0;

    // ��������� �� (�� ��������� ��������� � ������� ��)
    MbPlacement3D pl;

    // ����� ������� ��� ���������� ���������� (�� ������� 6)
    RPArray<MbContour> arrContours;
    CreateSketchKK(arrContours,RV, DNK);

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


    ::DeleteItem(pSolid);
    return MainSolid;
}