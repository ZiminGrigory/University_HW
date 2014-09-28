#pragma once
struct ListElement
{
	char value;
	ListElement *next;
};

struct List
{
	ListElement *head;
};

List *createList();
