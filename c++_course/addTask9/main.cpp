#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{

	//1
	/*Ввести несколько пар: строкa и целое число, пока не будет введена строка "*".
	 * Пусть это фамилии и оценки студентов. Найти и напечатать средние баллы для каждого студента.
	 *  Например, пользователь вводит:

	Иванов 5 Петров 4 Иванов 4 Сидоров 3 Сидоров 5 *

	и программа должна напечатать что-то вроде:
	Иванов 4.5
	Петров 4
	Сидоров 4*/

	map<string, pair<int,int>> mt;
	string s;
	int value;
	cin >> s;
	while (s != "*") {
		cin >> value;
		mt[s].first += value;
		mt[s].second++;
		cin >> s;
	}
	for (auto &i: mt) {
		cout << i.first << " " << static_cast<double>(i.second.first) / static_cast<double>(i.second.second) << endl;
	}


	//2
	/*
	 * Ввести информацию о людях – у кого какая любимая книга и любимая музыкальная группа. Если есть два человека, у которых совпадает любимая книга и любимая группа, напечатать их имена и прекратить ввод.
	 * Например:
	 * Иванов  Буратино Аквариум
	 * Петров  Гамлет  Beatles
	 * Сидоров Буратино Аквариум
	 * Печатаем «Интересы совпадают: Иванов Сидоров»
	 * */
	string name, mus, book;
	map<string, string> mt2;
	do {
		cin >> name >> book >> mus ;
		if (mt2.find(book + mus) != mt2.end()) {
			cout << "Интересы совпадают :" << name << " " << mt2[book + mus] << endl;
			break;
		} else {
			mt2[book + mus] = name;
		}
	} while (true);

	//3
	/*
	 * Ввести информацию о людях – у кого какая любимая книга и любимая музыкальная группа. Если есть два человека, у которых совпадает любимая книга или любимая группа, напечатать их имена и прекратить ввод.
	 * Например:
	 * Иванов  Буратино Аквариум
	 * Петров  Гамлет Beatles
	 * Сидоров Буратино ABBA
	 * Печатаем «Интересы частично совпадают: Иванов Сидоров»
	 */
		string name2, mus2, book2;
		map<string, string> mt3;
		do {
			cin >> name2 >> book2 >> mus2 ;
			if (mt3.find(book2) != mt3.end()) {
				cout << "Интересы частично совпадают :" << name2 << " " << mt3[book2] << endl;
				break;
			} else {
				mt3[book2] = name2;
			}
			if (mt3.find(mus2) != mt3.end()) {
				cout << "Интересы частично совпадают :" << name2 << " " << mt3[mus2] << endl;
				break;
			} else {
				mt3[mus2] = name2;
			}
		} while (true);

	return 0;
}
