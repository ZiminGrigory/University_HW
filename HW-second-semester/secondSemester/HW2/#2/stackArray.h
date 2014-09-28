#pragma once
#include "stack.h"


class StackArray : public Stack
{
public:
    StackArray();
    virtual ~StackArray();
    virtual void push(double value);
    virtual double top() const;
    virtual double pop();
    virtual bool isEmpty() const;
protected:
    double* stackAr;
    int number;
private:
    int cardinality;
};
