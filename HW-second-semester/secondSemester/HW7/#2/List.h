#pragma once
#include <iostream>
using namespace std;


template <typename T>
class List
{
public:
    List(): head(NULL){}
    ~List()
    {
        while(head != NULL)
        {
            ListElement *tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    void addElement(T value);
    void deleteElement(T value);
    bool isEmpty(){
        return (head == NULL);
    }
    bool exist(T element);
private:
    struct ListElement{
        ListElement *next;
        T value;
    };
    ListElement *createListElement(T value)
    {
        ListElement *temp = new ListElement;
        temp->value = value;
        temp->next = NULL;
        return temp;
    }
    ListElement* head;
};

template <typename T>
void List<T>::addElement(T value)
{
    if (head == NULL)
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
}

template <typename T>
void List<T>::deleteElement(T value)
{
    if (head->value == value)
    {
        if (head->next != NULL)
        {
            ListElement *tmp = head;
            head = head->next;
            delete tmp;
        }
        else
        {
            ListElement *tmp = head;
            head = NULL;
            delete tmp;
        }
    }
    else
    {
        ListElement* temp = head;
        while (temp->next != NULL)
        {
            if (temp->next->value == value)
            {
                ListElement *tmp = temp->next;
                temp->next = temp->next->next;
                delete tmp;
                return;
            }
            else
                temp = temp->next;
        }
    }

}

template <typename T>
bool List<T>::exist(T value)
{
    ListElement *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == value) return true;
        tmp = tmp->next;
    }
    return false;
}
