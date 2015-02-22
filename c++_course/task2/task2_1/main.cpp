#include <iostream>

/*
 * Описать функцию reverse. Должна позволять переставить: массив чисел в обратном порядке.
 * Желательно реализовать с помощью арифметики указателей (не используя [])
 * (И *(a+i) тоже не используя…)
*/

using namespace std;

void swap(int &a, int &b){
	b += a;
	a = b - a;
	b = b - a;
}

void reverse(int *array, int n)
{
	auto tmp = array + n - 1;
	auto half = n / 2;
	for (int i = 0; i < half; i++){
		swap(*array, *tmp);
		array++;
		tmp--;
	}
}

int main()
{
	int a[9]{1,2,3,4,5,6,7,8,9};
	reverse(a, sizeof a / sizeof (int));
	auto n = sizeof a / sizeof (int);
	auto *p = a;
	for (auto i = 0; i < n; i++){
		cout << *p++ << " ";
	}
	return 0;
}

