#pragma once
#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "BoobleSort.h"
#include "Comparator.h"
#include <iostream>

class TestSort:public QObject
{
    Q_OBJECT

public:
    explicit TestSort(QObject *parent = 0):QObject(parent){}

private slots:
    void init()
    {
    }

    void cleanup()
    {
    }

    void classIsBigger()
    {
        comparator = new isBigger<int>;
        count = 5;
        array = new int [5];
        array[0]=4;
        array[1]=5;
        array[2]=3;
        array[3]=1;
        array[4]=2;
        object = new BoobleSort<int>;
        object->sorting(comparator,count,array);
        QCOMPARE(array[0],1);
        QCOMPARE(array[1],2);
        QCOMPARE(array[2],3);
        QCOMPARE(array[3],4);
        QCOMPARE(array[4],5);
        delete array;
        delete object;
        delete objectTwo;

    }

    void classIsBiggerSecondTest()
    {
        comparatorTwo = new isBigger<char>;
        count = 5;
        char * charArray = new char [5];
        charArray[0]='e';
        charArray[1]='d';
        charArray[2]='b';
        charArray[3]='c';
        charArray[4]='a';
        objectTwo = new BoobleSort<char>;
        objectTwo->sorting(comparatorTwo,count,charArray);
        QCOMPARE(charArray[0],'a');
        QCOMPARE(charArray[1],'b');
        QCOMPARE(charArray[2],'c');
        QCOMPARE(charArray[3],'d');
        QCOMPARE(charArray[4],'e');
        delete charArray;
        delete comparator;
        delete comparatorTwo;

    }

    void lastTest()
    {
        comparatorThree = new isBigger<double>;
        count = 5;
        double *arrayDouble = new double [5];
        arrayDouble[0]=4.0;
        arrayDouble[1]=5.0;
        arrayDouble[2]=3.0;
        arrayDouble[3]=1.0;
        arrayDouble[4]=2.0;
        objectThree = new BoobleSort<double>;
        objectThree->sorting(comparatorThree,count,arrayDouble);
        QCOMPARE(arrayDouble[0],1.0);
        delete arrayDouble;
        delete objectThree;
        delete comparatorThree;
    }

private:
    BoobleSort<int> *object;
    Comparator<int> *comparator;
    BoobleSort<char> *objectTwo;
    Comparator<char> *comparatorTwo;
    BoobleSort<double> *objectThree;
    Comparator<double> *comparatorThree;
    int *array;
    int count;
};
QTEST_MAIN(TestSort)
