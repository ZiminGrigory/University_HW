#include <iostream>
#include <map>
#include <vector>
#include <list>

#include "mTime.h"


// but i don't know why.... how we could understand what type of middleValue
// for example we know that int -> double... but what's a point for value_type or decltype
// conclusion: middle value has the same type as vectror::value_type
template <class T>
typename T::value_type midlValue(T b)
{
	typename T::value_type sum = 0;
	int i = 0;
	for (auto &p : b) {
		if (p > 0) {
			sum += p;
			i++;
		}
	}
	return sum / i;
}

template <class T>
auto midlValue2(T b) -> typename std::remove_reference<decltype(*b.begin())>::type
{
	typename std::remove_reference<decltype(*b.begin())>::type sum = 0;
	int i = 0;
	for (auto &p : b) {
		if (p > 0) {
			sum += p;
			i++;
		}
	}
	return sum / i;
}

using namespace std;

int digSum (int a) {
	int res = 0;
	while (a != 0) {
		res += a % 10;
		a /= 10;
	}
	return res;
}

template <class T>
T numeric_limits()
{}

template <>
double numeric_limits<double>(){
	return 1.7e+308;
}

template <>
int numeric_limits<int>(){
	return 2147483647;
}

template <>
long long numeric_limits<long long>(){
	return 9223372036854775807;
}

int main()
{
	// 1
	/*Снова задача 2 из прошлого д.з. про сортировку по сумме цифр.
	 *  Но теперь ее надо сделать не используя sort, с помощью multimap.
	 * (Как это легко сделать, мы обсуждали на занятии).
	 * Ввести несколько целых чисел пока не будет введен 0 и записать их в вектор.
	 * Отсортировать вектор в порядке возрастания сумм цифр с помощью sort и своей функции сравнения.
	*/
	multimap<int, int> mp;
	int value;
	cin >> value;
	while (value) {
		mp.insert(make_pair(digSum(value),value));
		cin >> value;
	}
	for (auto i: mp) {
		cout << i.second << " ";
	}
	cout << endl;

	//2
	/*
	 * Опишите шаблон функции, которая для любого последовательного контейнера (списка, вектора)
	 * ищет среднее арифметическое входящих в него положительных элементов.
	 * (1.5 балла за 2 варианта – с value_type и decltype)
	 */
	vector<int> vec{1,2,3,4,0};
	cout << midlValue2(vec);
	cout << midlValue(vec);

	//3
	/*Описать шаблон numeric_limits
		(на самом деле, есть такой стандартный шаблон, но мы пробуем описать его сами).
		numeric_limits<T>::max() – максимальное значение, которое может принимать тип T.

		Пример вызова:
		cout <<
		 numeric_limits<int>::max();
		cout << numeric_limits
		 <unsigned short>::max();
	 */
	cout << numeric_limits<long long>() << endl << numeric_limits<double>();

	//4 done
	//5
/*	Переписать задачу про timeContainer с помощью unique_ptr.

	Замечания:
	- вы можете взять решения из слайдов 6 занятия или дописать свое решение.
	- писать почти ничего не надо, надо в основном убрать лишнее)
*/
	timeCollection tc;
	tc.add(new mTime(2,15));
	tc.add(new time_with_sec(2,15,24));
	tc.print();
	return 0;
}

