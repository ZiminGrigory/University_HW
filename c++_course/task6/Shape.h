#pragma once

#include <math.h>

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
	double area() override;
	double perim() override;
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
	double area() override;
	double perim() override;

private:
	double r;
};

class ShapeWithHole : public Shape{
public:
	ShapeWithHole(Shape *shape, double radius) : mShape(shape), insShape(new Circle(radius))
	{}

	ShapeWithHole(const ShapeWithHole& from) = delete;

	~ShapeWithHole() {
		delete mShape;
		delete insShape;
	}

	double area() override{
		return mShape->area() - insShape->area();
	}

	double perim() override {
		return mShape->perim() + insShape->perim();
	}

	ShapeWithHole& operator=(const ShapeWithHole& from) = delete;
private:
	Shape *mShape;
	Shape *insShape;
};
