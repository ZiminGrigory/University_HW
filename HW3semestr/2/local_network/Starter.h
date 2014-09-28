/**
*This program realise local network with stars model. Any PC have access to
*other PC in home group. Any PC can have 1 OS (LINUX, WINDOWS, MAC_OS),
*all OS can fix problem with viruses with definetly chance. Also all OS have
*different chance to be were infected. You have two button: show log of network or
*make new iteration, on new turn all PC send package to the one randomly PC
*with virus or clear package, OS in PC have definetly chance to be infected.
**/

#ifndef STARTER_H
#define STARTER_H
#include <QObject>
#include <Random.h>
#include "DialogForm.h"
#include "Switch.h"

class Starter: public QObject
{
Q_OBJECT
public:
	Starter();
	/**
	 * @brief start: start the widget and include components
	 */
	void start();
public slots:
	/**
	 * @brief makeNewLog: append empty row to text display
	 */
	void makeNewLog();
	void makeNextTurn();
private:
	QSharedPointer<DialogForm> dialog;
	QSharedPointer<Switch> mSwitch;
	QSharedPointer<Random> mRand;
	int turnCnt;
};

#endif // STARTER_H
