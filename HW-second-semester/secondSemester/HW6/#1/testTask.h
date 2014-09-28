/**
  *
  *Task HW6-1.
  *
**/
#ifndef TESTTASK_H
#define TESTTASK_H
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "operand.h"
#include "operator.h"
#include "parsetree.h"

class TestTask : public QObject
{
    Q_OBJECT
public:
    explicit TestTask(QObject *parent = 0) : QObject(parent) {}
private slots:
    void init()
    {
        parseTree = new ParseTree;
    }

    void cleanup()
    {
        delete parseTree;
    }
    void printTest()
    {
        cout << "PRINT TEST LOADING...\n";
        parseTree->setFileName("firstTest.txt");
        parseTree->makeTreeFromFile();
        parseTree->print();
        cout << endl<< "RESULT: ";
    }
    void firstExpressionTest()
    {
        parseTree->setFileName("firstTest.txt");
        parseTree->makeTreeFromFile();
        QCOMPARE(parseTree->calculate(),4.0);
    }
    void secondExpressionTest()
    {
        parseTree->setFileName("secondTest.txt");
        parseTree->makeTreeFromFile();
        QCOMPARE(parseTree->calculate(),-6.0);
    }
    void hardExpressionTest()
    {
        parseTree->setFileName("hardTest.txt");
        parseTree->makeTreeFromFile();
        QCOMPARE(parseTree->calculate(),54.4);
    }
private:
    ParseTree *parseTree;
};
#endif // TESTTASK_H
