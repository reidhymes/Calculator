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
	MOCKABLE bool isQuitMenuOptionSelected(const MenuOption& menuChoice);
	MOCKABLE void DisplayMenuText();
	MOCKABLE void DisplayWelcomeMessage();
	MOCKABLE void GetMenuSelection(MenuOption & menuChoice);
	MOCKABLE void ProcessMenu(MenuOption & menuChoice);

	Calculator _calc;
};