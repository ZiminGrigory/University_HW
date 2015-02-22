#include <iostream>
/*
 * Опишите функцию, которая удваивает данное число. В качестве параметра передается указатель на число.

Пример вызова:

	int i = 5;
	twice(&i); // теперь i == 10
*/

void twice(int *a){
	*a *= 2;
}

using namespace std;

int main()
{
	int a(2);
	cout << a;
	twice(&a);
	cout << " twice a = "<< a << endl;
	return 0;
}

