/*========================================================================
* QuitCalcOperation.h
*
*	Declares the calculator operation Quit. This is an operation
*	that does nothing, but passes through the user input to quit.
========================================================================*/
#pragma once

#include "CalcOperation.h"

class QuitCalcOperation : public CalcOperation
{
public:
	QuitCalcOperation() = default;
	~QuitCalcOperation() = default;

	string GetMenuText() const override;
	void Execute(OperandDataType& result) override;
};