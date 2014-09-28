#ifndef STARTERTEST_H
#define STARTERTEST_H
#include <QtCore/QObject>
#include <QtTest/QTest>
#include <QSharedPointer>
#include "Starter.h"
class StarterTest: public QObject
{
Q_OBJECT
private slots:
	void init()
	{
		starter = QSharedPointer<Starter>(new Starter);
	}

	void cleanup()
	{
	}

	void start()
	{
		starter->start();
	}
private:
	QSharedPointer<Starter> starter;
};
#endif // STARTERTEST_H
