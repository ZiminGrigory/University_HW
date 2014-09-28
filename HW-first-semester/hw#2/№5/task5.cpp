#include <iostream>
using namespace std;


void buildDown(int *heap, int i, int const n) // строим пирамиду удовлетвор€ющую услови€м родитель больше потомковб ошибки листьев не будет, так как мы используем в качестве материала массив. а не дерево
{   
    int maxIndex = i;
    int const value = heap[i];  
    while (true)
    {
		int left = i * 2 + 1; 
		if ((left < n) && (heap[left] > value))
			maxIndex = left;             
		int right = left + 1;
		if ((right < n) && (heap[right] > heap[maxIndex]))
			maxIndex = right;
		if (maxIndex == i) break;        
		heap[i] = heap[maxIndex]; heap[maxIndex] = value; 
		i = maxIndex;
    };
}
void heapSort(int *heap, int n) //сама сортировка из 2 шагов 1(строим пирамиду) 2 сортируем еЄ поледовательно удал€€ из нее наибоьший элемент(корневой) и мен€€ его с последним.
{   
	for (int i = n; i>=0; --i) 
		buildDown(heap, i, n);
	while (n > 1) 
	{
		n = n - 1;
		int firstElement = heap[0];
		heap[0] = heap[n];
		heap[n] = firstElement;
		buildDown(heap, 0, n);
	}
}
int main()
{
	int n = 0;
	cout << "enter the number of n\n";
	cin >> n;
	int const c = n;
	int *a = new int [n+1];
	cout << "enter the number\n";
	for (int i = 0; i <= n - 1; i++)
		cin >> a[i];
	heapSort(a, n);
	cout << "ANS=\n";
	for (int i = 0; i <= c - 1; i++)
		cout << a[i] << ' ';
	cout << endl;
	cin >> n;
	delete []a;
}