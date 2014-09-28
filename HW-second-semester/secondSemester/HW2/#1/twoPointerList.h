#pragma once
#include "list.h"

struct ListElementTPL;

class TwoPointerList : public List
{
public:
    TwoPointerList();
    virtual ~TwoPointerList();
    virtual void add(int value);
    virtual void deleteEl(int value);
    virtual void print();
    bool exist(int value);
protected:
    ListElementTPL* head;
    int number;
};
