#ifndef RBTREE_H
#define RBTREE_H
enum{ black = 0,
      red = 1 };

template <typename T>

class RBTree
{
public:
    RBTree() :root(NULL), unionRoot(NULL){}
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
    void intersectionOfSets(RBTree<T> *& tree1, RBTree<T> *& tree2);
    void setUnion(RBTree<T> *& tree1, RBTree<T> *& tree2);
private:
    struct Tree
    {
        T element;
        Tree *parent;
        Tree *leftChild;
        Tree *rightChild;
        int color;
    };
    void rotateLeft(Tree *tree);
    void rotateRight(Tree *tree);
    void insertFixup(Tree *tree);
    void deleteFixup(Tree *node);
    void destroy(Tree *&node);
    void traversalTreeForIntersec(RBTree<T> *& tree1, RBTree<T> *&tree2, Tree *&root);
    void traversalTreeForUnion(RBTree<T> *& tree1, RBTree<T> *&tree2, Tree *&root);
    Tree *root;
    Tree *unionRoot;
};


template <typename T>
void RBTree<T>::rotateLeft(Tree *tree) {
    Tree *temp = tree->rightChild;
    tree->rightChild = temp->leftChild;
    if (temp->leftChild != NULL) temp->leftChild->parent = tree;
    if (temp != NULL) temp->parent = tree->parent;
    if (tree->parent) {
        if (tree == tree->parent->leftChild)
            tree->parent->leftChild = temp;
        else
            tree->parent->rightChild = temp;
    } else {
        root = temp;
    }
    temp->leftChild = tree;
    if (tree != NULL) tree->parent = temp;
}

template <typename T>
void RBTree<T>::rotateRight(Tree *tree) {

    Tree *temp = tree->leftChild;
    tree->leftChild = temp->rightChild;
    if (temp->rightChild != NULL)
        temp->rightChild->parent = tree;
    if (temp != NULL)
        temp->parent = tree->parent;
    if (tree->parent) {
        if (tree == tree->parent->rightChild)
            tree->parent->rightChild = temp;
        else
            tree->parent->leftChild = temp;
    }
    else
        root = temp;
    temp->rightChild = tree;
    if (tree != NULL) tree->parent = temp;
}

template <typename T>
void RBTree<T>::insertFixup(Tree *tree) {
    while (tree != root && tree->parent->color == red) {
        if (tree->parent == tree->parent->parent->leftChild) {
            Tree *temp = tree->parent->parent->rightChild;
            if (temp->color == red) {
                tree->parent->color = black;
                temp->color = black;
                tree->parent->parent->color = red;
                tree = tree->parent->parent;
            }
            else{
                if (tree == tree->parent->rightChild) {
                    tree = tree->parent;
                    rotateLeft(tree);
                }
                tree->parent->color = black;
                tree->parent->parent->color = red;
                rotateRight(tree->parent->parent);
            }
        }
        else {
            Tree *temp = tree->parent->parent->leftChild;
            if (temp != NULL && temp->color == red) {
                tree->parent->color = black;
                temp->color = black;
                tree->parent->parent->color = red;
                tree = tree->parent->parent;
            }
            else {
                if (tree == tree->parent->leftChild) {
                    tree = tree->parent;
                    rotateRight(tree);
                }
                tree->parent->color = black;
                tree->parent->parent->color = red;
                rotateLeft(tree->parent->parent);
            }
        }
    }
    root->color = black;
}


template <typename T>
void  RBTree<T>::addElement(T element){
    Tree *current;
    Tree *parent;
    Tree *node;
    current = root;
    parent = 0;
    while (current != NULL) {
        if (element == current->element){
            return;
        }
        parent = current;
        if (element < current->element)
            current = current->leftChild;
        else
            current = current->rightChild;
    }
    node = new Tree;
    node->element = element;
    node->parent = parent;
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->color = red;

    if(parent) {
        if(element < parent->element)
            parent->leftChild = node;
        else
            parent->rightChild = node;
    }
    else
        root = node;

    insertFixup(node);
}

template <typename T>
void RBTree<T>::deleteFixup(Tree *node) {
    while (node != root && node->color == black) {
        if (node == node->parent->leftChild)
        {
            Tree *temp = node->parent->rightChild;
            if (temp->color == red) {
                temp->color = black;
                node->parent->color = red;
                rotateLeft (node->parent);
                temp = node->parent->rightChild;
            }
            if (temp->leftChild->color == black && temp->rightChild->color == black) {
                temp->color = red;
                node = node->parent;
            }
            else {
                if (temp->rightChild->color == black) {
                    temp->leftChild->color = black;
                    temp->color = red;
                    rotateRight (temp);
                    temp = node->parent->rightChild;
                }
                temp->color = node->parent->color;
                node->parent->color = black;
                temp->rightChild->color = black;
                rotateLeft (node->parent);
                node = root;
            }
        }
        else {
            Tree *temp = node->parent->leftChild;
            if (temp->color == red) {
                temp->color = black;
                node->parent->color = red;
                rotateRight (node->parent);
                temp = node->parent->leftChild;
            }
            if (temp->rightChild->color == black && temp->leftChild->color == black) {
                temp->color = red;
                node = node->parent;
            } else {
                if (temp->leftChild->color == black) {
                    temp->rightChild->color = black;
                    temp->color = red;
                    rotateLeft (temp);
                    temp = node->parent->leftChild;
                }
                temp->color = node->parent->color;
                node->parent->color = black;
                temp->leftChild->color = black;
                rotateRight (node->parent);
                node = root;
            }
        }
    }
    node->color = black;
}

template <typename T>
void RBTree<T>::deleteElement(T element) {
    Tree *current = root;
    while(current != NULL)
        if(element == current->element){
            break;
        }
        else
            if (element < current->element)
                current = current->leftChild;
            else
                current = current->rightChild;

    Tree *x = 0;
    Tree *temp = 0;

    if (current->leftChild == NULL || current->rightChild == NULL) {
        temp = current;
    }
    else {
        temp = current->rightChild;
        while (temp->leftChild != NULL)
            temp = temp->leftChild;
    }

    if (temp->leftChild != NULL)
        x = temp->leftChild;
    else
        x = temp->rightChild;
    if (x!= NULL)
        x->parent = temp->parent;

    if (temp->parent)
        if (temp == temp->parent->leftChild)
            temp->parent->leftChild = x;
        else
            temp->parent->rightChild = x;
    else
        root = x;

    if (temp != current)
        current->element = temp->element;


    if (temp->color == black)
        deleteFixup (x);

    //delete x;
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
void RBTree<T>::destroy(Tree *&node)
{
    if (node != NULL){
        while (!(node->leftChild == NULL && node->rightChild == NULL))
        {
            if  (node->leftChild != NULL)
            {
                if ((node->leftChild->leftChild == NULL && node->leftChild->rightChild == NULL))
                {
                    node->leftChild->parent = NULL;
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
                    node->rightChild->parent = NULL;
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
void RBTree<T>::traversalTreeForIntersec(RBTree<T> *&tree1, RBTree<T> *&tree2, Tree *&root)
{

    if (root == NULL)
        return;
    traversalTreeForIntersec(tree1,tree2,root->rightChild);
    if (tree2->search(root->element)){
        this->addElement(root->element);
    }
    traversalTreeForIntersec(tree1,tree2,root->leftChild);

}

template <typename T>
void RBTree<T>::traversalTreeForUnion(RBTree<T> *&tree1, RBTree<T> *&tree2, RBTree::Tree *&root)
{
    if (root == NULL)
        return;
    traversalTreeForUnion(tree1,tree2,root->rightChild);
    if (!this->search(root->element)){
        this->addElement(root->element);
    }
    traversalTreeForUnion(tree1,tree2,root->leftChild);
}

template <typename T>
void RBTree<T>::intersectionOfSets(RBTree<T> *&tree1, RBTree<T> *&tree2)
{
    traversalTreeForIntersec(tree1,tree2, *&tree1->root);
}

template <typename T>
void RBTree<T>::setUnion(RBTree<T> *&tree1, RBTree<T> *&tree2)
{
    traversalTreeForUnion(tree1,tree2,*&tree1->root);
    traversalTreeForUnion(tree1,tree2,*&tree2->root);
}

#endif // RBTREE_H
