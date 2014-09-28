/*
 *   tests are written for the whole task...often without using QVERIFY
     because, manually enter an array of 4 * 4 is useless spending time.
 */

#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <iostream>
#include "sort.h"
#include "array.h"


class TestTask : public QObject
{
    Q_OBJECT
public:
    explicit TestTask(QObject *parent = 0) : QObject(parent) {}
private:
    int **array;
    int numberOfColumns;
    int numberOfRows;
    Sort *sort;

private slots:
    void init()
    {
        sort = new Sort;
    }
    void cleanup()
    {
        delete sort;
    }
    void smallArray()
    {
        array = new int*[3];
        for (int i = 0; i < 3; i++)
            array[i] = new int [1];
        array[0][0] = 2;
        array[1][0] = 1;
        array[2][0] = 3;
        sort->sorting(2, array);
        QVERIFY(array[0][0] == 1);
        QVERIFY(array[1][0] == 2);
        QVERIFY(array[2][0] == 3);
        for (int i = 0; i < 3; i++)
            delete []array[i];
        delete []array;

    }
    void normalArray()
    {
        std::cout << "TEST :  normalArray \n";
        array = createArray(5, 6);
        std::cout << "\n array was generated automatically: \n";
        print(array,5,6);
        std::cout << "\n sorting... \n";
        sort->sorting(5 - 1, array);
        print(array,5,6);
        destroy(array, 5);
    }

};
