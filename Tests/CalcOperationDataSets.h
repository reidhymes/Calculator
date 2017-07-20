#pragma once

#include "CalcOperationTestFixture.h"

#include "..\Calculator\AddCalcOperation.h"
#include "..\Calculator\SubtractCalcOperation.h"
#include "..\Calculator\MultiplyCalcOperation.h"
#include "..\Calculator\DivideCalcOperation.h"
#include "..\Calculator\QuitCalcOperation.h"
#include "..\Calculator\InvalidCalcOperation.h"
#include "..\Calculator\ClearMemCalcOperation.h"

// Container class for all test values related to a particular CalcOperation
template<class T>
struct CalcOperationData
{
	CalcOperationData(OperandDataType res, OperandDataType first,
		OperandDataType second, string menuText, string expectedOut,
		OperandDataType negPosResult)
		: expectedMenuText(menuText),
		  expectedStdout(expectedOut),
		  expectedValue(res),
		  firstOperand(first),
		  secondOperandInput(second),
		  negativeNum(-7.0f),
		  positiveNum(8.0f),
		  negativePosResult(negPosResult)
	{}

	T operation;
	string expectedMenuText;
	string expectedStdout;
	OperandDataType expectedValue;
	OperandDataType firstOperand;
	OperandDataType secondOperandInput;
	OperandDataType negativeNum;
	OperandDataType positiveNum;
	OperandDataType negativePosResult;
};


struct AddCalcOperationData : CalcOperationData<AddCalcOperation>
{
	AddCalcOperationData()
		: CalcOperationData(5.5, 0, 5.5, "Add", "Value to add: ", 1)
	{}
};

struct SubtractCalcOperationData : CalcOperationData<SubtractCalcOperation>
{
	SubtractCalcOperationData()
		: CalcOperationData(-5.5, 10, 15.5, "Subtract", "Value to subtract: ", 15)
	{}
};

struct MultiplyCalcOperationData : CalcOperationData<MultiplyCalcOperation>
{
	MultiplyCalcOperationData()
		: CalcOperationData(7.5, 3, 2.5, "Multiply", "Value to multiply: ", -56)
	{}
};

struct DivideCalcOperationData : CalcOperationData<DivideCalcOperation>
{
	DivideCalcOperationData()
		: CalcOperationData(10 / static_cast<long double>(15.5f), 10, 15.5, "Divide", "Value to divide by: ", -8/static_cast<long double>(7.0))
	{}
};

struct QuitCalcOperationData : CalcOperationData<QuitCalcOperation>
{
	QuitCalcOperationData()
		: CalcOperationData(0, 0, 15.5, "Quit", "", 8)
	{}
};

struct InvalidCalcOperationData : CalcOperationData<InvalidCalcOperation>
{
	InvalidCalcOperationData()
		: CalcOperationData(0, 0, 15.5, "Invalid menu selection.", "Invalid menu selection.\n", 8)
	{}
};

struct ClearMemCalcOperationData : CalcOperationData<ClearMemCalcOperation>
{
	ClearMemCalcOperationData()
		: CalcOperationData(0, 0, 15.5, "Clear Memory", "", 0)
	{}
};