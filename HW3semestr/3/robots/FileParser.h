#ifndef FILEPARSER_H
#define FILEPARSER_H
#include <QSharedPointer>
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
	 * @brief getNumberOfTops
	 * @return возвращает число вершин
	 */
	int getNumberOfTops();
	/**
	 * @brief getRobots
	 * @return возвращает list с роботами(вершины, в которых они стоят)
	 */
	QVector<int> getRobots();
	/**
	 * @brief getMatrix
	 * @return возвращает матрицу связей вершин
	 */
	QVector<QVector<int> > getMatrix();

private:
	int tops;
	int numberOfrobots;
	QVector<int> robots;
	QVector<QPair<int, int> > connections;
	QVector<QVector<int> >  matrix;
};


#endif // FILEPARSER_H
