#include <iostream>
using namespace std;
int fact ( int x)
{
	static int res = 1;
	if (x > 1)
	{
		res = res * x;
		fact(x - 1);
	}
   return res;
}
int main ()
{
	int result = 1;
	int result2 = 1;
	cout << "Please enter x!!! \n";
	int x = 0;
	cin >> x ;
	int i = 0;
	for (i = 1; i <= x; i++)
		result = result * i;
	result2 = fact(x);
	cout << "first var. = " << result << endl;
	cout << "second var. = " << result2 << endl;
	cin >> x;
}