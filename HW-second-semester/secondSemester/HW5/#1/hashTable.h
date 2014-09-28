#pragma once
#include <string.h>
#include <string>
#include "hasher.h"

using namespace std;

struct List;

class HashTable
{
public:
    HashTable();
    ~HashTable();
    void addValue(string line);
    void deleteValue(string line);
    bool searchValue(string line);
    void giveStatistics();
    void chooseHasher(Hasher *hasher);
private:
    Hasher *function;
    List **table;
    int numberOfCells;
    int theLongestChain;
};
