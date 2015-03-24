#include "Shape.h"

#include <iostream>

using namespace std;

double distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

Rhombus::Rhombus(double xTop, double yTop, double xR, double yR) : xT(xTop), yT(yTop), xR(xR), yR(yR)
{
}

void Rhombus::draw()
{
	cout
		<< " Rhombus "
		<< "("<< xT << "," << yT << ")"
		<< ",(" << xR << "," << yR << ")"
		<< ",(" << xT << "," <<  yT - 2*yR << ")"
		<< ",(" << xT- xR << "," << yR << ")\n";
}

double Rhombus::area()
{
	return 2*(xR-xT)*(yT - yR);
}

double Rhombus::perim()
{
	return 4 * distance(xT, yT, xR, yR);
}

RhombusWithDiag::RhombusWithDiag(double xTop, double yTop, double xR, double yR): Rhombus(xTop, yTop, xR, yR)
{
}

void RhombusWithDiag::draw()
{
	Rhombus::draw();
	cout << "    also has diag-s \n";
}


Circle::Circle(double radius): r(radius)
{
}

double Circle::area()
{
	return M_PI*r*r;
}

double Circle::perim()
{
	return 2*M_PI*r;
}
