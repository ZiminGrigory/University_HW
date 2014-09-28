#include <iostream>
using namespace std;

int main()
{
	cout << " Enter x, please \n";
	int x = 0;
	cin >> x;
	int i = 0;
	int j = 0;
	bool test = false;
	for (i = 1; i <= x; i++)
	{
		test = true;
		j=2;
		while ((j <= i - 1) && (test != false))
		{
			if (i % j == 0) 
				test = false;
			j++;
		}
		if (test)
			cout << i << " ";
	}
	cin >> x;
}