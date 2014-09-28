#include <QtTest/QTest>

#include "testIterator.h"
#include "testSet.h"
int main()
{
    TestSet test;
    QTest::qExec(&test);

    TestIterator iteratorTest;
    QTest::qExec(&iteratorTest);
    return 0;
}
