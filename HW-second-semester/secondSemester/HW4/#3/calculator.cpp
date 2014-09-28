#include <QSignalMapper>
#include "calculator.h"
#include "ui_calculator.h"


enum
{
    dot = 10
};

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    power = 10;
    negativePower = 0.1;
    operand1 = 0;
    operand2 = 0;
    operation = 'e';
    operationPressed = false;
    secondOperand = false;
    pressedDot = false;
    ui->setupUi(this);
    digitMapper = new QSignalMapper (this);

    connect(ui->digit0, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->digit0, 0);
    connect(ui->digit1, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->digit1, 1);
    connect(ui->digit2, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->digit2, 2);
    connect(ui->digit3, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->digit3, 3);
    connect(ui->digit4, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->digit4, 4);
    connect(ui->digit5, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->digit5, 5);
    connect(ui->digit6, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->digit6, 6);
    connect(ui->digit7, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->digit7, 7);
    connect(ui->digit8, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->digit8, 8);
    connect(ui->digit9, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->digit9, 9);
    connect(ui->dot, SIGNAL(clicked()), digitMapper, SLOT(map()));
    digitMapper->setMapping(ui->dot, 10); //not to create a separate connect
    connect(digitMapper, SIGNAL(mapped(int)),
            this, SLOT(pressedDigit(int)));

    opMapper = new QSignalMapper (this);

    connect(ui->multiplicate, SIGNAL(clicked()), opMapper, SLOT(map()));
    opMapper->setMapping(ui->multiplicate, "*");
    connect(ui->division, SIGNAL(clicked()), opMapper, SLOT(map()));
    opMapper->setMapping(ui->division, "/");
    connect(ui->plus, SIGNAL(clicked()), opMapper, SLOT(map()));
    opMapper->setMapping(ui->plus, "+");
    connect(ui->minus, SIGNAL(clicked()), opMapper, SLOT(map()));
    opMapper->setMapping(ui->minus, "-");
    connect(ui->C, SIGNAL(clicked()), opMapper, SLOT(map()));
    opMapper->setMapping(ui->C, "C");

    connect(opMapper, SIGNAL(mapped(QString)),
            this, SLOT(choseOp(QString)));

    connect(ui->equal, SIGNAL(clicked()), this ,SLOT(pressedEqual()));
}

bool isDot(int digit)
{
    return (digit == dot);
}
bool dotPressedFirst(int digit, bool pressedDot)
{
    return (isDot(digit) && !pressedDot);
}

bool isIntegerPart(int digit, bool pressedDot)
{
    return (!isDot(digit) && !pressedDot);
}

bool isFractionalPart(int digit, bool pressedDot)
{
    return (!isDot(digit) && pressedDot);
}

void Calculator::pressedDigit(int digit)
{
    if (dotPressedFirst(digit, pressedDot))
        pressedDot = true;
    if (isIntegerPart(digit, pressedDot))
        operand1 = operand1* power +  digit;

    if (isFractionalPart(digit, pressedDot))
    {
        operand1 = operand1 + (negativePower * digit);
        negativePower /= 10;
    }
    ui->lcdNumber->display(operand1);
}

void Calculator::choseOp(QString operat)
{
    if (operationPressed && operat != "C")
    {
        operationPressed = false;
        QString answer = "";
        answer = calc.calculate(operand1, operand2, operation);
        if (answer != "00000000")
            operand1 = QString(answer).toDouble(0);
        else
        {
            ui->lcdNumber->display(QString("00000000"));
            return;
        }
        operand2 = 0;
    }
    if (!operationPressed && operat != "C")
    {
        operationPressed = true;
        operand2 = operand1;
        operand1 = 0;
        negativePower = 0.1;
        operation = operat;
    }
    else if (operat == "C")
    {
        if(pressedDot && operand1 != 0.0 && negativePower != 0.1)
        {
            negativePower *= 10;
            operand1 /= negativePower;
            operand1 = int(operand1 / 10) * negativePower * 10;
        }
        else if (pressedDot && negativePower == 0.1)
            pressedDot = false;

        if(!pressedDot && operand1 != 0.0)
            operand1 = int(operand1 / 10);
        ui->lcdNumber->display(operand1);
    }
}

void Calculator::pressedEqual()
{
    QString answer = "";
    answer = calc.calculate(operand1, operand2, operation);
    if (answer != "00000000")
        ui->lcdNumber->display(QString(answer).toDouble(0));
    else
    {
        ui->lcdNumber->display(QString("00000000"));
        return;
    }
    power = 10;
    negativePower = 0.1;
    operand1 = 0;
    operand2 = 0;
    operation = 'e';
    operationPressed = false;
    secondOperand = false;
    pressedDot = false;
}


Calculator::~Calculator()
{
    delete ui;
}
