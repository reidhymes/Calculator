/*========================================================================
* AddCalcOperation.cpp
*
*	Defines the calculator operation methods for Add.
========================================================================*/
#include <iostream>

#include "AddCalcOperation.h"
#include "Util.h"

using std::cout;


void AddCalcOperation::PromptForAdditionalOperands()
{
	DisplayInputMessage();
	ReadInput<OperandDataType>(_secondOperand);
}

void AddCalcOperation::CheckForCalculationError(const OperandDataType& result)
{
	if (result == INFINITY)
		_error = BOUNDARY_ERROR;
}

void AddCalcOperation::DisplayInputMessage()
{
	cout << "Value to add: ";
}

void AddCalcOperation::Execute(OperandDataType& result)
{
	PromptForAdditionalOperands();
	result += _secondOperand;
	CheckForCalculationError(result);
}

string AddCalcOperation::GetMenuText() const
{
	return "Add";
}
