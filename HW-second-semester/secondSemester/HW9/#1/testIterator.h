#pragma once
#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "rbtree.h"
#include <iostream>

class TestIterator:public QObject
{
    Q_OBJECT

public:
    explicit TestIterator(QObject *parent = 0):QObject(parent){}

private slots:
    void init()
    {
        tree = new RBTree<int>;
    }

    void cleanup()
    {
        delete tree;
    }

    void testIsEmpty()
    {
        RBTree<int>::Iterator iterator(tree);
        QCOMPARE(iterator.hasNext(), false);
    }

    void testAdd()
    {
        RBTree<int>::Iterator iterator(tree);
        iterator.add(1);
        iterator.add(2);
        iterator.add(3);
        iterator.add(4);
        iterator.setIndexToOne();
        QCOMPARE(iterator.next(), 1);
        QCOMPARE(iterator.next(), 2);
        QCOMPARE(iterator.next(), 3);
        QCOMPARE(iterator.next(), 4);
    }

    void deleteTest()
    {
        RBTree<int>::Iterator iterator(tree);
        iterator.add(1);
        iterator.add(2);
        iterator.add(3);
        iterator.add(4);
        iterator.setIndexToOne();
        iterator.remove();
        QCOMPARE(iterator.next(), 2);
        iterator.remove();
        QCOMPARE(iterator.next(), 4);
    }


private:
    RBTree<int> *tree;
};
