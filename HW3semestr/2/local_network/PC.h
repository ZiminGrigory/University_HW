#ifndef PC_H
#define PC_H
#include <QSharedPointer>
#include <QObject>
#include "OperatingSystem.h"
#include "DialogForm.h"
#include "Mac_OS.h"
#include "Linux.h"
#include "Windows.h"
#include "Virus.h"
#include "Random.h"

class PC : public QObject
{
Q_OBJECT
public:
	PC(QSharedPointer<DialogForm> dialog, int name, QSharedPointer<Random> random);
	/**
	 * @brief getPackage: get package from smth PC
	 * @param package: now it's empty class
	 */
	void getPackage(QSharedPointer<Package> package);
	/**
	 * @brief getOsStatus - get status os in pc, for test
	 * @return status of OS
	 */
	AttackStatus getOsStatus();

signals:
	/**
	 * @brief sendPackage: send Package to other PC
	 * @param package - class
	 * @param nameOfComputer: name is number 1..numberOfPC
	 */
	void sendPackage(QSharedPointer<Package> package, int nameOfComputer);

public slots:
	/**
	 * @brief getOSStatus : get status of OS
	 * @param status
	 */
	void getOSStatus(AttackStatus status);
	/**
	 * @brief makePackage: make Package with virus or empty
	 */
	void makePackage();

private slots:
	/**
	 * @brief logOutToDialog: dysplay status of OS
	 */
	void logOutToDialog();

private:
	/**
	 * @brief setRandomOS: set ranfom OS
	 */
	void setRandomOS();
	QSharedPointer<OperatingSystem> mOS;
	QSharedPointer<DialogForm> mDialog;
	QSharedPointer<Random> mRand;
	int mName;
	AttackStatus mOS_Status;
};

#endif // PC_H
