#include <iostream>
#include "hashTable.h"
#include "list.h"
using namespace std;

enum{
    n = 1000
};



HashTable::HashTable()
{
    table = createTable(n);
    Hasher *function;
    numberOfCells = 0;
    theLongestChain = 0;
}

HashTable::~HashTable()
{
    destroy(table, n);
}

void HashTable::chooseHasher(Hasher *hasher)
{
    int imaginTmp = 0;
    function = hasher;
    List **tableTmp = createTable(n);
    for (int i =0; i < n; i++)
    {
        List* tmp = table[i];
        while (tmp != NULL)
        {
            int index = 0;
            index = function->hashFunction(tmp->line, n);
            addElem(tableTmp[index], tmp->line, imaginTmp);
            tmp = tmp->next;
        }
    }
    theLongestChain = imaginTmp;
    destroy(table,n);
    table = tableTmp;
}


void HashTable::addValue(string line)
{
    int index = 0;
    index = function->hashFunction(line, n);
    addElem(table[index], line, theLongestChain);
    numberOfCells++;
}

bool HashTable::searchValue(string line)
{
    int index = 0;
    index = function->hashFunction(line, n);
    if (table[index] == NULL)
        return false;
    else
        return isExist(table[index], line);
    return false;
}

void HashTable::deleteValue(string line)
{
    int index = 0;
    index = function->hashFunction(line, n);
    if (searchValue(line))
    {
        deleteEl(table[index], line);
        numberOfCells--;
    }
}

void HashTable::giveStatistics()
{
    cout << "\n\n statistics: \n" <<
            "number of cells: " << numberOfCells <<
            "\n the Longest Chain: " << theLongestChain <<
            "\n load factor: " << double (numberOfCells) / n << "% \n\n";
}


