#include <gtest/gtest.h>

#include "CalcOperationTestFixture.h"
#include "CalcOperationDataSets.h"


TYPED_TEST_CASE_P(CalcOperationTestFixture);

// Verifies each CalcOperation has the appropriate menu text.
TYPED_TEST_P(CalcOperationTestFixture, VerifyMenuText)
{
	EXPECT_EQ(_testData.operation.GetMenuText(), _testData.expectedMenuText);
}

// Verifies the additional input needed for particular operations is received.
TYPED_TEST_P(CalcOperationTestFixture, VerifyOperandInput)
{
	OperandDataType result = _testData.firstOperand;

	CollectStdoutAndRunCalcOperation(result, _testData.secondOperandInput);

	EXPECT_EQ(result, _testData.expectedValue);
	EXPECT_EQ(GetTestStdout(), _testData.expectedStdout);
}

TYPED_TEST_P(CalcOperationTestFixture, VerifyOperationWithNegativeAndPositiveValues)
{
	OperandDataType result = _testData.positiveNum;

	CollectStdoutAndRunCalcOperation(result, _testData.negativeNum);

	EXPECT_EQ(result, _testData.negativePosResult);
	EXPECT_EQ(GetTestStdout(), _testData.expectedStdout);
}


// Register the templated tests with Google Test
REGISTER_TYPED_TEST_CASE_P(CalcOperationTestFixture, VerifyMenuText, VerifyOperandInput, VerifyOperationWithNegativeAndPositiveValues);

// Define the test fixtures to use for each execution of the above tests.
typedef testing::Types<AddCalcOperationData,
					   SubtractCalcOperationData, 
	                   MultiplyCalcOperationData,
					   DivideCalcOperationData,
					   InvalidCalcOperationData, 
					   QuitCalcOperationData, 
					   ClearMemCalcOperationData> TwoOpCalcOperationTypes;

// Let Google Test know what tests to run with what fixtures.
INSTANTIATE_TYPED_TEST_CASE_P(CalcOperationTests, CalcOperationTestFixture, TwoOpCalcOperationTypes);
