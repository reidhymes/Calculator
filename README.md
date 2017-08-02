# Calculator
Calculator Project

This ReadMe is suppose to help understand the reasoning behind this particular implementation of a Calculator in C++.

This calculator is very abstracted. In industry I'd argue that this is probably too abstract for how simplistic of a calculator 
it is. I wrote this calculator to show my clean code abilities rather than a practical implementation of a simple calculator.

As one Senior software engineer put it, "This is the Cadillac of calculators."

The goal of the CalcOperation class was to make the features of a calculator's operations extendable. To create a new CalcOperation,
simply create a new derived class, add an enumerated value to OperationTypes.h as well as add a switch case to OperationFactoryImpl.cpp
and you are done! If you wanted to add an Invert(1/x) operation, or square root operation it would only take a minute. On top of that, with this code base you can easily create a scientific calculator by deriving a ScientificCalcOperation interface to differentiate scientific operations from normal calculator operations. It is also easy to implement a feature like a history of operations similar to Microsoft Windows calculator so a user could see their last couple operations done because of this design.

By the time I finished the calculator I realized there was a better way to identify floating point exceptions by using _controlfp_s(), but I left it as is.

Test Project

To compile this project you must change your Additional Library Directories to point to your build of Google Test.
To do this right click on this project and go to Properties -> Linker -> General -> Additional Library Directories.

Note: I targeted a VC2015 x86 bit version of the Google Test static library with the custom Build Configuration of DebugStaticLib
      If you would like to build without tests, use Debug or Release Build Configurations.