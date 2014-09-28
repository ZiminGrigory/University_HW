#ifndef OSTEST_H
#define OSTEST_H
#include <QtCore/QObject>
#include <QtTest/QTest>
#include <QSharedPointer>
#include "OperatingSystem.h"
#include "Linux.h"
#include "Windows.h"
#include "Mac_OS.h"

class OSTest: public QObject
{
Q_OBJECT
private slots:
	void init()
	{
		linuuux = QSharedPointer<Linux>(new Linux(24));
		win = QSharedPointer<Mac_OS>(new Mac_OS(35));
		mac = QSharedPointer<Windows>(new Windows(33));
	}

	void cleanup()
	{
	}

	void setOSLinFriendlyName()
	{
		QVERIFY(linuuux->friendlyName() == "LINUX");
	}

	void setOSMacFriendlyName()
	{
		QVERIFY(win->friendlyName() == "MAC_OS");
	}

	void setOSWinFriendlyName()
	{
		QVERIFY(mac->friendlyName() == "WINDOWS");
	}

	void magicWithRiskOfVirusLin()
	{
		linuuux->attacked(52);
		linuuux->systemRecovery();
	}

	void magicWithRiskOfVirusWin()
	{
		win->attacked(25);
		win->systemRecovery();
	}

	void magicWithRiskOfVirusMac()
	{
		mac->attacked(33);
		mac->systemRecovery();
	}
private:
	QSharedPointer<OperatingSystem> linuuux; //linux is service
	QSharedPointer<OperatingSystem>	win;
	QSharedPointer<OperatingSystem> mac;

};
#endif // OSTEST_H
