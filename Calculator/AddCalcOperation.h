/*========================================================================
* AddCalcOperation.h
*
*	Declares the calculator operation Add
========================================================================*/
#pragma once

#include "TwoOperandCalcOperation.h"
#include "Util.h"

class AddCalcOperation : public TwoOperandCalcOperation
{
public:
	AddCalcOperation() = default;
	~AddCalcOperation() = default;

	void Execute(OperandDataType& result) override;
	string GetMenuText() const override;

private:
	void DisplayInputMessage();
	void PromptForAdditionalOperands() override;
	void CheckForCalculationError(const OperandDataType& result);

	OperandDataType _secondOperand;
};