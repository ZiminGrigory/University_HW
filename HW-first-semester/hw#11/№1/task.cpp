#include <iostream>
#include "rools.h"
#include "number.h"
using namespace std; 


void function (bool &ans)
{
	char c = 'f';
	while (ans && c != '\n')
		first(c, ans);
}

int main () 
{
	
	bool ans = true; 
	cout << "enter the function \n";
	char b = 's';
	function(ans);
	cout << "answer: ";
	if (ans) 
		cout << "Yes" << endl; 
	else 
		cout << "No " << endl; 
	while (b != '\n')
		cin >> b; 
	cout << endl;
	cin >> b;
	cout << endl;
}