#include <iostream>
#include "printInConsole.h"

using namespace std;

void PrintInConsole::print(int* array, int dimension)
{
    for (int i = 0; i < dimension * dimension; i++)
        cout << array[i] << ' ';
    delete []array;
}
