#include "BuildMathModel.h"
using namespace BuildMathModel;

// Вспомогательная функция для построения образующей в виде квадрата со скруглениями.
void CreateSketchCKP(RPArray<MbContour>& _arrContours, float RV, float DNK, float Ts, float L2, float B1)
{

    // Размер массива - 12 точек
    SArray<MbCartPoint> arrPnts(12);
    arrPnts.Add(MbCartPoint(-L2 + B1, 0));
    arrPnts.Add(MbCartPoint(-L2 + B1, DNK - 4 * B1 - 0.3 * Ts));
    arrPnts.Add(MbCartPoint(-L2, DNK - 4 * B1 - 0.3 * Ts));
    arrPnts.Add(MbCartPoint(-L2, DNK));
    arrPnts.Add(MbCartPoint(-L2 + 1.5 * Ts + 2 * B1, DNK));
    arrPnts.Add(MbCartPoint(-L2 + 1.5 * Ts + 2 * B1, RV + Ts));
    arrPnts.Add(MbCartPoint(L2 - Ts - 2 * B1, RV + Ts));
    arrPnts.Add(MbCartPoint(L2 - Ts - 2 * B1, DNK));
    arrPnts.Add(MbCartPoint(L2, DNK));
    arrPnts.Add(MbCartPoint(L2, DNK - 4 * B1 - 0.3 * Ts));
    arrPnts.Add(MbCartPoint(L2 - B1, DNK - 4 * B1 - 0.3 * Ts));
    arrPnts.Add(MbCartPoint(L2 - B1, 0));

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // Задание скругления с использованием функции FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchCKP1(RPArray<MbContour>& _arrContours, float RV, float Dy, float Ts, float H2)
{
    float Ry = Dy/2;
    // Размер массива - 8 точек
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(Ry + Ts, H2));
    arrPnts.Add(MbCartPoint(Ry + Ts + 10, H2 + Ry/ 2));
    arrPnts.Add(MbCartPoint(Ry + Ts + Ry / 2, H2 + Ry / 2));
    arrPnts.Add(MbCartPoint(Ry + Ts + Ry / 2, H2 + Ry * 4 / 5));
    arrPnts.Add(MbCartPoint(Ry + Ts + 10, H2 + Ry * 4 / 5));
    arrPnts.Add(MbCartPoint(Ry + Ts, H2 + Ry));
    arrPnts.Add(MbCartPoint(Ry, H2 + Ry));
    arrPnts.Add(MbCartPoint(Ry, H2));
    

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchCKP2(RPArray<MbContour>& _arrContours, float RV, float Dy, float Ts, float H2)
{
   
    float Ry = Dy/2;
    // Размер массива - 8 точек
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(Ry + Ts, -H2));
    arrPnts.Add(MbCartPoint(Ry + Ts + 10, -H2 - Ry / 2));
    arrPnts.Add(MbCartPoint(Ry + Ts + Ry / 2, -H2 - Ry / 2));
    arrPnts.Add(MbCartPoint(Ry + Ts + Ry / 2, -H2 - Ry * 4 / 5));
    arrPnts.Add(MbCartPoint(Ry + Ts + 10, -H2 - Ry * 4 / 5));
    arrPnts.Add(MbCartPoint(Ry + Ts, -H2 - Ry));
    arrPnts.Add(MbCartPoint(Ry, -H2 - Ry));
    arrPnts.Add(MbCartPoint(Ry, -H2));
    

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchCKP3(RPArray<MbContour>& _arrContours, float L2, float B1)
{  
    // Размер массива - 8 точек
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
SPtr<MbSolid> ParametricModelCreator::Distribution_Chamber_KP(BuildParams params)
{
    float Dy = params.Dy.toDouble(); //Внутренний диамерт
    float DV = params.diam.toDouble();//Наружный диаметр
    float L = params.length.toDouble(); //Длина
    float H = params.height.toDouble(); //Длина
    float A1 = params.A.toDouble();; //Левый бортик
    float Ry = Dy / 2; //Внутренний диамерт
    float DN = DV + DV / 100 * 8; //Внутренний диаметр
    float H2 = H / 2 - Dy / 2; //Длина
    float LK = (params.l1.toDouble() - L / 100) * 2; //Длина
    float L2 = LK / 2; //Длина
    float RV = DV / 2; //Внутренний радиус
    float Ts = (DN - DV) / 2;//Толщина стенки
    float DNK = (DV + DV / 100 * 19.5) / 2 + 20 + 0.3 * Ts;//Наружный диаметр крышки
    float B1 = 5; //Левый бортик
    // Множитель для преобразования угловых значений из градусов в радианы
    const double DEG_TO_RAD = M_PI / 180.0;

    // Локальная СК (по умолчанию совпадает с мировой СК)
    MbPlacement3D pl,pl1,pl2,pl3;

    // Вызов функции для построения образующей (из примера 6)
    RPArray<MbContour> arrContours,arrContours1,arrContours2,arrContours3;
    CreateSketchCKP(arrContours, RV, DNK, Ts, L2, B1);
    CreateSketchCKP1(arrContours1, RV, Dy, Ts, H2);
    CreateSketchCKP2(arrContours2, RV, Dy, Ts, H2);
    CreateSketchCKP3(arrContours3, L2, B1);
    
    
    // sweptData - объект, в котором хранятся сведения об образующей.
    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0),MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, arrContours);
    MbSweptData sweptData1(*pPlaneXY, arrContours1);
    MbSweptData sweptData2(*pPlaneXY, arrContours2);
    MbSweptData sweptData3(*pPlaneXY, arrContours3);

    RevolutionValues revParms(360*DEG_TO_RAD, 0, 0);
    // Именователи для операции построения тела вращения и для контуров образующей
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);

   
    MbAxis3D axis(pl.GetAxisX());
    MbAxis3D axis1(pl1.GetAxisY());
    MbAxis3D axis2(pl2.GetAxisY());
    MbSNameMaker operBoolNames( ct_BooleanSolid, MbSNameMaker::i_SideNone ); 
    // Исходные тела - цилиндры
    MbSolid *pCyl1 = NULL, *pCyl2 = NULL, *pCyl3 = NULL;
    
    // Объект-именователь для построения цилиндров - элементарных тел
    MbSNameMaker cylNames(ct_ElementarySolid, MbSNameMaker::i_SideNone); 

    SArray<MbCartPoint3D> pntsCyl1(3);
    pntsCyl1.Add(MbCartPoint3D(0, -H2, 0));
    pntsCyl1.Add(MbCartPoint3D(0, H2, 0));
    pntsCyl1.Add(MbCartPoint3D(0, 0, Ry+Ts));  
    // Построение элементарного тела - цилиндра - по трем точкам
   ::ElementarySolid( pntsCyl1, et_Cylinder, cylNames, pCyl1 );
   
   SArray<MbCartPoint3D> pntsCyl2(3);
    pntsCyl2.Add(MbCartPoint3D(0, -H2, 0));
    pntsCyl2.Add(MbCartPoint3D(0, H2, 0));
    pntsCyl2.Add(MbCartPoint3D(0, 0, Ry));  
    // Построение элементарного тела - цилиндра - по трем точкам
   ::ElementarySolid( pntsCyl2, et_Cylinder, cylNames, pCyl2 );
   
    SArray<MbCartPoint3D> pntsCyl3(3);
    pntsCyl3.Add(MbCartPoint3D(-L2, 0, 0));
    pntsCyl3.Add(MbCartPoint3D(L2, 0, 0));
    pntsCyl3.Add(MbCartPoint3D(-L2, RV, 0));  
    // Построение элементарного тела - цилиндра - по трем точкам
   ::ElementarySolid( pntsCyl3, et_Cylinder, cylNames, pCyl3 );
    // Вызов функции-утилиты для построения твердого тела вращения
    
     MbBooleanFlags flagsBool;
    flagsBool.InitBoolean(true);
    flagsBool.SetMergingFaces(true);
    flagsBool.SetMergingEdges(true);  

    // Результирующее тело
    MbSolid *pResSolid = NULL,* pDistributionChamber = NULL,*pConnector1 = nullptr,*pConnector2 = nullptr;
    ::RevolutionSolid(sweptData, axis, revParms,operNames, cNames, pDistributionChamber);
    ::RevolutionSolid(sweptData1, axis1, revParms,operNames, cNames, pConnector1);
    ::RevolutionSolid(sweptData2, axis2, revParms,operNames, cNames, pConnector2);
    
    
    ::BooleanResult( *pDistributionChamber, cm_Copy, *pCyl1, cm_Copy, bo_Union,flagsBool, operBoolNames, pResSolid );
    ::BooleanResult( *pResSolid, cm_Copy, *pCyl2, cm_Copy, bo_Difference,flagsBool, operBoolNames, pResSolid );
    ::BooleanResult( *pResSolid, cm_Copy, *pCyl3, cm_Copy, bo_Difference,flagsBool, operBoolNames, pResSolid );
    ::BooleanResult( *pResSolid, cm_Copy, *pConnector1, cm_Copy, bo_Union,flagsBool, operBoolNames, pResSolid );
    ::BooleanResult( *pResSolid, cm_Copy, *pConnector2, cm_Copy, bo_Union,flagsBool, operBoolNames, pResSolid );
    
    // Направляющий вектор для операции выдавливания
    MbVector3D dir(0, 0, -1);


    ExtrusionValues extrusionParam;

    extrusionParam.side1.way = sw_shell;
    extrusionParam.side2.way = sw_shell;

    
    MbSolid* pPlate = nullptr;
    ::ExtrusionSolid(sweptData3, dir, pResSolid, pResSolid, false, extrusionParam, operNames, cNames, pPlate);
    ::BooleanResult(*pResSolid, cm_Copy, *pPlate, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    

    c3d::SolidSPtr MainSolid(pResSolid);
    // Уменьшение счетчиков ссылок динамических объектов ядра
    ::DeleteItem(pDistributionChamber);
    ::DeleteItem(pCyl1);
    ::DeleteItem(pCyl2);
    ::DeleteItem(pCyl3);
    ::DeleteItem(pConnector1);
    ::DeleteItem(pConnector2);
    ::DeleteItem(pResSolid);

    return MainSolid;
}