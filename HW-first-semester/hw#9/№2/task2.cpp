#include <iostream>
#include <string>
#include "algoritm.h"
using namespace std;



int main()
{ 
	string stringFirst = "";
	string stringSec = "";
	cout << "enter the first string \n";
	char ch = cin.get();
	do
	{
		stringFirst = stringFirst + ch;
		ch = cin.get();
	}
	while (ch != '\n');
	cout << "enter the second string \n";
	
	ch = cin.get();
	do
	{
		stringSec = stringSec + ch;
		ch = cin.get();
	}
	while (ch != '\n');
	int answer = 0;
	if (stringFirst.size() < stringSec.size())
		cout << "incorrect srings \n";
	else
	{
		int *a = createMassifOfHash (stringFirst, stringFirst.size(),stringSec.size());
		int pattern = hashFunc (stringSec, stringSec.size());
		answer = search(pattern, a, stringFirst, stringSec);
		destroy (a,stringFirst, stringSec);
	}
	
	cout << "ANS = " << answer << endl;
	cin >> stringFirst;
	cout << endl;
}