#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <iostream>
#include "sort.h"
#include "quickSort.h"
#include "heapSort.h"
#include "boobleSort.h"
class SortTest : public QObject
{
    Q_OBJECT
public:
    explicit SortTest(QObject *parent = 0) : QObject(parent) {}
protected:
    virtual void create() = 0;
    Sort *sort;
    int a[10];

private slots:
    void init()
    {
        create();
    }
    void cleanup()
    {
        delete sort;
    }
    void descendingTest()
    {
        int j = 1;
        for (int i = 9; i >= 0; i--)
        {
            a[i] = j;
            j++;
        }
        sort->sorting(10, a);
        for (int i = 0; i <= 9; i++)
            QVERIFY(a[i] == i+1);
    }
    void almostOrdered()
    {
        a[0] = 1;
        a[1] = 3;
        a[2] = 5;
        a[3] = 2;
        a[4] = 4;
        a[5] = 6;
        a[6] = 8;
        a[7] = 7;
        a[8] = 9;
        a[9] = 10;
        sort->sorting(10, a);
        for (int i = 0; i <= 9; i++)
            QVERIFY(a[i] == i+1);
    }
    void arbitrary()
    {
        a[0] = 10;
        a[1] = 7;
        a[2] = 3;
        a[3] = 6;
        a[4] = 5;
        a[5] = 4;
        a[6] = 2;
        a[7] = 1;
        a[8] = 9;
        a[9] = 8;
        sort->sorting(10, a);
        for (int i = 0; i <= 9; i++)
            QVERIFY(a[i] == i+1);
    }
};

class TestBoobleSort : public SortTest
{
protected:
    void create()
    {
        sort = new BoobleSort;
    }
};

class TestHeapSort : public SortTest
{
protected:
    void create()
    {
        sort = new HeapSort;
    }
};

class TestQuickSort : public SortTest
{
protected:
    void create()
    {
        sort = new QuickSort;
    }
};
