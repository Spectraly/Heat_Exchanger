#include "BuildMathModel.h"
using namespace BuildMathModel;

// Вспомогательная функция для построения образующей в виде квадрата со скруглениями.
void CreateSketchCCKP(RPArray<MbContour>& _arrContours)
{
    float DV,RV,DNK,L,B1;
    DNK = 663/2+12.5;//Наружный диаметр крышки
    DV = 600; //Внутренний диамерт
    RV = DV/2; //Внутренний радиус
    L = 40; //Длина
    B1 = 7; //Левый бортик

    // Размер массива - 8 точек
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(0, 0));
    arrPnts.Add(MbCartPoint(0, DNK));
    arrPnts.Add(MbCartPoint(3*B1, DNK));
    arrPnts.Add(MbCartPoint(3*B1, DNK-2*B1));
    arrPnts.Add(MbCartPoint(4*B1, DNK-2*B1));
    arrPnts.Add(MbCartPoint(4*B1, RV));
    arrPnts.Add(MbCartPoint(L, RV));
    arrPnts.Add(MbCartPoint(L, 0));



    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // Задание скругления с использованием функции FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}
void CreateSketchCC1KP(RPArray<MbContour>& _arrContours)
{
    float DV,RV,DNK,L,B1;
    DNK = 663/2+12.5;//Наружный диаметр крышки
    DV = 600; //Внутренний диамерт
    RV = DV/2; //Внутренний радиус
    L = 40; //Длина
    B1 = 7; //Левый бортик

    // Размер массива - 4 точек
    SArray<MbCartPoint> arrPnts(4);
    arrPnts.Add(MbCartPoint(L-B1, -3));
    arrPnts.Add(MbCartPoint(L-B1, 3));
    arrPnts.Add(MbCartPoint(L, 3));
    arrPnts.Add(MbCartPoint(L, -3));


    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    // Задание скругления с использованием функции FilletPolyContour
    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

SPtr<MbSolid> ParametricModelCreator::Distribution_Chamber_Cover_KP(BuildParams params)
{
    // Множитель для преобразования угловых значений из градусов в радианы
    const double DEG_TO_RAD = M_PI / 180.0;

    // Локальная СК (по умолчанию совпадает с мировой СК)
    MbPlacement3D pl;

    // Вызов функции для построения образующей (из примера 6)
    RPArray<MbContour> arrContours,arrContours1;
    CreateSketchCCKP(arrContours);
    CreateSketchCC1KP(arrContours1);
    
    // Подготовка параметров для вызова функции построения тела вращения.
    // sweptData - объект, в котором хранятся сведения об образующей.
    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0),MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, arrContours);
    MbSweptData sweptData1(*pPlaneXY, arrContours1);
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
    MbVector3D dir(0, 0, -1);
    ExtrusionValues extrusionParam(1000,1000);
    MbSNameMaker operBoolNames( ct_BooleanSolid, MbSNameMaker::i_SideNone ); 
    MbBooleanFlags flagsBool;
    flagsBool.InitBoolean(true);
    flagsBool.SetMergingFaces(true);
    flagsBool.SetMergingEdges(true);  

    // Именователи для операции построения тела вращения и для контуров образующей
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);
    MbSNameMaker plateNames( MbSNameMaker::i_SideNone); 
    // Ось вращения для построения тела:
    // ось Y мировой СК смещается на -50 единиц вдоль оси X.
    MbAxis3D axis(pl.GetAxisX());
    //axis.Move(MbVector3D(MbCartPoint3D(0, 0, 0), MbCartPoint3D(-50, 0, 0)));

    // Вызов функции-утилиты для построения твердого тела вращения
    MbSolid* pSolid = nullptr,*pPlate = nullptr;
    ::RevolutionSolid(sweptData, axis, revParms,operNames, cNames, pSolid);
    MbResultType res =::ExtrusionResult(*pSolid,cm_Same,sweptData1, dir, extrusionParam, bo_Difference, plateNames, NULL,pSolid);

    c3d::SolidSPtr MainSolid(pSolid);

    // Уменьшение счетчиков ссылок динамических объектов ядра
    ::DeleteItem(pSolid);

    return MainSolid;
}