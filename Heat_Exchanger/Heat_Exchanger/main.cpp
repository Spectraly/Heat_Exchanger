#include "Heat_Exchanger.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Heat_Exchanger w;
    w.show();
    return a.exec();
}
