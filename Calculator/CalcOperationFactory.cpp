/*========================================================================
* CalcOperationFactory.cpp
*
*	Defines a factory pattern to initialize calculator operations.
========================================================================*/
#include "CalcOperationFactory.h"
#include "AddCalcOperation.h"
#include "InvalidCalcOperation.h"
#include "QuitCalcOperation.h"
#include "SubtractCalcOperation.h"
#include "MultiplyCalcOperation.h"
#include "DivideCalcOperation.h"
#include "ClearMemCalcOperation.h"

using std::make_unique;


unique_ptr<CalcOperation> CalcOperationFactory::GetOperation(const OperationType & operation) const
{
	switch (operation)
	{
	case QUIT:
		return make_unique<QuitCalcOperation>();

	case ADD:
		return make_unique<AddCalcOperation>();

	case SUBTRACT:
		return make_unique<SubtractCalcOperation>();

	case MULTIPLY:
		return make_unique<MultiplyCalcOperation>();

	case DIVIDE:
		return make_unique<DivideCalcOperation>();
	
	case CLEAR_MEMORY:
		return make_unique<ClearMemCalcOperation>();

	case INVALID_OPERATION:
	default:
		return make_unique<InvalidCalcOperation>();
	}
}