#include "List.h"

// The following code was adapted from Andy's lecture code

List::List()
{
	mpHead = nullptr;
}

List::List(const List &copyList)
{
	Node *pTemp = NULL;
	Node *nCopy = NULL;
	Node *pCur = NULL;
	this->mpHead = new Node;
	if (copyList.getHeadPtr() != NULL)
	{
		this->mpHead->setRecordNumber(copyList.getHeadPtr()->getRecordNumber());
		this->mpHead->setID(copyList.getHeadPtr()->getID());
		this->mpHead->setName(copyList.getHeadPtr()->getName());
		this->mpHead->setEmail(copyList.getHeadPtr()->getEmail());
		this->mpHead->setUnits(copyList.getHeadPtr()->getUnits());
		this->mpHead->setMajor(copyList.getHeadPtr()->getMajor());
		this->mpHead->setLevel(copyList.getHeadPtr()->getLevel());
		pCur = this->mpHead;
		nCopy = copyList.getHeadPtr()->getNextPtr();

		while (nCopy != NULL)
		{
			pTemp = new Node;
			pTemp->setRecordNumber(nCopy->getRecordNumber());
			pTemp->setID(nCopy->getID());
			pTemp->setName(nCopy->getName());
			pTemp->setEmail(nCopy->getEmail());
			pTemp->setUnits(nCopy->getUnits());
			pTemp->setMajor(nCopy->getMajor());
			pTemp->setLevel(nCopy->getLevel());
			pCur->setNextPtr(pTemp);
			pCur = pTemp;
			nCopy = nCopy->getNextPtr();
		}
	}
}

List::~List()
{
	destroyList();
}

Node * List::getHeadPtr() const
{
	return mpHead;
}

void List::setHeadPtr(Node * const pNewHead)
{
	mpHead = pNewHead;
}

bool List::insertAtFront(int recordNumber, int ID,
	string name, string email, string units,
	string major, string level)
{
	Node *pMem = makeNode(recordNumber, ID,
		name, email, units, major, level);
	bool success = false;

	if (pMem != nullptr)
	{
		success = true;
		pMem->setNextPtr(mpHead);
		mpHead = pMem;
	}
	return success;
}

bool List::isEmpty()
{
	return (mpHead == nullptr);
}

Node * List::makeNode(int recordNumber, int ID, 
	string name, string email, string units,
	string major, string level) 
{
	Node *pMem = new Node(recordNumber, ID, name,
		email, units, major, level);
	return pMem;
}

void List::printName()
{
	Node *pCur = mpHead;
	string absent;

	// To get date:
	time_t t = time(0);
	struct tm * now = localtime(&t);
	string date;
	date = (now->tm_year + 1990) << '-' << (now->tm_mon + 1) << '-' << (now->tm_mday);
	Stack obj;
	obj.push(date);

	while (pCur != nullptr)
	{
		cout << "Name: " << pCur->getName() << endl;
		cout << "Was this student absent today? Please enter 'Yes' or 'No': " << endl;
		cin >> absent;
		/*if (absent == "Yes" || absent == "yes")
		{
			pCur->setNumAbsences(pCur->getNumAbsences() + 1);
			pCur->setDatesAbsent(obj);
		}*/
		pCur = pCur->getNextPtr();
	}
}

void List::destroyListHelper(Node * const pMem)
{
	if (pMem != nullptr)
	{
		destroyListHelper(pMem->getNextPtr());
		delete pMem;
	}
}

void List::destroyList()
{
	destroyListHelper(mpHead);
}