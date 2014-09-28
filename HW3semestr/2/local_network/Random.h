#pragma once
#include "mConst.h"
/**
 * @brief The Random class возвращает рандомное или псевдораномное значение
 */
class Random{
public:
	Random();
	/**
	 * @brief rand?? return random number
	 * @param maximum - number 0..maximum
	 * @return random number
	 */
	virtual int randOS(int maximum);
	virtual int randInfectionShieldOS(OS os);
	virtual int randVirusPower(int maximum);
	virtual int randOSMakeVirus(int maximum);
	virtual int randNameOfPC(int maximum);

private:
	int randForAll(int maximum);
};
