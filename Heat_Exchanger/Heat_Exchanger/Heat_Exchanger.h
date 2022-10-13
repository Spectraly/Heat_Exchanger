#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Heat_Exchanger.h"

class Heat_Exchanger : public QMainWindow
{
    Q_OBJECT

public:
    Heat_Exchanger(QWidget *parent = nullptr);
    ~Heat_Exchanger();

private:
    Ui::Heat_ExchangerClass ui;
};
