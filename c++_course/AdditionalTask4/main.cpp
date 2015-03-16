#include <iostream>
#include <math.h>
#include <sys/time.h>

#include "tree.h"

using namespace std;


long long mtime()
{
	timeval t;

	gettimeofday(&t, NULL);
	long long mt = (long long)t.tv_sec * 1000 + t.tv_usec / 1000;
	return mt;
}

double func(double b) {
	for (int i = 0; i<=10000000; i++)
		b = sqrt(23.041) - sqrt(b);
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
	auto flambda = [](double a) {
		long long st = mtime();
		cout << "\nFunction started";
		auto ans = func(a);
		cout << " Function finised, time = " << mtime()-st << ' ';
		return ans;
	};

	double ans = flambda(3.14);
	cout << endl << ans << endl;
	return 0;
}

