#pragma once

#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	Node(string data = '\0'); // constructor
	virtual ~Node(); // destructor

	// getters
	string getData();
	Node *& getLeft();
	Node *& getRight();

	//setters
	void setData(string newData);
	void setLeftPointer(Node * pNewLeft);
	void setRightPointer(Node * pNewRight);

	virtual void printData() = 0;

protected:
	string mData;
	Node * mpLeft;
	Node * mpRight;
};