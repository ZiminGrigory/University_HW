#ifndef PSEUDORANDOM_H
#define PSEUDORANDOM_H
#include "Random.h"
#include <QVector>
/**
 * @brief The PseudoRandom class возвращает псевдорандомные числа, для теста
 */
class PseudoRandom : public Random
{
public:
	PseudoRandom(QVector<int> chanceOSBeClear
							   , QVector<int> virusPower
							   , QVector<int> chanceToMakeVirus
							   , QVector<int> chanceChooseOS
							   , QVector<int> nameOFComputer);
	virtual int randOS(int maximum);
	virtual int randInfectionShieldOS(OS os);
	virtual int randVirusPower(int maximum);
	virtual int randOSMakeVirus(int maximum);
	virtual int randNameOfPC(int maximum);

private:
	QVector<int> OSChance;
	QVector<int> OSVirusShield;
	QVector<int> virusPower;
	QVector<int> chanceToMakeVirus;
	//to .. sent package
	QVector<int> nameOfPC;
	int iterationOs;
	int iterationOSShield;
	int iterationVP;
	int iterationMakeVirus;
	int iterationName;
};

#endif // PSEUDORANDOM_H
