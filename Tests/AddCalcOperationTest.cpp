#include "gtest\gtest.h"

#include "StdinStreamTester.h"
#include "..\Calculator\AddCalcOperation.h"


TEST_F(StdinStreamTester, AddOverflow)
{
	AddCalcOperation op;

	testing::internal::CaptureStdout();

	WriteToStdin(LDBL_MAX);
	OperandDataType result = LDBL_MAX;
	op.Execute(result);

	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(result, INFINITY);
	EXPECT_EQ(op.GetError(), BOUNDARY_ERROR);
}
 