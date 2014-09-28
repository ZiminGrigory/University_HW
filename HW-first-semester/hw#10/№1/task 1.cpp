#include <vld.h>
#include <string>
#include "list.h"

//equals(p,q) -- проверка равенства многочленов p и q;
// value(p,x) -- вычисление значения многочления в точке x
//- add(p,q,r) -- вычисление суммы многочленов r = p + q;


int main()
{
	cout << "dear user, please enter the polynom correctly, for example ax^y +-ax^y +-..+-a (where a - cofficient, y- degree)" << endl 
		<< "second example 4x^3 -x^2 +4x +5, also please don't forget enter the degree descending as in second example,and don't enter polinom with null-cofficient thank u \n"; 
	int x = 0;
	cout << "enter first function\n";
	List *list = NULL;
	feeling(list);
	cout << "enter second function\n";
	List *listSec = NULL;
	feeling(listSec);
	List *listThird = NULL;
	string s;
	do
	{
		cout << "what do you want? write command equals or value or add or exit \n";
		cin >> s;
		if (s == "equals")
		{
			bool ans = equals(list, listSec);
			cout << endl << ans << endl;
		}
		if (s == "value")
		{
			cout << "enter x\n";
			cin >> x;
			int answer = value(x, list);
			cout << endl << answer << endl;
		}
		if (s == "add")
		{
			add(list, listSec, listThird);
			print(listThird);
		}
	}
	while (s != "exit");
	destroy(list);
	destroy(listSec);
	destroy(listThird);
	cout << endl;
}