#ifndef INFECTEDPROCESSTEST_H
#define INFECTEDPROCESSTEST_H
#include <QtCore/QObject>
#include <QtTest/QTest>
#include <QSharedPointer>
#include "Linux.h"
#include "Windows.h"
#include "Mac_OS.h"
#include "Switch.h"
#include "PC.h"
#include "PseudoRandom.h"
#include "Virus.h"
#include "Package.h"
#include "DialogForm.h"

class InfectedProcessTest: public QObject
{
Q_OBJECT
private slots:
	void init()
	{

	}

	void cleanup()
	{
		chanceToMakeVirus.clear();
		virusPower.clear();
		chanceChooseOs.clear();
		nameOfComputer.clear();
		chanceToResist.clear();
	}

	void PC1TryIndectedPC2_succes()
	{
		chanceToMakeVirus <<  90 << 90;
		virusPower <<  99 << 99;
		chanceChooseOs << 20 << 70;
		nameOfComputer << 1 << 0;
		chanceToResist << 99 << 1;
		mRand = QSharedPointer<PseudoRandom>(new PseudoRandom(
												 chanceToResist, virusPower, chanceToMakeVirus
												 , chanceChooseOs, nameOfComputer));
		dialog = QSharedPointer<DialogForm>(new DialogForm);
		PC0 = QSharedPointer<PC>(new PC(dialog, 0, mRand));
		PC1 = QSharedPointer<PC>(new PC(dialog, 1, mRand));
		mSwitch = QSharedPointer<Switch>(new Switch);
		mSwitch->connectPC(PC0);
		mSwitch->connectPC(PC1);
		PC0->makePackage();
		QCOMPARE(PC1->getOsStatus(), INFECTED);
	}

	void PC2TryIndectedPC3_un_succes()
	{
		chanceToMakeVirus <<  90 << 90;
		virusPower <<  20 << 20;
		chanceChooseOs << 20 << 70;
		nameOfComputer << 1 << 0;
		chanceToResist << 99 << 99;
		mRand2 = QSharedPointer<PseudoRandom>(new PseudoRandom(
												 chanceToResist, virusPower, chanceToMakeVirus
												 , chanceChooseOs, nameOfComputer));
		dialog2 = QSharedPointer<DialogForm>(new DialogForm);
		PC2 = QSharedPointer<PC>(new PC(dialog2, 0, mRand2));
		PC3 = QSharedPointer<PC>(new PC(dialog2, 1, mRand2));
		mSwitch2 = QSharedPointer<Switch>(new Switch);
		mSwitch2->connectPC(PC2);
		mSwitch2->connectPC(PC3);
		PC2->makePackage();
		QCOMPARE(PC3->getOsStatus(), NOT_INFECTED);
	}

	void PC4TryIndectedPC5_9()
	{
		chanceToMakeVirus << 90 << 75 << 50 << 20 << 84 << 44;
		virusPower << 20 << 70 << 40 << 10 << 50 << 99;
		chanceChooseOs << 20 << 70 << 55 << 40 << 22 << 10;
		nameOfComputer << 1 << 2 << 3 << 4 << 5 << 0;
		chanceToResist << 99 << 80 << 27 << 90 << 35 << 20;
		mRand3 = QSharedPointer<PseudoRandom>(new PseudoRandom(
												 chanceToResist, virusPower, chanceToMakeVirus
												 , chanceChooseOs, nameOfComputer));
		dialog3 = QSharedPointer<DialogForm>(new DialogForm);
		PC4 = QSharedPointer<PC>(new PC(dialog3, 0, mRand3));
		PC5 = QSharedPointer<PC>(new PC(dialog3, 1, mRand3));
		PC6 = QSharedPointer<PC>(new PC(dialog3, 2, mRand3));
		PC7 = QSharedPointer<PC>(new PC(dialog3, 3, mRand3));
		PC8 = QSharedPointer<PC>(new PC(dialog3, 4, mRand3));
		PC9 = QSharedPointer<PC>(new PC(dialog3, 5, mRand3));
		mSwitch3 = QSharedPointer<Switch>(new Switch);
		mSwitch3->connectPC(PC4);
		mSwitch3->connectPC(PC5);
		mSwitch3->connectPC(PC6);
		mSwitch3->connectPC(PC7);
		mSwitch3->connectPC(PC8);
		mSwitch3->connectPC(PC9);
		PC4->makePackage();
		PC4->makePackage();
		PC4->makePackage();
		PC4->makePackage();
		PC4->makePackage();
		QCOMPARE(PC5->getOsStatus(), NOT_INFECTED);
		QCOMPARE(PC6->getOsStatus(), INFECTED);
		QCOMPARE(PC7->getOsStatus(), NOT_INFECTED);
		QCOMPARE(PC8->getOsStatus(), NOT_INFECTED);
		QCOMPARE(PC9->getOsStatus(), NOT_INFECTED);
	}
private:
	QSharedPointer<Switch> mSwitch;
	QSharedPointer<DialogForm> dialog;
	QSharedPointer<PseudoRandom> mRand;
	QSharedPointer<Switch> mSwitch2;
	QSharedPointer<DialogForm> dialog2;
	QSharedPointer<PseudoRandom> mRand2;
	QSharedPointer<Switch> mSwitch3;
	QSharedPointer<DialogForm> dialog3;
	QSharedPointer<PseudoRandom> mRand3;
	QSharedPointer<PC> PC0;
	QSharedPointer<PC> PC1;
	QSharedPointer<PC> PC2;
	QSharedPointer<PC> PC3;
	QSharedPointer<PC> PC4;
	QSharedPointer<PC> PC5;
	QSharedPointer<PC> PC6;
	QSharedPointer<PC> PC7;
	QSharedPointer<PC> PC8;
	QSharedPointer<PC> PC9;
	QVector<int> virusPower;
	QVector<int> chanceToResist;
	QVector<int> chanceToMakeVirus;
	QVector<int> chanceChooseOs;
	QVector<int> nameOfComputer;


};
#endif // INFECTEDPROCESSTEST_H
