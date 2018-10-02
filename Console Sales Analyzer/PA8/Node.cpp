#include "Node.h"

Node::Node(string data)
{
	this->mData = data;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

Node::~Node()
{

}

string Node::getData()
{
	return this->mData;
}

Node *& Node::getLeft()
{
	return this->mpLeft;
}

Node *& Node::getRight()
{
	return this->mpRight;
}

void Node::setData(string newData)
{
	this->mData = newData;
}

void Node::setLeftPointer(Node * pNewLeft)
{
	this->mpLeft = pNewLeft;
}

void Node::setRightPointer(Node * pNewRight)
{
	this->mpRight = pNewRight;
}

void Node::printData()
{
	cout << getData() << " ";
}