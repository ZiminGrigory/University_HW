#include <iostream>

/*
 * “Треугольный массив”
 *Массив указателей:
int* a[10];
	а. Отвести динамические массивы длины 1, 2, 3… и запомнить указатели в массиве a.
	б. Инициализировать массивы так: в каждом массиве последний элемент 1, остальные 0.
	в. Напечатать массив.
*/
using namespace std;

int main()
{
	int *a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = new int[i+1];
		int j(0);
		for (; j < i; j++){
			a[i][j] = 0;
		}
		a[i][j] = 1;
	// printing
		auto p = a[i];
		for (j = 0; j <= i; j++){
			cout << *p++ << " ";
		}
		cout << endl;
	}

	//release memory
	for (int i = 0; i < 10; i++){
		delete [] a[i];
	}
	return 0;
}

