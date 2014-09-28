#include <iostream> 
#include <stdio.h>
#include "tree.h"
using namespace std;

int main(){
	FILE *inp = fopen("input.txt", "r");
	Tree *tree = createTree();
	add(tree, tree->root, inp);
	Print(tree, tree->root, inp);
	int s = count(tree);
	destroy(tree->root);
	delete tree->root;
	delete tree;
	cout << "\nANS = " << s << endl;
	cin >> s;
	cout << endl;
	fclose(inp);
}