#ifndef ANSWERANALYZER_H
#define ANSWERANALYZER_H
#include <QVector>
#include <QPair>
#include <QList>
#include <QSharedPointer>

class AnswerAnalyzer
{
public:
	AnswerAnalyzer(QVector<QVector<int> > robotsAndTops);
	/**
	 * @brief getAnswer
	 * @return возвращает ответ на задачу Y/N
	 */
	bool getAnswer();

private:
	QVector<QVector<int> > mRobotsAndTops;
};

#endif // ANSWERANALYZER_H
