#pragma once
#include "stack.h"

struct StackElement;

class StackPointer : public Stack
{
public:
    StackPointer();
    virtual ~StackPointer();
    virtual void push(double value);
    virtual double top() const;
    virtual double pop();
    virtual bool isEmpty() const;

protected:
    StackElement* head;
    int number;
};
