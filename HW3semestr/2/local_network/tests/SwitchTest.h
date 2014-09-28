#ifndef SWITCHTEST_H
#define SWITCHTEST_H
#include <QtCore/QObject>
#include <QtTest/QTest>
#include <QSharedPointer>
#include "Switch.h"
class SwitchTest: public QObject
{
Q_OBJECT
private slots:
	void init()
	{
		switcher = QSharedPointer<Switch>(new Switch);
		randomizer = QSharedPointer<Random>(new Random);
	}

	void cleanup()
	{
	}

	void connectPc()
	{
		switcher->connectServer(QSharedPointer<Server>(new Server));
	}

	void connectServer()
	{
		switcher->connectPC(QSharedPointer<PC>(new PC(QSharedPointer<DialogForm>(new DialogForm), 42, randomizer)));
	}
private:
	QSharedPointer<Switch> switcher;
	QSharedPointer<Random> randomizer;
};
#endif // SWITCHTEST_H
