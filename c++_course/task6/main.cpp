#include <iostream>
#include <string>

#include "Rational.h"
#include "tree.h"
#include "mString.h"

using namespace std;

std::pair<int, int> firstLastSpace (const string& s) { //return (-1, -1) if string hasn't space
	auto p = make_pair<int, int>(-1, -1);
	for (int i = 0; i < s.size(); i++) {
		if (s.at(i) == ' ') {
			if (p.first == -1) {
				p.first = i;
				p.second = i;
			} else {
				p.second = i;
			}
		}
	}
	return p;
}

int main()
{
	cout << "Hello World!" << endl;

	Rational r(1,3);
	double x = r;  // x = 0.33333
	cout << x;

	//2
	Tree<int> t;
	t.add(1);
	t.add(1);
	t.add(1);
	t.add(1);
	bool ans = t.hasEven();
	t.add(2);
	ans = t.hasEven();
	cout << ans;

	//3
	string s = "asfa sfa s";
	auto p = firstLastSpace(s);

	//4
	mString s1("abc"), s2("klm");
	s1 += s2;
	auto s3 = s1;
	cout << endl;
	s1.print(); // abcklm
	return 0;
}

