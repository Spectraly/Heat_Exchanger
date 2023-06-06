#include "BuildMathModel.h"
using namespace BuildMathModel;


SPtr<MbSolid> ParametricModelCreator::Movable_Tube_Sheet_KP(BuildParams params)
{
    float DV, RV, L, L2, D, R, B1;
    DV = params.diam.toDouble();//�������� �������
    L = params.S.toDouble(); //�����
    L2 = L / 2; //�����
    B1 = 5; //����� ������
    float B2 = 8; //������ ������
    D = DV - (DV / 100 * 9);

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
    R = D / 2;


    float d = params.d.toDouble(); // D �����
    float bigD = DV - (DV / 100 * 9); // D ����������� ����������
    float offsets;
    if (d == 20)
        offsets = 6; //���������� ����� ������������
    else
        offsets = 7; //���������� ����� ������������
    float t = (d + offsets); // ��� ����� ��������
    float n0 = floor(bigD / t); // ���-�� ��������� �� 0 ����
    float n = n0 + 3; // ���-�� ��������� �� 1 ����
    float h = bigD / 2 * sin(60 * M_PI / 180); // ������ 6 ���������

    const double DEG_TO_RAD = M_PI / 180.0;

    //�������� ��������� ����� �� ���� X � Y

    MbCartPoint p1(-L2, 0);
    MbCartPoint p2(-L2, R);
    MbCartPoint p3(-L2 + B1, R);
    MbCartPoint p4(-L2 + B1, RV);
    MbCartPoint p5(L2 - B1 , RV);
    MbCartPoint p6(L2 - B1, R);
    MbCartPoint p7(L2, R);
    MbCartPoint p8(L2, 0);



    MbPlacement* pl = new MbPlacement();

    //������������ �������� �������� ��������
    MbLineSegment* Seg1 = new MbLineSegment(p1, p2);
    MbLineSegment* Seg2 = new MbLineSegment(p2, p3);
    MbLineSegment* Seg3 = new MbLineSegment(p3, p4);
    MbLineSegment* Seg4 = new MbLineSegment(p4, p5);
    MbLineSegment* Seg5 = new MbLineSegment(p5, p6);
    MbLineSegment* Seg6 = new MbLineSegment(p6, p7);
    MbLineSegment* Seg7 = new MbLineSegment(p7, p8);
    MbLineSegment* Seg8 = new MbLineSegment(p8, p1);




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
    MbSNameMaker operBoolNames(ct_BooleanSolid, MbSNameMaker::i_SideNone);
    PArray<MbSNameMaker> cNames(0, 1, false);

    //��� �������� ��� ���������� ����
    MbAxis3D axis(place->GetAxisX());

    // ����� �������-������� ��� ���������� �������� ���� ��������
    MbSolid* m_pResSolid = nullptr;
    RevolutionSolid(*pCurves, axis, revParms, operNames, cNames, m_pResSolid);

    MbSNameMaker cylNames(ct_ElementarySolid, MbSNameMaker::i_SideNone);
    MbVector3D dir(1, 0, 0);
    ExtrusionValues extrusionParam(1000, 1000);
    MbSNameMaker plateNames(MbSNameMaker::i_SideNone);
    RPArray<MbContour>* ptrContoursR = new RPArray<MbContour>();
    MbPlane* pPlane = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(0, 1, 0), MbCartPoint3D(0, 0, 1));


    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            double x = (d + offsets) * n / 2 - d / 2 - i * t - cos(60 * M_PI / 180) * t * j - offsets / 2;
            double y = j * sin(60 * M_PI / 180) * t + t;

            double l = sqrt(pow(x, 2) + pow(y, 2));

            if (l + d / 2 < bigD / 2 && y < h)
            {
                MbArc* pBound = new MbArc(MbCartPoint(x, y), d / 2);
                MbContour* ptrContour = new MbContour();
                ptrContour->AddSegment(pBound);
                ptrContour->Rotate(MbCartPoint(0, 0), MbDirection(90 * DEG_TO_RAD), nullptr, nullptr);
                ptrContoursR->Add(ptrContour);
                ptrContour->Clear();
            }
        }
    }
    MbPlacement3D pl1;
    pl1.Rotate(MbAxis3D(MbVector3D(1, 0, 0)), -90 * DEG_TO_RAD);
    MbSweptData sweptData1(*pPlane, *ptrContoursR);

    ::ExtrusionResult(*m_pResSolid, cm_Same, sweptData1, dir, extrusionParam, bo_Difference, plateNames, NULL, m_pResSolid);
    ::SymmetrySolid(*m_pResSolid, cm_Copy, pl1, operBoolNames, m_pResSolid);

    ptrContoursR->clear();



    // ���������� ��������� ������ ������������ �������� ����
    c3d::SolidSPtr MainSolid(m_pResSolid);
    ::DeleteItem(m_pResSolid);

    return MainSolid;
}
