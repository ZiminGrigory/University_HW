#ifndef SWITCH_H
#define SWITCH_H
#include <QSharedPointer>
#include <QObject>
#include "QVector"
#include "PC.h"
#include "Server.h"
/**
 * @brief The Switch class realise switch (or hub)
 */
class Switch: public QObject
{
Q_OBJECT
public:
	Switch();
	~Switch();
	void connectPC(QSharedPointer<PC> pc);
	void connectServer(QSharedPointer<Server> server);

private slots:
	void sendPackageToPC(QSharedPointer<Package> package, int nameOfPC);

private:
	QVector<QSharedPointer<PC> > mWorkGroup;
	QSharedPointer<Server> mServer;
};

#endif // SWITCH_H
