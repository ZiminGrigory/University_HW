/**
  *program to work with exceptions.
  *implements a list in which each element occurs only 1 time.
*/

#ifndef UNIQUELIST_H
#define UNIQUELIST_H
#include "List.h"

template <typename T>
class UniqueList: public List<T>
{
public:
    class RepeatAdd{};
    class ItemHaveNotExist{};
    void addElement(T value)
    {
        if (exist(value))
            throw RepeatAdd();
        else
            List<T>::addElement(value);
    }
    void deleteElement(T value)
    {
        if (!exist(value))
            throw ItemHaveNotExist();
        else
            List<T>::deleteElement(value);
    }
};

#endif // UNIQUELIST_H
