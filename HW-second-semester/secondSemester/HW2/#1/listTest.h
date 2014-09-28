#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <iostream>
#include "list.h"
#include "onePointerList.h"
#include "twoPointerList.h"

class ListTest : public QObject
{
    Q_OBJECT
public:
    explicit ListTest(QObject *parent = 0) : QObject(parent) {}
protected:
    virtual void create() = 0;
    List *list;
private slots:
    void init()
    {
        create();
    }
    void cleanup()
    {
        delete list;
    }
    void AddElement()
    {
        list->add(5);
        QVERIFY(list->exist(5) == true);
    }
    void multipleAddElement()
    {
        list->add(6);
        list->add(62);
        QVERIFY(list->exist(62) == true);
    }
    void deleteElelement()
    {
        list->add(62);
        list->deleteEl(62);
        QVERIFY(!list->exist(62));
    }
};

class CreateOnePointerList : public ListTest
{
protected:
    void create()
    {
        list = new OnePointerList;
    }
};

class CreateTwoPointerList : public ListTest
{
protected:
    void create()
    {
        list = new TwoPointerList;
    }
};
