#include <iostream>
#include <cctype>
#include "stackCalc.h"
#include <string>
using namespace std;

bool isNumber(string str, int n)
{
    char test = 'd';
    char test2 = 'd';
    test = str[n];
    if (isdigit(test))
        return true;
    else
        if (test != '-')
            return false;
        else
        {
            test2 = str[n+1];
            if (isdigit(test2))
                return true;
        }
    return false;
}

int toInt(char c)
{
    return c - '0';
}

bool isDot(char c)
{
    return (c == '.');
}


double getOperand(string str, int &n)
{
    double power = 1;
    double negativePower = 0.1;
    double answer = 0;
    int sign = 1;
    bool existDot = false;
    if (str[n] == '-')
    {
        sign *= -1;
        n++;
    }
    while (str[n]!= ' ' && n != str.size())
    {
        if (!isDot(str[n]) && !existDot)
        {
            answer = answer * power + toInt(str[n]);
            power = 10;
        }
        if (isDot(str[n]))
            existDot = 1;
        if (!isDot(str[n]) && existDot)
        {
            answer = answer + toInt(str[n]) * negativePower;
            negativePower /= 10;
        }
        n++;
    }
    n--;
    return answer * sign;
}

double calculate(double operand1, double operand2, char operation)
{
    switch (operation)
    {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        default: if (operand2 == 0)
                    cout << "division by zero";
                else
                    return operand1 / operand2;
    }
}

double result(Stack &stack, string str)
{
    double operand = 1;
    double operand1 = 1;
    double operand2 = 1;
    char operation = 'f';
    int n = -1;
    while (n != str.size())
    {
        n++;
        if (isNumber(str, n))
        {
            operand = getOperand(str, n);
            stack.push(operand);
            n++;
        }
        else
        {
            operand2 = stack.pop();
            operand1 = stack.pop();
            operation = str[n];
            operand = calculate(operand1, operand2, operation);
            stack.push(operand);
            n++;
        }

    }
    return stack.pop();
}
