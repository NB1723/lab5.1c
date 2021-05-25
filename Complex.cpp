#include "Complex.h"

Complex::Complex()
	: x(0), y(0)
{}

Complex::Complex(double X, double Y) throw(logic_error)
{
	if (!(X > 0 && Y < 0))
		throw logic_error("Condition is not met");

	this->SetRe(X);
	this->SetIm(Y);
}

Complex::Complex(const Complex& v)
{
	x = v.x;
	y = v.y;
}

Complex& Complex::operator = (const Complex& n)
{
	x = n.x;
	y = n.y;
	return *this;
}

Complex::operator string () const
{
	stringstream ss;
	ss << "(" << this->x << " + i * " << this->y << ")" << endl;
	return ss.str();
}

Complex& Complex::operator --() throw(MyDerivedException)
{
	--y;
	if (y < -7)
		throw new MyDerivedException();
	return *this;
}

Complex& Complex::operator ++() throw(MyException)
{
	++x;
	if (x > 7)
		throw MyException("Real part of number is bigger than 7");
	return *this;
}

Complex Complex::operator --(int) throw(MyDerivedException)
{
	Complex a(*this);
	y--;
	if (y < -7)
		throw MyDerivedException();
	return a;
}

Complex Complex::operator ++(int) throw (MyException)
{
	Complex a(*this);
	x++;
	if (x > 7)
		throw new MyException("Real part of number is bigger than 7");
	return a;
}

Complex operator + (Complex Z1, Complex Z2)
{
	Complex tmp;
	tmp.x = Z1.x + Z2.x;
	tmp.y = Z1.y + Z2.y;
	return tmp;
}

Complex operator * (Complex Z1, Complex Z2)
{
	Complex tmp;
	tmp.x = (Z1.x * Z2.x) - (Z1.y * Z2.y);
	tmp.y = (Z1.x * Z2.y) + (Z2.x * Z1.y);
	return tmp;
}

bool operator == (Complex Z1, Complex Z2)
{
	return Z1.x == Z2.x && Z1.y == Z2.y;
}

ostream& operator <<(ostream& out, const Complex& a)
{
	return out << string(a);
}

istream& operator >>(istream& in, Complex& a) throw(logic_error)
{
	double x, y;
	cout << "x = "; in >> x;
	cout << "y = "; in >> y;

	if (!(x > 0 && y < 0))
		throw logic_error("Condition is not met");

	a.SetRe(x), a.SetIm(y);
	return in;
}