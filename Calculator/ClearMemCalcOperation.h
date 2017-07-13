/*========================================================================
* ClearMemCalcOperation.h
*
*	Declares the calculator operation ClearMem (CM).
*	This sets the Result value back to 0.
========================================================================*/
#pragma once

#include "CalcOperation.h"

class ClearMemCalcOperation : public CalcOperation
{
public:
	ClearMemCalcOperation() = default;
	~ClearMemCalcOperation() = default;

	void Execute(OperandDataType& result) override;
	string GetMenuText() const override;
};