#ifndef OPERATINGSYSTEM_H
#define OPERATINGSYSTEM_H
#include <QObject>
#include <QTime>
#include "mConst.h"

class OperatingSystem : public QObject
{
Q_OBJECT
public:
	OperatingSystem();
	/**
	 * @brief attacked: made attack on OS
	 * @return status infected or not
	 */
	AttackStatus attacked(int powerOFVirus);
	/**
	 * @brief friendlyName
	 * @return name of OS
	 */
	virtual QString friendlyName() = 0;
	/**
	 * @brief try to clear OS from viruses
	 */
	virtual void systemRecovery() = 0;
signals:
	void recoveryLog(AttackStatus status);

protected:
	int riskOfResist;
};

#endif // OPERATINGSYSTEM_H
