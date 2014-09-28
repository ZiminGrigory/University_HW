#ifndef VIRUS_H
#define VIRUS_H
#include "Package.h"

class Virus : public Package
{
public:
	Virus(int virusPower);
	bool getVirusContent();
	virtual int getVirusPover();

private:
	int mVirusPower;
};

#endif // VIRUS_H
