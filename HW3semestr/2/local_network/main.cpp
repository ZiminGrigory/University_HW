#include <QApplication>
#include <QtTest/QTest>
#include "Starter.h"
//tests:
#include "OSTest.h"
#include "PCTest.h"
#include "StarterTest.h"
#include "SwitchTest.h"
#include "InfectedProcessTest.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//for app-on
//	Starter start;
//	start.start();

	//old tests:
//	OSTest firstTest;
//	PCTest secondTest;
//	StarterTest thirdTest;
//	SwitchTest forthTest;

//	QTest::qExec(&firstTest);
//	QTest::qExec(&secondTest);
//	QTest::qExec(&thirdTest);
//	QTest::qExec(&forthTest);
	InfectedProcessTest test;
	QTest::qExec(&test);


	return a.exec();
}
