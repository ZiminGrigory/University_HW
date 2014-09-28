/*
 *   tests are written only to the main function in the problem.
 *   I did not write test for output of a 1-dimensional array.
 */

#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <iostream>
#include "toOneDimensional.h"


class TestToOneDimension : public QObject
{
    Q_OBJECT
public:
    explicit TestToOneDimension(QObject *parent = 0) : QObject(parent) {}
private:
    int **createArray(int dimension)
    {
        int **array = new int* [dimension + 1];
        for (int i = 1; i <= dimension; i++)
        {
            array[i] = new int [dimension + 1];
            for (int j = 1; j <= dimension; j++)
                array[i][j] = (i - 1) * dimension + j; // create array
        }
        return array;
    }
    int **array;
    ToOneDimensional *method;

private slots:
    void init()
    {
        method = new ToOneDimensional;
    }
    void cleanup()
    {
        delete method;
    }
    void smallArray()
    {
        array = createArray(1);
        int *arraySec = method->toOneDimensional(array, 1);
        QVERIFY(arraySec[0] == 1);
        delete arraySec;
    }
    void normalArray()
    {
        array = createArray(3);
        int *arraySec = method->toOneDimensional(array, 3);
        QVERIFY(arraySec[0] == 5);
        QVERIFY(arraySec[1] == 6);
        QVERIFY(arraySec[2] == 3);
        QVERIFY(arraySec[3] == 2);
        QVERIFY(arraySec[4] == 1);
        QVERIFY(arraySec[5] == 4);
        QVERIFY(arraySec[6] == 7);
        QVERIFY(arraySec[7] == 8);
        QVERIFY(arraySec[8] == 9);
        delete arraySec;
    }

};
