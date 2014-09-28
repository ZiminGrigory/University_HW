#include "operator.h"

Operator::Operator(QChar c)
{
    operation = c;
}

void Operator::print()
{
    cout << "( "<<operation.toAscii() <<" ";
    this->leftChild->print();
    this->rightChild->print();
    cout << ") ";
}

double Operator::calculate()
{
    double argFirst = this->leftChild->calculate();
    double argumentSec = this->rightChild->calculate();
    if (operation.toAscii() == '+')
        return argFirst + argumentSec;
    if (operation.toAscii() == '-')
        return argFirst - argumentSec;
    if (operation.toAscii() == '*')
        return argFirst * argumentSec;
    if (operation.toAscii() == '/')
        return  argFirst / argumentSec;
}
