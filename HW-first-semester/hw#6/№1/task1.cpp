#include <iostream>
#include "bst.h"
using namespace std;

enum Command
{
	commandExit = 0,
	commandAddEl = 1,
	commandDeletel = 2,
	commandPrintUp = 3,
	commandPrintDown = 4
};
void test()
{
    cout << "test1\n";
	Tree *tree = createTree();
    add(tree, 5);
    add(tree, 3);
	add(tree, 4);
    add(tree, 7);
    add(tree, -10);
    add(tree, -20);
    add(tree, 1);
    add(tree, 2);
	add(tree, 0);
	add(tree, -1);
	
    remove(tree, 1);
	printUp(tree);
	cout << endl;
	printDown(tree);
	destroy(tree);
	cout << endl;
}
int main()
{
	test();
	Tree *tree = createTree();
	int c = 0;
	int value = 0;
	do{	
		cout << "hello,\n CommandExit = 0 \n CommandAddEl = 1 \n CommandDeletel = 2 \n CommandPrintUp = 3 \n CommandPrintDown = 4 \n";
		cin >> c;
		switch(c) 
		{ 
			case (commandExit) :{
				destroy(tree);
				cout << "The end\n";
				break;
			}
			case (commandAddEl) : 
			{
				cout << "enter value\n";
				cin >> value;
				add(tree, value);
				break;
			};
			case commandDeletel	: {
				cout << "enter value\n";
				cin >> value;
				remove(tree, value);
				break;
			};
			
			case commandPrintUp :{ 
				printUp(tree);
				break;
			}
			case commandPrintDown :{
				printDown(tree);
				break;
			}
			default : cout << " incorrect command, repeat \n";
		}
	}
	while (c != commandExit);
	cin >> c;
	cout << endl;
	return 0;
}

