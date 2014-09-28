#include "PseudoRandom.h"

PseudoRandom::PseudoRandom(QVector<int> chanceOSBeClear, QVector<int> virusPower
						   , QVector<int> chanceToMakeVirus, QVector<int> chanceChooseOS, QVector<int> nameOFComputer):
	OSChance(chanceChooseOS), virusPower(virusPower)
  , chanceToMakeVirus(chanceToMakeVirus), OSVirusShield(chanceOSBeClear)
  , nameOfPC(nameOFComputer)
  , iterationOs(-1), iterationVP(-1), iterationMakeVirus(-1), iterationOSShield(-1), iterationName(-1)
{
}

int PseudoRandom::randOS(int maximum)
{
	Q_UNUSED(maximum);
	iterationOs++;
	return OSChance.at(iterationOs);
}

int PseudoRandom::randInfectionShieldOS(OS os)
{
	Q_UNUSED(os);
	iterationOSShield++;
	return OSVirusShield.at(iterationOSShield);
}

int PseudoRandom::randVirusPower(int maximum)
{
	Q_UNUSED(maximum);
	iterationVP++;
	return virusPower.at(iterationVP);
}

int PseudoRandom::randNameOfPC(int maximum)
{
	Q_UNUSED(maximum);
	iterationName++;
	return nameOfPC.at(iterationName);
}

int PseudoRandom::randOSMakeVirus(int maximum)
{
	Q_UNUSED(maximum);
	iterationMakeVirus++;
	return chanceToMakeVirus.at(iterationMakeVirus);
}
