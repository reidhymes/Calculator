/*========================================================================
* SubtractCalcOperation.cpp
*
*	Defines the calculator operation Substract.
========================================================================*/
#include <iostream>

#include "SubtractCalcOperation.h"
#include "Util.h"

using std::cout;


void SubtractCalcOperation::PromptForAdditionalOperands()
{
	DisplayInputMessage();
	ReadInput<OperandDataType>(_secondOperand);
}

void SubtractCalcOperation::CheckForCalculationError(const OperandDataType& result)
{
	if (result == INFINITY)
		_error = BOUNDARY_ERROR;
}

void SubtractCalcOperation::Execute(OperandDataType & result)
{
	PromptForAdditionalOperands();
	result -= _secondOperand;
	CheckForCalculationError(result);
}

string SubtractCalcOperation::GetMenuText() const
{
	return "Subtract";
}

void SubtractCalcOperation::DisplayInputMessage()
{
	cout << "Value to subtract: ";
}
