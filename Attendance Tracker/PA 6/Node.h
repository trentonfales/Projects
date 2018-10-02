#pragma once

#include <iostream>
#include <string>

#include "Stack.h"

using namespace std;

class Node
{
public:
	Node(int recordNumber = 0, int ID = 0,
		string name = nullptr, string email = nullptr, string units = nullptr,
		string major = nullptr, string level = nullptr); // constructor
	Node(const Node &copy); // copy constructor
	~Node(); // destructor

	int getRecordNumber() const; // getter
	int getID() const; // getter
	string getName() const; // getter
	string getEmail() const; // getter
	string getUnits() const; // getter
	string getMajor() const; // getter
	string getLevel() const; // getter
	int getNumAbsences() const; // getter
	Stack getDatesAbsent() const; // getter
	Node * getNextPtr() const; // getter

	void setRecordNumber(int const newRecordNumber); // setter
	void setID(int const newID); // setter
	void setName(string const newName); // setter
	void setEmail(string const newEmail); // setter
	void setUnits(string const newUnits); // setter
	void setMajor(string const newMajor); // setter
	void setLevel(string const newLevel); // setter
	void setNumAbsences(int const newNumAbsences); // setter
	void setDatesAbsent(Stack const newDateAbsent); // setter
	void setNextPtr(Node * const pNewNext);

private:
	int recordNumber;
	int ID;
	string name;
	string email;
	string units;
	string major;
	string level;
	int numAbsences;
	Stack datesAbsent[20];
	Node *mpNext;
};