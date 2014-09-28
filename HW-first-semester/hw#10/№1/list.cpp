#include <math.h>
#include "list.h"

using namespace std;

int toInt(char c)
{
	int toInt = 48;
	return  c - toInt;
}

char sgn(int val)
{
	if (val > 0) 
		return '+';
	else return '-';
}

bool sign(int val)
{
	if (val > 0)
		return 1;
	else return 0;
}

void feeling(List *&list)
{
	char c;
	c = cin.get();
	int res = 0;
	int resSec = 0;
	int sgn = 1;
	bool flag = 0;
	if (c == '-')
	{
		sgn = -1;
		c = cin.get();
	}
	if (c != 'x'){
		while ((c != 'x') && (c != '\n'))
		{
			res = res + toInt(c);
			res *= 10;
			c = cin.get();
		}
		res = res / 10;
	}
	if (c == 'x')
	{
		c = cin.get();
		flag = 1;
	}
	if (c == '^'){
		c = cin.get();
		while (c != ' ')
			{
				resSec = resSec	+ toInt(c);
				resSec *= 10;
				c = cin.get();
			}
		resSec = resSec / 10;
	}
	if (list == NULL)
		list = new List;
	if (res != 0)
		list->a = res * sgn;
	else 
		list->a = 1 * sgn;
	if (resSec > 0)
		list->deg = resSec;
	else if ((resSec == 0) && (flag))
		list->deg = 1;
	else
		list->deg = resSec;
	List *head = list;
	while (c != '\n')
	{
		flag = 0;
		sgn = 1;
		int res = 0;
		int resSec = 0;
		c = cin.get();
		if (c == '-')
			sgn = -1;
		c = cin.get();
		if (c != 'x')
		{
			while ((c != 'x') && (c != '\n'))
			{
				res = res + toInt(c);
				res *= 10;
				c = cin.get();
			}
			res = res / 10;
		}
		if (c == 'x')
		{
			c = cin.get();
			flag = 1;
		}		
		if (c == '^'){
			c = cin.get();
			while ((c != ' ') && (c != '/n'))
			{
				resSec = resSec + toInt(c);
				resSec *= 10;
				c = cin.get();
			}
			resSec = resSec / 10;
		}		
		list->next = new List;
		list = list->next;
		if (res != 0)
			list->a = res * sgn;
		else 
			list->a = 1 * sgn;
		if (resSec > 0)
			list->deg = resSec;
		else if ((resSec == 0) && (flag))
			list->deg = 1;
		else
			list->deg = resSec;
	}
	list->next = NULL;
	list = head;
}

bool equals(List *p, List *q)
{
	bool ans = 1;
	List *tmp = p;
	List *tmpSec = q;
	while ((tmp != NULL) && (tmpSec != NULL) && (ans))
	{
		if (!((tmp->a == tmpSec->a) && (tmp->deg == tmpSec->deg)))
			ans = 0;
		else
		{
			tmp = tmp->next;
			tmpSec = tmp->next;
		}
	}
	return ((tmp != NULL) && (tmpSec != NULL) && (ans));
}

void destroy(List *&list)
{
	List *head = list;
	while (list != NULL)
	{
		list = list->next;
		delete head;
		head = list;
	}
	delete list;
}

int toDeg(int a, int n)
{
	int x = 0; 
	int result = a;
	if (n == 0)
		result = 1;
	else	
		while (n != 1)
		{
			x = n % 2; 
			n = n / 2; 
			result = result * result;
			if (x == 1)
				result = result * a;
		}
	
	return result;
}

int value(int x, List *p)
{
	int result = 0;
	while (p != NULL)
	{
		result = result + p->a * toDeg(x, p->deg);
		p = p->next;
	}
	return result;
}

void add(List *list, List *listSec, List *&listThird)
{
	listThird = new List;
	List *head = listThird;
	while ((list != NULL) && (listSec != NULL))
	{
		if (list->deg > listSec->deg)
		{
			listThird->a = list->a;
			listThird->deg = list->deg;
			list = list->next;
		}
		else if (list->deg == listSec->deg)
		{
			listThird->a = list->a + listSec->a;
			listThird->deg = list->deg;
			list = list->next;
			listSec = listSec->next;
		}
		else if (list->deg < listSec->deg)
		{
			listThird->a = listSec->a;
			listThird->deg = listSec->deg;
			listSec = listSec->next;
		}
		if ((list != NULL) || (listSec != NULL))
		{
			listThird->next = new List;
			listThird = listThird->next;
		}
		else
			listThird->next = NULL;
	}
	if ((list != NULL) || (listSec != NULL))
	{	
		while (list != NULL)
		{
			listThird->a = list->a;
			listThird->deg = list->deg;
			list = list->next;
			if (list != NULL)
			{
				listThird->next = new List;
				listThird = listThird->next;
			}
			else
				listThird->next = NULL;
		}
		while (listSec != NULL)
		{
			listThird->a = listSec->a;
			listThird->deg = listSec->deg;
			listSec = listSec->next;
			if (listSec != NULL)
			{
				listThird->next = new List;
				listThird = listThird->next;
			}
			else
				listThird->next = NULL;
		}
	}
	listThird = head;
}

void print(List *&listThird)
{
	List *head = listThird;
	if ((head->deg != 0) && (head->deg != 1) && (head->a != 0) && (head->a != 1) && (head->a != -1))
		cout << head->a << "x^" << head->deg;
	else if ((head->deg != 0) && (head->deg != 1) && (head->a != 0) && ((head->a == 1) || (head->a == -1)))
	{
		if (!sign(head->a))
			cout << "-x^" << head->deg;
		else
			cout << "x^" << head->deg;
	}
	else if ((head->deg == 1) && (head->a != 0) && (head->a != 1) && (head->a != -1))
		cout << head->a << "x";
	else if ((head->deg == 1) && ((head->a == 1) || (head->a == -1)))
	{
		if (!sign(head->a))
			cout << "-x";
		else
			cout << "x";
	}
	else if ((head->deg == 0) && (head->a != 0))
		cout << head->a;
	head = head->next;
	while (head != NULL)
	{
		if ((head->deg != 0) && (head->deg != 1) && (head->a != 0) && (head->a != 1) && (head->a != -1))
			cout << ' ' << sgn(head->a) << abs(head->a) << "x^" << head->deg;
		else if ((head->deg != 0) && (head->deg != 1) && (head->a != 0) && ((head->a == 1) || (head->a == -1)))
		{
			if (!sign(head->a))
				cout << "-x^" << head->deg;
			else
				cout << "+x^" << head->deg;
		}
		else if ((head->deg == 1) && (head->a != 0) && (head->a != 1) && (head->a != -1))
			cout << ' ' << sgn(head->a) << abs(head->a) << "x";
		else if ((head->deg == 1) && ((head->a == 1) || (head->a == -1)))
		{
			if (!sign(head->a))
				cout << "-x" ;
			else
				cout << "+x" ;
		}
		else if ((head->deg == 0) && (head->a != 0))
			cout << sgn(head->a) << abs(head->a);
		head = head->next;
	}
	cout << endl;
}