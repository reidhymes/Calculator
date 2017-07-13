/*========================================================================
* Util.h
*
*	Defines small helper functions and macros used throughout the
*   appplication.
========================================================================*/
#pragma once

#include <iostream>

using std::cin;


// Adds a virtual flag to mockable methods. When MOCKABLE_LIB is not defined the virtual 
// flag is removed. This causes the code base to differ during testing and release, but 
// I decided that was acceptable here. 
// NOTE: I did not get around to mocking out Calculator or CalculatorExecutor methods.
#ifdef MOCKABLE_LIB
#define MOCKABLE virtual
#else
#define MOCKABLE
#endif


// Safely reads in an input from stdin of type T and discards remaining characters in the buffer. 
// This ensures no additional characters remain in the input buffer even when invalid input is read.
template<class T>
inline void ReadInput(T& inputBuffer)
{
	cin >> inputBuffer;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}
