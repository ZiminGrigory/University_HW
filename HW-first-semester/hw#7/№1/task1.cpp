#include <iostream> //если не списал ни с кого, то (-1)
using namespace std;

int check(int a[],int i)
{
	if ((a[i] != 1) && (a[i] != 2) && (a[i] != 3)&& (a[i] != -1))
	{
		int test = check(a, a[i]);
		a[i] = test;
		return test;
	}
	else return a[i];
}
int main(){
	int numberOfElement = 0;
	cout << "enter the number of element\n";
	cin >> numberOfElement;
	int *a = new int [numberOfElement + 1];
	int value = 0;
	int index = 0;
	for (int i = 1; i <= numberOfElement; i++)
	{
		cin >> index;
		cin >> value;
		a[index] = value;
	}
	cout << "ANS=\n";
	for (int i = 1; i <= numberOfElement; i++)
		check(a,i);
	for (int i = 1; i <= numberOfElement; i++)
		cout << i << " " << a[i] << endl;
	delete a;
	cin >> value;
	cout << endl;
}