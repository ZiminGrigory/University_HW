#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

template <class T>
struct queue {
public:
	void push(T t) {
		pseudoQ.push_front(t);
	}
	T pop() {
		T res = pseudoQ.back();
		pseudoQ.pop_back();
		return res;
	}
private:
	list<T> pseudoQ;
};


int digSum (int a) {
	int res = 0;
	while (a != 0) {
		res += a % 10;
		a /= 10;
	}
	return res;
}

bool mCompare1(int a, int b) {
	return digSum(a) < digSum(b);
}

void mSort(vector<int>& v, int n) {
	sort(v.begin(), v.end(), [n](int x, int y){
		int res1 = 0, res2 = 0;
		for (int i = 1; i <= n; i++) {
			res1 += x % 10 , res2 += y % 10 ;
			x /= 10, y /= 10;
		}
		return res1 < res2;
	});
}


int main()
{
	//1 Ввести число n и потом n раз фамилию человека и оценку.
	// Напечатать для каждого человека, сколько пятерок он получил. Например, вводим:
	int n = 0;
	cin >> n;
	map<string, int> table;
	string s = "";
	int value = 0;
	for (int i = 1; i <=n; i++) {
		cin >> s >> value;
		value = value == 5 ? 1: 0;
		if (table.find(s) != table.end()) {
			table[s] += value;
		} else {
			table.insert(make_pair(s,value));
		}
	}

	for (auto &p : table) {
		cout << p.first << " " << p.second <<endl;
	}


	//2Ввести несколько целых чисел пока не будет введен 0 и записать их в вектор.
	//Отсортировать вектор в порядке возрастания сумм цифр  с помощью sort и своей функции сравнения.
	vector<int> mv;
	n = -1;
	while (n) {
		cin >> n;
		mv.push_back(n);
	}
	mv.pop_back();
	sort(mv.begin(), mv.end(), mCompare1);
	copy(mv.begin(), mv.end(), ostream_iterator<int>(cout, " "));


	//3 Описать функцию с параметрами v и n, которая сортирует данный вектор целых чисел v по последним n цифрам.
	// При этом надо использовать стандартную функцию sort (и, видимо, лямбда выражения со списком захвата).
	vector<int> mv2{222,2222,113,1345,0};
	mSort(mv2,2);
	copy(mv2.begin(), mv2.end(), ostream_iterator<int>(cout, " "));

	//4Шаблон queue  - очередь (аналог stack, но first in – first out).
	// Пример использования
	//	  queue<int> q;
	//	  q.push(3); q.push(7);
	//	  q.push(11);
	//	  cout << q.pop();   // 3
	//	  cout << q.pop();   // 7

	//  Можно реализовать с использованием vector или list (или deque)
	//  Или можете считать, что очередь фиксированной длины и реализовать, как массив (примерно как стек в слайдах)
	  queue<int> q;
	  q.push(3); q.push(7);
	  q.push(11);
	  cout << q.pop();   // 3
	  cout << q.pop();   // 7

	// 5 В этой задаче не надо писать программу.
	// Надо просто описать словами какую-то ситуацию, в которой
	//, в современном С++, со всеми его list, string и т.д.
	// нам потребуется описать переменную или поле объекта, как указатель.

	// поле как указатель - структурные паттерны : адаптер, мост
	// переменная - постоянно передаем массивы, или более сложные объекты, например по цепи разных объектов
	//, для последовательной оработки полей объекта
	return 0;
}

