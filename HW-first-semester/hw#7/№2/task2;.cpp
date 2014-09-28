#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>
#include "hash.h"
using namespace std;



int main()
{
	ifstream inp;
	inp.open("input.txt");
	ofstream out;
	out.open("output.txt");
	int i = 0;
	const int n = 1000;
	List **a = filling(inp, n);
	meetWords(a, n, out);
	for (i = 0; i < n; i++)
		delete a[i];
	delete []a;
	cout << endl;	
	inp.close();
	out.close();
}
