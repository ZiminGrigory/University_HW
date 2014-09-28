#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void quickSort(int x[10], int maxIndex)
{
	int static const maxIndSec = maxIndex;
	int i = 0;
	int j = maxIndex;
	int m = x[maxIndex / 2]; // m это опорный элемент.
	do
	{
		while (x[i] < m) 
			i = i + 1;
		while (x[j] > m)
			j = j - 1;
		if (i <= j)
		{
			swap(x[i], x[j]);
		//	if (i < maxIndex) не знаю, нужны они или нет, для проверки переполнений..наверное, нет
				i = i + 1;
		//	if (j > 0)
				j = j - 1;
		}
	}
   while (i <= j);
   if (j > 0) 
	    quickSort(x, j);
   if (maxIndex > i) 
	    quickSort(x + i, maxIndex - i); //если я правильно понял, то что написано было на сайте, то вызов функции для x + i будет значить что первым элементом в рассмотрении станет x[i].
}	

int main()
{
	int x[10] = {};
	int i = 1;
	int j = 0;
	int numberOfInt = 0;
	cout << "Enter the number of integer..\n";
	cin >> numberOfInt;
	cout << "Enter the number..\n";
	for (i = 0; i <= numberOfInt - 1; i++)
		cin >> x[i];
	quickSort(x, numberOfInt - 1 );
	cout << "ANS: \n";
	for (i = 0; i <= numberOfInt - 1; i++)
		cout << " " << x[i];
	cin >> x[1];
	cout << endl;
}

