#include <fstream>
#include <iostream>
#include "printInFile.h"

using namespace std;

void PrintInFile::print(int *array, int dimension)
{
    ofstream output;
    output.open("output.txt");
    for (int i = 0; i < dimension * dimension; i++)
        output << array[i] << ' ';
    delete []array;
    output.close();
}
