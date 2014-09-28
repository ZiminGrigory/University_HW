#include "operand.h"

Operand::Operand(double numeric)
{
    value = numeric;
}

void Operand::print()
{
    cout << value << ' ';
}

double Operand::calculate()
{
    return value;
}
