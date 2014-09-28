#include "Linux.h"

Linux::Linux(int riskOfVirus)
{
	riskOfResist = riskOfVirus;
}

QString Linux::friendlyName()
{
	return "LINUX";
}

void Linux::systemRecovery()
{
	qsrand((uint)QTime::currentTime().msec());
	if (qrand() > RecoverySystemChance::LINUX){
		emit recoveryLog(NOT_INFECTED);
	}
}

