#include "FileParser.h"

FileParser::FileParser(ifstream &file)
{
	int count = 0;
	int tmp = 0;
	file >> count;
	for (int i = 1; i <= count; i++){
		file >> tmp;
		matrix.append(tmp);
	}
}

QVector<int> FileParser::getVector()
{
	return matrix;
}
