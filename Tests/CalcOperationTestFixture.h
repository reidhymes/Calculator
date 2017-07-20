#pragma once

#include "StdinStreamTester.h"
#include "..\Calculator\CalcOperation.h"

template<class T>
class CalcOperationTestFixture : public StdinStreamTester
{
public:
	void CollectStdoutAndRunCalcOperation(OperandDataType& result, OperandDataType& secondOp);
	string GetTestStdout() const;

protected:
	void RunCalculatorTestOperation(OperandDataType& result, OperandDataType& secondOp);

	std::istringstream _stdinStream;
	T _testData;
};

template<class T>
inline void CalcOperationTestFixture<T>::CollectStdoutAndRunCalcOperation(OperandDataType& result, OperandDataType& secondOp)
{
	// Capture Stdout during the execution of the operation
	// to verify the prompt for additional operands is shown.
	testing::internal::CaptureStdout();

	RunCalculatorTestOperation(result, secondOp);
}

template<class T>
inline string CalcOperationTestFixture<T>::GetTestStdout() const
{
	return testing::internal::GetCapturedStdout();
}

template<class T>
inline void CalcOperationTestFixture<T>::RunCalculatorTestOperation(OperandDataType& result, OperandDataType& secondOp)
{
	WriteToStdin(secondOp);
	_testData.operation.Execute(result);
}
