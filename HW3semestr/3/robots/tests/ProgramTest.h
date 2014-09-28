#ifndef PROGRAMTEST_H
#define PROGRAMTEST_H
#include <QtCore/QObject>
#include <QtTest/QTest>
#include <fstream>
#include "AnswerAnalyzer.h"
#include "FileParser.h"
#include "MatrixAnalyzer.h"
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
		QVector<QVector<int> > matrix = parser.getMatrix();
		QVector<int> robots = parser.getRobots();
		MatrixAnalyzer analyzer(matrix, robots);
		QVector<QVector<int> > robotsOnetops = analyzer.getRobotsAttainableOneTops();
		AnswerAnalyzer answer(robotsOnetops);
		QVERIFY(answer.getAnswer() == true);
		file.close();
	}

	void secondTest()
	{
		ifstream file("test2.txt");
		FileParser parser(file);
		MatrixAnalyzer analyzer(parser.getMatrix(), parser.getRobots());
		AnswerAnalyzer answer(analyzer.getRobotsAttainableOneTops());
		QVERIFY(answer.getAnswer() == true);
		file.close();
	}

	void thirdTest()
	{
		ifstream file("test3.txt");
		FileParser parser(file);
		MatrixAnalyzer analyzer(parser.getMatrix(), parser.getRobots());
		AnswerAnalyzer answer(analyzer.getRobotsAttainableOneTops());
		QVERIFY(answer.getAnswer() == false);
		file.close();
	}
};
#endif // PROGRAMTEST_H
