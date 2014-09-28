#include "Random.h"
#include <QtGlobal>
#include <QTime>


Random::Random()
{
}

int Random::randInfectionShieldOS(OS os)
{
	switch (os) {
	case LINUX:
		return this->randForAll(MaxRiskOfResist::LINUX) + Epsilon::LINUX;
		break;
	case WINDOWS:
		return randForAll(MaxRiskOfResist::WINDOWS) + Epsilon::WINDOWS;
		break;
	case MAC_OS:
		return randForAll(MaxRiskOfResist::MAC_OS) + Epsilon::MAC_OS;
		break;
	}
	return 0;
}

int Random::randVirusPower(int maximum)
{
	return randForAll(maximum);
}

int Random::randOSMakeVirus(int maximum)
{
	return randForAll(maximum);
}

int Random::randNameOfPC(int maximum)
{
	return randForAll(maximum);
}

int Random::randOS(int maximum)
{
	return randForAll(maximum);
}

int Random::randForAll(int maximum)
{
	qsrand((uint)QTime::currentTime().msec());
	return rand() % maximum;
}
