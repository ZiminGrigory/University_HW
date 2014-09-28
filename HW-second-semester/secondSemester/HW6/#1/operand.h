#ifndef OPERAND_H
#define OPERAND_H
#include "node.h"

class Operand : public Node
{
public:
    Operand(double numeric);
    void print();
    double calculate();
private:
    double value;
};

#endif // OPERAND_H
