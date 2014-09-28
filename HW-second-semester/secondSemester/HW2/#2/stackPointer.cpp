#include "stackPointer.h"
#include <iostream>
using namespace std;

struct StackElement
{
    double value;
    StackElement *next;
};

StackPointer::StackPointer()
{
    head = NULL;
    number = 0;
}

StackElement *createStackElement(double value)
{
    StackElement *stack = new StackElement;
    stack->next = NULL;
    stack->value = value;
    return stack;
}


bool StackPointer::isEmpty() const
{
    return head == NULL;
}

void StackPointer :: push (double value)
{
    StackElement *temp = createStackElement(value);
    temp->next = head;
    head = temp;
}

double StackPointer::top() const
{
    if (isEmpty())
    {
        cout << "Stack is empty :(" << endl;
        return 'x';
    }
    else
        return head->value;
}

double StackPointer::pop()
{
    if (isEmpty())
    {
        cout << "Warning! Stack is empty!!!\n";
    }
    double result = top();
    StackElement *tmp = head;
    head = head->next;
    delete tmp;
    return result;
}

StackPointer::~StackPointer()
{
    StackElement *temp = head;
    while(temp != NULL)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
}
