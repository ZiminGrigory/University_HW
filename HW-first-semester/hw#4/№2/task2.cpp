#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cout << "Enter the number of ...\n";
	cin >> n;
	if (n % 2 == 1)
	{
		int **c = new int* [n + 1]; 
		for (int i = 1; i <= n; i++)
		{
			c[i] = new int [n + 1];
			for (int j = 1; j <= n; j++)
				c[i][j] = (i - 1) * n + j;
		}

		int iMain = n / 2 + 1;
		int jMain = iMain;
		cout << c[iMain][jMain] << " ";
		if (n > 1)
		{
			int firstValue = 1;
			int secondValue = 2;
			for (int k = 1; k <= n / 2; k++)
			{
				int j = 1;
				for (j = 1; j <= firstValue; j++)
					cout << c[iMain][jMain + j] << " ";
				jMain = jMain + j - 1;
				for (j = 1; j <= firstValue; j++)
					cout << c[iMain - j][jMain] << " ";
				iMain = iMain - j + 1;
				for (j = 1; j <= secondValue; j++)
					cout << c[iMain][jMain - j] << " ";
				jMain = jMain - j + 1;
				for (j = 1; j <= secondValue; j++)
					cout << c[iMain + j][jMain] << " ";
				iMain = iMain + j - 1;
				firstValue = firstValue + 2;
				secondValue = secondValue + 2;
			}
		}
		for (int i = 2; i <=n; i++)
			cout << c[n][i] << " ";
		for (int i = 1; i <= n; i++) 
			delete []c [i];
		delete []c; 
			
	}
	else 
		cout << "mistake value!!!";
	cout << endl;
	cin >> n;
	cout << endl;
	
}
