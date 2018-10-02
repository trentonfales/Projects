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

#include "Queue.h"

Queue::Queue()
{
	this->pHead = this->pTail = NULL;
}

bool Queue::enqueue(Data &newData)
{
	QueueNode *pMem = NULL;
	pMem = new QueueNode(newData);
	bool success = false;
	if (this->pHead == NULL)
	{
		this->pHead = this->pTail = pMem;
	}
	else
	{
		this->pTail->setNextPtr(pMem);
		this->pTail = pMem;
	}
	success = true;
	return success;
}

Data Queue::dequeue()
{
	Data * d1 = NULL;
	if (this->pHead == this->pTail)
	{
		d1 = this->pHead->getData();
		delete this->pHead;
		this->pHead = this->pTail = NULL;
	}
	else
	{
		QueueNode *pTemp = NULL;
		pTemp = this->pHead;
		d1 = this->pHead->getData();
		this->pHead = this->pHead->getNextPtr();
		delete pTemp;
	}
	return *d1;
}

Queue::~Queue()
{
	destroyQueue();
}

void Queue::destroyQueue()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

bool Queue::isEmpty()
{
	return (this->pHead == NULL);
}