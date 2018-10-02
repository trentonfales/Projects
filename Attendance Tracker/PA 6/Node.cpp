#include "Node.h"

Node::Node(int recordNumber, int ID,
	string name, string email, string units,
	string major, string level)
{
	this->recordNumber = recordNumber;
	this->ID = ID;
	this->name = name;
	this->email = email;
	this->units = units;
	this->major = major;
	this->level = level;
	this->mpNext = nullptr;
}

Node::Node(const Node &copy)
{
	this->recordNumber = copy.recordNumber;
	this->ID = copy.ID;
	this->name = copy.name;
	this->email = copy.email;
	this->units = copy.units;
	this->major = copy.major;
	this->level = copy.level;
	this->mpNext = copy.mpNext;
}

Node::~Node()
{
	
}

int Node::getRecordNumber() const
{
	return this->recordNumber;
}

int Node::getID() const
{
	return this->ID;
}

string Node::getName() const
{
	return this->name;
}

string Node::getEmail() const
{
	return this->email;
}

string Node::getUnits() const
{
	return this->units;
}

string Node::getMajor() const
{
	return this->major;
}

string Node::getLevel() const
{
	return this->level;
}

int Node::getNumAbsences() const
{
	return this->numAbsences;
}

Stack Node::getDatesAbsent() const
{
	return this->datesAbsent[numAbsences];
}

Node * Node::getNextPtr() const
{
	return mpNext;
}

void Node::setRecordNumber(int const newRecordNumber)
{
	this->recordNumber = newRecordNumber;
}

void Node::setID(int const newID)
{
	this->ID = newID;
}

void Node::setName(string const newName)
{
	this->name = newName;
}

void Node::setEmail(string const newEmail)
{
	this->email = newEmail;
}

void Node::setUnits(string const newUnits)
{
	this->units = newUnits;
}

void Node::setMajor(string const newMajor)
{
	this->major = newMajor;
}

void Node::setLevel(string const newLevel)
{
	this->level = newLevel;
}

void Node::setNumAbsences(int const newNumAbsences)
{
	this->numAbsences = newNumAbsences;
}

void Node::setDatesAbsent(Stack const newDateAbsent)
{
	this->datesAbsent[numAbsences] = newDateAbsent;
}

void Node::setNextPtr(Node * const pNewNext)
{
	this->mpNext = pNewNext;
}