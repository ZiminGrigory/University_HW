#include <stdlib.h>
#include "bst.h"
#include <iostream>
using namespace std;

Tree *createTree()
{
	Tree *tree = new Tree;
	tree->root = NULL;
	return tree;
}

bool exists(TreeNode *root, int value)
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

bool exists(Tree *tree, int value)
{
	return exists(tree->root, value);
}

TreeNode *createNode(int value)
{
	TreeNode *node = new TreeNode;
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void add(TreeNode *&node, int value)
{
	if (node == NULL){
		node = createNode(value);
		return;
	}

	if (value < node->value)
		add(node->left, value);
	else if (value > node->value)
		add(node->right, value);
}

void add(Tree *tree, int value)
{
	add(tree->root, value);
}

TreeNode *leftmostChild(TreeNode *node)
{
	if (node->left != NULL)
		return leftmostChild(node->left);
	else
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
void remove(Tree *& tree, TreeNode *&node, int value)
{
	if (node->value > value)
		remove(tree, node->left, value);
	else if (node->value < value)
		remove(tree, node->right, value);
	else if (isLeaf(node))
	{
		if (node->value != tree->root->value)
		{
			TreeNode *tempSec = tree->root;
			while ((tempSec->right->value != node->value) && (tempSec->left->value != node->value)){
			if (tempSec->right->value > node->value)
				tempSec = tempSec->left;
			else if (tempSec->right->value < node->value)
				tempSec = tempSec->right;
			}
			if (tempSec->left->value == node->value)
			{
				delete tempSec->left;
				tempSec->left = NULL;
			}
			else if (tempSec->right->value == node->value)
			{
				delete tempSec->right;
				tempSec->right = NULL;
			}
		}
		else{
			node = NULL;
			delete node;
		}
	}
	else if (hasOneChild(node))
	{
		if (node->left != NULL)
		{
			node->value = node->left->value;
			delete node->left;
			node->left = NULL;
		}
		else if (node->right != NULL)
		{
			node->value = node->right->value;
			delete node->right;
			node->right = NULL;
		}
	}
	else
	{
		TreeNode *temp = leftmostChild(node->right);
		int valueSecond = temp->value;
		remove(tree, temp, temp->value);
		node->value = valueSecond;
	}
}
void remove(Tree *&tree, int value){
	if (!exists(tree, value))
		return;
	remove(tree, tree->root, value);
}

void printUp(TreeNode *root)
{
	if (root->left != NULL)
		if (isLeaf(root->left))
		{
			cout << root->left->value << " ";
			cout << root->value << " ";
		}
		else 
		{
			printUp(root->left);
			cout << root->value << " "; 
		}
	else 
		cout << root->value << " "; 
	if (root->right != NULL)
	{
		if (isLeaf(root->right))
			cout << root->right->value << " "; 
		else 
			printUp(root->right); 
	}
}

void printUp(Tree *tree)
{
	printUp(tree->root);
	cout << endl;
}

void printDown(TreeNode *root)
{
	if (root->right != NULL)
		if (isLeaf(root->right))
		{
			cout << root->right->value << " ";
			cout << root->value << " ";
		}
		else 
		{
			printDown(root->right);
			cout << root->value << " "; 
		}
	else 
		cout << root->value << " "; 
	if (root->left != NULL)
	{
		if (isLeaf(root->left))
			cout << root->left->value << " "; 
		else 
			printDown(root->left); 
	}
}

void printDown(Tree *tree)
{
	printDown(tree->root);
	cout << endl;
}

void destroy(TreeNode *&root){
	if (root->right != NULL)
		if (isLeaf(root->right))
		{
			delete root->right;
			root->right = NULL;
		}
		else 
			destroy(root->right);  
	if (root->left != NULL)
	{
		if (isLeaf(root->left)){
			delete root->left;
			root->left = NULL;
		}
		else 
			destroy(root->left); 
	}
}
void destroy(Tree *&tree)
{
	if (tree->root != NULL)
		while ((tree->root->left != NULL)&&(tree->root->left != NULL))
			destroy(tree->root);
	if  (tree->root != NULL)
		delete tree->root;
	delete tree;
}