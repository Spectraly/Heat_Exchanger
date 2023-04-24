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
void CreateSketch1KK(RPArray<MbContour>& _arrContours, float L)
{

    float B1 = 5; //����� ������

    // ������ ������� - 4 �����
    SArray<MbCartPoint> arrPnts(4);
    arrPnts.Add(MbCartPoint(L - B1, -3));
    arrPnts.Add(MbCartPoint(L - B1, 3));
    arrPnts.Add(MbCartPoint(L, 3));
    arrPnts.Add(MbCartPoint(L, -3));


    // ���������� ������ ������� �������� ������� �� ������
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // ������� ���������� � �������������� ������� FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

SPtr<MbSolid> ParametricModelCreator::Distribution_Chamber_Cover(BuildParams params)
{

    float L = 25; //�����
    float DV,DN,DNK,RV,LK;
    DV = params.diam.toDouble();//�������� �������
    DN = DV + DV / 100 * 8; //���������� �������
    DNK = (DN + 38) / 2 + 10;//�������� ������� ������
    RV = DV / 2; //���������� ������
    LK = 430;
    // ��������� ��� �������������� ������� �������� �� �������� � �������
    const double DEG_TO_RAD = M_PI / 180.0;

    // ��������� �� (�� ��������� ��������� � ������� ��)
    MbPlacement3D pl;

    // ����� ������� ��� ���������� ���������� (�� ������� 6)
    RPArray<MbContour> arrContours, arrContours1;
    CreateSketchKK(arrContours,RV, DNK);
    CreateSketch1KK(arrContours1,L);

    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0),MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, arrContours);
    MbSweptData sweptData1(*pPlaneXY, arrContours1);

    RevolutionValues revParms(360*DEG_TO_RAD, 0, 0);
    // ����������� ��� �������� ���������� ���� �������� � ��� �������� ����������
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);
    MbSNameMaker plateNames(MbSNameMaker::i_SideNone);
    MbVector3D dir(0, 0, -1);
    ExtrusionValues extrusionParam(DN, DN);

    MbAxis3D axis(pl.GetAxisX());

    MbSolid* pSolid = nullptr;
    ::RevolutionSolid(sweptData, axis, revParms,operNames, cNames, pSolid);
    ::ExtrusionResult(*pSolid, cm_Same, sweptData1, dir, extrusionParam, bo_Difference, plateNames, NULL, pSolid);

    c3d::SolidSPtr MainSolid(pSolid);


    ::DeleteItem(pSolid);
    return MainSolid;
}