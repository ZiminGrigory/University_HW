#include <iostream>
#include "print.h"
#include "printInConsole.h"
#include "printInFile.h"
#include "toOneDimensional.h"
#include "testToOneDimension.h"

using namespace std;




int main()
{
    TestToOneDimension test;
    QTest::qExec(test);
}

