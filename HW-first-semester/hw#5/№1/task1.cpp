
#include <iostream>
using namespace std;

void check(char string [1000])
{
	const int determineCode = 97;//to determine the number of code
	char a[26] = {};
	int b[26] = {};
	for (char i = 'a'; i <= 'z'; i++)
		a[i - determineCode] = i;
	int k = -1;
	do{
		for (int j = 0; j <= 25; j++)
				b[j] = 0;
		do{
			k++;
			if ((string[k] >= 'a') && (string[k] <= 'z'))
			{
				b[string[k] - determineCode]++;
				if (b[string[k] - determineCode] == 1)
					cout << (string[k]);
			}			
		}
		while ((string[k] != ' ') && (string[k] != 0));
		cout << ' ';
		if ((string[k] != ' ') && (string[k] != 0))
			k++;
	}
	while (string[k] != 0);
}
int main()
{
	cout << "hello, enter the text\n";  
	char string [1000];
	cin.getline(string, sizeof(string));
	check(string);
	cin >> string[2];
	cout << endl;
}