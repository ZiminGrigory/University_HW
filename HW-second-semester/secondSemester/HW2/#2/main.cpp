#include <iostream>
#include "stackTest.h"
#include "stackCalcTest.h"

using namespace std;
int main()
{
    StackTest *test = new CreateStackPointer;
    QTest::qExec(test);
    delete test;

    StackTest *test2 = new CreateStackArray;
    QTest::qExec(test2);
    delete test2;

    StackCalcTest *test3 = new StackCalcTest;
    QTest::qExec(test3);
    delete test3;
}
