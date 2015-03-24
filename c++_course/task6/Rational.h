#pragma once

#include <iostream>

using namespace std;

class Rational {
public:
	Rational(int a, int b) : a(a), b(b)
	{
		if (!b)
			throw("dib by zero");
	}
	operator double() const {
		return static_cast<double>(a) / static_cast<double>(b);
	}
	friend ostream& operator<< (ostream& output, const Rational& r);
private:
	int a;
	int b;
};

int NOD(int x, int y) {
	while (x != y) {
		if (x > y) {
			x = x - y;
		} else {
			y = y - x;
		}
	}
	return x;
}

ostream& operator<<(ostream& output, const Rational& r)
{
	if (r.a == 0) {
		output  << "\n0";
		return output;
	}
	int c = NOD(r.a, r.b);
	output << '\n' << r.a / c << "/" << r.b / c << '\n';
	return output;
}
