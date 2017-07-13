#pragma once
#include <cmath>
#include <string>

using std::string;


enum CalcErrorType : unsigned int
{
	NO_ERROR = 0,
	BOUNDARY_ERROR = 1,
	DIVIDE_BY_ZERO_ERROR = 2
};

inline string GetErrorMessage(CalcErrorType errValue)
{
	switch (errValue)
	{
	case NO_ERROR:
	default:
		return "";

	case BOUNDARY_ERROR:
		return "Boundary Error occurred during operation. To reset the value select Clear Memory.";

	case DIVIDE_BY_ZERO_ERROR:
		return "Divided By zero. To reset the value select Clear Memory.";
	}
}