/*========================================================================
* SubtractCalcOperation.h
*
*	Declares the calculator operation Substract.
========================================================================*/
#pragma once

#include "TwoOperandCalcOperation.h"

class SubtractCalcOperation : public TwoOperandCalcOperation
{
public:
	SubtractCalcOperation() = default;
	~SubtractCalcOperation() = default;

	void Execute(OperandDataType& result) override;
	string GetMenuText() const override;

private:
	void DisplayInputMessage();
	void PromptForAdditionalOperands() override;
	void CheckForCalculationError(const OperandDataType& result);

	OperandDataType _secondOperand;
};