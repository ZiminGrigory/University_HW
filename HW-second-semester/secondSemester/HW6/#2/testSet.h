#pragma once
#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "set.h"
#include <iostream>

class TestSet:public QObject
{
    Q_OBJECT

public:
    explicit TestSet(QObject *parent = 0):QObject(parent){}

private slots:
    void init()
    {
        object = new Set<int>;
        object2 = new Set<int>;
        object3 = new Set<int>;
    }

    void cleanup()
    {
        delete object;
        delete object2;
        delete object3;
    }

    void TestIsEmpty()
    {
        QCOMPARE(object->isEmpty(), true);
    }

    void TestSearch()
    {
        QVERIFY(!object->search(4));
    }

    void TestAddElement()
    {
        object->addElement(4);
        object->addElement(5);
        object->addElement(6);
        object->addElement(7);
        QVERIFY(object->search(7));
    }

    void TestDelValue()
    {
        object->addElement(4);
        object->addElement(5);
        object->deleteElement(4);
        QVERIFY(!object->search(4));
    }

    void TestIntersect()
    {
        object3->addElement(5);
        object3->addElement(6);
        object3->addElement(8);
        object2->addElement(3);
        object2->addElement(4);
        object2->addElement(8);
        object->intersectionOfSets(object2,object3);
        QVERIFY(object->search(8));
    }

    void TestSetUnion()
    {
        object2->addElement(1);
        object2->addElement(3);
        object3->addElement(2);
        object3->addElement(4);
        object->setUnion(object2, object3);
        QVERIFY(object->search(1) && object->search(2) && object->search(3) && object->search(4));
    }

private:
    Set<int> *object;
    Set<int> *object2;
    Set<int> *object3;
};
QTEST_MAIN(TestSet)
