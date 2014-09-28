#pragma once
#include <QSignalMapper>
#include <QMainWindow>
#include "calculating.h"

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

public slots:
    void pressedDigit(int digit);
    void choseOp(QString operat);
    void pressedEqual();

private:
    Calculating calc;
    QSignalMapper *digitMapper;
    QSignalMapper *opMapper;
    Ui::Calculator *ui;
    bool pressedDot;
    double operand1;
    double operand2;
    QString operation;
    bool secondOperand;
    bool operationPressed;
    double power;
    double negativePower;
};
