#include "BuildMathModel.h"
using namespace BuildMathModel;


SPtr<MbSolid> ParametricModelCreator::Casing_Cover(BuildParams params)
{
   float DV,RV,LK,L, DN, Ts,B1, Rb, Rm;
    DN = params.diam.toDouble(); //Внутренний диаметр
    DV = DN - 25;//Наружный диаметр
    LK = params.length.toDouble();
    RV = DV/2+30; //Внутренний радиус
    L = 342.5;
    B1 = 5; //Правый бортик
    Ts = (DN - DV) / 2;//Толщина стенки
    Rm = 45;
    Rb = Rm + Ts;
    const double DEG_TO_RAD = M_PI / 180.0;

    //Создание двумерные точки на осях X и Y
   
    MbCartPoint p1(-L + B1, RV);
    MbCartPoint p2(-L + B1, RV + 5 * B1);
    MbCartPoint p3(-L, RV + 5 * B1);
    MbCartPoint p4(-L, RV + 9 * B1);
    MbCartPoint p5(-L + 5 * B1, RV + 9 * B1);
    MbCartPoint p6(-L + 5 * B1, RV + Ts);
    MbCartPoint p7(0, RV + Ts);
    MbCartPoint p8(Rb, 0);
    MbCartPoint p9(Rm, 0);
    MbCartPoint p10(0, RV);


    MbPlacement* pl = new MbPlacement();

    //Динамическое создание объектов отрезков
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


    //Динамическое создание контура
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
    PArray<MbSNameMaker> cNames(0, 1, false);
    
    //Ось вращения для построения тела
    MbAxis3D axis(place->GetAxisX());

    // Вызов функции-утилиты для построения твердого тела вращения
    MbSolid* m_pResSolid = nullptr;
    MbResultType res = RevolutionSolid(*pCurves, axis, revParms, operNames, cNames, m_pResSolid);

    c3d::SolidSPtr MainSolid(m_pResSolid);
    m_pResSolid->Move(MbVector3D(LK/2 + L, 0, 0));

    ::DeleteItem(m_pResSolid);

    return MainSolid;
}