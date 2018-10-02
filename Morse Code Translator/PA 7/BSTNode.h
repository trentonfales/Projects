#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BSTNode
{
public:
	BSTNode();
	BSTNode(char newCharacter, string newCodedCharacter);
	
	char getCharacter();
	string getCodedCharacter();
	BSTNode *& getLeft();
	BSTNode *& getRight();

	void setCharacter(char newCharacter);
	void setCodedCharacter(string newCodedCharacter);
	void setLeftPointer(BSTNode * pNewLeft);
	void setRightPointer(BSTNode * pNewRight);

private:
	char character;
	string codedCharacter;
	BSTNode *mpLeft;
	BSTNode *mpRight;
};