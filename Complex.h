#pragma once
#pragma pack(1)
#include "MyException.h"
#include "MyDerivedException.h"

class Complex
{
private:
	double x, y;

public:
	Complex();
	Complex(double x, double y) throw(logic_error);
	Complex(const Complex& v);

	double GetRe() const { return x; }
	double GetIm() const { return y; }

	void SetRe(double value) { x = value; }
	void SetIm(double value) { y = value; }

	Complex& operator =(const Complex& n);
	operator string() const;

	Complex& operator --() throw(MyDerivedException);
	Complex& operator ++() throw(MyException);
	Complex operator --(int) throw(MyDerivedException);
	Complex operator ++(int) throw(logic_error);

	friend  Complex operator + (Complex Z1, Complex Z2);
	friend  Complex operator * (Complex Z1, Complex Z2);
	friend  bool operator == (Complex Z1, Complex Z2);

	friend ostream& operator <<(ostream& out, const  Complex& a);
	friend istream& operator >>(istream& in, Complex& a) throw(logic_error);
};