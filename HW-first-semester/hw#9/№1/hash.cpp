#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream> 
#include "hash.h"

using namespace std;

int hashFunc(string s, int n)
{
	int resultMain = 0;
	int f = s.length();
	for (int i = 0; i < f; i++)
		resultMain = resultMain + (7 * s[i] * (s[i] % 3 + i));
	return resultMain % n;
}

void deleteEl(List *&a, string s)
{
	if (a->s == s)
	{
		List *tmp = a;
		a = a->next;
		delete tmp;
	}
	else
	{
		List *tmp = a;
		while (tmp->next->s != s)
			tmp = tmp->next;
		List *tmpDel = tmp->next;
		tmp->next = tmp->next->next;
		delete tmpDel;
	}
}

bool isExist(List *a, string s)
{
	bool temp = 0;
	if (a == NULL)
	{
		temp = 0;
	}
	else
	{
		List *tmp = a;
		if (tmp->s == s)
				temp = 1;
		else
			while ((tmp->s != s) && (tmp->next != NULL))
			{
				tmp = tmp->next;
				if (tmp->s == s)
					temp = 1;
			}
	}
	return temp;
}

List **create(int n)
{
	
	List **a = new List *[n];
	for(int i = 0; i < n; i++)
		a[i] = NULL;
	return a;
}

void addEl(List *&a, string s)
{
	if (a == NULL)
	{
		a = new List;
		a->s = s;
		a->next = NULL;
	}
	else
	{
		List *tmp = a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new List;
		tmp->next->s = s;
		tmp->next->next = NULL;
	}
}

void meetString(List *a[], int n,ifstream& inpSec, ofstream& out)
{
	string s;
	char c;
	do
	{
		s = "";
		c = inpSec.get();
		while ((!inpSec.eof()) && (c != '\n'))
		{
			s = s + c;
			c = inpSec.get();
		}
		if (s != "") 
			if (isExist(a[hashFunc(s, n)], s))
				out << s << endl;
	}
	while (!inpSec.eof());
}


List **filling(ifstream& inp, int n)
{
	int i = 0;
	string s;
	List **a = create(n);
	char c = 'v';
	do
	{
		s = "";
		c = inp.get();
		while ((!inp.eof()) && (c != '\n'))
		{
			s = s + c;
			c = inp.get();
		}
		int f = hashFunc(s, n);
		if (s != "") 
			addEl(a[f], s);
	}
	while (!inp.eof());
	return a;
}