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

#include "QueueNode.h"

QueueNode::QueueNode(Data newData)
{
	this->pData = new Data(newData);
	this->pNext = NULL;
}

QueueNode::QueueNode(const QueueNode &newNode)
{
	
}

QueueNode::~QueueNode()
{

}

Data * QueueNode::getData() const
{
	return this->pData;
}

QueueNode * QueueNode::getNextPtr() const
{
	return this->pNext;
}

void QueueNode::setData(Data * const newData)
{
	this->pData = newData;
}

void QueueNode::setNextPtr(QueueNode * const newNextPtr)
{
	this->pNext = newNextPtr;
}