#ifndef LINUX_H
#define LINUX_H
#include "OperatingSystem.h"
class Linux : public OperatingSystem
{
public:
	Linux(int riskOfVirus);
	QString friendlyName();
	virtual void systemRecovery();
};

#endif // LINUX_H
