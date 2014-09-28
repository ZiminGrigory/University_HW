#pragma once

struct ListElement
{
	int value;
	ListElement *next;
};

struct List
{
	ListElement *head;
};

List *createList();
void deleteL(List *list, int value, int &n);
void add(List *list, int value, int &n);
bool isEmpty(List *list);
void print(List *list, int n);
void destroy(List *list, int n);