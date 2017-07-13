/*========================================================================
* DivideCalcOperation.cpp
*
*	Defines the calculator operation methods for Divide.
========================================================================*/
#include <iostream>

#include "DivideCalcOperation.h"
#include "Util.h"

using std::cout;


void DivideCalcOperation::PromptForAdditionalOperands()
{
	DisplayInputMessage();
	ReadInput<OperandDataType>(_secondOperand);
}

void DivideCalcOperation::CheckForCalculationError(const OperandDataType& result)
{
	// It may be possible to have more than one error occur at a time, but just propagate a single error.
	if (result < 0 && _secondOperand < 0 && result * _secondOperand <= 0)
		_error = BOUNDARY_ERROR;
	else if (_secondOperand == 0)
		_error = DIVIDE_BY_ZERO_ERROR;
}

void DivideCalcOperation::Execute(OperandDataType & result)
{
	PromptForAdditionalOperands();
	CheckForCalculationError(result);
	result /= _secondOperand;
}

string DivideCalcOperation::GetMenuText() const
{
	return "Divide";
}

void DivideCalcOperation::DisplayInputMessage()
{
	cout << "Value to divide by: ";
}
