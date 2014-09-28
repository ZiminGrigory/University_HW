#include "heapSort.h"

void buildDown(int *array, int i, int const n) // строим пирамиду удовлетвор€ющую услови€м родитель больше потомковб ошибки листьев не будет, так как мы используем в качестве материала массив. а не дерево
{
    int maxIndex = i;
    int const value = array[i];
    while (true)
    {
        int left = i * 2 + 1;
        if ((left < n) && (array[left] > value))
            maxIndex = left;
        int right = left + 1;
        if ((right < n) && (array[right] > array[maxIndex]))
            maxIndex = right;
        if (maxIndex == i) break;
        array[i] = array[maxIndex]; array[maxIndex] = value;
        i = maxIndex;
    };
}


void HeapSort::sorting(int number, int *array)
{
    for (int i = number; i>=0; --i)
        buildDown(array, i, number);
    while (number > 1)
    {
        number = number - 1;
        int firstElement = array[0];
        array[0] = array[number];
        array[number] = firstElement;
        buildDown(array, 0, number);
    }
}
