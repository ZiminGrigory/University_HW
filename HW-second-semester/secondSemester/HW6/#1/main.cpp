#include "testTask.h"
#include <QtTest/QtTest>
#include <iostream>
#include "operand.h"
#include "operator.h"
#include "parsetree.h"

int main()
{
    TestTask testTask;
    QTest::qExec(&testTask);
}
