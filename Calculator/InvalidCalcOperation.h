/*========================================================================
* InvalidCalcOperation.h
*
*	Declares the calculator operation Invalid Operation. This is a 
*	special operation of a calculator that prevents erroneous input.
========================================================================*/
#pragma once

#include "CalcOperation.h"

class InvalidCalcOperation : public CalcOperation
{
public:
	InvalidCalcOperation() = default;
	~InvalidCalcOperation() = default;

	string GetMenuText() const override;
	void Execute(OperandDataType& result) override;
};