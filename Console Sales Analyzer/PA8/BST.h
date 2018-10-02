#pragma once

#include <iostream>
#include <string>

#include "Node.h"
#include "TransactionNode.h"

using namespace std;

class BST
{
public:
	BST(); // constructor
	~BST(); // destructor

	Node *& getRoot(); // getter
	void setRoot(Node * pNewRoot); // setter

	void insert(string data, int units);
	void inOrderTraversal();
	TransactionNode & findSmallest();
	TransactionNode & findLargest();

private:
	Node * mpRoot;

	void insert(Node *& pTree, string data, int units);
	void inOrderTraversal(Node *pTree);
	void destroyTree(Node * pTree);
};