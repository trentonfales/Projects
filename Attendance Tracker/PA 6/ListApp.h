#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Node.h"
#include "List.h"

using namespace std;

// The following class was adapted from Andy's lecture code

class ListApp
{
public:
	ListApp();
	~ListApp();

	void loadList();
	void storeList();
	void printList();

private:
	ifstream mInputStream;
	ofstream mOutputStream;
	List mList;
};

ifstream & operator >> (ifstream &input, List &rhs);
ofstream & operator << (ofstream &output, List &list);