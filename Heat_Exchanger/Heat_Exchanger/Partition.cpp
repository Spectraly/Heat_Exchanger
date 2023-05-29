#include "BuildMathModel.h"
using namespace BuildMathModel;


SPtr<MbSolid> ParametricModelCreator::Partition(BuildParams params, bool slicePlace)
{
    float DV, RV, L, L2, B1;
    DV = params.diam.toDouble();//Внутренний диаметр
    RV = (DV-3) / 2;//Внутренний радиус
    L = 4; //Длина
    L2 = L / 2; //Длина
    B1 = 5; //Левый бортик

    float d = params.d.toDouble(); // D трубы
    float bigD = DV - (DV / 100 * 9); // D проверочной окружности
    float offsets;
    if (d == 20)
        offsets = 6; //расстояние между окружностями
    else
        offsets = 7; //расстояние между окружностями
    float t = (d + offsets); // Шаг между центрами
    float n0 = floor(bigD / t); // Кол-во отверстий на 0 ряду
    float n = n0 + 3; // Кол-во отверстий на 1 ряду
    float h = bigD / 2 * sin(60 * M_PI / 180); // Высота 6 угольника

    const double DEG_TO_RAD = M_PI / 180.0;

    //Создание двумерные точки на осях X и Y
    MbCartPoint p1(-L2, 0);
    MbCartPoint p2(-L2, RV);
    MbCartPoint p3(L2, RV);
    MbCartPoint p4(L2, 0);

    //Динамическое создание объектов отрезков
    MbLineSegment* Seg1 = new MbLineSegment(p1, p2);
    MbLineSegment* Seg2 = new MbLineSegment(p2, p3);
    MbLineSegment* Seg3 = new MbLineSegment(p3, p4);
    MbLineSegment* Seg4 = new MbLineSegment(p4, p1);

    //Динамическое создание контура
    MbContour* ptrContour = new MbContour();

    ptrContour->AddSegment(Seg1);
    ptrContour->AddSegment(Seg2);
    ptrContour->AddSegment(Seg3);
    ptrContour->AddSegment(Seg4);

    //------------------------------------------------------------------------//
    RPArray<MbContour>* ptrContours1 = new RPArray<MbContour>();

    if (params.type == HPG_MODEL)
    {
        int sliceSign;
        slicePlace ? sliceSign = 1 : sliceSign = -1;

        MbCartPoint ps1(-20, sliceSign * 74);
        MbCartPoint ps2(-20, sliceSign * DV);
        MbCartPoint ps3(20, sliceSign * DV);
        MbCartPoint ps4(20, sliceSign * 74);

        //Динамическое создание объектов отрезков
        MbLineSegment* Segs1 = new MbLineSegment(ps1, ps2);
        MbLineSegment* Segs2 = new MbLineSegment(ps2, ps3);
        MbLineSegment* Segs3 = new MbLineSegment(ps3, ps4);
        MbLineSegment* Segs4 = new MbLineSegment(ps4, ps1);

        //Динамическое создание контура
        MbContour* ptrContour1 = new MbContour();

        ptrContour1->AddSegment(Segs1);
        ptrContour1->AddSegment(Segs2);
        ptrContour1->AddSegment(Segs3);
        ptrContour1->AddSegment(Segs4);
        ptrContours1->Add(ptrContour1);
    }
    else if(params.type == KP_MODEL)
    {
        int sliceSign;
        slicePlace ? sliceSign = 1 : sliceSign = -1;

        MbCartPoint ps1(-DV, sliceSign * 104);
        MbCartPoint ps2(-DV, sliceSign * DV);
        MbCartPoint ps3(DV, sliceSign * DV);
        MbCartPoint ps4(DV, sliceSign * 104);

        //Динамическое создание объектов отрезков
        MbLineSegment* Segs1 = new MbLineSegment(ps1, ps2);
        MbLineSegment* Segs2 = new MbLineSegment(ps2, ps3);
        MbLineSegment* Segs3 = new MbLineSegment(ps3, ps4);
        MbLineSegment* Segs4 = new MbLineSegment(ps4, ps1);

        //Динамическое создание контура
        MbContour* ptrContour1 = new MbContour();

        ptrContour1->AddSegment(Segs1);
        ptrContour1->AddSegment(Segs2);
        ptrContour1->AddSegment(Segs3);
        ptrContour1->AddSegment(Segs4);

        ptrContours1->Add(ptrContour1);
    }

    
    //------------------------------------------------------------------------//

    MbCartPoint pp1(38, -8);
    MbCartPoint pp2(38, 8);
    MbCartPoint pp3(0, 8);
    MbCartPoint pp4(0, -8);

    //Динамическое создание объектов отрезков
    MbLineSegment* Segp1 = new MbLineSegment(pp1, pp2);
    MbLineSegment* Segp2 = new MbLineSegment(pp2, pp3);
    MbLineSegment* Segp3 = new MbLineSegment(pp3, pp4);
    MbLineSegment* Segp4 = new MbLineSegment(pp4, pp1);

    //Динамическое создание контура
    MbContour* ptrContour2 = new MbContour();

    ptrContour2->AddSegment(Segp1);
    ptrContour2->AddSegment(Segp2);
    ptrContour2->AddSegment(Segp3);
    ptrContour2->AddSegment(Segp4);
    ptrContour2->Rotate(MbCartPoint(0, 0), MbDirection(90 * DEG_TO_RAD), nullptr, nullptr);
    ptrContour2->Move(MbVector(0, -RV));


    MbLineSegment* Segp11 = new MbLineSegment(pp1, pp2);
    MbLineSegment* Segp22 = new MbLineSegment(pp2, pp3);
    MbLineSegment* Segp33 = new MbLineSegment(pp3, pp4);
    MbLineSegment* Segp44 = new MbLineSegment(pp4, pp1);

    MbContour* ptrContour3 = new MbContour();

    ptrContour3->AddSegment(Segp11);
    ptrContour3->AddSegment(Segp22);
    ptrContour3->AddSegment(Segp33);
    ptrContour3->AddSegment(Segp44);
    ptrContour3->Rotate(MbCartPoint(0, 0), MbDirection(90 * DEG_TO_RAD), nullptr, nullptr);
    ptrContour3->Move(MbVector(0, RV -38));


    RPArray<MbContour>* ptrContours2 = new RPArray<MbContour>();
    ptrContours2->Add(ptrContour2);
    ptrContours2->Add(ptrContour3);
    //------------------------------------------------------------------------//


    // Создание плоскости - она совпадает с плоскостью XY локальной СК
    MbPlacement3D* place = new MbPlacement3D();
    MbPlane* ptrSurface = new MbPlane(*place);

    //Создание образующей для тела вращения
    RPArray<MbContour>* ptrContours = new RPArray<MbContour>();
    ptrContours->Add(ptrContour);
    //объект, в котором хранятся сведения об образующей
    MbSweptData* pCurves;
    pCurves = new MbSweptData(*ptrSurface, *ptrContours);

    // Объект параметров для построения тел вращения.
    RevolutionValues revParms(360 * DEG_TO_RAD, 0, 0);

    //Именователи для операции построения тела вращения и для контуров образующей
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    MbSNameMaker operBoolNames(ct_BooleanSolid, MbSNameMaker::i_SideNone);
    PArray<MbSNameMaker> cNames(0, 1, false);

    //Ось вращения для построения тела
    MbAxis3D axis(place->GetAxisX());

    // Вызов функции-утилиты для построения твердого тела вращения
    MbSolid* m_pResSolid = nullptr;
    ::RevolutionSolid(*pCurves, axis, revParms, operNames, cNames, m_pResSolid);

    MbSNameMaker cylNames(ct_ElementarySolid, MbSNameMaker::i_SideNone);
    MbVector3D dir(1, 0, 0);
    MbVector3D dir1(0, 0, -1);
    ExtrusionValues extrusionParam(1000, 1000);
    MbSNameMaker plateNames(MbSNameMaker::i_SideNone);
    RPArray<MbContour>* ptrContoursR = new RPArray<MbContour>();
    MbPlane* pPlane = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(0, 1, 0), MbCartPoint3D(0, 0, 1));
    MbPlane* pPlane1 = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 1, 0));


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
    MbSweptData sweptData2H(*pPlane1, *ptrContours1);
    MbSweptData sweptData2K(*pPlane, *ptrContours1);
    MbSweptData sweptData3(*pPlane, *ptrContours2);

    ::ExtrusionResult(*m_pResSolid, cm_Same, sweptData1, dir, extrusionParam, bo_Difference, plateNames, NULL, m_pResSolid);
    ::SymmetrySolid(*m_pResSolid, cm_Copy, pl1, operBoolNames, m_pResSolid);

    if (params.type == HPG_MODEL)
    {
        ::ExtrusionResult(*m_pResSolid, cm_Same, sweptData2H, dir1, extrusionParam, bo_Difference, plateNames, NULL, m_pResSolid);
        ::ExtrusionResult(*m_pResSolid, cm_Same, sweptData3, dir, extrusionParam, bo_Difference, plateNames, NULL, m_pResSolid);
    }
    else if(params.type == KP_MODEL)
    {
        ::ExtrusionResult(*m_pResSolid, cm_Same, sweptData2K, dir, extrusionParam, bo_Difference, plateNames, NULL, m_pResSolid);
        ::ExtrusionResult(*m_pResSolid, cm_Same, sweptData3, dir, extrusionParam, bo_Difference, plateNames, NULL, m_pResSolid);
    }
    

    ptrContoursR->clear();

    // Уменьшение счетчиков ссылок динамических объектов ядра
    c3d::SolidSPtr MainSolid(m_pResSolid);
    ::DeleteItem(m_pResSolid);

    return MainSolid;
}
