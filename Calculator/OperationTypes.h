/*========================================================================
* OperationTypes.h
*
*	A header that can be modified to add 
*	or remove operations from the calculator.
========================================================================*/
#pragma once


enum OperationType : int
{
	INVALID_OPERATION = -1,
	QUIT = 0,
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	CLEAR_MEMORY,
	NUMBER_OF_OPERATION_TYPES
};
