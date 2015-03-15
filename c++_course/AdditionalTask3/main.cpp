/** 1. Опишите функцию с тремя параметрами lst, n и x
 * , которая в данном списке после элемента с номером n добавляет новый элемент
 * , содержащий в качестве значения x. (Если элемента с номером n нет, то ничего не делает).
 *
* 2. Опишите функцию, которая возвращает указатель на последний элемент списка.
 * С помощью этой функции возведите последний элемент какого-нибудь списка в квадрат.

 * 3. Опишите функцию, которая создает новый список из тех же элементов
 * , но записанных в обратном порядке. Например, если в исходном списке были числа, 1, 2, 3, 4
 * , то в новом списке должны оказаться числа 4, 3, 2, 1.

 * 4. Пусть у нас есть список. "Разверните" список на месте, т.е., не создавая новые элементы, переставьте указатели так
 * , чтобы элементы шли в обратном порядке. Т.е., например, если в исходном списке были числа
 * , 1, 2, 3, 4, то в результате first должен указывать на 4, next для 4 - на 3 и т.д.
 *   Можно считать, что в списке точно не меньше двух элементов.
*/

#include <iostream>

#include "List.h"

using namespace std;

template <typename T>
void insertNewElem(List<T> *lst, int n, T x) {
	auto p = lst->getHead();
	int i = 0;
	while (p != nullptr) {
		if (++i == n) {
			break;
		}

		p = p->next;
	}

	if (i == n && p != nullptr) {
		Node<T> *nNode = new Node<T>(x, p->next);
		p->next = nNode;
		if (nNode->next == nullptr) {
			lst->setNewTail(nNode);
		}
	}
}

template <typename T>
Node<T> *getLastInList(List<T> *lst) {
	auto p = lst->getHead();
	while (p != nullptr && p->next != nullptr) {
		p = p->next;
	}

	return p;
}

template <typename T>
List<T> *getReverseList(List<T> *lst) {
	auto p = lst->getHead();
	Node<T> *nHead(nullptr);
	Node<T> *nTail(nullptr);
	if (p != nullptr) {
		nTail = new Node<T>(p->value, nullptr);
		nHead = nTail;
		p = p->next;
	}

	while(p != nullptr) {
		Node<T> *nNode = new Node<T>(p->value, nHead);
		nHead = nNode;
		p = p->next;
	}

	List<T> *newList = new List<T>;
	newList->setNewHead(nHead);
	newList->setNewTail(nTail);
	return newList;
}

template <typename T>
void reverseList(List<T> *lst) {
	auto p = lst->getHead();
	int i = 0;
	Node<T> *oldHead(p);
	Node<T> *oldTail(nullptr);
	Node<T> *newTail(nullptr);
	while (p != nullptr) {
		if (p->next != nullptr) {
			p = p->next;
		} else {
			oldTail = p;
			break;
		}
		i++;
	}

	newTail = oldTail;
	for (int j = i; j > 1; j--) {
		p = oldHead;
		for (int k = 1; k < j; k++) {
			p = p->next;
		}
		newTail->next = p;
		newTail = p;
		p = p->next;
	}

	newTail->next = oldHead;
	newTail->next->next = nullptr;
	lst->setNewHead(oldTail);
	lst->setNewTail(newTail->next);
}

template <typename T>
void reverseList2(List<T> *lst) {
	auto p = lst->getHead();
	auto p1 = p->next;
	auto p2 = p->next->next;
	Node<T> *newTail(p);
	Node<T> *newHead(p1);
	newHead->next = p;
	while (p2) {
		p = p1;
		p1 = p2;
		p2 = p2->next;
		newHead = p1;
		newHead->next = p;
	}

	newTail->next = nullptr;
	lst->setNewHead(newHead);
	lst->setNewTail(newTail->next);
}

int main()
{
	List<int> *lst = new List<int>;
	lst->add(1);
	lst->add(2);
	lst->add(3);
	lst->add(4);
	lst->add(6);
	//1
	insertNewElem(lst, 4, 5);

	//2
	Node<int> *last = getLastInList(lst);
	last->value = last->value * last->value;

	//3
	List<int> *reverseLst = getReverseList(lst);
	//cout << reverseLst->getHead()->value;

	//4
	reverseList2(lst);

	delete lst;
	delete reverseLst;
	return 0;
}

