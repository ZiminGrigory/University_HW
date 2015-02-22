#include <iostream>

/*
Ф-я order(x, y, z); - меняет значения в x, y, z так, чтобы
x <= y и y <= z. Например:

  int a=5, b=1; c=3;
  order(a, b, c);

  … теперь a==1, b==3, c==5
*/

using namespace std;

void swap(int &a, int &b){
	b += a;
	a = b - a;
	b = b - a;
}

void order(int &a, int &b, int &c){
	if (a >= b){
		swap(a, b);
	}
	if (b >= c){
		swap(b, c);
	}
	if (a >= b){
		swap(a, b);
	}
}

int main()
{
	int b(1);
	int a(-5);
	int c(0);
	order(a, b, c);
	cout << a << ' ' << b << ' ' << c;
	return 0;
}

