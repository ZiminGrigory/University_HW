#include <iostream>
#include <functional>
#include <vector>
#include <mString.h>
#include "abc.h"


using namespace std;


double f(double x)
{
	return x * x * x;
}

double integral(function<double(double)> f, double a, double b) {
	double integ = 0.;
	double d = (b - a) / 100000;
	for (double i = a; i <= b - d; i += d) {
		integ += d * f((2 * i + d )/2.);
	}
	return integ;
}



void test() {
	Abc z;
	cout << Abc::num(); // 3 экземпляра
}

int main()
{
	//1
	Abc x; Abc y;
	cout << Abc::num(); // 2 экземпляра
	test();
	x = x;
	cout << Abc::num(); // снова 2 экземпляра

	//2
	double ans = integral(f, 0, 1);
	ans = integral([](double x){return x * x * x;}, 0, 1);


	//3
	string a = "";
	cin >> a;
	vector<pair <string, long long> > sv;
	long long tmp, max = -1;
	while (a != "*") {
		cin >> tmp;
		sv.push_back(make_pair(a, tmp));
		max = max < tmp ? tmp : max;
		cin >> a;
	}
	for(auto v : sv) {
		if (v.second == max) {
			cout << endl << v.first;
		}
	}


//4
	SharedString s1 = "abc";
	SharedString s2 = "klm";

	s2 = s1;  // “klm” освобождается. На  “abc” – 2 указателя.

	SharedString s3 = "pqr";
	s1 = s3;  // На  “abc” – 1 указатель.
	s2 = s3;  // “abc”  удаляется
	s2 += s2;



	return 0;
}

