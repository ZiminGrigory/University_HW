#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int nod(int a,int b)
{
    while((a!=0) && (b!=0))
    {
       if(a >= b)
		   a = a % b;
       else b = b % a;
    }
 return a + b;
}
void insertionSort(long double arr[1000], int arrSecond[1000], int arrThird[1000],  int length) 
{
      int i, j, tmp;
      for (i = 1; i < length; i++) 
	  {
            j = i;
            while (j > 0 && arr[j - 1] > arr[j]) 
			{
                  swap(arr[j], arr[j - 1]);
				  swap(arrSecond[j], arrSecond[j - 1]);
				  swap(arrThird[j], arrThird[j - 1]);
                  j--;
            }
      }
}
int main()
{
	cout << "please enter the max denominator >= 2 \n";
	int maxDenominator = 0;
	cin >> maxDenominator;
	int numerators[1000] = {};
	int denominators[1000] = {};	
	long double fractions[1000] = {};
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 2; i <= maxDenominator; i++)
		for (j = 1; j <= i; j++)
			if (nod(i,j) == 1) 
			{
				numerators[k] = j;
				denominators[k] = i;
				fractions[k] = (float) j / i;
				k++;
			}
	// быстрая сортировка работать отказалась...не знаю почему, поэтому использовал другую.
	insertionSort(fractions, numerators, denominators, k);
	cout << "ans = \n" ;
	for (i = 0; i <= k - 1; i++)
		cout << numerators[i] << "/" << denominators[i] << " ";
	cin >> maxDenominator;
	cout << endl;
	
}