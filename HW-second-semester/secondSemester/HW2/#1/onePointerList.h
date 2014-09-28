#pragma once
#include "list.h"

struct ListElement;

class OnePointerList : public List
{
public:
    OnePointerList();
    virtual ~OnePointerList();
    virtual void add(int value);
    virtual void deleteEl(int value);
    virtual void print();
    bool exist(int value);

protected:
    ListElement* head;
    int number;
};
