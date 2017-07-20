/*========================================================================
* CalcOperation.h
*
*	Declares an abstract calculator operation that all concrete 
*	calculator operations must adhere to.
========================================================================*/
#pragma once

#include <string>

#include "OperationTypes.h"
#include "CalcErrorTypes.h"
#include "Util.h"

using std::string;

using OperandDataType = long double;

class CalcOperation
{
public:
	CalcOperation();
	virtual ~CalcOperation() = default;

	virtual string GetMenuText() const = 0;
	virtual void Execute(OperandDataType& result) = 0;
	CalcErrorType GetError() const;

protected:
	CalcErrorType _error;
};

inline CalcOperation::CalcOperation()
	: _error(NO_ERROR)
{
}

inline CalcErrorType CalcOperation::GetError() const
{
	return _error;
}