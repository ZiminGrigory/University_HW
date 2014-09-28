#include "Mac_OS.h"

Mac_OS::Mac_OS(int riskOfVirus)
{
	riskOfResist = riskOfVirus;
}

QString Mac_OS::friendlyName()
{
	return "MAC_OS";
}

void Mac_OS::systemRecovery()
{
	qsrand((uint)QTime::currentTime().msec());
	if (qrand() > RecoverySystemChance::MAC_OS){
		emit recoveryLog(NOT_INFECTED);
	}
}
