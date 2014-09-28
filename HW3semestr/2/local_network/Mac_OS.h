#ifndef MAC_OS_H
#define MAC_OS_H
#include "OperatingSystem.h"

class Mac_OS : public OperatingSystem
{
public:
	Mac_OS(int riskOfVirus);
	QString friendlyName();
	virtual void systemRecovery();
};

#endif // MAC_OS_H
