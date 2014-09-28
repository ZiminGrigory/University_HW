#ifndef FILEPARSER_H
#define FILEPARSER_H
#include <QString>
#include <QFile>
#include <QPair>
#include <QVector>
#include <QFile>
#include <fstream>
using namespace std;
/**
 * @brief The MatrixAnalyzer class анализирует входные данные.
 */
class FileParser
{
public:
	FileParser(ifstream &file);
	/**
	 * @brief getMatrix
	 * @return возвращает матрицу в виде вектора
	 */
	QVector<int> getVector();

private:
	QVector<int> matrix;
};
#endif // FILEPARSER_H
