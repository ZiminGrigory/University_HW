#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits.h>
#include <list>
#include <map>
#include <string>


using namespace std;


template<class T>
auto equalNear(const T& cont) -> typename std::remove_reference<decltype(*cont.begin())>::type
{
	if (cont.size() < 2) {
		throw "wroooooooong!!!";
	}
	auto it = cont.cbegin();
	auto it2 = ++cont.cbegin();
	auto endIt = cont.cend();
	while (it2 != endIt) {
		if (*it == *it2) {
			return *it;
		}
		it++;
		it2++;
	}
	throw "wroooooooong!!!";
}


// т.к. неважно, что возвращать, если номер не найден, будем считать, что он найдется всегда
class numberBook{
public:
	numberBook(){}
	void addNew(int number, const string &name) {
		map1[number] = name;
		map2[name] = number;
	}
	/// int birthday : 12.11.84 -> 121184
	void addAddresAndBirthday(const string &address, const string &name, int birthday) {
		mAddress.insert(make_pair(address, name));
		mBirthday.insert(make_pair(birthday, name));
	}
	string getName(int number) {
		return map1[number];
	}
	int getNumber(const string &name){
		return map2[name];
	}
private:
	map<int, string> map1;
	map<string, int> map2;
	multimap<string, string> mAddress;
	multimap<int, string> mBirthday;
};


int main()
{
	//1
	/*Описать функцию, которая для данного вектора целых чисел вычисляет сумму всех его элементов
	 * , кроме максимального и минимального.
		Можно считать, что в контейнере только один максимальный и только один минимальный элемент.
		Дополнительное условие: пожалуйста, в этой задаче не пишите свои циклы по вектору
		, используйте стандартные функции.
	 *
	 */
	vector<int> vec1{1,5,2,15,6,-10,71,100};
	auto minmax = minmax_element(vec1.begin(), vec1.end());
	int res = accumulate(vec1.begin(), vec1.end(), 0) - *minmax.first - *minmax.second;
	cout << res << endl;

	//2	 *C помощью accumulate посчитайте произведение чисел в данном массиве вещественных чисел.
	vector<double> vec2{1.0, 10.123, 2.};
	cout << accumulate(vec2.begin(), vec2.end(), 1.0, [](double a, double b){return a*b;})  << endl ;

	//3
	//Написать шаблон функции, которая для данного контейнера (списка или вектора или deque) проверяет
	//, верно ли, что в нем есть два элемента подряд
	//, имеющих одно и то же значение, и возвращает это значение.
	// Например, для списка из чисел 4, 2, 7, 7, 9, 1 функция должна вернуть число 7.
	list<int> l{4, 2, 7, 7, 9, 1};
	cout << equalNear(l) << endl;
//	list<int> l2{4,3};
//	cout << equalNear(l2);

	//4
	numberBook nb;
	nb.addNew(12345, "mike");
	nb.addNew(12355, "mike1");
	nb.addNew(134355, "mike2");
	cout << nb.getName(12355) << endl;
	cout << nb.getNumber("mike2") << endl;
	return 0;
}

