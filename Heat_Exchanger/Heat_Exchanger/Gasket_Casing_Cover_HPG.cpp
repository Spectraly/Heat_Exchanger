#include "BuildMathModel.h"
using namespace BuildMathModel;


SPtr<MbSolid> ParametricModelCreator::Gasket_Casing_Cover_HPG(BuildParams params)
{
   float B1,DN,DV,RV,Ts;
    B1 = 5; //Левый бортик
    DV = params.diam.toDouble();//Наружный диаметр
    DN = DV + DV / 100 * 8; //Внутренний диаметр
    RV = DV / 2 + 30; //Внутренний радиус
    Ts = (DN - DV) / 2;//Толщина стенки
    
    const double DEG_TO_RAD = M_PI / 180.0;

    //Создание двумерные точки на осях X и Y
   
    MbCartPoint p1(B1, RV);
    MbCartPoint p2(-B1, RV);
    MbCartPoint p3(-B1, RV + Ts + 3 * B1);
    MbCartPoint p4(B1, RV + Ts + 3 * B1);


    
    MbPlacement* pl = new MbPlacement();

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
    ::RevolutionSolid(*pCurves, axis, revParms, operNames, cNames, m_pResSolid);

    // Уменьшение счетчиков ссылок динамических объектов ядра
    c3d::SolidSPtr MainSolid(m_pResSolid);
    ::DeleteItem(m_pResSolid);

    return MainSolid;
}