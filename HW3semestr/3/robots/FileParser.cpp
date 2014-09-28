#include "FileParser.h"

FileParser::FileParser(ifstream &file)
{
	int ribs = 0;
	int first = 0;
	int second = 0;
	int robot = 0;
	file >> tops;
	file >> numberOfrobots;
	file >> ribs;
	for (int i = 1; i <= ribs; i++){
		file >> first >> second;
		connections.append(QPair<int, int>(first, second));
	}
	for (int i = 1; i <= numberOfrobots; i++){
		file >> robot;
		robots.append(robot);
	}
}

int FileParser::getNumberOfTops()
{
	return tops;
}

QVector<int> FileParser::getRobots()
{
	return robots;
}

QVector<QVector<int> > FileParser::getMatrix()
{
	matrix.resize(tops);
	for (int i = 0; i < connections.size(); i++){
		matrix[connections[i].second].append(connections[i].first);
		matrix[connections[i].first].append(connections[i].second);
	}
	return matrix;
}
