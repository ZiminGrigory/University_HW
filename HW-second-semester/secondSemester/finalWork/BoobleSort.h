#include <iostream>
#pragma once
#include "Comparator.h"
/**
  *tamplate class implements the bubble sort
  *The method takes an array of values ??of any type,
  *size of the array, and a comparator,
  *which allows them to compare.
  *The result returns the array after sorting.
*/

template <typename T>
class BoobleSort
{
public:
    BoobleSort(){}
    ~BoobleSort(){}
    void sorting(Comparator<T> *comparator,int count,T *array)
    {
        for (int i = count - 1; i > 0; i--)
            for (int j = 0; j < i; j++)
            {
                if(comparator->compare(array[j], array[j + 1]))
                {
                    T tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                }
            }
    }

};

