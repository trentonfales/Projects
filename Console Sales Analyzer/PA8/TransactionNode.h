#pragma once

#include <iostream>
#include <string>

#include "Node.h"

using namespace std;

class TransactionNode : public Node
{
public:
	TransactionNode(string data = "", int units = 0) : Node(data)
	{
		this->mUnits = units;
	} // constructor
	~TransactionNode(); // destructor

	int getUnits(); // getter
	void setUnits(int newUnits); // setter

	void printData();

private:
	int mUnits;
};