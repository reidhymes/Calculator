#pragma once

#include "StdinStreamTester.h"

template<class T>
class CalcOperationTestFixture : public StdinStreamTester
{
protected:
	std::istringstream _stdinStream;
	T _testData;
};