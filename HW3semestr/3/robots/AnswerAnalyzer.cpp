#include "AnswerAnalyzer.h"

AnswerAnalyzer::AnswerAnalyzer(QVector<QVector<int> > robotsAndTops):
	mRobotsAndTops(robotsAndTops)
{
}

bool AnswerAnalyzer::getAnswer()
{
	for (int i = 0; i < mRobotsAndTops.size(); i++){
		if (mRobotsAndTops[i].size() <= 1){
			return false;
		}
	}
	return true;
}
