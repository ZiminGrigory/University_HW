#include <iostream>
#include <fstream>
#include <vld.h>
#include "hash.h"
using namespace std;

int main()
{
	ifstream inp;
	inp.open("input.txt");
	ifstream inpSec;
	inpSec.open("input2.txt");
	ofstream out;
	out.open("output.txt");
	int i = 0;
	const int n = 1000;
	List **a = filling(inp, n);
	meetString(a, n, inpSec, out);
	for (i = 0; i < n; i++)
		delete a[i];
	delete []a;


	inp.close();
	inpSec.close();
	out.close();
}