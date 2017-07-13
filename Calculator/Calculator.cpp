/*========================================================================
* Calculator.h
*
*	Defines a Calculator that has a set of operations and a result
*	value that rolls over after every operation similar to the Windows
*	Calculator.
========================================================================*/
#include <iostream>

#include "Calculator.h"
#include "OperationTypes.h"
#include "Util.h"

using std::cout;
using std::endl;


Calculator::Calculator()
	: _factory(), _operations(), _result(0.0)
{
	for (int i = -1; i < NUMBER_OF_OPERATION_TYPES; ++i)
	{
		_operations.push_back(_factory.GetOperation(static_cast<OperationType>(i)));
	}
}

void Calculator::ProcessErrors(const OperationType& operationIndex)
{
	if (_operations[operationIndex + 1]->GetError() != NO_ERROR)
		cout << GetErrorMessage(_operations[operationIndex + 1]->GetError()) << endl;
}

void Calculator::ProcessSelection(const OperationType& operationIndex)
{
	if (operationIndex >= NUMBER_OF_OPERATION_TYPES)
		_operations[INVALID_OPERATION + 1]->Execute(_result);
	else
	{
		_operations[operationIndex + 1]->Execute(_result);
		ProcessErrors(operationIndex);
	}
}

OperandDataType Calculator::GetResult() const
{
	return _result;
}

string Calculator::GetOperationText(const int& index) const
{
	return _operations[index + 1]->GetMenuText();
}