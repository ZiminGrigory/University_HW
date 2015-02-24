#include <iostream>
#include <algorithm>
#include "limits.h"
/*1. Напишите две очень простые функции. Одна заполняет данный массив длины n данным числом x. Вторая копирует одни массив длины n в другой. Все нассивы передаются в параметрах, результат у обеих функций должен быть void. Пример вызова м.б. таким:

int a[10];
set(a, 10, 999); // заполнить массив a длины 10 числами 999
int b[10];
copy(b, a, 10); // Скопировать 10 чисел из массива a в массив b
2. Пусть у нас есть массив из 10 целых чисел, и точно известно, что в нем максимальный элемент единственный. Найдите этот максимальный элемент и замените его на 0.

3. Для данного массива из 10 чисел проверить, есть ли в нем два числа, отличающихся ровно на 1, и напечатать "да" или "нет".

4. (Более сложная задача).
Пусть у нас есть двумерный массив int a[10][10]. Заполнить массив указателей int* b[10]; так, чтобы указатель b[0] указывал на строчку в массиве a, в которой сумма чисел максимальная, b[1] - на строку. в которой сумма чисел вторая по величине, b[2] - на строчку с третьей по величине суммой и т.д.

Замечание, полезное для задания начальных данных:
Двумерный массив можно инициализировать примерно так же, как одномерный. Например,

int a[10][10] = {{1,2,3}, {9}, {1,1,1,1,1,1,1,1}};
	// Все не выписанные явно элементы заполняются нулями
*/

using namespace std;

void set(int* a, int n, int value)
{
	for (int i = 0; i < n; i++, a++){
		*a = value;
	}
}

void copy(int *target, int *source, int n)
{
	for (int i = 0; i < n; i++, target++, source++){
		*target = *source;
	}
}

void max2zero(int* a, int n)
{
	auto p = a;
	int max = INT_MIN;
	for (int i = 0; i < n; i++, a++){
		if (*a >= max){
			max = *a;
			p = a;
		}
	}
	*p = 0;
}

void max2Int_min(int* a, int n)
{
	auto p = a;
	int max = INT_MIN;
	for (int i = 0; i < n; i++, a++){
		if (*a >= max){
			max = *a;
			p = a;
		}
	}
	*p = INT_MIN;
}

bool thirdTask1(int* a, int n)
{
	std::sort(a, a + n);
	auto p = a;
	a++;
	for (int i = 1; i < n; i++, p++, a++ ){
		if (abs(*a - *p) == 1){
			return true;
		}
	}
	return false;
}

bool thirdTask2(int* a, int n)
{
	for (int i = 1; i < n; i++, a++){
		auto tmp = a;
		tmp++;
		for (int j = i + 1; j < n; j++, tmp++){
			if (abs(*a - *tmp) == 1){
				return true;
			}
		}
	}
	return false;
}

int sumOfArray(int* a, int n)
{
	int ans{0};
	for (int i = 0; i < n; i++, a++){
		ans += *a;
	}
	return ans;
}

int main()
{
	//1
	int array[10]{};
	int arrayB[10]{};
	set(array, 10, 24);
	for (auto x: array){
		cout << x << ' ';
	}
	cout << endl;
	copy(arrayB, array, 10);
	for (auto x: arrayB){
		cout << x << ' ';
	}

	//2
	int a2[10]{1, 2, 3, 4, 5, 18, 2, 3};
	cout << endl;
	for (auto x: a2){
		cout << x << ' ';
	}
	cout << endl;
	max2zero(a2, 10);
	for (auto x: a2){
		cout << x << ' ';
	}
	cout << endl;

	//3
	int a3[10]{-2, 4, 0, 6, 5, 18, 22, 33, 45, 46};
	int a32[10]{};
	cout << "answer on 3 = " << thirdTask1(a3, 10) << endl;
	cout << "answer on 3 = " << thirdTask1(a32, 10) << endl;
	cout << "answer on 3 = " << thirdTask2(a3, 10) << endl;
	cout << "answer on 3 = " << thirdTask2(a32, 10) << endl;

	//4
	int a4[10][10] = {{1,2,3}, {9}, {1,1,1,1,1,1,1,1}, {3,54,32,1}, {100}, {12,2,3}, {0,2,3}, {23,23,43}, {11,11}, {122}};
	int sumTmp[10]{};
	for (int i = 0; i < 10; i++){
		sumTmp[i] = sumOfArray(a4[i], 10);
	}
	int *b[10];
	int index = 0;
	for (int i = 0; i < 10; i++){
		index = distance(sumTmp, max_element(sumTmp, sumTmp + 10));
		max2Int_min(sumTmp, 10);
		b[i] = a4[index];
	}
	cout << endl;
	return 0;
}

