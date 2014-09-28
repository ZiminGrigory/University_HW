#ifndef BASECALCULATOR_H
#define BASECALCULATOR_H
#pragma once
#include <QtCore/QString>
#include <fstream>
#include <iostream>

using namespace std;

struct TreeNode
{
    QString str;
    TreeNode *left;
    TreeNode *right;
};

struct Tree
{
    TreeNode *root;
};

class BaseCalculator
{
public: //i know that it is bad, but protected doesn't work
    ifstream inp;
    TreeNode *node;
    Tree *tree;
};

#endif // BASECALCULATOR_H
