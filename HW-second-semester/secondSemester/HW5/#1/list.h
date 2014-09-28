#pragma once
#include <string.h>
#include <string>
using namespace std;

struct List{
 string line;
 List *next;
};

void addElem(List *&table, string line, int &theLongestChain);
bool isExist(List *table, string line);
List **createTable(int n);
void destroy(List **table, int n);
void deleteEl(List *&table, string line);
