#include <iostream>
#include <limits>
#include "twoPointerList.h"
using namespace std;

struct ListElementTPL
{
    int value;
    ListElementTPL *next;
    ListElementTPL *previous;
};

ListElementTPL *createListElementTPL(int value)
{
    ListElementTPL *temp = new ListElementTPL;
    temp->value = value;
    temp->next = NULL;
    return temp;
}

TwoPointerList::TwoPointerList()
{
    head = NULL;
    number = 0;
}

void TwoPointerList::add(int value)
{
    if (number == 0)
    {
        ListElementTPL* temp = createListElementTPL(value);
        temp->previous = NULL;
        head = temp;
    }
    else
    {
        ListElementTPL* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        ListElementTPL* tmp = createListElementTPL(value);
        temp->next = tmp;
        tmp->previous = temp;
    }
    number++;
    return;
}

void TwoPointerList::deleteEl(int value)
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
            ListElementTPL *tmp = head;
            head = head->next;
            head->previous = NULL;
            delete tmp;
            number--;
            return;
        }
        else
        {
            ListElementTPL *tmp = head;
            delete tmp;
            head = NULL;
            number--;
            return;
        }
    }

    ListElementTPL* temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->value == value)
        {
            ListElementTPL *tmp = temp->next;
            temp->next = temp->next->next;
            if (tmp->next != NULL)
                tmp->next->previous = temp;
            tmp->previous = NULL;
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

void TwoPointerList::print()
{
    if (number == 0)
        cout << "already is empty";
    else
    {
        cout << "forward sequence: ";
        ListElementTPL* temp = head;
        while(temp->next != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << temp->value << " ";
        cout << endl << "inverted sequence: ";
        while(temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->previous;
        }
    }
    return;
}

bool TwoPointerList::exist(int value)
{
    ListElementTPL *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == value) return true;
        tmp = tmp->next;
    }
    return false;
}

TwoPointerList::~TwoPointerList()
{
    ListElementTPL *temp = head;
    if (temp != NULL){
        while(temp->next != NULL)
        {
            temp = head->next;
            temp->previous = NULL;
            delete head;
            head = temp;
        }
        if (temp->next == NULL)
        {
            temp = head->next;
            delete head;
            head = temp;
        }
   }
}
