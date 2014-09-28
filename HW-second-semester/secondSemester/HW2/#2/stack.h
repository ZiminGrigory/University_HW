#pragma once

class Stack
{
public:
    virtual void push(double value) = 0;
    virtual double top() const = 0;
    virtual double pop() = 0;
    virtual bool isEmpty() const = 0;
    virtual ~Stack()
    {
    }
};
