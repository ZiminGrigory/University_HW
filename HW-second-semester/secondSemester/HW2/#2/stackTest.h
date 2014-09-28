#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <iostream>
#include "stack.h"
#include "stackArray.h"
#include "stackPointer.h"

class StackTest : public QObject
{
    Q_OBJECT
public:
    explicit StackTest(QObject *parent = 0) : QObject(parent) {}
protected:
    virtual void create() = 0;
    Stack *stack;
private slots:
    void init()
    {
        create();
    }
    void cleanup()
    {
        delete stack;
    }
    void testEmptyStack()
    {
        QVERIFY(stack->isEmpty());
    }

    void testPush()
    {
        stack->push(1);
        QVERIFY(stack->isEmpty() == 0);
    }

    void testTop()
    {
        stack->push(2);
        QVERIFY(stack->top() == 2);
    }

    void testPop()
    {
        stack->push(2);
        stack->pop();
        QVERIFY(stack->isEmpty());
    }

    void testMultipleAdd()
    {
        stack->push(2);
        stack->push(3);
        stack->push(5);
        QVERIFY(stack->pop() == 5);
    }
};

class CreateStackPointer : public StackTest
{
protected:
    void create()
    {
        stack = new StackPointer;
    }
};

class CreateStackArray : public StackTest
{
protected:
    void create()
    {
        stack = new StackArray;
    }
};
