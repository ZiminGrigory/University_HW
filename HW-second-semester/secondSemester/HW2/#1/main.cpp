#include <iostream>
#include "list.h"
#include "onePointerList.h"
#include "twoPointerList.h"
#include "listTest.h"

using namespace std;



int main()
{
    ListTest *test = new CreateOnePointerList;
    QTest::qExec(test);
    delete test;
    ListTest *test2 = new CreateTwoPointerList;
    QTest::qExec(test2);
    delete test;
}
