#include <iostream>
#include <limits>
#include "onePointerList.h"

using namespace std;

struct ListElement
{
    int value;
    ListElement *next;
};

ListElement *createListElement(int value)
{
    ListElement *temp = new ListElement;
    temp->value = value;
    temp->next = NULL;
    return temp;
}

OnePointerList::OnePointerList()
{
    head = NULL;
    number = 0;
}

void OnePointerList::add(int value)
{
    if (number == 0)
    {
        ListElement *temp = createListElement(value);
        head = temp;
    }
    else
    {
        ListElement* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        ListElement* tmp = createListElement(value);
        temp->next = tmp;
    }
    number++;
    return;
}

void OnePointerList::deleteEl(int value)
{
    if (number == 0)
    {
        cout << "now is empty" << endl;
        return;
    }

    if (head->value == value)
    {
        if (number != 1)
        {
            ListElement *tmp = head;
            head = head->next;
            delete tmp;
            number--;
            return;
        }
        else
        {
            ListElement *tmp = head;
            head = NULL;
            delete tmp;
            number--;
            return;
        }
    }

    ListElement* temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->value == value)
        {
            ListElement *tmp = temp->next;
            temp->next = temp->next->next;
            delete tmp;
            number--;
            return;
        }
        else
        {
            temp = temp->next;
        }
    }
}

void OnePointerList::print()
{
    if (number == 0)
        cout << "already is empty";
    else
    {
        ListElement* temp = head;
        while(temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    return;
}

bool OnePointerList::exist(int value)
{
    ListElement *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == value) return true;
        tmp = tmp->next;
    }
    return false;
}



OnePointerList::~OnePointerList()
{
    ListElement *temp = head;
    while(temp != NULL)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
}

