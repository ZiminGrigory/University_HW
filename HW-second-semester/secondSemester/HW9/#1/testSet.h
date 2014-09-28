#pragma once
#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "bag.h"
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
    }

    void cleanup()
    {
        delete object;
    }

    void testIsEmpty()
    {
        QCOMPARE(object->isEmpty(), true);
    }

    void testSearch()
    {
        QVERIFY(!object->search(4));
    }

    void testAddElement()
    {
        object->addElement(1);
        object->addElement(3);
        object->addElement(5);
        object->addElement(4);
        object->addElement(8);
        object->addElement(7);
        object->addElement(6);
        object->addElement(9);
        object->addElement(12);
        object->addElement(17);
        object->addElement(15);
        object->addElement(10);
        object->addElement(14);
        QVERIFY(object->search(4));
        QVERIFY(object->search(5));
        QVERIFY(object->search(6));
        QVERIFY(object->search(7));
        QVERIFY(object->search(8));
    }

    void testMultiAdd()
    {
        object->addElement(4);
        object->addElement(4);
        object->addElement(4);
        QVERIFY(object->searchCount(4) == 3);
    }

    void testMultiElementRemove()
    {
        object->addElement(4);
        object->addElement(4);
        object->addElement(4);
        object->deleteElement(4);
        QVERIFY(object->searchCount(4) == 2);
    }

    void easyDeleteEl() //red leaf
    {
        object->addElement(1);
        object->addElement(3);
        object->addElement(5);
        object->addElement(4);
        object->addElement(8);
        object->addElement(7);
        object->addElement(6);
        object->addElement(9);
        object->addElement(12);
        object->addElement(17);
        object->addElement(15);
        object->addElement(10);
        object->addElement(14);
        object->deleteElement(10);
        QVERIFY(object->searchCount(10) == false);
    }

    void easyDelete2El() //red parent of leaf
    {
        object->addElement(1);
        object->addElement(3);
        object->addElement(5);
        object->addElement(4);
        object->addElement(8);
        object->addElement(7);
        object->addElement(6);
        object->addElement(9);
        object->addElement(12);
        object->addElement(17);
        object->addElement(15);
        object->addElement(10);
        object->addElement(14);
        object->deleteElement(6);
        QVERIFY(object->searchCount(6) == false);
    }

    void deleteEl() //swaped-element or deleted-element is black
    {
        object->addElement(1);
        object->addElement(3);
        object->addElement(5);
        object->addElement(4);
        object->addElement(8);
        object->addElement(7);
        object->addElement(6);
        object->addElement(9);
        object->addElement(12);
        object->addElement(17);
        object->addElement(15);
        object->addElement(10);
        object->addElement(14);
        object->deleteElement(3);
        QVERIFY(object->searchCount(3) == false);
    }



private:
    Set<int> *object;
};
