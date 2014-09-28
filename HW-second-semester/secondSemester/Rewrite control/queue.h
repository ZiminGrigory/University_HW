#pragma once
/**
  *program implements a priority queue
  *class Queue includes methods enqueue():
  *takes a value and a numerical priority.
  *dequeue():
  *Return the item with the highest priority
  */

using namespace std;
class Empty{};

template <typename T>
class Queue
{
public:
    Queue();
    ~Queue();
    void enqueu(T value, int priority);
    T dequeue();
private:
    struct List
    {
        T value;
        int priority;
        List *next;
    };

    List *head;
    void destroyList();

    List *createNewDate(T value, int priority)
    {
        List *newDate = new List;
        newDate->value = value;
        newDate->priority = priority;
        newDate->next = NULL;
        return newDate;
    }
    void setNewDate(List *newDate);
};

template<typename T>
Queue<T>::Queue() : head(NULL)
{}

template<typename T>
Queue<T>::~Queue()
{
    destroyList();
}

template<typename T>
void Queue<T>::enqueu(T value, int priority)
{
    List *newDate = createNewDate(value,priority);
    setNewDate(newDate);
}

template<typename T>
T Queue<T>::dequeue()
{
    if (head == NULL)
        throw (Empty());

    List *tmp = head;
    T answer = head->value;
    head = head->next;
    delete tmp;
    return answer;
}

template<typename T>
void Queue<T>::destroyList()
{
    while(head != NULL)
    {
        List *tmp = head;
        head = head->next;
        delete tmp;
    }
}

template<typename T>
void Queue<T>::setNewDate(List *newDate)
{
    if(head == NULL)
    {
        head = newDate;
        return;
    }

    if (head->priority < newDate->priority)
    {
        newDate->next = head;
        head = newDate;
        return;
    }

    List *tmp = head;
    while((tmp->next != NULL) && (tmp->next->priority > newDate->priority))
    {
        tmp = tmp->next;
    }
    if (tmp->next == NULL)
        tmp->next = newDate;
    else
    {
        List* nextElement = tmp->next;
        tmp->next = newDate;
        newDate->next = nextElement;
    }
}
