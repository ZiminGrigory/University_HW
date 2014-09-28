#include <iostream>
#include "list.h"
using namespace std;

// считалочка

int main()
{
	int n = 0;
	cout << "enter number of elements\n";
	cin >> n;
	int const nConst = n;
	int k = 1;// число в считалочке сокр от KillNumber
	int j = 0;
	cout << "enter i-element\n";
	cin >> j;
	List *l = createList(nConst);
	cout << "ANS = \n";
	for (k = 1; k <= nConst; k++)
	{
		while (l->value != l->next->value)
		{
			for (int i = 1; i <= k; i++)
				l = l->next;
			deleteL(l, n);
		}
		if (l->value == j)
			cout << k << " ";
		delete l;
		n = nConst;
		List *l =  createList(nConst);
	}
	cin >> n;
	cout << endl;
	
}	