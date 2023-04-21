#include "BuildMathModel.h"
using namespace BuildMathModel;

// Вспомогательная функция для построения образующей в виде квадрата со скруглениями.
void CreateSketchKK(RPArray<MbContour>& _arrContours, float RV, float DNK)
{
    float L,B1;
    L = 25; //Длина
    B1 = 5; //Левый бортик

    // Размер массива - 10 точек
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(0, 0));
    arrPnts.Add(MbCartPoint(0, DNK));
    arrPnts.Add(MbCartPoint(3 * B1, DNK));
    arrPnts.Add(MbCartPoint(3 * B1, DNK - 2 * B1));
    arrPnts.Add(MbCartPoint(4 * B1, DNK - 2 * B1));
    arrPnts.Add(MbCartPoint(4 * B1, RV));
    arrPnts.Add(MbCartPoint(L, RV));
    arrPnts.Add(MbCartPoint(L, 0));


    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // Задание скругления с использованием функции FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

SPtr<MbSolid> ParametricModelCreator::Distribution_Chamber_Cover(BuildParams params)
{

    float DV,DN,DNK,RV,LK;
    DN = params.diam.toDouble(); //Внутренний диамерт
    DV = DN - 25;//Наружный диаметр
    DNK = (DN + 38) / 2 + 10;//Наружный диаметр крышки
    RV = DV / 2; //Внутренний радиус
    LK = 430;
    // Множитель для преобразования угловых значений из градусов в радианы
    const double DEG_TO_RAD = M_PI / 180.0;

    // Локальная СК (по умолчанию совпадает с мировой СК)
    MbPlacement3D pl;

    // Вызов функции для построения образующей (из примера 6)
    RPArray<MbContour> arrContours;
    CreateSketchKK(arrContours,RV, DNK);

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


    ::DeleteItem(pSolid);
    return MainSolid;
}