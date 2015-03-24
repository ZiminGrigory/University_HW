#pragma once

#include <math.h>

class Shape
{
public:
	Shape(){}
	virtual ~Shape(){}
	virtual double area() const  = 0;
	virtual double perim() const = 0;
};


class Rhombus: public Shape
{
public:
	Rhombus(double xTop, double yTop, double xR, double yR);
	virtual void draw() const;
	double area() const override;
	double perim() const override;
protected:
	double xT, yT, xR, yR;
};

class RhombusWithDiag: public Rhombus
{
public:
	RhombusWithDiag(double xTop, double yTop, double xR, double yR);
	void draw() const;
};


class Circle: public Shape
{
public:
	Circle(double radius);
	double area() const override;
	double perim() const override;

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

	double area() const override{
		return mShape->area() - insShape->area();
	}

	double perim() const override {
		return mShape->perim() + insShape->perim();
	}

	ShapeWithHole& operator=(const ShapeWithHole& from) = delete;
private:
	Shape *mShape;
	Shape *insShape;
};
