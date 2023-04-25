#include "BuildMathModel.h"
using namespace BuildMathModel;

void CreateSketchK(RPArray<MbContour>& _arrContours,float RV, float DNK, float Ts, float L2, float B1)
{


    // Размер массива - 12 точек
    SArray<MbCartPoint> arrPnts(12);
    arrPnts.Add(MbCartPoint(-L2 + B1, 0));
    arrPnts.Add(MbCartPoint(-L2 + B1, DNK - 2 * B1));
    arrPnts.Add(MbCartPoint(-L2, DNK - 2 * B1));
    arrPnts.Add(MbCartPoint(-L2, DNK));
    arrPnts.Add(MbCartPoint(-L2 + 2 * Ts, DNK));
    arrPnts.Add(MbCartPoint(-L2 + 2 * Ts, RV + Ts));
    arrPnts.Add(MbCartPoint(L2 - 3.5 * B1, RV + Ts));
    arrPnts.Add(MbCartPoint(L2 - 3.5 * B1, DNK));
    arrPnts.Add(MbCartPoint(L2, DNK));
    arrPnts.Add(MbCartPoint(L2, DNK - 2 * B1));
    arrPnts.Add(MbCartPoint(L2 - B1, DNK - 2 * B1));
    arrPnts.Add(MbCartPoint(L2 - B1, 0));

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // Задание скругления с использованием функции FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchK1(RPArray<MbContour>& _arrContours, float RV, float Dy1, float Ts,float H2)
{
    float Ry1 = Dy1 / 2; //Внутренний диамерт
    // Размер массива - 8 точек
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(Ry1 + Ts, H2));
    arrPnts.Add(MbCartPoint(Ry1 + Ts + 10, H2 + Ry1 / 2));
    arrPnts.Add(MbCartPoint(Ry1 + Ts + Ry1 / 2, H2 + Ry1 / 2));
    arrPnts.Add(MbCartPoint(Ry1 + Ts + Ry1 / 2, H2 + Ry1 * 4 / 5));
    arrPnts.Add(MbCartPoint(Ry1 + Ts + 10, H2 + Ry1 * 4 / 5));
    arrPnts.Add(MbCartPoint(Ry1 + Ts, H2 + Ry1));
    arrPnts.Add(MbCartPoint(Ry1, H2 + Ry1));
    arrPnts.Add(MbCartPoint(Ry1, H2));
    

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchK2(RPArray<MbContour>& _arrContours, float RV, float Dy1, float Ts, float H2)
{
    float Ry1 = Dy1 / 2; //Внутренний диамерт
    // Размер массива - 8 точек
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(Ry1 + Ts, -H2));
    arrPnts.Add(MbCartPoint(Ry1 + Ts + 10, -H2 - Ry1 / 2));
    arrPnts.Add(MbCartPoint(Ry1 + Ts + Ry1 / 2, -H2 - Ry1 / 2));
    arrPnts.Add(MbCartPoint(Ry1 + Ts + Ry1 / 2, -H2 - Ry1 * 4 / 5));
    arrPnts.Add(MbCartPoint(Ry1 + Ts + 10, -H2 - Ry1 * 4 / 5));
    arrPnts.Add(MbCartPoint(Ry1 + Ts, -H2 - Ry1));
    arrPnts.Add(MbCartPoint(Ry1, -H2 - Ry1));
    arrPnts.Add(MbCartPoint(Ry1, -H2));
    

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchK3(RPArray<MbContour>& _arrContours,float L2, float B1)
{
    SArray<MbCartPoint> arrPnts(20);
    arrPnts.Add(MbCartPoint(-L2 + B1 / 2, 3));
    arrPnts.Add(MbCartPoint(-L2, 3));
    arrPnts.Add(MbCartPoint(-L2, 6));
    arrPnts.Add(MbCartPoint(-L2 + B1, 6));
    arrPnts.Add(MbCartPoint(-L2 + B1, 3));

    arrPnts.Add(MbCartPoint(L2 - B1, 3));
    arrPnts.Add(MbCartPoint(L2 - B1, 6));
    arrPnts.Add(MbCartPoint(L2, 6));
    arrPnts.Add(MbCartPoint(L2, 3));
    arrPnts.Add(MbCartPoint(L2 - B1 / 2, 3));

    arrPnts.Add(MbCartPoint(L2 - B1 / 2, -3));
    arrPnts.Add(MbCartPoint(L2, -3));
    arrPnts.Add(MbCartPoint(L2, -6));
    arrPnts.Add(MbCartPoint(L2 - B1, -6));
    arrPnts.Add(MbCartPoint(L2 - B1, -3));

    arrPnts.Add(MbCartPoint(-L2 + B1, -3));
    arrPnts.Add(MbCartPoint(-L2 + B1, -6));
    arrPnts.Add(MbCartPoint(-L2, -6));
    arrPnts.Add(MbCartPoint(-L2, -3));
    arrPnts.Add(MbCartPoint(-L2 + B1 / 2, -3));



    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

SPtr<MbSolid> ParametricModelCreator::Distribution_Chamber(BuildParams params)
{
    float Dy = params.Dy1.toDouble(); //Внутренний диамерт
    float DV = params.diam.toDouble();//Наружный диаметр
    float L = params.length.toDouble(); //Длина
    float H = params.height.toDouble(); //Длина
    float A1 = params.A.toDouble();; //Левый бортик
    float Ry = Dy / 2; //Внутренний диамерт
    float DN = DV + DV / 100 * 8; //Внутренний диаметр
    float H2 = H/2 - Dy / 2; //Длина
    float LK = (L/100) * 11.5; //Длина
    float L2 = LK/2; //Длина
    float RV = DV / 2; //Внутренний радиус
    float Ts = (DN - DV) / 2;//Толщина стенки
    float DNK = (DV + DV / 100 * 19.5) / 2 + 20;//Наружный диаметр крышки
    int B1 = 5; //Левый бортик
    // Множитель для преобразования угловых значений из градусов в радианы
    const double DEG_TO_RAD = M_PI / 180.0;

    // Локальная СК (по умолчанию совпадает с мировой СК)
    MbPlacement3D pl, pl1, pl2, pl3;


    RPArray<MbContour> arrContours, arrContours1, arrContours2, arrContours3;

    CreateSketchK(arrContours, RV, DNK, Ts,L2, B1);

    CreateSketchK1(arrContours1, RV, Dy, Ts, H2);

    CreateSketchK2(arrContours2, RV, Dy, Ts,H2);

    // Подготовка параметров для вызова функции построения тела вращения.
    CreateSketchK3(arrContours3,L2, B1);




    // sweptData - объект, в котором хранятся сведения об образующей.
    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, arrContours);
    MbSweptData sweptData1(*pPlaneXY, arrContours1);
    MbSweptData sweptData2(*pPlaneXY, arrContours2);
    MbSweptData sweptData3(*pPlaneXY, arrContours3);

    // Объект параметров для операции построения тела вращения.
    // Первые два параметра конструктора задают углы вращения в прямом и обратном
    // направлении (по нормали к образующей или противоположно этой нормали).
    // В данном примере вращение осуществляется на 120 градусов в прямом направлении.
    // Третий параметр задает форму топологии твердого тела.
    // При s = 0 строится тело с топологией сферы, при s = 1 - с топологией тора.
    // Если образующая - незамкнутая кривая, и ось вращения лежит в плоскости кривой,
    // то при s = 0 при построении образующая будет автоматически продлена до оси
    // вращения. В данном примере различий между значениями s нет, т.к. образующая
    // имеет вид замкнутого контура.
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
    pntsCyl1.Add(MbCartPoint3D(0, -H2, 0));
    pntsCyl1.Add(MbCartPoint3D(0, H2, 0));
    pntsCyl1.Add(MbCartPoint3D(0, 0, Ry + Ts));
    // Построение элементарного тела - цилиндра - по трем точкам
    ::ElementarySolid(pntsCyl1, et_Cylinder, cylNames, pCyl1);

    SArray<MbCartPoint3D> pntsCyl2(3);
    pntsCyl2.Add(MbCartPoint3D(0, -H2, 0));
    pntsCyl2.Add(MbCartPoint3D(0, H2, 0));
    pntsCyl2.Add(MbCartPoint3D(0, 0, Ry));
    // Построение элементарного тела - цилиндра - по трем точкам
    ::ElementarySolid(pntsCyl2, et_Cylinder, cylNames, pCyl2);

    SArray<MbCartPoint3D> pntsCyl3(3);
    pntsCyl3.Add(MbCartPoint3D(-L2, 0, 0));
    pntsCyl3.Add(MbCartPoint3D(L2, 0, 0));
    pntsCyl3.Add(MbCartPoint3D(-L2, RV, 0));
    // Построение элементарного тела - цилиндра - по трем точкам
    ::ElementarySolid(pntsCyl3, et_Cylinder, cylNames, pCyl3);
    // Вызов функции-утилиты для построения твердого тела вращения
    MbBooleanFlags flagsBool;
    flagsBool.InitBoolean(true);
    flagsBool.SetMergingFaces(true);
    flagsBool.SetMergingEdges(true);

    // Результирующее тело
    MbSolid* pResSolid = NULL, * pDistributionChamber = NULL, * pConnector1 = nullptr, * pConnector2 = nullptr;
    ::RevolutionSolid(sweptData, axis, revParms, operNames, cNames, pDistributionChamber);
    ::RevolutionSolid(sweptData1, axis1, revParms, operNames, cNames, pConnector1);
    ::RevolutionSolid(sweptData2, axis2, revParms, operNames, cNames, pConnector2);


    ::BooleanResult(*pDistributionChamber, cm_Copy, *pCyl1, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pCyl2, cm_Copy, bo_Difference, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pCyl3, cm_Copy, bo_Difference, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pConnector1, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pConnector2, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);

    // Направляющий вектор для операции выдавливания
    MbVector3D dir(0, 0, -1);


    ExtrusionValues extrusionParam(294,294);

    extrusionParam.side1.way = sw_shell;
    extrusionParam.side2.way = sw_shell;
    
    MbSolid* pPlate = nullptr;
    
    ::ExtrusionSolid(sweptData3, dir, pResSolid, pResSolid, false, extrusionParam, operNames, cNames, pPlate);
    ::BooleanResult( *pResSolid, cm_Copy, *pPlate, cm_Copy, bo_Union,flagsBool, operBoolNames, pResSolid );

    c3d::SolidSPtr MainSolid(pResSolid);

    // Уменьшение счетчиков ссылок динамических объектов ядра
    ::DeleteItem(pResSolid);
    ::DeleteItem(pDistributionChamber);
    ::DeleteItem(pCyl1);
    ::DeleteItem(pCyl2);
    ::DeleteItem(pCyl3);
    ::DeleteItem(pConnector1);
    ::DeleteItem(pConnector2);

    return MainSolid;
}