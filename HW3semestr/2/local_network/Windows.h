#ifndef WINDOWS_H
#define WINDOWS_H
#include "OperatingSystem.h"

class Windows : public OperatingSystem
{
public:
	Windows(int riskOfVirus);
	QString friendlyName();
	virtual void systemRecovery();
};

#endif // WINDOWS_H
