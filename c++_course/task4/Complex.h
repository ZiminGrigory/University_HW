#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {

public:
	Complex(double re_ = 0, double im_ = 0) : re(re_), im(im_)
	{}

	friend Complex operator+(const Complex &c1, const Complex &c2);
	friend Complex operator*(const Complex &c1, const Complex &c2);

	Complex &operator*=(const Complex &c2)
	{
		double mR = re;
		double mI = im;
		this->re = mR * c2.re - mI * c2.im;
		this->im = mR * c2.im + mI * c2.re;
		return *this;
	}
private:
	double re, im;
};

Complex operator+(const Complex &c1, const Complex &c2)
{
	return Complex(c1.re + c2.re, c1.im + c2.im);
}

Complex operator*(const Complex &c1, const Complex &c2)
{
	return Complex(c1).operator *=(c2);
}

#endif // COMPLEX_H
