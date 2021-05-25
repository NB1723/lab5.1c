#include "MyDerivedException.h"

const char* MyDerivedException::What() const
{
	return "Exception: MyDerivedException: y < -7 ";
}