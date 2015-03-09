#ifndef LIST_H
#define LIST_H

template <typename T>
struct Node
{
	T value;
	Node* next = nullptr;
};

template <typename T>
class List
{
public:
	List(): head(nullptr), tail(nullptr)
	{}
	~List()
	{
		while (head != nullptr) {
			tail = head;
			head = head->next;
			delete tail;
		}
	}

	void add(T elem)
	{
		if (head == nullptr) {
			head = new Node<T>;
			head->value = elem;
			tail = head;
		} else {
			tail->next = new Node<T>;
			tail->next->value = elem;
			tail = tail->next;
		}
	}

	Node<T>* getHead() {
		return head;
	}

private:
	Node<T>* head;
	Node<T>* tail;
};

#endif // LIST_H
