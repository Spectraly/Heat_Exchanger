#include "BuildMathModel.h"
using namespace BuildMathModel;

// Вспомогательная функция для построения образующей в виде квадрата со скруглениями.
void CreateSketchKK(RPArray<MbContour>& _arrContours, float L, float RV, float DNK,float Ts)
{

    float B1 = 5; //Левый бортик

    // Размер массива - 10 точек
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(0, 0));
    arrPnts.Add(MbCartPoint(0, DNK));
    arrPnts.Add(MbCartPoint(L - 2 * B1, DNK));
    arrPnts.Add(MbCartPoint(L - 2 * B1, DNK - 4 * B1 - 0.3 * Ts));
    arrPnts.Add(MbCartPoint(L - B1, DNK - 4 * B1 - 0.3 * Ts));
    arrPnts.Add(MbCartPoint(L -B1, RV));
    arrPnts.Add(MbCartPoint(L, RV));
    arrPnts.Add(MbCartPoint(L, 0));


    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // Задание скругления с использованием функции FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketch1KK(RPArray<MbContour>& _arrContours, float L)
{

    float B1 = 5; //Левый бортик

    // Размер массива - 4 точек
    SArray<MbCartPoint> arrPnts(4);
    arrPnts.Add(MbCartPoint(L - B1, -3));
    arrPnts.Add(MbCartPoint(L - B1, 3));
    arrPnts.Add(MbCartPoint(L, 3));
    arrPnts.Add(MbCartPoint(L, -3));


    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // Задание скругления с использованием функции FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

SPtr<MbSolid> ParametricModelCreator::Distribution_Chamber_Cover_HPG(BuildParams params)
{

    float DV,DN,DNK,RV,L,Ts;
    L = params.length.toDouble() /100; //Длина
    DV = params.diam.toDouble();//Наружный диаметр
    DN = DV + DV / 100 * 8; //Внутренний диаметр
    Ts = params.TsS;//Толщина стенки
    DNK = (DV + DV / 100 * 19.5) / 2 + 20 + 0.3 * Ts;//Наружный диаметр крышки
    RV = DV / 2; //Внутренний радиус
    // Множитель для преобразования угловых значений из градусов в радианы
    const double DEG_TO_RAD = M_PI / 180.0;

    // Локальная СК (по умолчанию совпадает с мировой СК)
    MbPlacement3D pl;

    // Вызов функции для построения образующей (из примера 6)
    RPArray<MbContour> arrContours, arrContours1;
    CreateSketchKK(arrContours,L,RV, DNK, Ts);
    CreateSketch1KK(arrContours1,L);

    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0),MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, arrContours);
    MbSweptData sweptData1(*pPlaneXY, arrContours1);

    RevolutionValues revParms(360*DEG_TO_RAD, 0, 0);
    // Именователи для операции построения тела вращения и для контуров образующей
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