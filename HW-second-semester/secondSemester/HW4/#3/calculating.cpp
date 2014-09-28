#include "calculating.h"



QString Calculating::calculate(int operand1, int operand2, QString operation )
{
    int answer = 0;
    if (operation == "+")
        answer = operand2 + operand1;
    if (operation == "-")
        answer = operand2 - operand1;
    if (operation == "*")
        answer = operand2 * operand1;
    if (operation == "/")
    {
        if (operand1 == 0.0)
        {
            return "00000000";
        }
        else
            answer = operand2 / operand1;
    }
    return QString::number(answer, 'g', 6);
}
