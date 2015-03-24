#include <iostream>
#include <string>
#include <string.h>

#include "Rational.h"
#include "Shape.h"

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

int aprilCount(const char* const s) {
	int ans = 0;
	auto ms = s;
	while (ms) {
		ms = strstr(ms, "April");
		if (ms) {
			ans++;
			ms+=5;
		}
	}
	return ans;
}

int main()
{

	Rational r(8,6);
	double x = r;  // x = 0.33333
	cout << x;
	cout << r;


	cout << aprilCount("April   Apr il Ap ril Apri lApril");

	cout << endl;
	Shape* s1 = new ShapeWithHole(new Rhombus(0, 100, 100, 0), 20);     // Ромб, и в нем вырезан круг радиуса 20
	Shape* s2 = new ShapeWithHole(new Circle(200), 50);   // Прямоугольник, и в нем вырезан круг радиуса 50
	cout << s1->area() << endl;
	cout << s2->perim() << endl;
}

