#pragma once
#include <iostream>
#include <QString>

using namespace std;

class Node
{
public:
    virtual ~Node();
    Node *&getLeftChild();
    Node *&getRightChild();
    virtual void print()=0;
    virtual double calculate()=0;
    void setLeftChild();
    void setRightChild();
protected:
    Node *leftChild;
    Node *rightChild;
};
