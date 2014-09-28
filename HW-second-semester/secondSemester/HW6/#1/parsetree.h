#ifndef PARSETREE_H
#define PARSETREE_H
#pragma once
#include <QString>
#include "fstream"
#include "node.h"
#include "operand.h"
#include "operator.h"

using namespace std;

class ParseTree
{
public:
    ParseTree() : root(NULL){}
    ~ParseTree();
    void makeTreeFromFile();
    void setFileName(QString str);
    double calculate();
    void print();
private:
    void makeTree(Node *&node, ifstream &inp);
    Node *root;
    ifstream inp;
};

#endif // PARSETREE_H
