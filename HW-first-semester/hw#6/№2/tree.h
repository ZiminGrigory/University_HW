#pragma once
#include <stdio.h>
struct TreeNode
{
	char value;
	TreeNode *left;
	TreeNode *right;
};

struct Tree
{
	TreeNode *root;
};

Tree *createTree();
void Print(Tree *&tree, TreeNode *&node, FILE *inp);
void add(Tree *&tree, TreeNode *&node, FILE *inp);
void destroy(TreeNode *&node);
int count(Tree *&tree);