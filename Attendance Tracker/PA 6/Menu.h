#pragma once

#include <iostream>

#include "ListApp.h"
#include "List.h"
#include "Node.h"

using namespace std;

class Menu
{
public:
	Menu();
	~Menu();

	int getOption() const;

	void setOption(const int newOption);

	void displayMenu();
	int determineOptionValidity();
	int executeOption(int option);

private:
	int option;
};