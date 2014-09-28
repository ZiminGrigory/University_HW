#include <iostream>
using namespace std;

int main()
{
	cout << "please enter a \n";
	int a = 0;
	cin >> a;
	cout << "to what degree you want to build a number of, please enter n \n";
	int n = 0;
	cin >> n;
	int x = 0; 
	int result = a;
	while (n != 1)
	{
		x = n % 2; 
		n = n / 2; 
		result = result * result;
		if (x == 1)
			result = result * a;

	}
	
	cout << "ANS = " << result << endl;
	cin >> a;
	cout << endl;
}