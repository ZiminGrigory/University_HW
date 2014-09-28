#include "stackArray.h"
#include <iostream>
using namespace std;

StackArray::StackArray()
{
    cardinality = 10;
    stackAr = new double [cardinality];
    number = 0;
}
bool StackArray::isEmpty() const
{
    return number == NULL;
}

void StackArray :: push (double value)
{
    if (number < cardinality)
        stackAr[number] = value;
    else
    {
        cardinality = cardinality + 10;
        double *temp = new double [cardinality];
        for (int i=0; i < number; i++)
            temp[i] = stackAr[i];
        delete [] stackAr;
        stackAr = temp;
    }
    number++;
}

double StackArray::top() const
{
    if (isEmpty())
    {
        cout << "Stack is empty :(" << endl;
        return 'x';
    }
    else
        return stackAr[number - 1];
}

double StackArray::pop()
{
    if (isEmpty())
    {
        cout << "Warning! Stack is empty!!!\n";
        return 'x';
    }
    double result = top();
    number--;
    return result;
}

StackArray::~StackArray()
{
    delete []stackAr;
}
