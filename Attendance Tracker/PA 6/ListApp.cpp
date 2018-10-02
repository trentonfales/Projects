#include "ListApp.h"

ListApp::ListApp()
{
	mInputStream.open("classList.csv", ios::in);
	mOutputStream.open("master.txt", ios::out);
}

ListApp::~ListApp()
{
	if (mInputStream.is_open())
	{
		mInputStream.close();
	}
	if (mOutputStream.is_open())
	{
		mOutputStream.close();
	}
}

void ListApp::loadList()
{
	if (mInputStream.is_open())
	{
		mInputStream >> mList;
	}
}

void ListApp::storeList()
{
	if (mOutputStream.is_open())
	{
		mOutputStream << &mList;
	}
}

void ListApp::printList()
{
	mInputStream >> mList;
	mList.printName();
}

ifstream & operator >> (ifstream &input, List &list)
{
	char line[100] = "";
	int index = 0;
	input.getline(line, 100);

	while (index < 10)
	{
		input.getline(line, 100, ',');
		int recordNumber = atoi(line);
		input.getline(line, 100, ',');
		int ID = atoi(line);
		input.getline(line, 100, ',');
		string name = line;
		input.getline(line, 100, ',');
		string email = line;
		input.getline(line, 100, ',');
		string units = line;
		input.getline(line, 100, ',');
		string major = line;
		input.getline(line, 100);
		string level = line;
		list.insertAtFront(recordNumber, ID, name, email, units, major, level);
		++index;
	}
	return input;
}

// Angelina Paredes helped me with the following function
ofstream & operator << (ofstream &output, List &list)
{
	Node *pCur = list.getHeadPtr();
	while (pCur != nullptr)
	{
		output << pCur->getRecordNumber() << endl;
		output << pCur->getID() << endl;
		output << pCur->getName() << endl;
		output << pCur->getEmail() << endl;
		output << pCur->getUnits() << endl;
		output << pCur->getMajor() << endl;
		output << pCur->getLevel() << endl;
		pCur = pCur->getNextPtr();
	}
	return output;
}