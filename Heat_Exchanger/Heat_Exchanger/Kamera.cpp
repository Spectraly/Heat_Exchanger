#include "BuildMathModel.h"
using namespace BuildMathModel;

void CreateSketchKTY(RPArray<MbContour>& _arrContours)
{
    float DV = 325; //Внутренний диамерт
    float RV = DV / 2; //Внутренний радиус
    float LK = 500; //Длина
    float L1 = 50; //Длина
    float L2 = LK / 2; //Длина пополам
    float B1 = 5; //Левый бортик

    // Размер массива - 8 точек
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(-L2 - L1 + B1, 0));
    arrPnts.Add(MbCartPoint(-L2 - L1 + B1, RV + 4 * B1));
    arrPnts.Add(MbCartPoint(L2 - 3 * B1, RV + 4 * B1));
    arrPnts.Add(MbCartPoint(L2 - 3 * B1, RV + 8 * B1));
    arrPnts.Add(MbCartPoint(L2, RV + 8 * B1));
    arrPnts.Add(MbCartPoint(L2, RV + 6 * B1));
    arrPnts.Add(MbCartPoint(L2 - B1, RV + 6 * B1));
    arrPnts.Add(MbCartPoint(L2 - B1, 0));

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // Задание скругления с использованием функции FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchK1TY(RPArray<MbContour>& _arrContours)
{
    float DV = 325; //Внутренний диамерт
    float RV = DV / 2; //Внутренний радиус
    float S;
    S = 1145;
    // Размер массива - 8 точек
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(50, RV + 70));
    arrPnts.Add(MbCartPoint(50, RV + 70 + 38));
    arrPnts.Add(MbCartPoint(65, RV + 70 + 38));
    arrPnts.Add(MbCartPoint(70, RV + 70 + 30));
    arrPnts.Add(MbCartPoint(90, RV + 70 + 30));
    arrPnts.Add(MbCartPoint(90, RV + 70 + 20));
    arrPnts.Add(MbCartPoint(70, RV + 70 + 20));
    arrPnts.Add(MbCartPoint(65, RV + 70));

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchK2TY(RPArray<MbContour>& _arrContours)
{
    float DV = 325; //Внутренний диамерт
    float RV = DV / 2; //Внутренний радиус
    float S;
    S = 1185;

    // Размер массива - 8 точек
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(50, -RV - 70));
    arrPnts.Add(MbCartPoint(50, -RV - 70 - 38));
    arrPnts.Add(MbCartPoint(65, -RV - 70 - 38));
    arrPnts.Add(MbCartPoint(70, -RV - 70 - 30));
    arrPnts.Add(MbCartPoint(90, -RV - 70 - 30));
    arrPnts.Add(MbCartPoint(90, -RV - 70 - 20));
    arrPnts.Add(MbCartPoint(70, -RV - 70 - 20));
    arrPnts.Add(MbCartPoint(65, -RV - 70));

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

void CreateSketchCurveK(RPArray<MbContour>& _ptrContours)
{
    float DV = 325; //Внутренний диамерт
    float RV = DV / 2; //Внутренний радиус
    float LK = 500; //Длина
    float L1 = 50; //Длина
    float L2 = LK / 2; //Длина пополам
    float B1 = 5; //Левый бортик

    //Динамическое создание контура
    MbContour* ptrContour = new MbContour();
    //Добавление в контур сегментов

    MbCartPoint p1(-L1 - L2 + B1, RV + 3 * B1); //(-295, 177.5)
    MbCartPoint p2(-L1 - L2 + B1, RV + 4 * B1); //(-295, 182.5)
    MbCartPoint p3(-L1 - L2 - 65, 0); //(-365, 0)
    MbCartPoint p4(-L1 - L2 - 55, 0); //(-355, 0)

    MbPlacement* plCurve = new MbPlacement(MbCartPoint(-L1 - L2 + B1, 0), MbDirection(0.0));

    //Динамическое создание объектов отрезков
    MbLineSegment* Seg1 = new MbLineSegment(p1, p2);
    MbArc* Seg2 = new MbArc(-65, RV + 4 * B1, *plCurve, p2, p3, -1);
    MbLineSegment* Seg3 = new MbLineSegment(p3, p4);
    MbArc* Seg4 = new MbArc(-55, RV + 3 * B1, *plCurve, p4, p1, 1);

    ptrContour->AddSegment(Seg1);
    ptrContour->AddSegment(Seg2);
    ptrContour->AddSegment(Seg3);
    ptrContour->AddSegment(Seg4);

    _ptrContours.push_back(ptrContour);
}

SPtr<MbSolid> ParametricModelCreator::Distribution_ChamberTY(double length)
{
    float DV = 325; //Внутренний диамерт
    float RV = DV / 2; //Внутренний радиус
    float LK = 500; //Длина
    float L1 = 50; //Длина
    float L2 = LK / 2; //Длина пополам
    float B1 = 5; //Левый бортик
    // Множитель для преобразования угловых значений из градусов в радианы
    const double DEG_TO_RAD = M_PI / 180.0;

    // Локальная СК (по умолчанию совпадает с мировой СК)
    MbPlacement3D pl, pl1, pl2;

    // Вызов функции для построения образующей (из примера 6)
    RPArray<MbContour> arrContours, arrContours1, arrContours2, ptrContours;
    CreateSketchKTY(arrContours);
    CreateSketchK1TY(arrContours1);
    CreateSketchK2TY(arrContours2);
    CreateSketchCurveK(ptrContours);

    // Подготовка параметров для вызова функции построения тела вращения.
    // sweptData - объект, в котором хранятся сведения об образующей.
    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, arrContours);
    MbSweptData sweptData1(*pPlaneXY, arrContours1);
    MbSweptData sweptData2(*pPlaneXY, arrContours2);
    MbSweptData sweptData3(*pPlaneXY, ptrContours);

    // Объект параметров для операции построения тела вращения.
    RevolutionValues revParms(360 * DEG_TO_RAD, 0, 0);
    // Именователи для операции построения тела вращения и для контуров образующей
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);

    // Ось вращения для построения тела:
    // ось Y мировой СК смещается на -50 единиц вдоль оси X.
    MbAxis3D axis(pl.GetAxisX());
    MbAxis3D axis1(pl1.GetAxisY());
    MbAxis3D axis2(pl2.GetAxisY());
    MbSNameMaker operBoolNames(ct_BooleanSolid, MbSNameMaker::i_SideNone);
    // Исходные тела - цилиндры
    MbSolid* pCyl1 = NULL, * pCyl2 = NULL, * pCyl3 = NULL;

    // Объект-именователь для построения цилиндров - элементарных тел
    MbSNameMaker cylNames(ct_ElementarySolid, MbSNameMaker::i_SideNone);

    SArray<MbCartPoint3D> pntsCyl1(3);
    pntsCyl1.Add(MbCartPoint3D(0, -RV - 70, 0));
    pntsCyl1.Add(MbCartPoint3D(0, RV + 70, 0));
    pntsCyl1.Add(MbCartPoint3D(0, 0, 65));
    // Построение элементарного тела - цилиндра - по трем точкам
    ::ElementarySolid(pntsCyl1, et_Cylinder, cylNames, pCyl1);

    SArray<MbCartPoint3D> pntsCyl2(3);
    pntsCyl2.Add(MbCartPoint3D(0, -RV - 70, 0));
    pntsCyl2.Add(MbCartPoint3D(0, RV + 70, 0));
    pntsCyl2.Add(MbCartPoint3D(0, 0, 50));
    ::ElementarySolid(pntsCyl2, et_Cylinder, cylNames, pCyl2);

    SArray<MbCartPoint3D> pntsCyl3(3);
    pntsCyl3.Add(MbCartPoint3D(-L2 - L1, 0, 0));
    pntsCyl3.Add(MbCartPoint3D(L2, 0, 0));
    pntsCyl3.Add(MbCartPoint3D(-L2 - L1, RV, 0));
    ::ElementarySolid(pntsCyl3, et_Cylinder, cylNames, pCyl3);
    
    // Вызов функции-утилиты для построения твердого тела вращения
    MbBooleanFlags flagsBool;
    flagsBool.InitBoolean(true);
    flagsBool.SetMergingFaces(true);
    flagsBool.SetMergingEdges(true);

    // Результирующее тело
    MbSolid* pResSolid = NULL, * pDistributionChamber = NULL, * pConnector1 = nullptr, * pConnector2 = nullptr, * pCurves = nullptr;
    ::RevolutionSolid(sweptData, axis, revParms, operNames, cNames, pDistributionChamber);
    ::RevolutionSolid(sweptData1, axis1, revParms, operNames, cNames, pConnector1);
    ::RevolutionSolid(sweptData2, axis2, revParms, operNames, cNames, pConnector2);
    ::RevolutionSolid(sweptData3, axis, revParms, operNames, cNames, pCurves);

    ::BooleanResult(*pDistributionChamber, cm_Copy, *pCyl1, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pCyl2, cm_Copy, bo_Difference, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pCyl3, cm_Copy, bo_Difference, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pConnector1, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pConnector2, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pCurves, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);

  
    c3d::SolidSPtr MainSolid(pResSolid);
    pResSolid->Move(MbVector3D(-length/2 - LK/2, 0, 0));

    // Уменьшение счетчиков ссылок динамических объектов ядра
    ::DeleteItem(pResSolid);
    ::DeleteItem(pDistributionChamber);
    ::DeleteItem(pCyl1);
    ::DeleteItem(pCyl2);
    ::DeleteItem(pCyl3);
    ::DeleteItem(pConnector1);
    ::DeleteItem(pConnector2);
    ::DeleteItem(pCurves);

    return MainSolid;
}