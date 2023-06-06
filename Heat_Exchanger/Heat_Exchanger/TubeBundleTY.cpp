#include "BuildMathModel.h"
using namespace BuildMathModel;

SPtr<MbSolid> ParametricModelCreator::TubeBundleTU(BuildParams params)
{
    float DV = params.diam.toDouble(); //Внутренний диамерт
    if (DV == 325)
        DV = 300;
    float d = params.d.toDouble(); // D трубы
    float l = params.l.toDouble(); //Длина труб

    float offsets; //расстояние между окружностями
    if (d == 20)
        offsets = 6;
    else
        offsets = 7;

    float RV = DV / 2; //Внутренний радиус
    float bigD = DV - (DV / 100 * 9); // D проверочной окружности
    float t = (d + offsets); // Шаг между центрами
    float n0 = floor(bigD / t); // Кол-во отверстий на 0 ряду
    float n = n0 + 3; // Кол-во отверстий на 1 ряду

    // Множитель для преобразования угловых значений из градусов в радианы
    const double DEG_TO_RAD = M_PI / 180.0;
    float h = bigD / 2 * sin(60 * DEG_TO_RAD); // Высота 6 угольника

    RPArray<MbContour>* arrContours = new RPArray<MbContour>();
    RPArray<MbContour3D>* ptrContours = new RPArray<MbContour3D>();
    MbSolid* pSolid = nullptr;

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            double x = (d + offsets) * n / 2 - d / 2 - i * t - cos(60 * DEG_TO_RAD) * t * j - offsets / 2;
            double y = j * sin(60 * DEG_TO_RAD) * t + t;

            double l1 = sqrt(pow(x, 2) + pow(y, 2));

            if (l1 + d / 2 < bigD / 2 && y < h)
            {
                MbArc* Circle = new MbArc(MbCartPoint(x, y), d / 2); //Внешняя окружность
                MbArc* Circle1 = new MbArc(MbCartPoint(x, y), d / 2 - 2); //Внутренняя окружность

                //Внешняя окружность
                MbContour* arrContourCircle = new MbContour();
                arrContourCircle->AddSegment(Circle);

                //Внутренняя окружность
                MbContour* arrContourCircle1 = new MbContour();
                arrContourCircle1->AddSegment(Circle1);

                arrContours->Add(arrContourCircle);
                arrContours->Add(arrContourCircle1);

                //show(Style(1, RGB(0, 0, 255)), Circle1);

                MbCartPoint3D pnt0(x, 0, l);
                MbCartPoint3D pnt1(x, y, 0);
                MbCartPoint3D pnt2(x, y, l);
                MbCartPoint3D pnt3(x, 0, l + y);
                MbCartPoint3D pnt4(x, -y, l);
                MbCartPoint3D pnt5(x, -y, 0);

                MbLineSegment3D* pLine1 = new MbLineSegment3D(pnt1, pnt2);
                MbArc3D* pLine2 = new MbArc3D(pnt0, pnt2, pnt3, 0, false);
                MbArc3D* pLine3 = new MbArc3D(pnt0, pnt3, pnt4, 0, false);
                MbLineSegment3D* pLine4 = new MbLineSegment3D(pnt4, pnt5);

                MbContour3D* ptrContour = new MbContour3D();

                ptrContour->AddSegment(*pLine1, 1);
                ptrContour->AddSegment(*pLine2, 1);
                ptrContour->AddSegment(*pLine3, 1);
                ptrContour->AddSegment(*pLine4, 1);

                ptrContours->Add(ptrContour);
            }
        }
    }

    MbContour3D* ptrContour1 = new MbContour3D();

    for (int i = 0; i < ptrContours->size(); i++)
        ptrContour1 = ptrContours->GetLast();

    //show(Style(1, RGB(50, 200, 200)), ptrContour1);

    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 1, 0));
    MbSweptData sweptData(*pPlaneXY, *arrContours);

    // Объект с параметрами операции построения тела заметания
    EvolutionValues param;

    // Служебные объекты-именователи для вызова геометрической операции
    MbSNameMaker operNames(ct_CurveEvolutionSolid, MbSNameMaker::i_SideNone, 0);
    MbSNameMaker cNames(ct_CurveSweptSolid, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> contourNames(1, 0, false);
    contourNames.Add(&cNames);
    MbSNameMaker splineNames(ct_CurveSweptSolid, MbSNameMaker::i_SideNone, 0);

    ::EvolutionSolid(sweptData, *ptrContour1, param, operNames, contourNames, splineNames, pSolid);

    MbPlacement3D pl;
    MbAxis3D axisY(pl.GetAxisY());
    pSolid->Rotate(axisY, 90 * DEG_TO_RAD, nullptr);

    c3d::SolidSPtr MainSolid(pSolid);

    // Уменьшение счетчиков ссылок динамических объектов ядра
    ::DeleteItem(pSolid);

    return MainSolid;
}