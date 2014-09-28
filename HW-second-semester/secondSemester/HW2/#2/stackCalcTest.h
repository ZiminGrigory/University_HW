#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <iostream>
#include "stack.h"
#include "stackArray.h"
#include "stackPointer.h"
#include "stackCalc.h"

class StackCalcTest : public QObject
{
    Q_OBJECT
public:
    explicit StackCalcTest(QObject *parent = 0) : QObject(parent) {}
private:
    Stack *stack;
    string str;
private slots:
    void init()
    {
        stack = new StackPointer;
    }
    void cleanup()
    {
        delete stack;
    }
    void easyExpression()
    {
        str = "4 2 +";
        QVERIFY(result(*stack, str) == 6);
    }

    void expression()
    {
        str = "4 2 4 + - -4 *";
        QVERIFY(result(*stack, str) == 8);
    }

    void hardExpression()
    {
        str = "4.25 2.5 -0.25 + - 4 *";
        QVERIFY(result(*stack, str) == 8);
    }
};
