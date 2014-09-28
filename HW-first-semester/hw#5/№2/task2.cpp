#include <stdlib.h> 
#include <iostream>

using namespace std;

void printNumberInExpForm(double value)
{
	unsigned long long int *bitPointer = reinterpret_cast <unsigned long long int*> (&value);

	if (!(*bitPointer << 1)) // �������� �� ���� ������ �� 1  ������� ��������
	{
		cout << 0 << endl;
		return;
	}
	
	unsigned long long int mask = 1;
	mask <<= 63; 

	if (*bitPointer & mask)// �������� �����
		cout << '-';
	else
		cout << '+';
	mask >>= 12;    //�������� �� ������ ��������
	unsigned long long check = 0;
	check = ~check;
	unsigned long long int protectionOfFull = check / 10; // �������� �� ������������, ������������ ����.
	check >>= 12; //�������� � ��������
	unsigned long long mantissa = 0;
	unsigned long long pValue = 1; // ��� �������� ��������
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
	if (mantissa != 0)//����� ��������
	{
		cout << ".";
		for (int i = 0; i < nulls - d; i++) 
		{
			cout << '0';
		}
		cout << mantissa;
	}

	//����������
	cout << " *";     
	*bitPointer <<= 1;     //c�������, ����� �������� ��� �����
	*bitPointer >>= 53;    // �������� � �������� ��� 2^10 - 1 (�.�. ����� �������� �� ����� 1 ��� ����������� ) ����� ��� ������� ���� ���� ������� � ���������� ��
    int exp = *bitPointer ; 
    exp = exp - 1023;       //������ (2^10 -1) � ������� ������� �����
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