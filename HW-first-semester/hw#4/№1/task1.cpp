#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void insertionSort(char arr[256], int length) 
{
      int i = 0;
	  int j = 0;
      for (i = 1; i < length; i++) 
	  {
            j = i;
            while (j > 0 && arr[j - 1] > arr[j]) 
			{
                  swap(arr[j], arr[j - 1]);
                  j--;
            }
      }
}
int main ()
{
	int result = 0;
	char string[256];
	char stringSecond[256];
	cout << "enter first string \n";
	cin.getline(string, sizeof(string));
	int lengthFirst = strlen(string);
	cout << "enter second string \n";
	cin.getline(stringSecond, sizeof(stringSecond));
	int lengthSecond = strlen(stringSecond);
	cout << "ANS = \n";
	if (lengthSecond == lengthFirst)
	{
		insertionSort(string, lengthFirst);
		insertionSort(stringSecond, lengthSecond);
		bool boolValue = 1;
		for (int i = 0; i <= lengthFirst - 1; i++)
			if (string[i] != stringSecond[i])
				boolValue = 0;
		if (boolValue)
			cout << "Yes \n";
		else
			cout << "No";
	}
	else
		cout << "No";
	cin >> lengthSecond;
	cout << endl;
}