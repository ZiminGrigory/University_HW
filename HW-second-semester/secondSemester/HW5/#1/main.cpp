#include <iostream>
#include "hasher.h"
#include "hashTable.h"
#include "hashTest.h"
using namespace std;


int main()
{
    HashTest test;
    QTest::qExec(&test);
}
