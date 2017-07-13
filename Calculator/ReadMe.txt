
This ReadMe.txt is suppose to help understand the reasoning behind this particular implementation of a Calculator in C++.

This calculator is very abstracted. In industry I'd argue that this is probably too abstract for how simplistic of a calculator 
it is. I wrote this calculator to show my clean code abilities rather than a practical implementation of a simple calculator.

If you look through the code you will see a CalcOperation class, this class can take one operand to complete its operation.
I added another abstract class TwoOperandCalcOperation which takes two operands. I could just as easily add another abstraction
for operations that require more than two operands via Variable Arg Lists, but decided that was over engineering an already
robust calculator.

The goal of the CalcOperation class was to make the features of a calculator's operations extendable. To create a new CalcOperation,
simply create a new derived class, add an enumerated value to OperationTypes.h as well as add a switch case to OperationFactoryImpl.cpp
and you are done! It is also easy to implement a feature like a history of operations similar to Microsoft Windows calculator so a user
could see their last couple operations done because of this design.

My biggest gripe about testing C++ code is the inability to test the code without making modifications to the code base specifically for testing purposes.
I chose to use a macro called MOCKABLE which replaces itself with the keyword 'virtual' to allow particular methods to be mocked. This preprocessor
directive is replaced with nothing when compiled in any configuration other than DebugStaticLib thus making the code base change for testability.

By the time I finished the calculator I realized there was a better way to identify FPU exceptions by using _controlfp_s(), but I left it as is.