#include <iostream>
#include "boobleSort.h"
#include "heapSort.h"
#include "quickSort.h"
#include "sortTest.h"
using namespace std;

int main()
{
    SortTest *testBooble = new TestBoobleSort;
    QTest::qExec(testBooble);
    SortTest *testQuick = new TestQuickSort;
    QTest::qExec(testQuick);
    SortTest *testHeap = new TestHeapSort;
    QTest::qExec(testHeap);
    delete testBooble;
    delete testQuick;
    delete testHeap;
}
