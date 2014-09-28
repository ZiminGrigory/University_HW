#pragma once

#include <iostream>
#include <fstream>
#include <limits.h>
#include "graph.h"
using namespace std;

struct List
{
	int top;
	int weight;
	List *next;
};

List **createAndFilling(int n, int m, ifstream &inp);

void deleteGraph(List **&a, int n);

List **createListsOfWay(int n);

void deleteWay(List *&way);

void processingWays(List **&way, List **a, List *temp,  int minIndex);