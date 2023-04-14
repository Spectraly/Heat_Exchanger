#include "BuildMathModel.h"
using namespace BuildMathModel;

// Вспомогательная функция для построения образующей в виде квадрата со скруглениями.
void CreateSketchCKP(RPArray<MbContour>& _arrContours)
{
    float DV,RV,DN,DNK,TS,LK,L2,B1;
    DV = 600; //Внутренний диамерт
    DNK = 663/2+12.5;//Наружный диаметр крышки
    DN = DV + 30;//Наружный диаметр
    TS = (DN-DV)/2;//Толщина стенки
    RV = DV/2; //Внутренний радиус
    LK = 518; //Длина
    L2 = LK/2; //Длина пополам
    B1 = 7; //Левый бортик

    // Размер массива - 12 точек
    SArray<MbCartPoint> arrPnts(12);
    arrPnts.Add(MbCartPoint(-L2+B1, 0));
    arrPnts.Add(MbCartPoint(-L2+B1, DNK-2*B1));
    arrPnts.Add(MbCartPoint(-L2,  DNK-2*B1));
    arrPnts.Add(MbCartPoint(-L2,  DNK));
    arrPnts.Add(MbCartPoint(-L2+2*TS,  DNK));
    arrPnts.Add(MbCartPoint(-L2+2*TS, RV+TS));
    
    arrPnts.Add(MbCartPoint(L2-3.5*B1, RV+TS));
    arrPnts.Add(MbCartPoint(L2-3.5*B1, DNK));
    arrPnts.Add(MbCartPoint(L2, DNK));
    arrPnts.Add(MbCartPoint(L2, DNK-2*B1));
    arrPnts.Add(MbCartPoint(L2-B1, DNK-2*B1));
    arrPnts.Add(MbCartPoint(L2-B1, 0));

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // Задание скругления с использованием функции FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchCKP1(RPArray<MbContour>& _arrContours)
{
    float DV,RV,Dy1,Ry1,TS,DN;
    DV = 600; //Внутренний диамерт
    RV = DV/2; //Внутренний радиус
    Dy1 = 200;
    Ry1 = Dy1/2;
    DN = DV + 30;//Наружный диаметр
    TS = (DN-DV)/2;//Толщина стенки
    // Размер массива - 8 точек
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(Ry1+TS, RV+215));
    arrPnts.Add(MbCartPoint(Ry1+TS+10, RV+215+25));
    arrPnts.Add(MbCartPoint(Dy1, RV+215+25));
    arrPnts.Add(MbCartPoint(Dy1, RV+215+40));
    arrPnts.Add(MbCartPoint(Ry1+TS+10, RV+215+40));
    arrPnts.Add(MbCartPoint(Ry1+TS, RV+215+50));
    arrPnts.Add(MbCartPoint(Ry1, RV+215+50));
    arrPnts.Add(MbCartPoint(Ry1, RV+215));
    

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchCKP2(RPArray<MbContour>& _arrContours)
{
    
    float DV,RV,Dy1,Ry1,TS,DN;
    DV = 600; //Внутренний диамерт
    RV = DV/2; //Внутренний радиус
    Dy1 = 200;
    Ry1 = Dy1/2;
    DN = DV + 30;//Наружный диаметр
    TS = (DN-DV)/2;//Толщина стенки
    // Размер массива - 8 точек
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(Ry1+TS, -RV-215));
    arrPnts.Add(MbCartPoint(Ry1+TS+10, -RV-215-25));
    arrPnts.Add(MbCartPoint(Dy1, -RV-215-25));
    arrPnts.Add(MbCartPoint(Dy1, -RV-215-40));
    arrPnts.Add(MbCartPoint(Ry1+TS+10, -RV-215-40));
    arrPnts.Add(MbCartPoint(Ry1+TS, -RV-215-50));
    arrPnts.Add(MbCartPoint(Ry1, -RV-215-50));
    arrPnts.Add(MbCartPoint(Ry1, -RV-215));
    

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchCKP3(RPArray<MbContour>& _arrContours)
{
    float DV,RV,DN,DNK,TS,LK,L2,B1;
    DV = 600; //Внутренний диамерт
    DNK = 663/2+12.5;//Наружный диаметр крышки
    DN = DV + 30;//Наружный диаметр
    TS = (DN-DV)/2;//Толщина стенки
    RV = DV/2; //Внутренний радиус
    LK = 518; //Длина
    L2 = LK/2; //Длина пополам
    B1 = 7; //Левый бортик
    
    // Размер массива - 8 точек
    SArray<MbCartPoint> arrPnts(20);
    arrPnts.Add(MbCartPoint(-L2+2*B1, -10));
    arrPnts.Add(MbCartPoint(-L2+2*B1, -35));
    arrPnts.Add(MbCartPoint(-L2, -35));
    arrPnts.Add(MbCartPoint(-L2, -30));
    arrPnts.Add(MbCartPoint(-L2+B1, -30));
    arrPnts.Add(MbCartPoint(-L2+B1, 30));
    arrPnts.Add(MbCartPoint(-L2, 30));
    arrPnts.Add(MbCartPoint(-L2, 35));
    arrPnts.Add(MbCartPoint(-L2+2*B1, 35));
    arrPnts.Add(MbCartPoint(-L2+2*B1, 10));
    
    arrPnts.Add(MbCartPoint(L2-2*B1, 10));
    arrPnts.Add(MbCartPoint(L2-2*B1, 35));
    arrPnts.Add(MbCartPoint(L2, 35));
    arrPnts.Add(MbCartPoint(L2, 30));
    arrPnts.Add(MbCartPoint(L2-B1, 30));
    arrPnts.Add(MbCartPoint(L2-B1, -30));
    arrPnts.Add(MbCartPoint(L2, -30));
    arrPnts.Add(MbCartPoint(L2, -35));
    arrPnts.Add(MbCartPoint(L2-2*B1, -35));
    arrPnts.Add(MbCartPoint(L2-2*B1, -10));

    

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
SPtr<MbSolid> ParametricModelCreator::Distribution_Chamber_KP(BuildParams params)
{
    float DV,RV,DN,Dy,Ry,DNK,TS,LK,L2,B1;
    DV = 600; //Внутренний диамерт
    DNK = 663/2+12.5;//Наружный диаметр крышки
    DN = DV + 30;//Наружный диаметр
    TS = (DN-DV)/2;//Толщина стенки
    RV = DV/2; //Внутренний радиус
    Dy = 200;
    Ry = Dy/2;
    LK = 518; //Длина
    L2 = LK/2; //Длина пополам
    // Множитель для преобразования угловых значений из градусов в радианы
    const double DEG_TO_RAD = M_PI / 180.0;

    // Локальная СК (по умолчанию совпадает с мировой СК)
    MbPlacement3D pl,pl1,pl2,pl3;

    // Вызов функции для построения образующей (из примера 6)
    RPArray<MbContour> arrContours,arrContours1,arrContours2,arrContours3;
    CreateSketchCKP(arrContours);
    CreateSketchCKP1(arrContours1);
    CreateSketchCKP2(arrContours2);
    CreateSketchCKP3(arrContours3);
    
    
    // sweptData - объект, в котором хранятся сведения об образующей.
    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0),MbCartPoint3D(0, 1, 0));
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
    RevolutionValues revParms(360*DEG_TO_RAD, 0, 0);
    // Именователи для операции построения тела вращения и для контуров образующей
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);

    // Ось вращения для построения тела:
    // ось Y мировой СК смещается на -50 единиц вдоль оси X.
    MbAxis3D axis(pl.GetAxisX());
    MbAxis3D axis1(pl1.GetAxisY());
    MbAxis3D axis2(pl2.GetAxisY());
    MbSNameMaker operBoolNames( ct_BooleanSolid, MbSNameMaker::i_SideNone ); 
    // Исходные тела - цилиндры
    MbSolid *pCyl1 = NULL, *pCyl2 = NULL, *pCyl3 = NULL;
    
    // Объект-именователь для построения цилиндров - элементарных тел
    MbSNameMaker cylNames(ct_ElementarySolid, MbSNameMaker::i_SideNone); 

    SArray<MbCartPoint3D> pntsCyl1(3);
    pntsCyl1.Add(MbCartPoint3D(0, -RV-215, 0));
    pntsCyl1.Add(MbCartPoint3D(0, RV+215, 0));
    pntsCyl1.Add(MbCartPoint3D(0, 0, Ry+TS));  
    // Построение элементарного тела - цилиндра - по трем точкам
   ::ElementarySolid( pntsCyl1, et_Cylinder, cylNames, pCyl1 );
   
   SArray<MbCartPoint3D> pntsCyl2(3);
    pntsCyl2.Add(MbCartPoint3D(0, -RV-215, 0));
    pntsCyl2.Add(MbCartPoint3D(0, RV+215, 0));
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
    
    //СЮДА эта хуйня выдавливает ща в лево и право на 600 соответственно она работает можешь запустить и посмотреть че будет
    //по поводу эскиза я уже думаю его поменять и оставить просто палку а не распорку потому что я в инструкции вычитал что вот этот эскиз для выдавливания до тела должен быть меньше чем само тело типа не выходить за его границы. теперь смотри ниже
    // Параметры операции выдавливания
    ExtrusionValues extrusionParam(600,600);
    // Задание поверхности, до которой будет выполняться выдавливание
    // в прямом направлении
    // Указание способа выдавливания в прямом направлении - до пересечения с поверхностью
    
    //-----------------БОЧЕ короче брат смотри такая тема вот эти две строки снизу должны включать выдавливание до тела. они крашат приложение их лучше включать если что то придумал. смотри выше
    //extrusionParam.side1.way = sw_shell;
    //extrusionParam.side2.way = swShell;
    
    //ЗДЕСЬ короче первая операция это выдавливание записывающее инвормацию о нем в тело pPlate затем следующая операция соединяет это тело с основным
    MbSolid* pPlate = nullptr;
    //MbResultType res =::ExtrusionSolid(sweptData3, dir, nullptr, nullptr, false, extrusionParam, operNames, cNames, pPlate);
    //::BooleanResult( *pResSolid, cm_Copy, *pPlate, cm_Copy, bo_Union,flagsBool, operBoolNames, pResSolid );
    

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