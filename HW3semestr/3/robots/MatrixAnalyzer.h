#ifndef MATRIXANALYZER_H
#define MATRIXANALYZER_H
#include <QVector>
#include <QPair>
#include <QStack>
#include <QList>
#include <QSharedPointer>
/**
 * @brief The MatrixAnalyzer class анализирует матрицу
 */
class MatrixAnalyzer
{
public:
	MatrixAnalyzer(QVector<QVector<int> > matrix, QVector<int> robots);
	/**
	 * @brief getAttainableTops
	 * @return возвращает вектор роботов,
	 * которые могут достичь 1 вершину.
	 */
	QVector<QVector<int> > getRobotsAttainableOneTops();

private:
	void getTopsAfterMiddleTop(int top, int currentTop);
	QVector<QPair<QVector<int> ,QVector<int> > > topsAndRobots;
	QVector<QVector<int> > mMatrix;
	QVector<int> mRobots;
	QStack<int> unvisitedTops;
	QStack<int> visitedTops;
	int currentClass;
};

#endif // MATRIXANALYZER_H
