#include "Sort.h"

void swap(int *&operand1, int *&operand2)
{
    int *temp = operand1;
    operand1 = operand2;
    operand2 = temp;
}

void Sort::sorting(int numberOfColumns, int **array)
{
    int i = 0;
    int j = numberOfColumns;
    int basicAl = array[numberOfColumns / 2][0];
    do
    {
        while (array[i][0] < basicAl)
            i = i + 1;
        while (array[j][0] > basicAl)
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
   if (numberOfColumns > i)
        sorting(numberOfColumns - i, array + i);
}
