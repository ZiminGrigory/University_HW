#include <iostream>
#include <stdlib.h>
#include "tree.h"

using namespace std;


Tree *createTree()
{
	Tree *tree = new Tree;
	tree->root = NULL;
	return tree;
}

TreeNode *leftmostChild(TreeNode *node)
{
	if (node->left != NULL)
		return leftmostChild(node->left);
	else
		return node;
}

bool exists(TreeNode *root, char value)
{
	if (root == NULL)
		return false;
	if (root->value == value)
		return true;
	if (root->value > value)
		return exists(root->left, value);
	else
		return exists(root->right, value);
}

bool exists(Tree *tree, char value)
{
	return exists(tree->root, value);
}

TreeNode *createNode(char value)
{
	TreeNode *node = new TreeNode;
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

bool isLeaf(TreeNode *node)
{
	return (node->left == NULL && node->right == NULL);\
}

bool hasOneChild(TreeNode *node)
{
	return ((node->left != NULL && node->right == NULL)
		|| (node->left == NULL && node->right != NULL));
}

bool isAction(char c)
{
	return ((c == '*')||(c == '/')||(c == '+')||(c == '-'));
}

int toInteger (char c)
{
	char toInt = '0';
	return c - toInt;
}

void Print(Tree *&tree, TreeNode *&node, FILE *inp)// написать
{
	if (isAction(node->value))
	{
		cout << "(" << node->value << " ";
		if (isAction(node->left->value))
			Print(tree, node->left,inp);
		else
		{
			cout << node->left->value << " ";
		}
		if (isAction(node->right->value))
			Print(tree, node->right,inp);
		else{
			cout << node->right->value << " ";
		}
		cout << ")";
	}
	else{
		cout << node->value << " ";
		Print(tree, node->left,inp);
		Print(tree, node->right,inp);
	}
}

void add(Tree *&tree, TreeNode *&node, FILE *inp){
	char s;
	do{
		s = getc(inp);
		if (isAction(s))
		{
			node = new TreeNode;
			node->left = NULL;
			node->right = NULL;
			node->value = s;
			add(tree,node->left, inp);
			add(tree,node->right, inp);
		}
		else if ((s != '(') && (s != ')') && (s != ' '))
		{
			node = new TreeNode;
			node->left = NULL;
			node->right = NULL;
			node->value = s;
			return;
		}
		else if (s == ')')
			return;

	}	
	while (!feof(inp));
}

int calculate(int argFirst, int argumentSec, char action)
{
	switch(action)
		{
			case '+': return argFirst + argumentSec;
				break;
			case '-': return argFirst - argumentSec; 
				break;
			case '*': return argFirst * argumentSec; 
				break;
			case '/': return argFirst / argumentSec;
				break;
		}
}

int calcChild(TreeNode *node)
{
	if (!isAction(node->value))
		return toInteger(node->value);	
	return calculate(calcChild(node->left),calcChild(node->right), node->value);	
}

int count(Tree *&tree)
{
	return calculate(calcChild(tree->root->left), calcChild(tree->root->right), tree->root->value);
}

void destroy(TreeNode *&node)
{ 
	while (!isLeaf(node))
	{
		if	(node->left != NULL)
			if (isLeaf(node->left))
			{
				delete node->left;
				node->left = NULL;
			}
			else 
				destroy(node->left);
		if	(node->right != NULL)
			if (isLeaf(node->right))
			{
				delete node->right;
				node->right = NULL;
			}
			else 
				destroy(node->right);
	}
}