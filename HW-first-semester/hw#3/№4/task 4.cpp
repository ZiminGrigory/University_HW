#include <iostream>
using namespace std;

struct List
{
	int value;
	List *next;
};

int numberOfNumeral(int n)
{
	int answer = 1;
	if (n > 1)
		while ((n / 10) != 0)
		{
			answer++;
			n = n % 10;
		}
	else
		if (n < -1)
		{
			n = n * (-1);
			while ((n / 10) != 0)
			{
				answer++;
				n = n % 10;
			}
		}
		else 
			if ((n == 0) || (n == 1) || (n == (-1)))
				answer = 0;
	return answer;
}

int main ()
{
	int n = 0; // кол-во коэф-в 
	List *head = new List;
	int c = 0; //для ввода коэф-в
	cout << "enter the coefficient \n";
	cin >> c;
	List *temp = new List;
	temp->value = c;
	head = temp;
	List *headValue = head;
	bool answer = 0;
	cout << "is that all ? enter 1 or 0 \n";
	cin >> answer;
	while (!answer)
	{
		cout << "enter the coefficient \n";
		cin >> c;
		List *temp = new List;
		temp->value = c;
		headValue->next = temp;
		headValue = headValue->next;
		n++;
		cout << "is that all ? enter 1 or 0 \n";
		cin >> answer;
	}
	cout << "ANS = \n";
	int nSecond = n;
	//начало вывода степеней считаем, что есть хотя бы х в степени 1, иначе это не многочлен
	headValue = head;
	if (headValue->value > 0)
	{
		for (int i = 1; i <= numberOfNumeral(headValue->value) + 1; i++)
			cout << " ";
		if (n > 1)
			cout << n;  
	}
	else
		if (headValue->value < 0)
		{
			for (int i = 1; i <= numberOfNumeral(headValue->value) + 2; i++)
				cout << " ";
			if (n > 1)
				cout << n;  
		}
	headValue = headValue->next;
	n--;
	while (n > 0)
	{
		if (headValue->value > 0)
		{
			for (int i = 1; i <= numberOfNumeral(headValue->value) + 2; i++)
				cout << " ";
			if (n > 1)
				cout << n;  
		}
		else
			if (headValue->value < 0)
			{
				for (int i = 1; i <= numberOfNumeral(headValue->value) + 3; i++)
					cout << " ";
				if (n > 1)
					cout << n;  
			}
		n--;
		headValue = headValue->next;
	}
	cout << endl;
	//конец вывода степеней
	//вывод многочлена начало
	n = nSecond;
	headValue = head;
	if ((headValue->value != 1) && (headValue->value != -1))
		cout << headValue->value << "x";
	else
		if (headValue->value == 1)
			cout << "x";
		else
			cout << "-x";
	if (n > 1)
		for (int i = 1; i <= numberOfNumeral(n); i++)
			cout << " ";
	headValue = headValue->next;
	n--;
	
	while (n > 0)
	{
		if (headValue->value == 0)
		{
			headValue = headValue->next;
			n--;
		}
		else
		{	
			if (headValue->value > 0)
			cout << "+";
			if ((headValue->value != 1) && (headValue->value != -1))
				cout << headValue->value << "x";
			else
				if (headValue->value == 1)
					cout << "x";
				else
					cout << "-x";
			if (n > 1)
				for (int i = 1; i <= numberOfNumeral(n); i++)
					cout << " ";
			headValue = headValue->next;
			n--;
		}
	}
	if (headValue->value > 0)
		cout << "+";
	if (headValue->value != 0) 
		cout << headValue->value;
	// конец вывода многочлена

	// очистка памяти
	n = nSecond+1;
	headValue = NULL;
	for (int i = 1; i <= n; i++)
	{
		List *headValue = head;
		head = head->next;
		delete headValue;
	}
	cin >> n;
	cout << endl;
}