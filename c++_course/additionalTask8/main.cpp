//Описать функцию, которая для данного списка list<int> возвращает второе по величине число.
//Можно считать, что мы точно знаем, что числа в списке разные.

//Описать функцию, которая для данного списка list<int> возвращает длину самого длинного начала этого списка
//, состоящего из двух одинаковых частей. Например, если список содержит числа 2 3 2 3 5 2 3 2 3 5 2 8
//, то функция должна вернуть 10, потому что самое длинное такое начало - это 2 3 2 3 5 2 3 2 3 5.

#include <iostream>
#include <list>
#include <iterator>

#include "mString.h"

using namespace std;

int getScndMax(const list<int> &l) {
	int m1 = -1000000000, m2 = -1000000000;
	auto tmp = l.begin();
	tmp++;
	m1 = l.front();
	while (tmp != l.end()) {
		if (*tmp > m1) {
			m2 = m1;
			m1 = *tmp;
		} else if (*tmp > m2) {
			m2 = *tmp;
		}
		tmp++;
	}
	return m2;
}

int countOfEquals(const list<int> &l) {
	int ans = l.begin() == ++l.begin();
	int n = l.size() / 2, breakf = 2;
	auto it = l.begin(), it2 = ++(++l.begin());
	for (; breakf != n; breakf++, it2++) {
		if (equal(it, it2, it2)) {
			ans = breakf;
		}
	}
	return 2*ans;
}

int main()
{
//	//1
//	//list<int> l{1,2,3,4,3,2,5};
//	list<int> l{1,5,3};
//	cout << getScndMax(l);


//	//2
//	list<int> l2{2, 3, 2 ,3, 5, 2, 3, 2, 3, 5, 2, 8};
//	cout << countOfEquals(l2);

	mString s = "abcdefg";
	mString s1 = s.substr(2, 4);  // "cdef"
	//б. При этом надо, чтобы string можно было использовать и слева в присваивании. Пример вызова:

	mString s2 = "abcdefgh";
	s2.substr(2, 4) = "!!" ;      // Заменить символы "cdef" на "!!"
	s2.print();          // ab!!gh

	return 0;
}

