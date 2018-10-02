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
#include <cstdlib>
#include <ctime>
// The following libraries were taken from: http://www.cplusplus.com/forum/beginner/14954/
#include <conio.h>
#include <Windows.h>

#include "QueueNode.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Queue
{
public:
	Queue(); // constructor
	bool enqueue(Data &newData);
	Data dequeue();
	bool isEmpty();
	~Queue(); // destructor

private:
	QueueNode *pHead;
	QueueNode *pTail;
	void destroyQueue();
};