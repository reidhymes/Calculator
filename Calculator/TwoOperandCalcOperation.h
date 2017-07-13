#pragma once

#include "CalcOperation.h"


class TwoOperandCalcOperation : public CalcOperation
{
public:
	TwoOperandCalcOperation() = default;
	virtual ~TwoOperandCalcOperation() = default;

protected:
	virtual void PromptForAdditionalOperands() = 0;
	virtual void CheckForCalculationError(const OperandDataType& result) = 0;
};