#ifndef MASSIVANALYZER_H
#define MASSIVANALYZER_H
#include <QVector>
/**
 * @brief The MassivAnalyzer class нализирирует массив принимая его как вектор
 */
class MassivAnalyzer
{
public:
	MassivAnalyzer(QVector<int> massiv);
	/**
	 * @brief getNumberOfNullElements
	 * @return озвращает кол-во нулевых элементов в массиве данных
	 */
	int getNumberOfNullElements();

private:
	QVector<int> massiv;
};

#endif // MASSIVANALYZER_H
