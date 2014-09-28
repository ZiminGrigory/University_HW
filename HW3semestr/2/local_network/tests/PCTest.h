#ifndef PCTEST_H
#define PCTEST_H
#include <QtCore/QObject>
#include <QtTest/QTest>
#include <QSharedPointer>
#include "PC.h"
class PCTest: public QObject
{
Q_OBJECT
private slots:
	void init()
	{
		pc = QSharedPointer<PC>(new PC(QSharedPointer<DialogForm>(new DialogForm), 42
									   ,QSharedPointer<Random>(new Random)));
	}

	void cleanup()
	{
	}

	void getPackage()
	{
		pc->getPackage(QSharedPointer<Package>(new Package));
	}

	void getStatus()
	{
		pc->getOSStatus(INFECTED);
		pc->getOSStatus(NOT_INFECTED);
	}
private:
	QSharedPointer<PC> pc;
};
#endif // PCTEST_H
