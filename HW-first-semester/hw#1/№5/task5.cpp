#include <iostream>
using namespace std;

int main ()
{
	char string[256];
	cout << "enter string \n";
    cin.getline(string, sizeof(string));
    int i = strlen(string);
	int balance_bct = 0;
	int j = 0;
	for (j = 0; j < i; j++)
	  {	
		if (string[j] == '(')
			balance_bct++;
		else if (string[j] == ')')
			balance_bct--;
		if (balance_bct < 0)
			{
				cout << "Mistake!!! \n";
				break;
			}
	  }		
	if ((j == i) && ( balance_bct == 0))
		cout << "all right \n";
	else
		cout << "Mistake!!!\n";
    cin >> string;
}