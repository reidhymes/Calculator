#include <stdlib.h>
#include <gtest/gtest.h>


void DisplayFinishPromptAndPause();

int main(int ac, char* av[])
{
	testing::InitGoogleTest(&ac, av);
	auto exit_val = RUN_ALL_TESTS();

	DisplayFinishPromptAndPause();

	return exit_val;
}

void DisplayFinishPromptAndPause()
{
	system("pause");
}