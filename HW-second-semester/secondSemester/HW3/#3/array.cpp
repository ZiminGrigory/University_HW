#include <iostream>
#include <cstdlib>
#include <time.h>
#include "array.h"

using namespace std;

int **createArray(int numberOfColumns, int numberOfRows)
{
    srand(time(NULL));
    int **array = new int* [numberOfColumns];
    for (int i = 0; i < numberOfColumns; i++)
    {
        array[i] = new int [numberOfRows];
        for (int j = 0; j < numberOfRows; j++)
            array[i][j] = rand()%100; // create array
    }
    return array;
}

void print(int **array, int numberOfColumns, int numberOfRows)
{
    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
            cout << array[j][i] << ' ';
        cout << endl;
    }
}

void destroy(int **array, int numberOfColumns)
{
    for (int i = 0; i < numberOfColumns; i++)
        delete []array[i];
    delete []array;
}
