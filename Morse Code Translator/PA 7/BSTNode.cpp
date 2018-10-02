#include "BSTNode.h"

BSTNode::BSTNode()
{
	this->character = '\0';
	this->codedCharacter = nullptr;
	this->mpLeft = nullptr;
	this->mpRight;
}

BSTNode::BSTNode(char newCharacter, string newCodedCharacter)
{
	this->character = newCharacter;
	this->codedCharacter = newCodedCharacter;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

char BSTNode::getCharacter()
{
	return this->character;
}

string BSTNode::getCodedCharacter()
{
	return this->codedCharacter;
}

BSTNode *& BSTNode::getLeft()
{
	return this->mpLeft;
}

BSTNode *& BSTNode::getRight()
{
	return this->mpRight;
}

void BSTNode::setCharacter(char newCharacter)
{
	this->character = newCharacter;
}

void BSTNode::setCodedCharacter(string newCodedCharacter)
{
	this->codedCharacter = newCodedCharacter;
}

void BSTNode::setLeftPointer(BSTNode * pNewLeft)
{
	this->mpLeft = pNewLeft;
}

void BSTNode::setRightPointer(BSTNode * pNewRight)
{
	this->mpRight = pNewRight;
}