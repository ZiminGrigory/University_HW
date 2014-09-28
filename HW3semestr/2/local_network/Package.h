#ifndef PACKAGE_H
#define PACKAGE_H
/**
 * @brief The Package class can be appended, but why? now it's not nessesary
 */
class Package
{
public:
	Package();
	virtual bool getVirusContent();
	virtual int getVirusPover();
};

#endif // PACKAGE_H
