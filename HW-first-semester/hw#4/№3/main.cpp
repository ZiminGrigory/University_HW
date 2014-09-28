#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
	int value = 0;
	int c = 0;
	int n = 0;
	List *list = createList();
	do
	{
		cout << "please make a choice \n" << "0 - exit\n" << "1 - add value to sorted list\n" << "2 - remove value from list\n" << "3 - print list \n";
		cin >> c;
		switch (c)
		{
			case 1: 
			{
				cout << "please enter the value\n";
				cin >> value;
				add(list, value, n);
				break;
			}
			case 2: 
			{
				cout << "please enter the value\n";
				cin >> value;
				deleteL(list, value, n);
				break;
			}
			case 3:
			{
				cout << "LIST : \n";
				print(list, n);
				break;
			}
		}

	}
	while (c != 0);
	if (n != 1)
		destroy(list, n);
	delete list;
	std::cin >> n;
	cout << endl;
}