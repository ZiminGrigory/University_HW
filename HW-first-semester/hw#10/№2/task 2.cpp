#include <iostream>

using namespace std; 

bool isNumber (char c) 
{
	return ((c >= '0') && (c <= '9')); 
}

int goTo (int x, char c)
{
	switch (x) 
	{
		case -1: 
			if (c == '-')
				return 0; 
			else  if (isNumber(c)) 
				return 1; 
		case 0:
			if (isNumber(c)) 
				return 1; 
			else 
				return 7; 
		case 1: 
			if (isNumber(c))
				return 1; 
			else if (c == '.') 
				return 2; 
			else if ((c == 'e') || (c == 'E')) 
				return 4; 
			else 
				return 7; 
		case 2: 
			if (isNumber(c)) 
				return 3; 
			else 
				return 7; 
		case 3: 
			if (isNumber(c)) 
				return 3; 
			else if (c == 'e')
				return 4; 
			else 
				return 7; 
		case 4: 
			if ((c == '-')||(c == '+')) 
				return 5; 
			else  if (isNumber(c)) 
				return 5; 
		case 5: 
			if (isNumber(c)) 
				return 5; 
			else 
				return 7;  
	}

	return 7; 

}

int main () 
{
	char c;
	int x = -1; 
	bool ans = true; 
	cout << "enter the number \n";
	c = cin.get();
	while (c != '\n')
	{
		x = goTo(x, c); 
		if (x == 7) 
		{
			ans = false; 
			break; 
		}
		c = cin.get();
	}
	while (c != '\n')
		c = cin.get();
	if (!((x != 4) && (x != 7)))
		ans = false; 
	cout << "answer: ";
	if (ans) 
		cout << "Yes" << endl; 
	else 
		cout << "No " << endl; 
	cin >> c; 
	return 0; 
}