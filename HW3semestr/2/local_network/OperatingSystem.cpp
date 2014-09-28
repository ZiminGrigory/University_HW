#include "OperatingSystem.h"

OperatingSystem::OperatingSystem()
{
}

AttackStatus OperatingSystem::attacked(int powerOFVirus)
{
	if (powerOFVirus > riskOfResist){
		return INFECTED;
	}
	return NOT_INFECTED;
}
