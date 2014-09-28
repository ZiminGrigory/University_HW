#include "PC.h"
#include "Package.h"
#include "Virus.h"
PC::PC(QSharedPointer<DialogForm> dialog, int name, QSharedPointer<Random> random):
	mDialog(dialog), mName(name), mOS_Status(NOT_INFECTED), mRand(random)
{
setRandomOS();
	connect(mDialog.data(), SIGNAL(clickButtonNextTurn()), SLOT(makePackage()));
	connect(mDialog.data(), SIGNAL(clickButtonLogStatus()), SLOT(logOutToDialog()));
}

void PC::setRandomOS()
{
	int switcher = mRand->randOS(100);
	if (switcher <= 33){
		mOS = QSharedPointer<Linux>(new Linux(mRand->randInfectionShieldOS(LINUX)));
	} else if (switcher <= 66){
		mOS = QSharedPointer<Mac_OS>(new Mac_OS(mRand->randInfectionShieldOS(MAC_OS)));
	} else if (switcher <= 99){
		mOS = QSharedPointer<Windows>(new Windows(mRand->randInfectionShieldOS(WINDOWS)));
	}
	// if you want play longer delete slash(also in methos getPackage), and OS will can fix itself
	//connect(mOS.data(), SIGNAL(recoveryLog(AttackStatus)), this, SLOT(getOSStatus(AttackStatus)));
}

void PC::getPackage(QSharedPointer<Package> package){
	if (package->getVirusContent()){
		if (mOS->attacked(package->getVirusPover()) == INFECTED){
			mOS_Status = INFECTED;
			mDialog->appendText(QString::fromLocal8Bit("Компьютер № ") + QString::number(mName)
								+ QString::fromLocal8Bit(" ИНФЕЦИРОВАН"));
		}
		else {
			mDialog->appendText(QString::fromLocal8Bit("Компьютер № ") + QString::number(mName)
								+ QString::fromLocal8Bit(" ЧИСТ"));
		}
	}
//	if (mOS_Status == INFECTED){
//		mOS->systemRecovery();
	//	}
}

AttackStatus PC::getOsStatus()
{
	return mOS_Status;
}

void PC::getOSStatus(AttackStatus status)
{
	mOS_Status = status;
}

void PC::makePackage()
{
	int switcher = mRand->randOSMakeVirus(100);
	int nameOfComputer = mRand->randNameOfPC(numberOfPC);
	while (nameOfComputer == mName){
		nameOfComputer = mRand->randNameOfPC(numberOfPC);
	}
	if (switcher >= VIRUS_CHANCE){
		mDialog->appendText(QString::fromLocal8Bit("Компьютер № ") + QString::number(mName)
							+ QString::fromLocal8Bit(" Послал пакет с ВИРУСОМ компьютеру ")
							+ QString::number(nameOfComputer));
		emit sendPackage(QSharedPointer<Virus>(new Virus(mRand->randVirusPower(100))), nameOfComputer);
	} else{mDialog->appendText(QString::fromLocal8Bit("Компьютер № ") + QString::number(mName)
							   + QString::fromLocal8Bit(" Послал чистый пакет компьютеру ")
							   + QString::number(nameOfComputer));
		emit sendPackage(QSharedPointer<Package>(new Package), nameOfComputer);
	}
}

void PC::logOutToDialog()
{
	QString text;
	if (mOS_Status == INFECTED){
		text = QString::fromLocal8Bit(" ИНФЕЦИРОВАН");
	} else{
		text = QString::fromLocal8Bit(" ЧИСТ");
	}
	mDialog->appendText(QString::fromLocal8Bit("Компьютер номер ") + QString::number(mName)
						+ QString::fromLocal8Bit(" ось: ")
						+ mOS->friendlyName() + text);
}
