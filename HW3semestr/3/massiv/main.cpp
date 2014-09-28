/**
 * Программа дает ответ на задачу:
 * Сколько нулей в массиве.
 *
 * Консольная программа принимает файл.txt, в котором в первой строке находятся число элементов в массиве n(int)
 * затем во второй строке идут - n чисел.
 * Считается, что входные данные корректны:число чисес совпадает с n.
 *
 * Результат работы программы будет выведен в консоль Y/N.
 */

#include <QCoreApplication>
#include "FileParser.h"
#include "MassivAnalyzer.h"
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
//		MassivAnalyzer massivAnalyzer(fileParser.getVector());
//		int answer = massivAnalyzer.getNumberOfNullElements());
//		ofstream fileAnswer("answer.txt");
//		fileAnswer.open("answer.txt");
//		fileAnswer << answer;
//	}
	ProgramTest test;
	QTest::qExec(&test);
	return a.exec();
}
