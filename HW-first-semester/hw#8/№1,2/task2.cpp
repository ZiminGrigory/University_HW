#include <iostream>
#include <fstream>
#include <limits.h>
#include "graph.h"
#include "bubbleSort.h"
using namespace std;


int main()
{
	ifstream inp;
	inp.open("input.txt");
	ofstream out;
	out.open("output.txt");
	int n = 0;
	inp >> n;
	int m = 0;
	inp >> m;
	List **a = createAndFilling(n, m, inp);
	Dijkstra(a, n, m, out);
	deleteGraph(a, n);
	inp.close();
	out.close();
}