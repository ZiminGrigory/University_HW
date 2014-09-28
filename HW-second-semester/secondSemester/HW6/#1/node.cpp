#include "node.h"

void Node :: setLeftChild()
{
    leftChild = NULL;
}

void Node::setRightChild()
{
    rightChild = NULL;
}

Node::~Node()
{
    delete leftChild;
    delete rightChild;
    //cout << "delete\n"; check destructor
}

Node *&Node::getLeftChild()
{
    return leftChild;
}

Node *&Node::getRightChild()
{
    return rightChild;
}
