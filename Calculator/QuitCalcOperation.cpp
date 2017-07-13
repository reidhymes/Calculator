/*========================================================================
* QuitCalcOperation.cpp
*
*	Defines the calculator operation Quit. This is an operation
*	that does nothing, but passes through the user input to quit.
========================================================================*/
#include "QuitCalcOperation.h"


string QuitCalcOperation::GetMenuText() const
{
	return "Quit";
}

void QuitCalcOperation::Execute(OperandDataType & result)
{
}
