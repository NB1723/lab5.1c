#include "pch.h"
#include "CppUnitTest.h"
#include "../Complex.cpp"
#include "../Complex_Private.cpp"
#include "../Complex_Public.cpp"
#include "../MyDerivedException.cpp"
#include "../MyException.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Complex_Private A(4, -1);
			Complex_Private B(6, -3);

			Complex_Private C = A + B;
			Assert::AreEqual(C.GetRe(), 10.0);
		}
	};
}