#ifndef PROGRAMTEST_H
#define PROGRAMTEST_H
#include <QtCore/QObject>
#include <QtTest/QTest>
#include <fstream>
#include <QDebug>
#include "MassivAnalyzer.h"
#include "FileParser.h"
#include <QVector>

using namespace std;

class ProgramTest: public QObject
{
Q_OBJECT
private slots:
	void init()
	{
	}

	void cleanup()
	{
	}

	void firstTest()
	{
		ifstream file("test1.txt");
		FileParser parser(file);
		QVector<int> matrix = parser.getVector();
		MassivAnalyzer analyzer(matrix);
		QVERIFY(analyzer.getNumberOfNullElements() == 0);
		file.close();
	}

	void secondTest()
	{
		ifstream file("test2.txt");
		FileParser parser(file);
		MassivAnalyzer analyzer(parser.getVector());
		QVERIFY(analyzer.getNumberOfNullElements() == 5);
		file.close();
	}

	void thirdTest()
	{
		ifstream file("test3.txt");
		FileParser parser(file);
		MassivAnalyzer analyzer(parser.getVector());
		QVERIFY(analyzer.getNumberOfNullElements() == 10);
		file.close();
	}
};
#endif // PROGRAMTEST_H
