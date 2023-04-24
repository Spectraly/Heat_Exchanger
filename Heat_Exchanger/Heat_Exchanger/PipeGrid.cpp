#include "BuildMathModel.h"
using namespace BuildMathModel;

void CreateSketchPG(RPArray<MbContour>& _arrContours)
{
    float DV = 325; //Внутренний диамерт
    float RV = DV / 2; //Внутренний радиус
    float B1 = 4; //Левый бортик
    float B2 = 8; //Правый бортик

    float d = 20; // D трубы
    float bigD = 295; // D проверочной окружности
    float offsets = 6; //расстояние между окружностями
    float t = (d + offsets); // Шаг между центрами
    float n0 = floor(bigD / t); // Кол-во отверстий на 0 ряду
    float n = n0 + 3; // Кол-во отверстий на 1 ряду
    float h = bigD / 2 * sin(60 * M_PI / 180); // Высота 6 угольника

    // Размер массива - 8 точек (y - умножили на 2)
    SArray<MbCartPoint> arrPnts(8);
    arrPnts.Add(MbCartPoint(-2 * B2, 0)); //(-16, 0)
    arrPnts.Add(MbCartPoint(-2 * B2, (RV - B1))); //(-16, 158.5)
    arrPnts.Add(MbCartPoint(-2 * B2 + 2 * B1, (RV - B1))); //(-8, 158.5)
    arrPnts.Add(MbCartPoint(-2 * B2 + 2 * B1, (RV + B2 + B1 * 5))); //(-8, 170.5)

    arrPnts.Add(MbCartPoint(2 * B2 - 2 * B1, (RV + B2 + B1 * 5))); //(8, 170.5)
    arrPnts.Add(MbCartPoint(2 * B2 - 2 * B1, (RV - B1))); //(8, 158.5)
    arrPnts.Add(MbCartPoint(2 * B2, (RV - B1))); //(16, 158.5)
    arrPnts.Add(MbCartPoint(2 * B2, 0)); //(16, 0)

    // Построение единой ломаной внешнего контура по точкам
    MbPolyline* pPolyline = new MbPolyline(arrPnts, true);
    MbContour* pContourPolyline = nullptr;

    ::FilletPolyContour(pPolyline, 0, false, arrPnts[4], pContourPolyline);

    _arrContours.push_back(pContourPolyline);
}

SPtr<MbSolid> ParametricModelCreator::PipeGride(BuildParams params)
{
    float DV = 325; //Внутренний диамерт
    float RV = DV / 2; //Внутренний радиус
    float B1 = 4; //Левый бортик
    float B2 = 8; //Правый бортик

    float d = 20; // D трубы
    float bigD = 295; // D проверочной окружности
    float offsets = 6; //расстояние между окружностями
    float t = (d + offsets); // Шаг между центрами
    float n0 = floor(bigD / t); // Кол-во отверстий на 0 ряду
    float n = n0 + 3; // Кол-во отверстий на 1 ряду
    float h = bigD / 2 * sin(60 * M_PI / 180); // Высота 6 угольника

    // Множитель для преобразования угловых значений из градусов в радианы
    const double DEG_TO_RAD = M_PI / 180.0;

    // Локальная СК (по умолчанию совпадает с мировой СК)
    MbPlacement3D pl, pl1;

    MbAxis3D global_axY(MbCartPoint3D(0, 0, 0), MbVector3D(0, 1, 0));
    pl1.Rotate(global_axY, M_PI / 2);

    // Вызов функции для построения образующей (из примера 6)
    RPArray<MbContour> arrContours;
    CreateSketchPG(arrContours);

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
    MbAxis3D axis(pl.GetAxisX());
    MbSNameMaker operBoolNames(ct_BooleanSolid, MbSNameMaker::i_SideNone);

    // Результирующее тело
    MbSolid* pResSolid = NULL;
    ::RevolutionSolid(sweptData, axis, revParms, operNames, cNames, pResSolid);

    MbSNameMaker cylNames(ct_ElementarySolid, MbSNameMaker::i_SideNone);


    MbBooleanFlags flagsBool;
    flagsBool.InitBoolean(true);
    flagsBool.SetMergingFaces(true);
    flagsBool.SetMergingEdges(true);

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            double x = (d + offsets) * n / 2 - d / 2 - i * t - cos(60 * M_PI / 180) * t * j - offsets / 2;
            double y = j * sin(60 * M_PI / 180) * t + t;

            double l = sqrt(pow(x, 2) + pow(y, 2));

            if (l + d / 2 < bigD / 2 && y < h)
            {
                MbSolid* pCyl1 = NULL, * pCyl2 = NULL;
                SArray<MbCartPoint3D> cylPntsYPlus(3);
                cylPntsYPlus.Add(MbCartPoint3D(-2 * B2, y, x));
                cylPntsYPlus.Add(MbCartPoint3D(2 * B2, y, x));
                cylPntsYPlus.Add(MbCartPoint3D(-2 * B2, y + d / 2, x));
                ::ElementarySolid(cylPntsYPlus, et_Cylinder, cylNames, pCyl1);
                //cylPntsYPlus.shrink_to_fit();
                SArray<MbCartPoint3D> cylPntsYMinus(3);
                cylPntsYMinus.Add(MbCartPoint3D(-2 * B2, -y, x));
                cylPntsYMinus.Add(MbCartPoint3D(2 * B2, -y, x));
                cylPntsYMinus.Add(MbCartPoint3D(-2 * B2, -y + d / 2, x));
                ::ElementarySolid(cylPntsYMinus, et_Cylinder, cylNames, pCyl2);
                //cylPntsYMinus.shrink_to_fit();
                ::BooleanResult(*pResSolid, cm_Copy, *pCyl1, cm_Copy, bo_Difference, flagsBool, operBoolNames, pResSolid);
                ::BooleanResult(*pResSolid, cm_Copy, *pCyl2, cm_Copy, bo_Difference, flagsBool, operBoolNames, pResSolid);
                ::DeleteItem(pCyl1);
                ::DeleteItem(pCyl2);
            }
        }
    }

    c3d::SolidSPtr MainSolid(pResSolid);
    pResSolid->Move(MbVector3D(-3000 / 2, 0, 0));

    // Уменьшение счетчиков ссылок динамических объектов ядра
    ::DeleteItem(pResSolid);

    return MainSolid;
}