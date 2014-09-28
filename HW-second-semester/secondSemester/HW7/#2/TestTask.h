#ifndef TESTTASK_H
#define TESTTASK_H

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "UniqueList.h"

class TestTask:public QObject
{
    Q_OBJECT

public:
    explicit TestTask(QObject *parent = 0):QObject(parent){}

private slots:

    void init()
    {
        list = new UniqueList<double>();
    }

    void cleanup()
    {
        delete list;
    }

    void testAdd()
    {
        list->addElement(10.0);
        QVERIFY(list->exist(10.0));
        try
        {
            list->addElement(10.0);
        }
        catch (UniqueList<double>::RepeatAdd)
        {
            test = true;
        }
        QCOMPARE(test, true);
    }

    void testRemove()
    {
        try
        {
            list->deleteElement(10214124.9);
        }
        catch (UniqueList<double>::ItemHaveNotExist)
        {
            test = true;
        }
        QCOMPARE(test, true);
    }

private:
    bool test;
    UniqueList<double> *list;
};

QTEST_MAIN(TestTask)
#endif // TESTTASK_H
