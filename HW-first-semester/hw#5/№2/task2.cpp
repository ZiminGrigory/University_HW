#include <stdlib.h> 
#include <iostream>

using namespace std;

void printNumberInExpForm(double value)
{
	unsigned long long int *bitPointer = reinterpret_cast <unsigned long long int*> (&value);

	if (!(*bitPointer << 1)) // проверка на ноль смещая на 1  смотрим значение
	{
		cout << 0 << endl;
		return;
	}
	
	unsigned long long int mask = 1;
	mask <<= 63; 

	if (*bitPointer & mask)// проверка знака
		cout << '-';
	else
		cout << '+';
	mask >>= 12;    //сдвинули до начала мантиссы
	unsigned long long check = 0;
	check = ~check;
	unsigned long long int protectionOfFull = check / 10; // проверка на переполнение, используется ниже.
	check >>= 12; //сдвинули к мантиссе
	unsigned long long mantissa = 0;
	unsigned long long pValue = 1; // для подсчета мантиссы
    int nulls = 0;             
	
	
	while (check & *bitPointer)//create mantissa based on memory
	{
		if (mantissa <= protectionOfFull)      
        {
            mantissa = mantissa * 10;      
            pValue = pValue * 5;         
            nulls++;             
        }                    
        else                 
            pValue = pValue / 2;
                             
        if (*bitPointer & mask)   
            mantissa = mantissa + pValue;
 
        mask >>= 1;
        check >>= 1;
	}
	int d = 1; 
	if (nulls != 0)
	{
		unsigned long long int copyMantissa = mantissa;
		d = 0;
		while (copyMantissa > 0)
		{
			copyMantissa = copyMantissa / 10;
			d++;
		}
	}
	cout << "1";
	if (mantissa != 0)//вывод мантиссы
	{
		cout << ".";
		for (int i = 0; i < nulls - d; i++) 
		{
			cout << '0';
		}
		cout << mantissa;
	}

	//экспонента
	cout << " *";     
	*bitPointer <<= 1;     //cдвинули, чтобы потерять бит знака
	*bitPointer >>= 53;    // сдвинули к мантиссе там 2^10 - 1 (т.к. ессли мантисса не пуста 1 уже учитывается ) слева бит порядка плюс наша степень в десятичной сс
    int exp = *bitPointer ; 
    exp = exp - 1023;       //вычтем (2^10 -1) и получим степень числа
    cout << "2^" << exp << "\n";


}
int main()
{
	cout << "enter the number\n"; 
	double value;
	cin >> value;
	cout << endl;
	printNumberInExpForm(value);

	cout << endl;
	int n;
	cin >> n;
	cout << endl;

}