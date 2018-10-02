/**********************************************************************************************
* Programmer: Trenton Fales                                                                   *
* Class: CptS 122 Spring 2018; Lab Section 9                                                  *
* Programming Assignment: 5                                                                   *
* Date: March 5, 2018                                                                         *
*                                                                                             *
* Description: This program simulates two lines using queues. One line will represent an      *
*              express lane while the other will represent a normal lne. Arrival times for    *
*              customers and service times are randomly generated. The simulation is ran for  *
*              a certain number of minutes that is inputted by the user.                      *
**********************************************************************************************/

#pragma once

#include <iostream>
#include <string>

#include "Data.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class QueueNode
{
public:
	QueueNode(Data newData); // constructor
	QueueNode(const QueueNode &newNode); // copy constructor
	~QueueNode(); // destructor

	Data * getData() const; // getter
	QueueNode * getNextPtr() const; // getter

	void setData(Data * const newData); // setter
	void setNextPtr(QueueNode * const newNextPtr); // setter
private:
	Data *pData;
	QueueNode *pNext;
};