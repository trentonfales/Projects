#pragma once

#include <iostream>
#include <ctime>

#include "Node.h"

using namespace std;

// The following was adapted from Andy's lecture code

class List
{
public:
	List();
	List(const List &copyList);
	~List();

	Node * getHeadPtr() const; // getter

	void setHeadPtr(Node * const pNewHead); // setter

	bool insertAtFront(int recordNumber, int ID,
		string name, string email, string units,
		string major, string level);
	bool isEmpty();
	void printName();

private:
	Node *mpHead;

	Node * makeNode(int recordNumber, int ID,
		string name, string email, string units,
		string major, string level);
	void destroyList();
	void destroyListHelper(Node * const pMem);
};