#ifndef VECTOR_H
#define VECTOR_H

#pragma once

/**
  *
  *  class implements a vector.
  *  with the use of functions to work with vectors, implementation konstruktorv copy (explicitly).
  *  Working with the coordinates of type double. The number of coordinates specified by the user.
  */
class Overflow{};

class Vector
{
public:
    Vector(unsigned int n);
    Vector(const Vector &vector); //copy constuctor
    void setValue(int index, double value);
    ~Vector();
    void operator+=(const Vector &vector);
    void operator-=(const Vector &vector);
    double operator*=(const Vector &vector);// *=scalar product
    bool isNullVector();
    double getCoordinate(int index);
private:
    double *array;
    unsigned int dimension;
    void setDimension(unsigned int value);
};
#endif // VECTOR_H
