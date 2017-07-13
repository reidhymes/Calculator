/*========================================================================
* ClearMemCalcOperation.cpp
*
*	Defines the calculator operation methods for ClearMem.
========================================================================*/
#include "ClearMemCalcOperation.h"


void ClearMemCalcOperation::Execute(OperandDataType & result)
{
	result = static_cast<OperandDataType>(0);
}

string ClearMemCalcOperation::GetMenuText() const
{
	return "Clear Memory";
}
