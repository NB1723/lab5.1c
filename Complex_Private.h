#pragma once
#include "Complex.h"

class Complex_Private : private Complex
{
public:
	using Complex::GetRe;
	using Complex::GetIm;

	using Complex::SetRe;
	using Complex::SetIm;

	using Complex::Complex;

	Complex_Private();
	Complex_Private(int x, int y);
	Complex_Private(const Complex_Private& v);

	Complex_Private& operator = (const Complex_Private& n);
	operator string() const;

	Complex_Private& operator --() throw(MyDerivedException);
	Complex_Private& operator ++() throw(MyException);
	Complex_Private operator --(int) throw(MyDerivedException);
	Complex_Private operator ++(int) throw(logic_error);

	friend  Complex_Private operator + (const Complex_Private Z1, const Complex_Private Z2);
	friend  Complex_Private operator * (const Complex_Private Z1, const Complex_Private Z2);
	friend  bool operator == (const Complex_Private Z1, const Complex_Private Z2);

	friend ostream& operator <<(ostream& out, const  Complex_Private& a);
	friend istream& operator >>(istream& in, Complex_Private& a) throw(logic_error);
};