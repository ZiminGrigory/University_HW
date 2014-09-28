#include "calc.h"
#include "ui_calc.h"

Calc::Calc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calc)
{
    ui->setupUi(this);
}

Calc::~Calc()
{
    delete ui;
}


void Calc::calcAndPrintAnswer()
{
    int operandFirst = ui->Operand1->value();
    int operandSecond = ui->operand2->value();
    QString operation = ui->operation->currentText();
    int answer;
    if (operation == "+")
        answer = operandFirst + operandSecond;
    if (operation == "-")
        answer = operandFirst - operandSecond;
    if (operation == "*")
        answer = operandFirst * operandSecond;
    if (operation == "/")
    {
        if (operandSecond == 0)
        {
            ui->answer->setText("mistake");
            return;
        }
        else
            answer = operandFirst / operandSecond;
    }
    QString answerStr = QString::number(answer);
    ui->answer->setText(answerStr);

}
