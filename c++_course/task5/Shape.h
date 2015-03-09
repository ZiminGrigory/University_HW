#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
	Shape(){}
	virtual ~Shape(){}
	virtual double area() = 0;
	virtual double perim() = 0;
};


class Rhombus: public Shape
{
public:
	Rhombus(double xTop, double yTop, double xR, double yR);
	virtual void draw();
	double area();
	double perim();
protected:
	double xT, yT, xR, yR;
};

class RhombusWithDiag: public Rhombus
{
public:
	RhombusWithDiag(double xTop, double yTop, double xR, double yR);
	void draw();
};


class Circle: public Shape
{
public:
	Circle(double radius);
	double area();
	double perim();

private:
	double r;
};
#endif // SHAPE_H
