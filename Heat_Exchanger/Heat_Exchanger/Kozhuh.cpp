#include "BuildMathModel.h"
using namespace BuildMathModel;

void CreateSketchTY(RPArray<MbContour>& _arrContours, float RV, float LK, float B1)
{
    // Размер массива - 9 точек
    SArray<MbCartPoint> arrPnts(9);
    arrPnts.Add(MbCartPoint(-LK + B1, 0));
    arrPnts.Add(MbCartPoint(-LK + B1, RV + RV * 0.20));
    arrPnts.Add(MbCartPoint(-LK, RV + RV * 0.20));
    arrPnts.Add(MbCartPoint(-LK, RV + RV * 0.20 + 3 * B1));

    arrPnts.Add(MbCartPoint(-LK + 3 * B1, RV + RV * 0.20 + 3 * B1));
    arrPnts.Add(MbCartPoint(-LK + 3 * B1, RV + 4 * B1));
    arrPnts.Add(MbCartPoint(-LK + 4 * B1, RV + 3 * B1));
    arrPnts.Add(MbCartPoint(LK, RV + 3 * B1));
    arrPnts.Add(MbCartPoint(LK, 0));

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

void CreateSketch1TY(RPArray<MbContour>& _arrContours, float LK, float A1, float H2, float Ry, float B2)
{
    float S = -LK + A1;
    // Размер массива - 8 точек
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(S - Ry, H2 - 4 * Ry / 5));
    arrPnts.Add(MbCartPoint(S - Ry, H2));
    arrPnts.Add(MbCartPoint(S - Ry - 1.5 * B2, H2));
    arrPnts.Add(MbCartPoint(S - Ry - 2 * B2, H2 - Ry / 5));
    arrPnts.Add(MbCartPoint(S - Ry - 4 * B2, H2 - Ry / 5));
    arrPnts.Add(MbCartPoint(S - Ry - 4 * B2, H2 - 2 * Ry / 5));
    arrPnts.Add(MbCartPoint(S - Ry - 2 * B2, H2 - 2 * Ry / 5));
    arrPnts.Add(MbCartPoint(S - Ry - 1.5 * B2, H2 - 4 * Ry / 5));

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketch2TY(RPArray<MbContour>& _arrContours, float LK, float A1, float A2, float H2, float Ry, float B2)
{
    float S = -LK + A1 + A2;

    // Размер массива - 8 точек
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(Ry + S, -H2 + 4 * Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + S, -H2));
    arrPnts.Add(MbCartPoint(Ry + 1.5 * B2 + S, -H2));
    arrPnts.Add(MbCartPoint(Ry + 2 * B2 + S, -H2 + Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + 4 * B2 + S, -H2 + Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + 4 * B2 + S, -H2 + 2 * Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + 2 * B2 + S, -H2 + 2 * Ry / 5));
    arrPnts.Add(MbCartPoint(Ry + 1.5 * B2 + S, -H2 + 4 * Ry / 5));

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

void CreateSketchCurve(RPArray<MbContour>& _ptrContours, float RV, float LK, float B1, float B2)
{
    //Динамическое создание контура
    MbContour* ptrContour = new MbContour();
    //Добавление в контур сегментов

    MbCartPoint p1(LK, RV);
    MbCartPoint p2(LK, RV + 3 * B1);
    MbCartPoint p3(LK + RV / 2, 0);
    MbCartPoint p4(LK + RV / 2 - 1.5 * B2, 0);

    MbPlacement* plCurve = new MbPlacement(MbCartPoint(LK, 0), MbDirection(0.0));

    //Динамическое создание объектов отрезков
    MbLineSegment* Seg1 = new MbLineSegment(p1, p2);
    MbArc* Seg2 = new MbArc(RV / 2, RV + 3 * B1, *plCurve, p2, p3, -1);
    MbLineSegment* Seg3 = new MbLineSegment(p3, p4);
    MbArc* Seg4 = new MbArc(RV / 2 - 1.5 * B2, RV, *plCurve, p4, p1, 1);

    ptrContour->AddSegment(Seg1);
    ptrContour->AddSegment(Seg2);
    ptrContour->AddSegment(Seg3);
    ptrContour->AddSegment(Seg4);

    _ptrContours.push_back(ptrContour);
}

SPtr<MbSolid> ParametricModelCreator::CasingTY(BuildParams params)
{
    float DV = params.diam.toDouble(); //Внутренний диамерт
    float l = params.l.toDouble(); //Длина
    float L = params.length.toDouble(); //Длина
    float Dy = params.Dy.toDouble(); //Диамерт штуцеров
    float H = params.height.toDouble(); //Высота штуцеров
    float A2 = params.A1.toDouble(); //Правый штуцер (A1)
    float A1 = params.A.toDouble() / 2; //Левый штуцер (A)
    float l1 = params.l1.toDouble(); //Длина до первого штуцера

    float RV = DV / 2; //Внутренний радиус
    float h = (DV - 30) / 2 * sin(60 * M_PI / 180); // Высота 6 угольника
    
    //float LK = (l + h)/2;
    float LK1 = l1 + A1; //Длина камеры
    float LK = (L - LK1) / 2; //Длина кожуха пополам

    float B1 = 5; //Левый бортик
    float B2 = 10; //Правый бортик
    float H2 = H / 2; //Высота штуцеров пополам
    float Ry = Dy / 2; //Диамерт штуцеров пополам

    // Множитель для преобразования угловых значений из градусов в радианы
    const double DEG_TO_RAD = M_PI / 180.0;

    // Локальная СК (по умолчанию совпадает с мировой СК)
    MbPlacement3D pl, pl1, pl2;

    // Вызов функции для построения образующей (из примера 6)
    RPArray<MbContour> arrContours, arrContours1, arrContours2, ptrContours;
    CreateSketchTY(arrContours, RV, LK, B1);
    CreateSketch1TY(arrContours1, LK, A1, H2, Ry, B2);
    CreateSketch2TY(arrContours2, LK, A1, A2, H2, Ry, B2);
    CreateSketchCurve(ptrContours, RV, LK, B1, B2);

    //for (int i = 0; i < arrContours1.size(); i++)
        //show(Style(1, RGB(0, 0, 255)), arrContours1[i], &pl);

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
    MbAxis3D axis(pl.GetAxisX());
    MbAxis3D axis1(pl1.GetAxisY());
    MbAxis3D axis2(pl2.GetAxisY());
    axis1.Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(-LK + A1, 0, 0)));
    axis2.Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(-LK + A1 + A2, 0, 0)));


    // Вызов функции-утилиты для построения твердого тела вращения
    MbSolid* pCasing = nullptr, * pConnector1 = nullptr, * pConnector2 = nullptr, * pCurves = nullptr;
    ::RevolutionSolid(sweptData, axis, revParms, operNames, cNames, pCasing);
    ::RevolutionSolid(sweptData1, axis1, revParms, operNames, cNames, pConnector1);
    ::RevolutionSolid(sweptData2, axis2, revParms, operNames, cNames, pConnector2);
    ::RevolutionSolid(sweptData3, axis, revParms, operNames, cNames, pCurves);

    //---------------------------------------------------------//
    MbSNameMaker operBoolNames(ct_BooleanSolid, MbSNameMaker::i_SideNone);
    // Исходные тела - цилиндры
    MbSolid* pCyl1 = NULL, * pCyl2 = NULL, * pCyl3 = NULL, * pCyl4 = NULL, * pCyl5 = NULL;

    // Объект-именователь для построения цилиндров - элементарных тел
    MbSNameMaker cylNames(ct_ElementarySolid, MbSNameMaker::i_SideNone);

    // Массив точек для построения первого цилиндра   
    SArray<MbCartPoint3D> pntsCyl1(3);
    pntsCyl1.Add(MbCartPoint3D(-LK + A1, 0, 0));
    pntsCyl1.Add(MbCartPoint3D(-LK + A1, H2 - 4 * Ry / 5, 0));
    pntsCyl1.Add(MbCartPoint3D(-LK + A1, 0, Ry + 1.5 * B2));
    // Построение элементарного тела - цилиндра - по трем точкам
    ::ElementarySolid(pntsCyl1, et_Cylinder, cylNames, pCyl1);

    SArray<MbCartPoint3D> pntsCyl2(3);
    pntsCyl2.Add(MbCartPoint3D(-LK + A1 + A2, 0, 0));
    pntsCyl2.Add(MbCartPoint3D(-LK + A1 + A2, -H2 + 4 * Ry / 5, 0));
    pntsCyl2.Add(MbCartPoint3D(-LK + A1 + A2, 0, Ry + 1.5 * B2));
    ::ElementarySolid(pntsCyl2, et_Cylinder, cylNames, pCyl2);

    SArray<MbCartPoint3D> pntsCyl3(3);
    pntsCyl3.Add(MbCartPoint3D(-LK + A1, 0, 0));
    pntsCyl3.Add(MbCartPoint3D(-LK + A1, H2 - 4 * Ry / 5, 0));
    pntsCyl3.Add(MbCartPoint3D(-LK + A1, 0, Ry));
    ::ElementarySolid(pntsCyl3, et_Cylinder, cylNames, pCyl3);

    SArray<MbCartPoint3D> pntsCyl4(3);
    pntsCyl4.Add(MbCartPoint3D(-LK + A1 + A2, 0, 0));
    pntsCyl4.Add(MbCartPoint3D(-LK + A1 + A2, -H2 + 4 * Ry / 5, 0));
    pntsCyl4.Add(MbCartPoint3D(-LK + A1 + A2, 0, Ry));
    ::ElementarySolid(pntsCyl4, et_Cylinder, cylNames, pCyl4);

    SArray<MbCartPoint3D> pntsCyl5(3);
    pntsCyl5.Add(MbCartPoint3D(-LK, 0, 0));
    pntsCyl5.Add(MbCartPoint3D(LK, 0, 0));
    pntsCyl5.Add(MbCartPoint3D(-LK, RV, 0));
    ::ElementarySolid(pntsCyl5, et_Cylinder, cylNames, pCyl5);

    //---------------------------------------------------------//
    // Флаги булевой операции: построение замкнутого тела с объединением
    // подобных граней и ребер.
    MbBooleanFlags flagsBool;
    flagsBool.InitBoolean(true);
    flagsBool.SetMergingFaces(true);
    flagsBool.SetMergingEdges(true);

    // Результирующее тело
    MbSolid* pResSolid = NULL;
    // Вызов булевой операции для выполнения объединения.
    // Для выполнения вычитания надо вместо типа операции bo_Union указать
    // значение bo_Difference, для пересечения - значение bo_Intersect.
    //---------------------------------------------------------//
    ::BooleanResult(*pCasing, cm_Copy, *pCyl1, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pCyl2, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pCyl3, cm_Copy, bo_Difference, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pCyl4, cm_Copy, bo_Difference, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pCyl5, cm_Copy, bo_Difference, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pConnector1, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pConnector2, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pCurves, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);

    c3d::SolidSPtr MainSolid(pResSolid);

    // Уменьшение счетчиков ссылок динамических объектов ядра
    ::DeleteItem(pCyl1);
    ::DeleteItem(pCyl2);
    ::DeleteItem(pCyl3);
    ::DeleteItem(pCyl4);
    ::DeleteItem(pCyl5);
    ::DeleteItem(pCasing);
    ::DeleteItem(pConnector1);
    ::DeleteItem(pConnector2);
    ::DeleteItem(pCurves);
    ::DeleteItem(pResSolid);

    return MainSolid;
}