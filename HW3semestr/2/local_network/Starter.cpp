#include "Starter.h"
#include "mConst.h"
#include "PC.h"
#include "Switch.h"
#include <QSharedPointer>

Starter::Starter(): turnCnt(0)
{
}

void Starter::start()
{
	dialog = QSharedPointer<DialogForm>(new DialogForm);
	dialog->resize(680, 420);
	dialog->show();
	mRand = QSharedPointer<Random>(new Random);
	connect(dialog.data(), SIGNAL(clickButtonNextTurn()), SLOT(makeNextTurn()));
	connect(dialog.data(), SIGNAL(clickButtonLogStatus()), SLOT(makeNewLog()));
	mSwitch = QSharedPointer<Switch>(new Switch);
	for (int i = 0; i < numberOfPC; i++){
		mSwitch->connectPC(QSharedPointer<PC>(new PC(dialog, i, mRand)));
	}
}

void Starter::makeNewLog()
{
	dialog->appendText("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" + QString::fromLocal8Bit("Лог системы\n"));
}

void Starter::makeNextTurn()
{
	turnCnt++;
	dialog->appendText("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	dialog->appendText(QString::fromLocal8Bit("Ход №  ") + QString::number(turnCnt)+ "\n\n");
}
