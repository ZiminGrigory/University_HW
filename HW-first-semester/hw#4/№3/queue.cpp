#include "queue.h"
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

List *createList()
{
	List *list = new List;
	list->head = NULL;
	return list;
}


bool isEmpty(List *list) 
{
	return list->head == 0;
}


void add(List *list, int value, int &n)
{
	List *headSecond = new List;
	if (n == 0)
	{
		ListElement *temp = new ListElement;
		temp->value = value;
		temp->next = temp;
		list->head = temp;
		n++;
	}
	else
		if (n == 1)
		{
			ListElement *temp = new ListElement;
			temp->value = value;
			temp->next = list->head;
			list->head->next = temp;
			n++;
		}
		else
		{
			bool varLow = 1;
			headSecond->head = list->head;
			for (int i = 1; i < n; i++)
			{
				if ((headSecond->head->value < value) && (headSecond->head->next->value > value))
					varLow = 0;
				headSecond->head = headSecond->head->next;
			}
			if (varLow == 0)
			{	
				for (int i = 1; i < n; i++)
				{
					if ((headSecond->head->value < value) && (headSecond->head->next->value > value))
						break;
					headSecond->head = headSecond->head->next;
				}
				ListElement *temp = new ListElement;
				temp->value = value;
				temp->next = headSecond->head->next;
				headSecond->head->next = temp;
				n++;
			}
			else
			{
				while (headSecond->head->value < headSecond->head->next->value)
					headSecond->head = headSecond->head->next;
				ListElement *temp = new ListElement;
				temp->value = value;
				temp->next = headSecond->head->next;
				headSecond->head->next = temp;
				n++;
			}
		}
		delete headSecond;
	
}

void deleteL(List *list, int value, int &n)
{
	if (n != 0)
	{
		List *headSecond = new List;
		headSecond->head = list->head;
		while (headSecond->head->next->value != value)
			headSecond->head = headSecond->head->next;
		ListElement *tmp = headSecond->head->next;
		headSecond->head->next = headSecond->head->next->next;
		delete tmp;
		delete headSecond;
		n--;
	}
}

void print(List *list, int n)
{
	
	if (n != 0)
	{
		List *headSecond = new List;
		headSecond->head = list->head;
		while (headSecond->head->value < headSecond->head->next->value)
			headSecond->head = headSecond->head->next;
		headSecond->head = headSecond->head->next;
		while (n != 0)
		{
			cout << headSecond->head->value << " ";
			headSecond->head = headSecond->head->next;
			n--;
		}
		cout << endl;
		delete headSecond;
	}

}

void destroy(List *list, int n)
{
	List *headSecond = new List;
	headSecond->head = list->head;
	for (int i = 1; i <= n; i++)
	{
		ListElement *tmp = headSecond->head->next;
		headSecond->head->next = headSecond->head->next->next;
		delete tmp;
	}
		delete headSecond;
	
}