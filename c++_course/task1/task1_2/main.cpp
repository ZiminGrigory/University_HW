#include <iostream>

using namespace std;

int main()
{
	// 2
	cout << "enter sequence of numbers(0 meet once, and ends sequence) \n number-->:";
	int a(0);
	int product(1);
	cin >> a;
	if (a == 0){
		product = 0;
	}
	while(a){
		cout << "number-->:";
		product *= a;
		cin >> a;
	}
	cout << "\n product = " << product << endl;

	return 0;
}

