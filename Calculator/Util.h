/*========================================================================
* Util.h
*
*	Defines small helper functions and macros used throughout the
*   appplication.
========================================================================*/
#pragma once

#include <iostream>

using std::cin;


// Safely reads in an input from stdin of type T and discards remaining characters in the buffer. 
// This ensures no additional characters remain in the input buffer even when invalid input is read.
template<class T>
inline void ReadInput(T& inputBuffer)
{
	cin >> inputBuffer;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}
