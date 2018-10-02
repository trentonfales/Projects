#include "Menu.h"

int main(void)
{
	Menu menu;
	int option = 0;

	while (option != 7)
	{
		option = menu.determineOptionValidity();
		menu.executeOption(option);
	}

	return 0;
}