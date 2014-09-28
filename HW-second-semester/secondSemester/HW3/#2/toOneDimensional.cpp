#include "toOneDimensional.h"

int *ToOneDimensional:: toOneDimensional(int** array, int dimension)
{
    int index = 0;
    int *returnArray = new int [dimension*dimension];
    int iMain = dimension / 2 + 1;
    int jMain = iMain;
    returnArray[index] = array[iMain][jMain];
    index++;
    if (dimension > 1)
    {
        int firstValue = 1;
        int secondValue = 2;
        for (int k = 1; k <= dimension / 2; k++)
        {
            int j = 1;
            for (j = 1; j <= firstValue; j++)
            {
                returnArray[index] = array[iMain][jMain + j];
                index++;
            }
            jMain = jMain + j - 1;
            for (j = 1; j <= firstValue; j++)
            {
                returnArray[index] = array[iMain - j][jMain];
                index++;
            }
            iMain = iMain - j + 1;
            for (j = 1; j <= secondValue; j++)
            {
                returnArray[index] = array[iMain][jMain - j];
                index++;
            }
            jMain = jMain - j + 1;
            for (j = 1; j <= secondValue; j++)
            {
                returnArray[index] = array[iMain + j][jMain];
                index++;
            }
            iMain = iMain + j - 1;
            firstValue = firstValue + 2;
            secondValue = secondValue + 2;
        }
    }

    for (int i = 2; i <=dimension; i++)
    {
        returnArray[index] = array[dimension][i];
        index++;
    }
    for (int i = 1; i <= dimension; i++)
        delete []array[i];
    delete []array;
    return returnArray;

}
