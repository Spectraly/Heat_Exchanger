#include "BuildMathModel.h"
using namespace BuildMathModel;


SPtr<MbSolid> ParametricModelCreator::Casing_Cover(BuildParams params)
{
   float DV,RV,LK,L,B1,B2;
    DV = params.diam.toDouble(); //Внутренний диаметр
    L = params.length.toDouble();
    RV = DV/2; //Внутренний радиус
    B2 = 10; //Правый бортик

    const double DEG_TO_RAD = M_PI / 180.0;

    //Создание двумерные точки на осях X и Y
   
    MbCartPoint p1(-135, RV + 4.4 * B2);
    MbCartPoint p2(-135, RV + 7 * B2);
    MbCartPoint p3(-110, RV + 7 * B2);
    MbCartPoint p4(-110, RV + 4.4 * B2);
    MbCartPoint p5(-90, RV + 4 * B2);
    MbCartPoint p6(0, RV + 4 * B2);
    MbCartPoint p7(65, 0);
    MbCartPoint p8(55, 0);
    MbCartPoint p9(0, RV+3*B2);
    MbCartPoint p10(-125,RV+3*B2);
    MbCartPoint p11(-125, RV + 4.4 * B2);

    
    MbPlacement* pl = new MbPlacement();

    //Динамическое создание объектов отрезков
    MbLineSegment* Seg1 = new MbLineSegment(p1, p2);
    MbLineSegment* Seg2 = new MbLineSegment(p2, p3);
    MbLineSegment* Seg3 = new MbLineSegment(p3, p4);
    MbLineSegment* Seg4 = new MbLineSegment(p4, p5);
    MbLineSegment* Seg5 = new MbLineSegment(p5, p6);
    MbArc* Seg6 = new MbArc(65, RV + 4 * B2, *pl, p6, p7 ,-1);
    MbLineSegment* Seg7 = new MbLineSegment(p7, p8);
    MbArc* Seg8 = new MbArc(55, RV+3*B2, *pl, p8, p9 ,1);
    MbLineSegment* Seg9 = new MbLineSegment(p9, p10);
    MbLineSegment* Seg10 = new MbLineSegment(p10, p11);
    MbLineSegment* Seg11 = new MbLineSegment(p11, p1);


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
    ptrContour->AddSegment(Seg11);
    
   

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
    m_pResSolid->Move(MbVector3D(L/2 + 135, 0, 0));

    ::DeleteItem(m_pResSolid);

    return MainSolid;
}