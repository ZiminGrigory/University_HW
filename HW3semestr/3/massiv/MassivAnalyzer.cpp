#include "MassivAnalyzer.h"

MassivAnalyzer::MassivAnalyzer(QVector<int> massiv): massiv(massiv)
{
}

int MassivAnalyzer::getNumberOfNullElements()
{
	int countOfNull = 0;
	for (int i = 0; i < massiv.size(); i++){
		if (massiv[i] == 0){
			countOfNull++;
		}
	}
	return countOfNull;
}
