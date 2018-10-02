#include "Menu.h"

Menu::Menu()
{
	option = 0;
}

Menu::~Menu()
{

}

int Menu::getOption() const
{
	return option;
}

void Menu::setOption(const int newOption)
{
	option = newOption;
}

void Menu::displayMenu()
{
	cout << "1. Import Course List" << endl;
	cout << "2. Load Master List" << endl;
	cout << "3. Store Master List" << endl;
	cout << "4. Mark Absences" << endl;
	cout << "5. Edit Absences" << endl;
	cout << "6. Generate Report" << endl;
	cout << "7. Exit" << endl;
}

int Menu::determineOptionValidity()
{
	do
	{
		displayMenu();
		cout << "Option: ";
		cin >> option;
		cout << endl;
	} while ((option < 1) || (option > 7));
	return option;
}

int Menu::executeOption(int option)
{
	ListApp app;
	switch (option)
	{
	case 1:
		cout << "Importing course list..." << endl << endl;
		// Done during construction of ListApp app
		return 1;
	case 2:
		cout << "Loading master list..." << endl << endl;
		app.loadList();
		return 2;
	case 3:
		cout << "Storing master list..." << endl << endl;
		app.storeList();
		return 3;
	case 4:
		app.printList();
		return 4;
	case 5:
		// BONUS
		return 5;
	case 6:
		return 6;
	case 7:
		exit(option);
		break;
	}
}