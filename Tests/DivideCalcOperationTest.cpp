#include "gtest\gtest.h"

#include "StdinStreamTester.h"
#include "..\Calculator\DivideCalcOperation.h"


TEST_F(StdinStreamTester, DivideByZero)
{
	DivideCalcOperation op;

	testing::internal::CaptureStdout();

	WriteToStdin(0);
	OperandDataType result = 5;
	op.Execute(result);

	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(result, INFINITY);
	EXPECT_EQ(op.GetError(), DIVIDE_BY_ZERO_ERROR);
}

// Verify an underflow error occurs.
// This is a limitation of the IEEE 754 floating point/double type.
TEST_F(StdinStreamTester, DivideUnderflow)
{
	DivideCalcOperation op;

	testing::internal::CaptureStdout();

	WriteToStdin(FLT_MIN);
	OperandDataType result = FLT_MIN;
	op.Execute(result);

	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_NE(result, 1.0f);
	EXPECT_NE(result, FLT_MIN / FLT_MIN);
	EXPECT_FALSE(op.GetError());
}