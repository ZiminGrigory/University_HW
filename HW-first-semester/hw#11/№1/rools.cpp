#include <iostream>
#include "rools.h"
#include "number.h"
using namespace std;



bool isFunc (char c) 
{
	return ((c == '+') || (c == '-') || (c == '*') || (c == '/')); 
}

void first(char &c, bool &ans)
{
	c = cin.get();
	third(c, ans);
	second(c, ans);
}

void second(char &c, bool &ans)
{
	if (c != ')' && c != ' ' && c != '\n')	
		if (isFunc(c))
		{
			c = cin.get();
			if (c == ' ')
			{	
				c = cin.get();
				third(c, ans);
				second(c, ans);
			}
			else ans = false;
		}
		else ans = false;
}

void third(char &c, bool &ans)
{
	forth(c, ans);
	second(c, ans);
}

void forth(char &c, bool &ans)
{
	if (c == '(')
	{
		first(c, ans);
		if (c != ')')
			ans = false;
		else 
		{
			c = cin.get();
			if (c != ' ' && c != '\n' && c != ')')
				ans = false;
			if (c == ' ')
				c = cin.get();
		}
	}
	else 
		number(c, ans);
}
