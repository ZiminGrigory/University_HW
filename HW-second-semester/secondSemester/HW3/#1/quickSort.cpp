#include "quickSort.h"

void swap(int &operand1, int &operand2)
{
    int temp = operand1;
    operand1 = operand2;
    operand2 = temp;
}

void QuickSort::sorting(int number, int *array)
{
    int i = 0;
    int j = number;
    int basicAl = array[number / 2];
    do
    {
        while (array[i] < basicAl)
            i = i + 1;
        while (array[j] > basicAl)
            j = j - 1;
        if (i <= j)
        {
            swap(array[i], array[j]);
            i = i + 1;
            j = j - 1;
        }
    }
   while (i <= j);
   if (j > 0)
        sorting(j, array);
   if (number > i)
        sorting(number - i, array + i);
}
