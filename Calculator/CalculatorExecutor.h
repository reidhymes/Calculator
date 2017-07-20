/*========================================================================
* CalculatorExecutor.h
*
*	Facilitates a CLI GUI and menu options for the Calculator class.
========================================================================*/
#pragma once

#include "Calculator.h"


using MenuOption = OperationType;

class CalculatorExecutor
{
public:
	CalculatorExecutor() = default;
	~CalculatorExecutor() = default;
	void Run();

private:
	bool isQuitMenuOptionSelected(const MenuOption& menuChoice);
	void DisplayMenuText();
	void DisplayWelcomeMessage();
	void GetMenuSelection(MenuOption & menuChoice);
	void ProcessMenu(MenuOption & menuChoice);

	Calculator _calc;
};