#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "BSTNode.h"

using namespace std;

class BST
{
public:
	BST();
	~BST();

	void insert(char character, string codedCharacter);
	void print();
	string search(char character);

private:
	BSTNode *mpRoot;
	fstream mInputStream;

	void insert(BSTNode *& pTree, char character, string codedCharacter);
	void print(BSTNode *pTree);
	string search(BSTNode *pTree, char character);
};