#include <iostream>
#include <math.h>
#include <sys/time.h>
#include <functional>

#include "tree.h"

using namespace std;


long long mtime()
{
	timeval t;
	gettimeofday(&t, NULL);
	long long mt = (long long)t.tv_sec * 1000 + t.tv_usec / 1000;
	return mt;
}

struct Wrapper {
	Wrapper() {
		cout << "\n STARTED \n";
	}
	~Wrapper() {
		cout << "\n FINISED time = "<< -st + mtime() << "\n";
	}
	long long st = mtime();
};

double func(double b) {
	Wrapper wr;
	for (int i = 0; i<=10000000; i++)
		b = sqrt(23.041) - sqrt(b);
	throw ("test");
	return b;
}

int main()
{
	cout << "Hello World!" << endl;

	//1,2
	Tree<int> t;
	int a(-1);
	while (a) {
		cin >> a;
		if (a) {
			t.add(a);
		}
	}

	t.printTreeWithDepths();
	cout << "\nhasElBetween20_30 =" << t.hasElBetween20_30();

	//2
	try {
		double ans = func(3.14);
		cout << endl << ans << endl;
	} catch(...) {}

	return 0;
}

