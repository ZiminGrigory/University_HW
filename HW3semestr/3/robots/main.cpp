/**
 * Программа дает ответ на задачу:
 * Есть связный неориентированный граф, в вершинах графа находится несколько роботов.
 * каждый ход роботы могут телепортироваться,
 * перепрыгивая через одну вершину. Например, если граф выглядит так: (R)----(*)----(*),
 * то на следующем ходу робот может остаться на месте, а может телепортироваться: (*)----(*)----(R).
 * Если два или больше роботов телепортируются в одну вершину графа, они самоуничтожаются.
 * Задача --- по заданному графу и заданному начальному расположению роботов определить,
 * существует ли такая последовательность телепортаций, при которой все роботы самоуничтожатся.
 *
 * Консольная программа принимает файл.txt, в котором в первой строке находятся 3 числа: х - число вершин
 * у - число роботов, z - число ребер,
 * затем строки в который по паре чисел задают ребра (к примеру: 0 2, 7 вершин 0 - 6),
 * на следующей - номера вершин в которых находятся роботы.
 * Считается, что входные данные корректн: граф связен, число роботов не превосходит числа вершин,
 * и числа введены верно.
 *
 * Результат работы программы будет выведен в консоль Y/N.
 */

#include <QCoreApplication>
#include "AnswerAnalyzer.h"
#include "FileParser.h"
#include "MatrixAnalyzer.h"
#include "ProgramTest.h"
#include <fstream>
#include "ProgramTest.h"

using namespace std;

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
//	QString const graphFile = argv[1];
//	ifstream file(graphFile.toLocal8Bit());
//	if (file.is_open()){
//		FileParser fileParser(file);
//		MatrixAnalyzer matrixAnalyzer(fileParser.getMatrix(), fileParser.getRobots());
//		AnswerAnalyzer answerAnalyzer(matrixAnalyzer.getRobotsAttainableOneTops());
//		bool answer = answerAnalyzer.getAnswer();
//		ofstream fileAnswer("answer.txt");
//		fileAnswer.open("answer.txt");
//		fileAnswer << answer;
//	}
	ProgramTest test;
	QTest::qExec(&test);
	return a.exec();
}
