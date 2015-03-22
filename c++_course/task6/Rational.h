#pragma once

#include <iostream>

using namespace std;

class Rational {
public:
	Rational(int a, int b) : a(a), b(b)
	{}
	operator double() const {
		return static_cast<double>(a) / static_cast<double>(b);
	}
private:
	int a;
	int b;
};
