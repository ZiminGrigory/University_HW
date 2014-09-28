#include "MatrixAnalyzer.h"

MatrixAnalyzer::MatrixAnalyzer(QVector<QVector<int> > matrix, QVector<int> robots):
	mMatrix(matrix), mRobots(robots), currentClass(-1)
{
}

QVector<QVector<int> > MatrixAnalyzer::getRobotsAttainableOneTops()
{
	for (int i = 0; i < mMatrix.size(); i++){
		if(!visitedTops.contains(i)){
			currentClass++;
			topsAndRobots.append(QPair<QVector<int> ,QVector<int> >());
			unvisitedTops.append(i);

			while (unvisitedTops.size() != 0){
				int tmp = unvisitedTops.pop();
				if (!topsAndRobots[currentClass].first.contains(tmp)){
					topsAndRobots[currentClass].first.append(tmp);
				}
				if (mRobots.contains(tmp) && !topsAndRobots[currentClass].second.contains(tmp)){
					topsAndRobots[currentClass].second.append(tmp);
				}
				if(mMatrix[tmp].size() != 0){
					for(int i = 0; i < mMatrix[tmp].size(); i++){
						getTopsAfterMiddleTop(mMatrix[tmp][i], tmp);
					}
					if (!visitedTops.contains(tmp)){
						visitedTops.push(tmp);
					}
				}
			}
		}
	}
	QVector<QVector<int> > robots;
	for (int i = 0; i < topsAndRobots.size(); i++){
		if (topsAndRobots[i].second.size() != 0){
			robots.append(QVector<int>());
			robots.last() = topsAndRobots[i].second;
		}
	}
	return robots;
}

void MatrixAnalyzer::getTopsAfterMiddleTop(int top, int currentTop)
{
	for(int i = 0; i < mMatrix[top].size(); i++){
		if(!visitedTops.contains(mMatrix[top][i]) &&  mMatrix[top][i] != currentTop
				&& !topsAndRobots[currentClass].first.contains(i)){
			unvisitedTops.push(mMatrix[top][i]);
		}
	}
}
