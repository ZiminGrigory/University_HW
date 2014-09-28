#include "list.h"

List **createTable(int n)
{
    List **table = new List *[n];
    for (int i = 0; i < n; i++)
        table[i] = NULL;
    return table;
}

void destroy(List **table, int n)
{
    for (int i = 0; i < n; i++)
        while (table[i] != NULL)
        {
            List *tmp = table[i];
            table[i] = table[i]->next;
            delete tmp;
        }
    for (int i = 0; i < n; i++)
        delete table[i];
    delete []table;
}

void addElem(List *&table, string line, int &theLongestChain)
{
    int numberOfElements = 0;
    if (table == NULL)
    {
        table = new List;
        table->line = line;
        table->next = NULL;
        numberOfElements++;
    }
    else
    {
        numberOfElements = 1;
        List *tmp = table;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            numberOfElements++;
        }
        tmp->next = new List;
        tmp->next->line = line;
        tmp->next->next = NULL;
        numberOfElements++;
    }
    if (numberOfElements > theLongestChain)
        theLongestChain = numberOfElements;
}

bool isExist(List *table, string line)
{
    if (table != NULL)
    {
        List *tmp = table;
        if (tmp->line == line)
                return true;
        else
            while ((tmp->line != line) && (tmp->next != NULL))
            {
                tmp = tmp->next;
                if (tmp->line == line)
                    return true;
            }
    }
    return false;
}

void deleteEl(List *&table, string line)
{
    if (table->line == line)
    {
        List *tmp = table;
        table = table->next;
        delete tmp;
    }
    else
    {
        List *tmp = table;
        while (tmp->next->line != line)
            tmp = tmp->next;
        List *tmpDel = tmp->next;
        tmp->next = tmp->next->next;
        delete tmpDel;
    }
}
