#include "Windows.h"

Windows::Windows(int riskOfVirus)
{
	riskOfResist = riskOfVirus;
}

QString Windows::friendlyName()
{
	return "WINDOWS";
}

void Windows::systemRecovery()
{
	qsrand((uint)QTime::currentTime().msec());
	if (qrand() > RecoverySystemChance::WINDOWS){
		emit recoveryLog(NOT_INFECTED);
	}
}
