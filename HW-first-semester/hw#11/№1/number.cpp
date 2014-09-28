#include <iostream>
#include "number.h"


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

void number(char &c, bool &ans)
{
	if ((c == '-') || isNumber(c))
	{
		int x = -1;
		while ((c != ')') && (c != '\n') && (c != ' ') && ans)
		{
			x = goTo(x, c); 
			if (x == 7) 
			{
				ans = false; 
			}
			c = cin.get();
		}
		if (!((x != 4) && (x != 7)))
		{
			ans = false;
		}
		else if ((c != '\n') && (c != ')'))
			c = cin.get();
	}
}