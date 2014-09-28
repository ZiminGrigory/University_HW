#ifndef OPERATOR_H
#define OPERATOR_H
#include "node.h"

class Operator : public Node
{
public:
    Operator(QChar c);
    void print();
    double calculate();
private:
    QChar operation;
};

#endif // OPERATOR_H
