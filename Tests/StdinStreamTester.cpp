#include "StdinStreamTester.h"

void StdinStreamTester::TearDown()
{
	_stdinStream.clear();
	_stdinStream.ignore(INT_MAX, '\n');
}
