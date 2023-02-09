#include "BuildMathModel.h"
using namespace BuildMathModel;

// Вспомогательная функция для построения образующей в виде квадрата со скруглениями.
void CreateSketchKK(RPArray<MbContour>& _arrContours)
{
    float DV,RV,L,B1;
    DV = 325; //Внутренний диамерт
    RV = DV/2; //Внутренний радиус
    L = 35; //Длина
    B1 = 5; //Левый бортик

    // Размер массива - 10 точек
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


    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // Задание скругления с использованием функции FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

SPtr<MbSolid> ParametricModelCreator::Distribution_Chamber_Cover()
{
    float LK;
    LK = 400;
    // Множитель для преобразования угловых значений из градусов в радианы
    const double DEG_TO_RAD = M_PI / 180.0;

    // Локальная СК (по умолчанию совпадает с мировой СК)
    MbPlacement3D pl;

    // Вызов функции для построения образующей (из примера 6)
    RPArray<MbContour> arrContours;
    CreateSketchKK(arrContours);

    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0),MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, arrContours);

    RevolutionValues revParms(360*DEG_TO_RAD, 0, 0);
    // Именователи для операции построения тела вращения и для контуров образующей
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