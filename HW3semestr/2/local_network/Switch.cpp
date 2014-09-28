#include "Switch.h"

Switch::Switch()
{
}

Switch::~Switch()
{
}

void Switch::connectPC(QSharedPointer<PC> pc)
{
	connect(pc.data(), SIGNAL(sendPackage(QSharedPointer<Package>, int))
			, this, SLOT(sendPackageToPC(QSharedPointer<Package>, int)));
	mWorkGroup.append(pc);
}

void Switch::connectServer(QSharedPointer<Server> server)
{
	mServer = server;
}

void Switch::sendPackageToPC(QSharedPointer<Package> package, int nameOfPC)
{
	mWorkGroup.at(nameOfPC)->getPackage(package);
}
