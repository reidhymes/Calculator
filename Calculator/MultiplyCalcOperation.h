/*========================================================================
* MultiplyCalcOperation.h
*
*	Declares the calculator operation Multiply.
========================================================================*/
#pragma once

#include "TwoOperandCalcOperation.h"

class MultiplyCalcOperation : public TwoOperandCalcOperation
{
public:
	MultiplyCalcOperation() = default;
	~MultiplyCalcOperation() = default;

	void Execute(OperandDataType& result) override;
	string GetMenuText() const override;

private:
	void DisplayInputMessage();
	void PromptForAdditionalOperands() override;
	void CheckForCalculationError(const OperandDataType& result);

	OperandDataType _secondOperand;
};