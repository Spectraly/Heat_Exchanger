#include "BuildMathModel.h"
using namespace BuildMathModel;

SPtr<MbSolid> ParametricModelCreator::TubeBundles(BuildParams params)
{
   


    float DV = params.diam.toDouble();//Наружный диаметр
    float DN = DV + DV / 100 * 8; //Внутренний диаметр
    float B1 = 4; //Левый бортик
    float B2 = 8; //Правый бортик
    float D = DV - B1;
    float R = D / 2;
    float L = 3000; //Правый бортик


    float d = params.d.toDouble(); // D трубы
    float bigD = DV - (DV / 100 * 9); // D проверочной окружности
    float offsets;
    if (d == 20)
         offsets = 6; //расстояние между окружностями
    else
         offsets = 7; //расстояние между окружностями

    float t = (d + offsets); // Шаг между центрами
    float n0 = floor(bigD / t); // Кол-во отверстий на 0 ряду
    float n = n0 + 3; // Кол-во отверстий на 1 ряду
    float h = bigD / 2 * sin(60 * M_PI / 180); // Высота 6 угольника

    // Множитель для преобразования угловых значений из градусов в радианы
    const double DEG_TO_RAD = M_PI / 180.0;
    MbSolid* pSolid = nullptr;
    RPArray<MbContour>* ptrContours = new RPArray<MbContour>();

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            double x = (d + offsets) * n / 2 - d / 2 - i * t - cos(60 * M_PI / 180) * t * j - offsets / 2;
            double y = j * sin(60 * M_PI / 180) * t + t;

            double l = sqrt(pow(x, 2) + pow(y, 2));

            if (l + d / 2 < bigD / 2 && y < h)
            {
                MbArc* Circle = new MbArc(MbCartPoint(x, y), d / 2);
                MbContour* ptrContour = new MbContour();
                ptrContour->AddSegment(Circle);
                ptrContours->Add(ptrContour);

                MbArc* Circle1 = new MbArc(MbCartPoint(x, y), d / 2 - 2);
                MbContour* ptrContour1 = new MbContour();
                ptrContour1->AddSegment(Circle1);
                ptrContours->Add(ptrContour1);

                MbArc* Circle2 = new MbArc(MbCartPoint(x, -y), d / 2 );
                MbContour* ptrContour2 = new MbContour();
                ptrContour2->AddSegment(Circle2);
                ptrContours->Add(ptrContour2);

                MbArc* Circle3 = new MbArc(MbCartPoint(x, -y), d / 2 - 2);
                MbContour* ptrContour3 = new MbContour();
                ptrContour3->AddSegment(Circle3);
                ptrContours->Add(ptrContour3);

            }
        }

    }


    MbPlane* pPlaneXY = new MbPlane(MbCartPoint3D(0, 0, 0), MbCartPoint3D(1, 0, 0), MbCartPoint3D(0, 1, 0));


    MbSNameMaker operNames(1, MbSNameMaker::i_SideNone, 0);
    PArray<MbSNameMaker> cNames(0, 1, false);
    MbVector3D dir(0, 0, -1);
    ExtrusionValues extrusionParam(params.l.toDouble(), 0);
    MbSweptData sweptData(*pPlaneXY, *ptrContours);


    ::ExtrusionSolid(sweptData, dir, nullptr, nullptr, false, extrusionParam, operNames, cNames, pSolid);

    c3d::SolidSPtr MainSolid(pSolid);

    ::DeleteItem(pSolid);

    return MainSolid;

}