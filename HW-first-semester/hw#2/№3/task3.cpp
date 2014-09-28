
#include <iostream>
using namespace std;

void next(int x[], int &length)
{
	int i = 0;
	int j = 0;
	int s = x[length]; //для определения того, сколько осталось добавить элементов до числа
	i = length - 1;
	while ((i > 1) && (x[i - 1] <= x[i])) 
	{
      s = s + x[i];
      i--;
	}
    x[i]++;
    length = i + s - 1;
    for (j = i + 1;j <= length; j++)
      x[j] = 1;
}

int main()
{
	int i = 0;
	int n = 0;
	cout << " enter the number please\n";
	cin >> n;
	int *x = new int[n]; 
	int length = n;
	for (i = 1; i <= length; i++)
		x[i] = 1;
	for (i = 1; i <= n; i++)
      cout << x[i] << " ";
	cout << endl;
	do
	{
		next(x, length);
		for (i = 1; i <= length; i++)
			cout << x[i] << " ";
			cout << endl;
	}
	while (length != 1);
	cin >> n;
	cout << endl;
	delete []x;
}