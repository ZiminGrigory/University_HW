#pragma once
#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include <iostream>
#include "Task6-2.h"

using namespace std;


class TaskTest:public QObject
{
    Q_OBJECT

public:
    explicit TaskTest(QObject *parent = 0):QObject(parent){}

private slots:
    void TestTask()
    {
        try
        {
            object = new TestClassFirst;
        }
        catch (Exception &)
        {
            cout << "handling of exceptions" << endl;
        }
    }
    void cleanup()
    {
        delete object; //it causes a heap, but also removed as it ought be
    }
private:
    TestClassFirst *object;
};
