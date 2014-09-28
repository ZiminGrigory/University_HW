#ifndef CALCULATOR_H
#define CALCULATOR_H
#pragma once
#include "basecalculator.h"

class Calculator : public BaseCalculator
{
public:
    double calculator(Tree *&tree);
};

class Printer : public Calculator
{
public:
    void print(Tree *&tree, TreeNode *&node);
};
#endif // CALCULATOR_H
