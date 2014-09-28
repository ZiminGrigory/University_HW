/**
  *pattern set, that implemented on a red-black tree
  *with using a pointer to the parent element
  *also implemented turns and rebalancing after adding and deleting an element in the search tree
  */


#pragma once
#include <QString>
#include "rbtree.h"

template <typename T>
class Set
{
public:
    Set(){
        rBTree = new RBTree<T>;
    }
    ~Set(){
        delete rBTree;
    }

    void addElement(T element);
    void deleteElement(T element);
    bool isEmpty(){
        return rBTree->isEmpty();
    }
    bool search(T element);
    void intersectionOfSets(Set<T> * object1 ,Set<T> *object2);
    void setUnion(Set<T> * object1 ,Set<T> *object2);
private:
    RBTree<T> *rBTree;
};

template <typename T>
void Set<T>::addElement(T element)
{
    rBTree->addElement(element);
}

template <typename T>
void Set<T>::deleteElement(T element)
{
    rBTree->deleteElement(element);
}

template <typename T>
bool Set<T>::search(T element)
{
    return rBTree->search(element);
}

template <typename T>
void Set<T>::intersectionOfSets(Set<T> * object1, Set<T> *object2)
{
    rBTree->intersectionOfSets(*&object1->rBTree,*&object2->rBTree);
}

template <typename T>
void Set<T>::setUnion(Set<T> * object1, Set<T> *object2)
{
    rBTree->setUnion(*&object1->rBTree,*&object2->rBTree);
}


