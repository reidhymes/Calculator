#include <gtest/gtest.h>

#include "StdinStreamTester.h"
#include "..\Calculator\CalcErrorTypes.h"
#include "..\Calculator\MultiplyCalcOperation.h"


TEST_F(StdinStreamTester, MultiplyZeros)
{
	MultiplyCalcOperation op;

	testing::internal::CaptureStdout();

	WriteToStdin("0");
	OperandDataType result = 0;
	op.Execute(result);

	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(result, 0);
}

TEST_F(StdinStreamTester, MultiplyLargeNumbers)
{
	MultiplyCalcOperation op;

	testing::internal::CaptureStdout();

	WriteToStdin(2);
	OperandDataType result = FLT_MAX;
	op.Execute(result);

	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(result, INFINITY);
	EXPECT_EQ(op.GetError(), BOUNDARY_ERROR);
}


TEST_F(StdinStreamTester, MultiplyUnderflow)
{
	MultiplyCalcOperation op;

	testing::internal::CaptureStdout();

	WriteToStdin(FLT_MIN);
	OperandDataType result = FLT_MIN;
	op.Execute(result);

	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(result, 0);
	EXPECT_FALSE(op.GetError());
}