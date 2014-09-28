#pragma once

class List
{
public:
    virtual ~List()
    {
    }
    virtual void add(int value) = 0;
    virtual void deleteEl(int value) = 0;
    virtual void print() = 0;
    virtual bool exist(int value) = 0;
};
