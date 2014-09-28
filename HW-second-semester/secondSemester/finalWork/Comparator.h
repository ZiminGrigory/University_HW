#pragma once
class Exception{};

template <typename T>
class Comparator
{
public:
    virtual ~Comparator(){}
    virtual bool compare(T elementFirst,T elementSecond)=0;
};

template <typename T>
class isBigger:public Comparator<T>
{
    bool compare(T elementFirst,T elementSecond)
    {
        return elementFirst > elementSecond;
    }
};


template <typename T>
class isBiggerFractionOfOneBelowSMTH:public Comparator<T>
{
    bool compare(T elementFirst,T elementSecond)
    {
        if (elementFirst != 0 && elementSecond !=0)
            return 1/elementFirst > 1/elementSecond;
        else throw Exception();
    }
};

