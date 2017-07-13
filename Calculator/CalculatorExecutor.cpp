/*========================================================================
* CalculatorExecutor.cpp
*
*	Facilitates a CLI GUI and menu options for the Calculator class.
========================================================================*/
#include <iostream>

#include "CalculatorExecutor.h"
#include "OperationTypes.h"
#include "Util.h"

using std::cout;
using std::endl;


bool CalculatorExecutor::isQuitMenuOptionSelected(const MenuOption& menuChoice)
{
	return menuChoice == QUIT;
}

void CalculatorExecutor::DisplayMenuText()
{
	cout << "\nResult: " << _calc.GetResult() << endl;
	cout << "Select an option by typing the corresponding number and pressing Enter:\n";
	for (int i = 0; i < static_cast<int>(NUMBER_OF_OPERATION_TYPES); ++i)
		cout << i << ") " << _calc.GetOperationText(i) << '\n';

	cout << endl;
}

void CalculatorExecutor::DisplayWelcomeMessage()
{
	cout << "Welcome to the Command Line Interface Calculator (CLIC)" << endl;
}

void CalculatorExecutor::GetMenuSelection(MenuOption& menuChoice)
{
	menuChoice = INVALID_OPERATION;
	auto choice = static_cast<int>(menuChoice);
	ReadInput<int>(choice);
	menuChoice = static_cast<MenuOption>(choice);
}

void CalculatorExecutor::ProcessMenu(MenuOption& menuChoice)
{
	DisplayMenuText();
	GetMenuSelection(menuChoice);
	_calc.ProcessSelection(menuChoice);
}

void CalculatorExecutor::Run()
{	
	// Use a string to read in text in case someone wants to be a wise-guy and 
	// feed in more than one menu option into the stdin buffer at a time.
	MenuOption menuChoice;

	DisplayWelcomeMessage();

	do
	{
		ProcessMenu(menuChoice);
	} while( !isQuitMenuOptionSelected(menuChoice) );
}
