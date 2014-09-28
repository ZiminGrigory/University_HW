#include "boobleSort.h"

void BoobleSort::sorting(int number, int *array)
{
    for (int i = number - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if(array[j] > array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

