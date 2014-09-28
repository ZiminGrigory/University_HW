#include <iostream>
using namespace std;

int main ()
{
	int result = 0;
	char string[256];
	char string2[256];
	cout << "enter first string \n";
	cin.getline(string, sizeof(string));
	int lengthfirst = strlen(string);
	cout << "enter second string \n";
	cin.getline(string2, sizeof(string2));
	int lengthsecond = strlen(string2);
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < lengthsecond; i++)
		if (string2[i] == string[0])
		{	
			j = 0;
			k = 0;
			while ((j <= lengthfirst) && (string2[i + j] == string[j]) && (i + j <= lengthsecond))
				{
					if (i + j != lengthsecond)
						k++;
					j++;
				}
			if (k == lengthfirst) 
			result++;
			i = i + j - 1;
		}
	cout << "result  =  " << result << endl;
	cin >> string;
	cout << "\n";

}