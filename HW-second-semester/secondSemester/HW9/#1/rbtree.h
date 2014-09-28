
/**
  class RBtree contains iterator with methods next() hasNext add() remove()
  */
#pragma once
#include <iostream>
#include <QList>

enum{ black = 0,
      red = 1 };
template <typename T>
struct Tree;

template <typename T>
class RBTree
{
public:
    RBTree() :root(NULL), head(NULL),deleteElementForIterator(NULL)
    {}
    ~RBTree()
    {
        destroy(root);
        delete root;
    }
    bool isEmpty(){
        return root == NULL;
    }

    void addElement(T element);
    void deleteElement(T element);
    bool search(T element);
    unsigned int searchCount(T element);
    class Iterator;
private:
    struct Tree
    {
        T element;
        unsigned int count;
        Tree *leftChild;
        Tree *rightChild;
        int color;
    };
    struct List
    {
        Tree *element;
        List *next;
        List *previous;
    };
    List *head;
    Tree *deleteElementForIterator;
    void destroy(Tree *&node);
    Tree *root;
    List *pointerTemp;
    unsigned int nPath;
    void includeElement(Tree *&node, T element);
    void destroyList();
    void addPointer(Tree *&tmpPointer);
    Tree *leftRotate(Tree *&node)
    {
        Tree *temp = node->rightChild;
        Tree *temp2 = node->rightChild->leftChild;
        temp->leftChild = node;
        temp->leftChild->rightChild = temp2;
        return temp;
    }
    Tree* rightRotate(Tree *&node)
    {
        Tree *temp = node->leftChild;
        Tree *temp2 = node->leftChild->rightChild;
        temp->rightChild = node;
        temp->rightChild->leftChild = temp2;
        return temp;
    }
    Tree* getPointerOnNode(T element)
    {
        Tree *current = root;
        while(current != NULL)
            if(element == current->element)
                return current;
            else
                if (element < current->element)
                    current = current->leftChild;
                else
                    current = current->rightChild;
    }
    void includeFix3();
    void includeFix4();
    void includeFix5();
    void deleteCase1();
    void deleteCase2();
    void deleteCase3();
    void deleteCase4();
    void deleteCase5();
    void deleteCase6();
    Tree *parent;

};

template <typename T>
void RBTree<T>::destroy(Tree *&node)
{
    if (node != NULL){
        while (!(node->leftChild == NULL && node->rightChild == NULL))
        {
            if  (node->leftChild != NULL)
            {
                if ((node->leftChild->leftChild == NULL && node->leftChild->rightChild == NULL))
                {
                    delete node->leftChild;
                    node->leftChild = NULL;
                }
                else
                    destroy(node->leftChild);
            }
            if  (node->rightChild != NULL)
            {
                if ((node->rightChild->leftChild == NULL && node->rightChild->rightChild == NULL))
                {
                    delete node->rightChild;
                    node->rightChild = NULL;
                }
                else
                    destroy(node->rightChild);
            }
        }
    }
}

template <typename T>
void RBTree<T>::includeElement(RBTree::Tree *&node, T element)
{
    if (root == NULL) //includeFix1
    {
        node = new Tree;
        node->element = element;
        node->color = black;
        node->count = 1;
        node->leftChild = NULL;
        node->rightChild = NULL;
        return;
    }

    if (node != NULL){
        addPointer(node);
        nPath++;
    }
    else
    {
        node = new Tree;
        node->element = element;
        node->color = red;
        node->count = 1;
        node->leftChild = NULL;
        node->rightChild = NULL;
        addPointer(node);
        nPath++;
        return;
    }

    if (element < node->element)
          includeElement(node->leftChild, element);
    else if (element > node->element)
        includeElement(node->rightChild, element);

    includeFix3();
    includeFix4();
    includeFix5();
    //change
    pointerTemp = pointerTemp->previous;
    nPath--;
    root->color = black;
    //change
}

template <typename T>
void RBTree<T>::destroyList()
{
    List *tmp = head;
    while (head != NULL)
    {
        head = head->next;
        delete tmp;
        tmp = head;
    }
}

template <typename T>
void RBTree<T>::addPointer(Tree *&tmpPointer)
{
    if (head == NULL)
    {
        pointerTemp = new List;
        pointerTemp->next = NULL;
        pointerTemp->previous = NULL;
        pointerTemp->element = tmpPointer;
        head = pointerTemp;
        return;
    }
    pointerTemp->next = new List;
    pointerTemp->next->previous = pointerTemp;
    pointerTemp = pointerTemp->next;
    pointerTemp->element = tmpPointer;
    pointerTemp->next = NULL;
}


template <typename T>
void RBTree<T>::includeFix3()
{
    Tree *pNode, *pParent, *pGrandParent, *pUncle; //p = pointer
    if (nPath < 3) return;

    pNode = pointerTemp->element;
    if (pNode->color == black) return;

    pParent = pointerTemp->previous->element;
    if (pParent->color == black) return; // includeFix2

    pGrandParent = pointerTemp->previous->previous->element;

    if (pParent == pGrandParent->leftChild)
        pUncle = pGrandParent->rightChild;
    else if (pParent == pGrandParent->rightChild)
        pUncle = pGrandParent->leftChild;

    if (pUncle != NULL && pUncle->color == red)
    {
        pParent->color = black;
        pUncle->color = black;
        pGrandParent->color = red;
    }
}

template <typename T>
void RBTree<T>::includeFix4()
{
    Tree *pNode, *pParent, *pGrandParent, *pUncle, *pTemp; //p = pointer
    if (nPath < 3) return;

    pNode = pointerTemp->element;
    if ( pNode->color == black) return;

    pParent = pointerTemp->previous->element;
    if ( pParent->color == black) return;// includeFix2

    pGrandParent = pointerTemp->previous->previous->element;

    if (pParent == pGrandParent->leftChild)
    {
        if (pNode == pParent->leftChild) return;
        pUncle = pGrandParent->rightChild;
        if (pUncle != NULL && pUncle->color == red) return;

        pTemp = pNode->leftChild;
        pNode->leftChild = pParent;
        pGrandParent->leftChild = pNode;
        pParent->rightChild = pTemp;
     }
     else
     if (pParent == pGrandParent->rightChild)
     {
        if (pNode == pParent->rightChild) return;
        pUncle = pGrandParent->leftChild;
        if (pUncle != NULL && pUncle->color == red) return;
        pTemp = pNode->rightChild;
        pNode->rightChild = pParent;
        pGrandParent->rightChild = pNode;
        pParent->leftChild = pTemp;
      }
      pointerTemp->previous->element = pNode;
      pointerTemp->element = pParent;
}

template <typename T>
void RBTree<T>::includeFix5()
{
    Tree *pNode, *pParent, *pGrandParent, *pGrandGrandParent, *pUncle, *pTemp; //p = pointer

    if (nPath <3) return;

    pNode = pointerTemp->element;
    if (pNode->color != red) return;
    pParent = pointerTemp->previous->element;
    if (pParent->color != red) return; // includeFix2
    pGrandParent = pointerTemp->previous->previous->element;
    if (pParent == pGrandParent->leftChild){
        pUncle = pGrandParent->rightChild;
        if (pUncle != NULL && pUncle->color == red) return;
        pTemp = pParent->rightChild;
        pParent->rightChild = pGrandParent;
        pGrandParent->leftChild = pTemp;
    }
    else
        if (pParent == pGrandParent->rightChild)
        {
            pUncle = pGrandParent->leftChild;
            if (pUncle != NULL && pUncle->color == red) return;
            pTemp = pParent->leftChild;
            pParent->leftChild = pGrandParent;
            pGrandParent->rightChild = pTemp;
        }

    pParent->color = black;
    pGrandParent->color = red;

    if (pGrandParent == root)
    {
        root = pParent;
        head->element = pParent;
        head->next->element = pNode;

        pointerTemp = head->next;
        return;
    }

    pGrandGrandParent = pointerTemp->previous->previous->previous->element;

    if (pGrandParent == pGrandGrandParent->leftChild)
        pGrandGrandParent->leftChild = pParent;
    else
    if (pGrandParent == pGrandGrandParent->rightChild)
        pGrandGrandParent->rightChild = pParent;

    pointerTemp->previous->previous->element = pParent;
    pointerTemp->previous->element = pNode;

    nPath--;
    List *temp = head;
    for (int i = 1; i <= nPath; i++)
        temp = temp->next;
    pointerTemp = temp->previous;
}

template <typename T>
void RBTree<T>::deleteCase1()
{
    if (pointerTemp->previous != NULL)
        deleteCase2();
}

template <typename T>
void RBTree<T>::deleteCase2()
{
    Tree *sibling;
    if (pointerTemp->element == pointerTemp->previous->element->leftChild)
        sibling = pointerTemp->previous->element->rightChild;
    else
        sibling = pointerTemp->previous->element->leftChild;
    Tree *delElement = pointerTemp->element;

    if (sibling->color == red)
    {
        pointerTemp->previous->element->color = red;
        sibling->color = black;
        if (pointerTemp->element == pointerTemp->previous->element->leftChild)
        {
            if(pointerTemp->previous->previous != NULL)
            {
                if (pointerTemp->previous->previous->element->leftChild == pointerTemp->previous->element)
                    pointerTemp->previous->previous->element->leftChild = leftRotate(pointerTemp->previous->element);
                else
                    pointerTemp->previous->previous->element->rightChild = leftRotate(pointerTemp->previous->element);

                List*temp = pointerTemp->previous->previous;
                while (temp->element != delElement)
                {
                    if (delElement->element < temp->element->count)
                    {
                        temp->next->element = temp->element->leftChild;
                        temp->next->previous = temp;
                        temp = temp->next;
                    }
                    else
                    {
                        temp->next->element = temp->element->rightChild;
                        temp->next->previous = temp;
                        temp = temp->next;
                    }
                }
                pointerTemp = temp;
            }
            else
            {
                root = leftRotate(pointerTemp->previous->element);
                destroyList();
                Tree*temp = root;
                addPointer(temp);
                while (temp->element != delElement->element)
                {
                    if (delElement->element < temp->element)
                    {
                        temp = temp->leftChild;
                        addPointer(temp);
                    }
                    else
                    {
                        temp = temp->rightChild;
                        addPointer(temp);
                    }
                }
            }
        }
        else
        {
            if(pointerTemp->previous->previous != NULL)
            {
                if (pointerTemp->previous->previous->element->leftChild == pointerTemp->previous->element)
                    pointerTemp->previous->previous->element->leftChild = rightRotate(pointerTemp->previous->element);
                else
                    pointerTemp->previous->previous->element->rightChild = rightRotate(pointerTemp->previous->element);

                List*temp = pointerTemp->previous->previous;
                while (temp->element != delElement)
                {
                    if (delElement->element < temp->element->count)
                    {
                        temp->next->element = temp->element->leftChild;
                        temp->next->previous = temp;
                        temp = temp->next;
                    }
                    else
                    {
                        temp->next->element = temp->element->rightChild;
                        temp->next->previous = temp;
                        temp = temp->next;
                    }
                }
                pointerTemp = temp;
            }
            else
            {
                root = rightRotate(pointerTemp->previous->element);
                destroyList();
                Tree*temp = root;
                addPointer(temp);
                while (temp->element != delElement->element)
                {
                    if (delElement->element < temp->element)
                    {
                        temp = temp->leftChild;
                        addPointer(temp);
                    }
                    else
                    {
                        temp = temp->rightChild;
                        addPointer(temp);
                    }
                }
            }
        }

    }
    deleteCase3();
}

template <typename T>
void RBTree<T>::deleteCase3()
{
    Tree *sibling;
    if (pointerTemp->element == pointerTemp->previous->element->leftChild)
        sibling = pointerTemp->previous->element->rightChild;
    else
        sibling = pointerTemp->previous->element->leftChild;
    if ((pointerTemp->previous->element->color == black) &&
        (sibling->color == black) &&
        (sibling->leftChild == NULL || sibling->leftChild->color == black) &&
        (sibling->rightChild == NULL || sibling->rightChild->color == black))
    {
        sibling->color = red;
        pointerTemp = pointerTemp->previous;
        nPath--;
        deleteCase1();
    } else
        deleteCase4();
}

template <typename T>
void RBTree<T>::deleteCase4()
{
    Tree *sibling;
    if (pointerTemp->element == pointerTemp->previous->element->leftChild)
        sibling = pointerTemp->previous->element->rightChild;
    else
        sibling = pointerTemp->previous->element->leftChild;

    if ((pointerTemp->previous->element->color == red) &&
    (sibling->color == black) &&
    (sibling->leftChild == NULL || sibling->leftChild->color == black) &&
    (sibling->rightChild == NULL || sibling->rightChild->color == black))
    {
        sibling->color = red;
        pointerTemp->previous->element->color = black;
    }
    else
        deleteCase5();
}

template <typename T>
void RBTree<T>::deleteCase5()
{
    Tree *sibling;
    Tree *delElement = pointerTemp->element;
    if (pointerTemp->element == pointerTemp->previous->element->leftChild)
        sibling = pointerTemp->previous->element->rightChild;
    else
        sibling = pointerTemp->previous->element->leftChild;

    if  (sibling->color == black
         &&(sibling->rightChild->color == black || sibling->rightChild->color == NULL)
         &&(sibling->leftChild->color != NULL && sibling->leftChild->color == red))
    {
        if ((pointerTemp->element == pointerTemp->previous->element->leftChild) &&
        (sibling->rightChild->color == black) &&
        (sibling->leftChild->color == red))
        {
            sibling->color = red;
            sibling->leftChild->color = black;
            pointerTemp->previous->element->leftChild = rightRotate(sibling);
        }
        else if ((pointerTemp->element == pointerTemp->previous->element->rightChild) &&
                (sibling->leftChild->color == black) &&
                (sibling->rightChild->color == red))
                {
                    sibling->color = red;
                    sibling->rightChild->color = black;
                    pointerTemp->previous->element->rightChild = leftRotate(sibling);
                }
        List*temp = pointerTemp->previous;
        while (temp->element != delElement)
        {
            if (delElement->element < temp->element->count)
            {
                temp->next->element = temp->element->leftChild;
                temp->next->previous = temp;
                temp = temp->next;
            }
            else
            {
                temp->next->element = temp->element->rightChild;
                temp->next->previous = temp;
                temp = temp->next;
            }
        }
        pointerTemp = temp;
    }
    deleteCase6();
}

template <typename T>
void RBTree<T>::deleteCase6()
{
    Tree *sibling;
    if (pointerTemp->element == pointerTemp->previous->element->leftChild)
        sibling = pointerTemp->previous->element->rightChild;
    else
        sibling = pointerTemp->previous->element->leftChild;
    Tree *delElement = pointerTemp->element;
    sibling->color = pointerTemp->previous->element->color;
    pointerTemp->previous->element->color = black;

    if (pointerTemp->element != pointerTemp->previous->element->rightChild)
    {
        sibling->rightChild->color = black;
        if(pointerTemp->previous->previous != NULL)
        {
            if (pointerTemp->previous->previous->element->leftChild == pointerTemp->previous->element)
                pointerTemp->previous->previous->element->leftChild = leftRotate(pointerTemp->previous->element);
            else
                pointerTemp->previous->previous->element->rightChild = leftRotate(pointerTemp->previous->element);
        }
        else
        {
            root = leftRotate(pointerTemp->previous->element);
        }
    }

    else
    {
        sibling->leftChild->color = black;
        if(pointerTemp->previous->previous != NULL)
        {
            if (pointerTemp->previous->previous->element->leftChild == pointerTemp->previous->element)
                pointerTemp->previous->previous->element->leftChild = rightRotate(pointerTemp->previous->element);
            else
                pointerTemp->previous->previous->element->rightChild = rightRotate(pointerTemp->previous->element);
        }
        else
        {
            root = rightRotate(pointerTemp->previous->element);
        }
    }
}


template <typename T>
void RBTree<T>::addElement(T element)
{
    nPath = 0;
    if (!search(element))
        includeElement(root, element);
    else{
        Tree *temp = root;
        while(temp->element != element)
        {
            if(temp->element > element)
                temp = temp->leftChild;
            else
                temp = temp->rightChild;
        }
        temp->count++;
    }
    destroyList();
}

template <typename T>
void RBTree<T>::deleteElement(T element)
{
    if (searchCount(element) == 0)
        return;
    if (searchCount(element) > 1)
    {
        Tree *current = root;
        while(current != NULL)
            if(element == current->element)
            {
                current->count--;
                return;
            }
            else
                if (element < current->element)
                    current = current->leftChild;
                else
                    current = current->rightChild;
    }
    else
    {
        nPath = 0;
        Tree *delElement;
        Tree *current = root;
        while(element != current->element)
        {
            addPointer(current);
            nPath++;
            if (element < current->element)
                current = current->leftChild;
            else
                current = current->rightChild;
        }
        addPointer(current);
        nPath++;
        if (current == root
                && current->leftChild == NULL
                && current->rightChild == NULL) // case 0
        {
            deleteElementForIterator = current;
            delete root;
            root = NULL;
            return;
        }

        if ((current->color == red &&
                current->leftChild == NULL
                && current->rightChild == NULL)
                || (pointerTemp->previous != NULL &&
                    (pointerTemp->previous->element->color == red
                    && (pointerTemp->previous->element->leftChild ==NULL
                        || pointerTemp->previous->element->leftChild ==NULL )))) // 1fixup is leaf, red-colored
        {
            if (current == pointerTemp->previous->element->leftChild)
                pointerTemp->previous->element->leftChild = NULL;
            else
                pointerTemp->previous->element->rightChild = NULL;
            deleteElementForIterator = current;
            delete current;
            destroyList();
            return;
        }
        delElement = current;
        if (current->rightChild != NULL)//2fixup swaped-element is red
        {
            current = current->rightChild;
            addPointer(current);
            nPath++;
            while (current->leftChild != NULL)
            {
                current = current->leftChild;
                addPointer(current);
                nPath++;
            }
            if ((current->color == red &&
                    current->leftChild == NULL
                    && current->rightChild == NULL)
                    || (pointerTemp->previous->element->color == red
                        && (pointerTemp->previous->element->leftChild ==NULL
                            || pointerTemp->previous->element->leftChild ==NULL )))
            {
                delElement->count = current->count;
                delElement->element = current->element;
                if (current == pointerTemp->previous->element->leftChild)
                    pointerTemp->previous->element->leftChild = NULL;
                else
                    pointerTemp->previous->element->rightChild = NULL;
                deleteElementForIterator = current;
                delete current;
                destroyList();
                return;
            }
        }
        // case where current is black...
        if (current->color == black && current->element != element)
        {
            delElement->count = current->count;
            delElement->element = current->element;
            delElement->color = current->color;
            parent = pointerTemp->previous->element;
            deleteCase1();
            if (current == parent->leftChild)
                parent->leftChild = NULL;
            else
                parent->rightChild = NULL;
            deleteElementForIterator = current;
            delete current;
        }
        else if (current->color == black && current->element == element)
        {
            parent = pointerTemp->previous->element;
            deleteCase1();
            if (current == parent->leftChild)
                parent->leftChild = NULL;
            else
                parent->rightChild = NULL;
            deleteElementForIterator = current;
            delete current;
            destroyList();
        }
    }
}

template <typename T>
bool RBTree<T>::search(T element) {
    Tree *current = root;
    while(current != NULL)
        if(element ==current->element)
            return true;
        else
            if (element < current->element)
                current = current->leftChild;
            else
                current = current->rightChild;
    return false;
}

template <typename T>
unsigned int RBTree<T>::searchCount(T element) {
    if (!search(element))
        return 0;
    else
    {
        Tree *current = root;
        while(current != NULL)
            if(element ==current->element)
                return current->count;
            else
                if (element < current->element)
                    current = current->leftChild;
                else
                    current = current->rightChild;
    }
}


template <typename T>
class RBTree<T>::Iterator
{
public:
    explicit Iterator(RBTree<T> *tree)
        : thisTree(tree), index(0)
    {
    }

    ~Iterator()
    {
        myList.clear();
    }

    T next()
    {
        if (index < myList.size())
            index++;
        else throw;
        Tree *node = myList.at(index-1);
        return node->element;
    }

    bool hasNext()
    {
        return (index < myList.size());
    }

    void add(T element)
    {
        index++;
        thisTree->addElement(element);
        myList.append(thisTree->getPointerOnNode(element));
    }

    void setIndexToOne()
    {
        index = 0;
    }

    void remove()
    {
        if (index <= myList.size())
        {
            Tree *node = myList.at(index);
            thisTree->deleteElement(node->element);
            myList.removeOne(thisTree->deleteElementForIterator);
            if (index != 1)
                index--;
            if ((index == 0 || index == -1) && myList.size() >= 1)
                index++;
        }
        else throw;
    }

private:
    RBTree<T> *thisTree;
    int index;
    QList <RBTree<T>::Tree *> myList;
};
