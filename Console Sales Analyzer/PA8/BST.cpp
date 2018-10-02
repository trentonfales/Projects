#include "BST.h"

BST::BST()
{
	mpRoot = nullptr;
}

BST::~BST()
{
	destroyTree(this->mpRoot);
}

void BST::destroyTree(Node * pTree)
{
	if (pTree != nullptr)
	{
		destroyTree(pTree->getLeft());
		destroyTree(pTree->getRight());
		delete pTree;
	}
}

Node *& BST::getRoot()
{
	return this->mpRoot;
}

void BST::setRoot(Node * pNewRoot)
{
	this->mpRoot = pNewRoot;
}

void BST::insert(string data, int units)
{
	insert(this->mpRoot, data, units);
}

void BST::insert(Node *& pTree, string data, int units)
{
	if (pTree == nullptr)
	{
		Node * pMem = new TransactionNode(data, units);
		pTree = pMem;
	}
	else if (units < (dynamic_cast<TransactionNode*>(pTree))->getUnits())
	{
		insert(pTree->getLeft(), data, units);
	}
	else
	{
		insert(pTree->getRight(), data, units);
	}
}

void BST::inOrderTraversal()
{
	inOrderTraversal(this->mpRoot);
}

void BST::inOrderTraversal(Node *pTree)
{
	if (pTree != nullptr)
	{
		inOrderTraversal(pTree->getLeft());
		pTree->printData();
		inOrderTraversal(pTree->getRight());
	}
}

TransactionNode & BST::findSmallest()
{
	Node* min = mpRoot;
	while (min->getLeft() != nullptr)
	{
		min = min->getLeft();
	}
	return (TransactionNode &)*min;
}

TransactionNode & BST::findLargest()
{
	Node* max = mpRoot;
	while (max->getRight() != nullptr)
	{
		max = max->getRight();
	}
	return (TransactionNode &)*max;
}