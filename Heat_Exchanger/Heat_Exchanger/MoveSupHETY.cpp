#include "BuildMathModel.h"
using namespace BuildMathModel;

void CreateSketchMoveSupTY(RPArray<MbContour>& _arrContours, float L2, float B1, float h)
{
    // Размер массива - 10 точек
    SArray<MbCartPoint> arrPnts(10);
    arrPnts.Add(MbCartPoint(0, 0)); //(0, 0)
    arrPnts.Add(MbCartPoint(-L2, 0)); //(-120, 0)
    arrPnts.Add(MbCartPoint(-L2, B1)); //(-120, 5)
    arrPnts.Add(MbCartPoint(-L2 + 5, B1)); //(-115, 5)
    arrPnts.Add(MbCartPoint(-L2 + 5, h)); //(-115, 292)
    arrPnts.Add(MbCartPoint(-L2 + 10, h)); //(-110, 292)
    arrPnts.Add(MbCartPoint(-L2 + 10, B1)); //(-110, 5)
    arrPnts.Add(MbCartPoint(-2.5, B1)); //(-2.5, 5)
    arrPnts.Add(MbCartPoint(-2.5, h)); //(-2.5, 292)
    arrPnts.Add(MbCartPoint(0, h)); //(0, 292)

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[10], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

void CreateSketchMoveSupTY1(RPArray<MbContour>& _arrContours, float L2, float B1, float h)
{
    // Размер массива - 4 точек
    SArray<MbCartPoint> arrPnts(4);
    arrPnts.Add(MbCartPoint(-2.5, B1)); //(, )
    arrPnts.Add(MbCartPoint(-L2 + 10, B1)); //(, )
    arrPnts.Add(MbCartPoint(-L2 + 10, h)); //(, )
    arrPnts.Add(MbCartPoint(-2.5, h)); //(, )

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[10], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

void CreateSketchMoveSupTYCurve(RPArray<MbContour>& _ptrContours, float DV, float h)
{
    float RV = DV / 2; //Внутренний радиус

    //Создание точек контура
    MbCartPoint p1(0, h - RV + 2.5);
    MbCartPoint p2(0, h - RV);
    MbCartPoint p3(-DV * sin(70 * M_PI / 180), DV * cos(70 * M_PI / 180)); // Прикол с углом
    MbCartPoint p4(-DV * sin(70 * M_PI / 180), DV * cos(70 * M_PI / 180) + 2.5); // Прикол с углом

    //Динамическое создание объектов отрезков
    MbLineSegment* Seg1 = new MbLineSegment(p1, p2);
    MbArc* Seg2 = new MbArc(MbCartPoint(0, h), RV, p2, p3, -1);
    MbArc* Seg4 = new MbArc(MbCartPoint(0, h + 2.5), RV, p4, p1, 1);
    MbCartPoint p5, p6;
    Seg2->GetEndPoint(p5);
    Seg4->GetStartPoint(p6);
    MbLineSegment* Seg3 = new MbLineSegment(p5, p6);

    //Динамическое создание контура
    MbContour* ptrContour = new MbContour();

    //Добавление в контур сегментов
    ptrContour->AddSegment(Seg1);
    ptrContour->AddSegment(Seg2);
    ptrContour->AddSegment(Seg3);
    ptrContour->AddSegment(Seg4);
    _ptrContours.push_back(ptrContour);
}

SPtr<MbSolid> ParametricModelCreator::MoveSupHETU(BuildParams params)
{
    float DV = params.diam.toDouble();//Наружный диаметр
    float h = params.h.toDouble(); //Высота опоры от центра

    //float DN = DV + DV / 100 * 8; //Внутренний диаметр
    float RV = DV / 2; //Внутренний радиус
    float L = DV / 100 * 80; //Длина
    float L2 = L / 2; //Длина пополам
    float L1 = 250; //Длина - правого края
    float B1 = 5; //Левый бортик

    float B;
    if (DV >= 325 || DV < 800)
        B = 180 / 2;
    else
        B = 250 / 2;

    // Множитель для преобразования угловых значений из градусов в радианы
    const double DEG_TO_RAD = M_PI / 180.0;

    // Локальная СК (по умолчанию совпадает с мировой СК)
    MbPlacement3D pl, pl1;
    pl1.Rotate(MbAxis3D(MbVector3D(0, 1, 0)), 90 * DEG_TO_RAD);

    // Вызов функции для построения образующей 
    RPArray<MbContour> arrContours, arrContours1, ptrContours;
    CreateSketchMoveSupTY(arrContours, L2, B1, h);
    CreateSketchMoveSupTY1(arrContours1, L2, B1, h);
    CreateSketchMoveSupTYCurve(ptrContours, DV, h);

    // Подготовка параметров для вызова функции построения тела вращения.
    // sweptData - объект, в котором хранятся сведения об образующей.
    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, arrContours);
    MbSweptData sweptData1(*pPlaneXY, arrContours1);
    MbSweptData sweptData2(*pPlaneXY, ptrContours);

    // Направляющий вектор для операции выдавливания
    MbVector3D dir(0, 0, -1);

    // Объект параметров для операции построения тела вращения.
    // Первые два параметра конструктора задают углы вращения в прямом и обратном
    // направлении (по нормали к образующей или противоположно этой нормали).
    // В данном примере вращение осуществляется на 360 градусов в прямом направлении.
    // Третий параметр задает форму топологии твердого тела.
    // При s = 0 строится тело с топологией сферы, при s = 1 - с топологией тора.
    // Если образующая - незамкнутая кривая, и ось вращения лежит в плоскости кривой,
    // то при s = 0 при построении образующая будет автоматически продлена до оси
    // вращения. В данном примере различий между значениями s нет, т.к. образующая
    // имеет вид замкнутого контура.
    RevolutionValues revParms(360 * DEG_TO_RAD, 0, 0);

    MbSNameMaker operBoolNames(ct_BooleanSolid, MbSNameMaker::i_SideNone);

    // Именователи элементов модели твердого тела и контуров образующей
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);

    // Ось вращения для построения тела:
    MbAxis3D axis(pl.GetAxisX());

    ExtrusionValues extrusionParams(B, B);
    ExtrusionValues extrusionParams1(B1, B1);
    ExtrusionValues extrusionParams2(B + 5 * B1, B + 5 * B1);

    // Вызов функции-утилиты для построения твердого тела вращения
    MbSolid* pSup = nullptr, * pSup1 = nullptr, * pSup2 = nullptr;
    ::ExtrusionSolid(sweptData, dir, nullptr, nullptr, false, extrusionParams, operNames, cNames, pSup);
    ::ExtrusionSolid(sweptData1, dir, nullptr, nullptr, false, extrusionParams1, operNames, cNames, pSup1);
    ::ExtrusionSolid(sweptData2, dir, nullptr, nullptr, false, extrusionParams2, operNames, cNames, pSup2);


    MbSNameMaker cylNames(ct_ElementarySolid, MbSNameMaker::i_SideNone);
    MbSolid* pCyl = NULL;
    // Построение ограничивающей цилиндрической поверхности
    SArray<MbCartPoint3D> pCylSurf(3);
    pCylSurf.Add(MbCartPoint3D(0, h, -B));
    pCylSurf.Add(MbCartPoint3D(0, h, B));
    pCylSurf.Add(MbCartPoint3D(0, h + RV, -B));
    ::ElementarySolid(pCylSurf, et_Cylinder, cylNames, pCyl);
    //show(Style(1, RGB(50, 200, 200)), pCyl);

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
    ::BooleanResult(*pSup, cm_Copy, *pSup1, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pCyl, cm_Copy, bo_Difference, flagsBool, operBoolNames, pResSolid);
    ::BooleanResult(*pResSolid, cm_Copy, *pSup2, cm_Copy, bo_Union, flagsBool, operBoolNames, pResSolid);
    ::SymmetrySolid(*pResSolid, cm_Copy, pl1, operBoolNames, pResSolid);
    // Отображение построенного тела
    //if (res == rt_Success)
        //show(Style(1, LIGHTGRAY), pResSolid);

    MbAxis3D axisY(pl.GetAxisY());
    pResSolid->Rotate(axisY, 90 * DEG_TO_RAD, nullptr);

    float LO = params.length.toDouble(); //Длина аппарата

    float l1 = params.l1.toDouble(); //Длина до первого штуцера
    float A1 = params.A.toDouble(); //Левый штуцер (A)
    float A2 = params.A1.toDouble(); //Левый штуцер (A1)
    float l2 = params.l2.toDouble(); //Расстояние до подвижной опоры
    float LK = (LO - l1 - A1/2) / 2; //Длина кожуха пополам
    float LK1 = LK + l1 + A1 / 2; //Длина кожуха пополам
    float LS = -LK1 + (l1 + A1 + A2) - l2; //Расстояние до неподвижной опоры


    pResSolid->Move(MbVector3D(LS, -h - 3 * B1 - 2.5, 0));

    c3d::SolidSPtr MainSolid(pResSolid);

    // Уменьшение счетчиков ссылок динамических объектов ядра
    ::DeleteItem(pResSolid);

    return MainSolid;
}