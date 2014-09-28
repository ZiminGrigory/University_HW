#include <iostream>
using namespace std;

int main ()
{
	cout << "Enter string \n";
	int result = 1;
	char string[256];
	cin.getline(string, sizeof(string));
	int length = strlen(string);
	int j = 0;
	for (j = 0; j <= length / 2; j++)
		if (string[j] != string[length - j])
			result = result * (- 1);
	if (result == 1)
		cout << "Yes \n";
	else 
		cout << "No \n";
	cin >> string;
	cout << endl;
}
