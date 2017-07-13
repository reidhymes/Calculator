/*========================================================================
* Calculator.h
*
*	Declares a Calculator that has a set of operations and a result 
*	value that rolls over after every operation similar to the Windows 
*	Calculator.
========================================================================*/
#pragma once

#include <vector>

#include "CalcOperationFactory.h"

using std::vector;

class Calculator
{
public:
	Calculator();
	~Calculator() = default;

	void ProcessSelection(const OperationType& operation);
	OperandDataType GetResult() const;
	string GetOperationText(const int& index) const;

private:
	void ProcessErrors(const OperationType& operationIndex);

	CalcOperationFactory _factory;
	vector<unique_ptr<CalcOperation>> _operations;
	OperandDataType _result;
};