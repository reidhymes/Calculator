#pragma once

#include <sstream>
#include <string>

#include "gtest\gtest.h"

using std::stringstream;
using std::string;


class StdinStreamTester : public testing::Test
{
protected:
	template<class T>
	void WriteToStdin(const T data);

	void TearDown() override;

	std::istringstream _stdinStream;
};


template<class T>
void StdinStreamTester::WriteToStdin(const T data)
{
	stringstream s;
	s << data;
	_stdinStream.str(s.str());
	std::cin.rdbuf(_stdinStream.rdbuf());
}