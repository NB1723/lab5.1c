#include "Complex_Private.h"
#include "Complex_Public.h"

void _unexpected_to_bad()
{
	cerr << "bad_exception" << endl;
	throw;
}

void Call_Bad() throw(bad_exception)
{
	throw bad_exception();
}

int main()
{
	set_unexpected(_unexpected_to_bad);

	try
	{
		Complex_Private A1;
		cin >> A1;
		cout << A1;

		cout << "Size of private class: " << sizeof(A1) << endl;

		Complex_Private B1(5, -1);
		cout << B1 << endl;

		cout << "Sum of complex numbers" << endl;
		Complex_Private C1 = A1 + B1;
		cout << "C1 = " << C1 << endl;

		cout << "Product of complex numbers" << endl;
		Complex_Private D1 = A1 * B1;
		cout << "D1 = " << D1 << endl;

		cout << "Comparison of complex numbers" << endl;
		if (A1 == B1)
			cout << "Complex numbers are equal" << endl;
		else
			cout << "Complex numbers are not equal" << endl;
		try
		{
			A1--;
		}
		catch (MyDerivedException a)
		{
			cerr << a.What() << endl << endl;
		}
		catch (MyDerivedException* a)
		{
			cerr << a->What() << endl << endl;
		}
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	Complex_Private N1;
	cin >> N1;
	cout << N1;

	try
	{
		N1++;
	}
	catch (MyException& a)
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		Complex_Public A2;
		cin >> A2;
		cout << A2;

		cout << "Size of public class: " << sizeof(A2) << endl;

		Complex_Public B2(4, -2);
		cout << B2 << endl;

		cout << "Sum of complex numbers" << endl;
		Complex_Public C2 = A2 + B2;
		cout << "C2 = " << C2 << endl;

		cout << "Product of complex numbers" << endl;
		Complex_Public D2 = A2 * B2;
		cout << "D2 = " << D2 << endl;

		cout << "Comparison of complex numbers" << endl;
		if (A2 == B2)
			cout << "Complex numbers are equal" << endl;
		else
			cout << "Complex numbers are not equal" << endl;
		try
		{
			A2--;
		}
		catch (MyDerivedException a)
		{
			cerr << a.What() << endl << endl;
		}
		catch (MyDerivedException* a)
		{
			cerr << a->What() << endl << endl;
		}
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	Complex_Public N2;
	cin >> N2;
	cout << N2;

	try
	{
		N2++;
	}
	catch (MyException& a)
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		Call_Bad();
	}
	catch (bad_exception)
	{
		cerr << "catch (bad_exception)" << endl;
	}
}