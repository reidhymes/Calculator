/*========================================================================
* MultiplyCalcOperation.cpp
*
*	Defines the calculator operation methods for Multiply.
========================================================================*/
#include <iostream>

#include "MultiplyCalcOperation.h"
#include "Util.h"

using std::cout;


void MultiplyCalcOperation::PromptForAdditionalOperands()
{
	DisplayInputMessage();
	ReadInput<OperandDataType>(_secondOperand);
}

void MultiplyCalcOperation::CheckForCalculationError(const OperandDataType& result)
{
	if ( result * _secondOperand == INFINITY )
		_error = BOUNDARY_ERROR;
}

void MultiplyCalcOperation::Execute(OperandDataType & result)
{
	PromptForAdditionalOperands();
	CheckForCalculationError(result);
	result *= _secondOperand;
}

string MultiplyCalcOperation::GetMenuText() const
{
	return "Multiply";
}

void MultiplyCalcOperation::DisplayInputMessage()
{
	cout << "Value to multiply: ";
}
