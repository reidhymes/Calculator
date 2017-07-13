/*========================================================================
* DivideCalcOperation.h
*
*	Declares the calculator operation Divide
========================================================================*/
#pragma once

#include "TwoOperandCalcOperation.h"

class DivideCalcOperation : public TwoOperandCalcOperation
{
public:
	DivideCalcOperation() = default;
	~DivideCalcOperation() = default;

	void Execute(OperandDataType& result) override;
	string GetMenuText() const override;

private:
	void DisplayInputMessage();
	void PromptForAdditionalOperands() override;
	void CheckForCalculationError(const OperandDataType& result);

	OperandDataType _secondOperand;
};