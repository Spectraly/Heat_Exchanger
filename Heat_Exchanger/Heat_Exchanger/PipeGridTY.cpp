#include "BuildMathModel.h"
using namespace BuildMathModel;

void CreateSketchPGTY(RPArray<MbContour>& _arrContours, float RV, float B1, float B2)
{
    // Размер массива - 8 точек (y - умножили на 2)
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(-2 * B2, 0)); //(-16, 0)
    arrPnts.Add(MbCartPoint(-2 * B2, RV - 1)); //(-16, 158.5)
    arrPnts.Add(MbCartPoint(-2 * B2 + 2 * B1, RV - 1)); //(-8, 158.5)
    arrPnts.Add(MbCartPoint(-2 * B2 + 2 * B1, (RV + RV * 0.20 - 1))); //(-8, 170.5)

    arrPnts.Add(MbCartPoint(2 * B2 - 2 * B1, (RV + RV * 0.20 - 1))); //(8, 170.5)
    arrPnts.Add(MbCartPoint(2 * B2 - 2 * B1, RV - 1 )); //(8, 158.5)
    arrPnts.Add(MbCartPoint(2 * B2, RV - 1)); //(16, 158.5)
    arrPnts.Add(MbCartPoint(2 * B2, 0)); //(16, 0)

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

SPtr<MbSolid> ParametricModelCreator::PipeGrideTU(BuildParams params)
{
    float DV = params.diam.toDouble(); //Внутренний диамерт
    float d = params.d.toDouble(); // D трубы
    
    float offsets; //расстояние между окружностями
    if (d == 20)
        offsets = 6;
    else
        offsets = 7;
    
    float RV = DV / 2; //Внутренний радиус
    float B1 = 4; //Левый бортик
    float B2 = 8; //Правый бортик

    float bigD = DV - (DV / 100 * 9); // D проверочной окружности
    float t = (d + offsets); // Шаг между центрами
    float n0 = floor(bigD / t); // Кол-во отверстий на 0 ряду
    float n = n0 + 3; // Кол-во отверстий на 1 ряду

    // Множитель для преобразования угловых значений из градусов в радианы
    const double DEG_TO_RAD = M_PI / 180.0;

    float h = bigD / 2 * sin(60 * DEG_TO_RAD); // Высота 6 угольника
    
    // Локальная СК (по умолчанию совпадает с мировой СК)
    MbPlacement3D pl;

    // Вызов функции для построения образующей (из примера 6)
    RPArray<MbContour> arrContours;
    CreateSketchPGTY(arrContours, RV, B1, B2);
    //for (int i = 0; i<arrContours.size(); i++)
        //show(Style(1, RGB(0, 0, 255)), arrContours[i], &pl);

    // Подготовка параметров для вызова функции построения тела вращения.
    // sweptData - объект, в котором хранятся сведения об образующей.
    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, arrContours);

    // Объект параметров для операции построения тела вращения.
    RevolutionValues revParms(360 * DEG_TO_RAD, 0, 0);
    // Именователи для операции построения тела вращения и для контуров образующей
    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);

    // Ось вращения для построения тела:
    MbAxis3D axisX(pl.GetAxisX());
    MbSNameMaker operBoolNames(ct_BooleanSolid, MbSNameMaker::i_SideNone);

    // Результирующее тело
    MbSolid* pResSolid = NULL;
    ::RevolutionSolid(sweptData, axisX, revParms, operNames, cNames, pResSolid);

    MbSNameMaker cylNames(ct_ElementarySolid, MbSNameMaker::i_SideNone);

    MbBooleanFlags flagsBool;
    flagsBool.InitBoolean(true);
    flagsBool.SetMergingFaces(true);
    flagsBool.SetMergingEdges(true);

    SArray<MbCartPoint3D>* cylPntsYPlus = new SArray<MbCartPoint3D>();
    MbSolid* pCyl = NULL;

    RPArray<MbContour>* arrContours1 = new RPArray<MbContour>();

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            double x = (d + offsets) * n / 2 - d / 2 - i * t - cos(60 * DEG_TO_RAD) * t * j - offsets / 2;
            double y = j * sin(60 * DEG_TO_RAD) * t + t;

            double l = sqrt(pow(x, 2) + pow(y, 2));

            if (l + d / 2 < bigD / 2 && y < h)
            {
                MbArc* CirclePlus = new MbArc(MbCartPoint(x, y), d / 2);
                MbArc* CircleMinus = new MbArc(MbCartPoint(x, -y), d / 2);

                MbContour* arrContourCircleP = new MbContour();
                arrContourCircleP->AddSegment(CirclePlus);

                MbContour* arrContourCircleM = new MbContour();
                arrContourCircleM->AddSegment(CircleMinus);

                arrContours1->Add(arrContourCircleP);
                arrContours1->Add(arrContourCircleM);
            }
        }
    }

    MbSweptData sweptData1(*pPlaneXY, *arrContours1);

    MbVector3D dir(0, 0, -1);
    ExtrusionValues extrusionParam(2 * B2, 2 * B2);

    ::ExtrusionSolid(sweptData1, dir, nullptr, nullptr, false, extrusionParam, operNames, cNames, pCyl);

    MbAxis3D axisY(pl.GetAxisY());
    pCyl->Rotate(axisY, 90 * DEG_TO_RAD, nullptr);

    ::BooleanResult(*pResSolid, cm_Copy, *pCyl, cm_Copy, bo_Difference, flagsBool, operBoolNames, pResSolid);

    c3d::SolidSPtr MainSolid(pResSolid);

    float L = params.length.toDouble(); //Длина аппарата
    float A1 = params.A.toDouble()/2; //Левый штуцер (A)
    float l1 = params.l1.toDouble(); //Длина до первого штуцера
    float LK = (L - l1 - A1)/2; //Длина кожуха пополам

    pResSolid->Move(MbVector3D(-LK - 4, 0, 0));

    // Уменьшение счетчиков ссылок динамических объектов ядра
    ::DeleteItem(pCyl);
    ::DeleteItem(pResSolid);

    return MainSolid;
}