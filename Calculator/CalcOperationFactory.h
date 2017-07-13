/*========================================================================
* CalcOperationFactory.h
*
*	Declares a factory pattern to initialize calculator operations.
========================================================================*/
#pragma once

#include <memory>

#include "CalcOperation.h"

using std::unique_ptr;

class CalcOperationFactory
{
public:
	CalcOperationFactory() = default;
	~CalcOperationFactory() = default;
	unique_ptr<CalcOperation> GetOperation(const OperationType& operation) const;
};
