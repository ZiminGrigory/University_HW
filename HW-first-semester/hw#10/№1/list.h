#pragma once
#include <iostream>
using namespace std;

struct List
{
	int a;
	int deg;
	List *next;
};

void feeling(List *&list);

bool equals(List *p, List *q);

void destroy(List *&list);

int value(int x, List *p);

void add(List *list, List *listSec, List *&listThird);

void print(List *&listThird);