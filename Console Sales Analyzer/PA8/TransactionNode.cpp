#include "TransactionNode.h"

TransactionNode::~TransactionNode()
{

}

int TransactionNode::getUnits()
{
	return this->mUnits;
}

void TransactionNode::setUnits(int newUnits)
{
	this->mUnits = newUnits;
}

void TransactionNode::printData()
{
	cout << getData() << ": " << getUnits() << " units" << endl;
}

