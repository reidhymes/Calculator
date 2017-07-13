/*========================================================================
* InvalidCalcOperation.cpp
*
*	Defines the calculator operation methods for invalid operation.
========================================================================*/
#include <iostream>

#include "InvalidCalcOperation.h"

using std::cout;
using std::endl;


string InvalidCalcOperation::GetMenuText() const
{
	return "Invalid menu selection.";
}

void InvalidCalcOperation::Execute(OperandDataType& result)
{
	cout << GetMenuText() << endl;
}
