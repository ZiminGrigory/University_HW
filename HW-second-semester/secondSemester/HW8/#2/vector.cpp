#include "vector.h"
#include <iostream>
Vector::Vector(unsigned int n): dimension(n)
{
    if (dimension >= 1)
    {
        array = new double [dimension];
        for (int unsigned i = 0; i < dimension; i++)
            array[i] = 0.0;
    }
    else throw Overflow();
}

Vector::Vector(const Vector &vector)
{
    this->dimension = vector.dimension;
    this->array = new double [this->dimension];
    for (int unsigned i = 0; i < dimension; i++)
        this->array[i] = vector.array[i];
}

void Vector::setValue(int index, double value)
{
    if (index >= 0 && index < this->dimension)
    {
        array[index] = value;
    }
    else throw Overflow();

}


Vector::~Vector()
{
    delete []array;
}

void Vector::operator +=(const Vector &vector)
{
    if (vector.dimension == this->dimension)
    {
        for (int unsigned i = 0; i < dimension; i++)
            this->array[i] = this->array[i] + vector.array[i];
    }
    else throw Overflow();

}

void Vector::operator -=(const Vector &vector)
{
    if (vector.dimension == this->dimension)
    {
        for (int unsigned i = 0; i < dimension; i++)
            this->array[i] = this->array[i] - vector.array[i];
    }
    else throw Overflow();

}

double Vector::operator *=(const Vector &vector)
{
    if (vector.dimension == this->dimension)
    {
        double answer = 0.0;
        for (int unsigned i = 0; i < dimension; i++)
            answer += this->array[i] * vector.array[i];
        return answer;
    }
    else throw Overflow();

}

bool Vector::isNullVector()
{
    for (int unsigned i = 0; i < dimension; i++)
        if (array[i] != 0.0)
            return false;
    return true;
}

double Vector::getCoordinate(int index)
{
    return array[index];
}

void Vector::setDimension(unsigned int value)
{
    this->dimension = value;
}




