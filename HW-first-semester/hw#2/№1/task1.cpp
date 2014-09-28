#include <iostream>
using namespace std;

int functionFib(int x)
{
	if ((x == 1) || (x == 2)) 
		return 1;
	else
		return functionFib(x - 1) + functionFib(x - 2);
}
int main()
{
	cout << "please enter number of fib. \n";
	int x = 0;
	cin >> x;
	int i = 0;
	int a = 1; // переменная для вывода числа итеративно
	int result = 1;
	if ((x == 1) || (x == 2)) 
		cout << "ANS first = 1 \n";
	else
	{
		for (i = 3; i <= x; i++)
		{
			result = result + a;
			a = result - a;
		}
		cout << "ANS first = " << result << endl;
	}
	cout << "ANS second = " << functionFib(x) << endl;
	cin >> x;
	cout << endl;

}