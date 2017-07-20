#include <gtest/gtest.h>

#include "CalcOperationTestFixture.h"
#include "CalcOperationDataSets.h"


TYPED_TEST_CASE_P(CalcOperationTestFixture);

// Verifies each CalcOperation has the appropriate menu text.
TYPED_TEST_P(CalcOperationTestFixture, VerifyMenuText)
{
	EXPECT_EQ(_testData.operation.GetMenuText(), _testData.expectedMenuText);
}

// Verifies the derived implementation of CalcOperation::PromptForAdditionalOperand() is called
TYPED_TEST_P(CalcOperationTestFixture, VerifyOperandInput)
{
	OperandDataType result = _testData.firstOperand;

	// Capture Stdout during the execution of the operation
	// to verify the prompt for additional operands is shown.
	testing::internal::CaptureStdout();

	WriteToStdin(_testData.secondOperandInput);
	_testData.operation.Execute(result);

	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(result, _testData.expectedValue);
	EXPECT_EQ(output, _testData.expectedStdout);
}

TYPED_TEST_P(CalcOperationTestFixture, VerifyOperationWithNegativeAndPositiveValues)
{
	OperandDataType result = _testData.positiveNum;
	testing::internal::CaptureStdout();

	WriteToStdin(_testData.negativeNum);
	_testData.operation.Execute(result);

	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(result, _testData.negativePosResult);
}

// Register the templated test fixture and data
REGISTER_TYPED_TEST_CASE_P(CalcOperationTestFixture, VerifyMenuText, VerifyOperandInput, VerifyOperationWithNegativeAndPositiveValues);

typedef testing::Types<AddCalcOperationData, SubtractCalcOperationData, MultiplyCalcOperationData,
	DivideCalcOperationData, InvalidCalcOperationData, QuitCalcOperationData, ClearMemCalcOperationData> TwoOpCalcOperationTypes;
INSTANTIATE_TYPED_TEST_CASE_P(CalcOperationTests, CalcOperationTestFixture, TwoOpCalcOperationTypes);
