#pragma once
#include <QWidget>
#include <QString>
#include "ui_calc.h"

namespace Ui {
class Calc;
}

class Calc : public QWidget
{
    Q_OBJECT
    
public:
    explicit Calc(QWidget *parent = 0);
    ~Calc();
protected slots:
    void calcAndPrintAnswer();    
private:
    Ui::Calc *ui;


};
