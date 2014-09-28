#ifndef TESTTASK_H
#define TESTTASK_H
#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "vector.h"
#include <iostream>

class TestTask:public QObject
{
    Q_OBJECT

public:
    explicit TestTask(QObject *parent = 0):QObject(parent){}

private slots:
    void init()
    {
        vectorFirst = NULL;
    }
    void cleanup()
    {
        delete vectorFirst;
    }
    void firstPlusTest()
    {
        vectorFirst = new Vector(2);
        vectorFirst->setValue(0,1);
        Vector vector(2);
        vector.setValue(1,1);
        (*vectorFirst) += vector;
        QCOMPARE(vectorFirst->getCoordinate(0),1.0);
        QCOMPARE(vectorFirst->getCoordinate(1),1.0);

    }
    void secondPlusTest()
    {
        vectorFirst = new Vector(2);
        vectorFirst->setValue(0,1);
        Vector vector(3);
        try
        {
            (*vectorFirst) += vector;
        }
        catch (Overflow)
        {
            QCOMPARE(1,1);
        }
    }

    void firstMinusTest()
    {
        vectorFirst = new Vector(2);
        vectorFirst->setValue(0,1);
        vectorFirst->setValue(1,1);
        Vector vector(*vectorFirst);
        (*vectorFirst) -= vector;
        QCOMPARE(vectorFirst->isNullVector(), true);

    }

    void secondMinusTest()
    {
        vectorFirst = new Vector(2);
        vectorFirst->setValue(0,1);
        vectorFirst->setValue(1,1);
        Vector vector(3);
        try
        {
            (*vectorFirst) -= vector;
        }
        catch (Overflow)
        {
            QCOMPARE(1,1);
        }
    }

    void firstScalarProductTest()
    {
        vectorFirst = new Vector(2);
        vectorFirst->setValue(0,1);
        vectorFirst->setValue(1,1);
        Vector vector(*vectorFirst);
        QCOMPARE((*vectorFirst)*= vector, 2.0);

    }

    void secondScalarProductTest()
    {
        vectorFirst = new Vector(2);
        vectorFirst->setValue(0,1);
        vectorFirst->setValue(1,1);
        Vector vector(3);
        try
        {
            QCOMPARE((*vectorFirst)*= vector, 2.0);
        }
        catch (Overflow)
        {
            QCOMPARE(1,1);
        }
    }

    void isNullTest()
    {
        vectorFirst = new Vector(2);
        QVERIFY(vectorFirst->isNullVector());

    }

    void copyTest()
    {
        Vector firstVector(2);
        firstVector.setValue(0,1);
        firstVector.setValue(1,1);
        Vector secondVector(firstVector);
        secondVector.setValue(0,2);
        QVERIFY(firstVector.getCoordinate(0) != secondVector.getCoordinate(0));

    }

private:
    Vector *vectorFirst;
};
#endif // TESTTASK_H
