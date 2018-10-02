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

#include "Data.h"

Data::Data()
{
	customerNumber = 0;
	serviceTime = 0;
	totalTime = 0;
}

Data::Data(Data &copy)
{
	customerNumber = copy.getCustomerNumber();
	serviceTime = copy.getServiceTime();
	totalTime = copy.getTotalTime();
}

Data::~Data()
{

}

int Data::getCustomerNumber() const
{
	return customerNumber;
}

int Data::getServiceTime() const
{
	return serviceTime;
}

int Data::getTotalTime() const
{
	return totalTime;
}

void Data::setCustomerNumber(int newCustomerNumber)
{
	if (newCustomerNumber > 0)
	{
		customerNumber = newCustomerNumber;
	}
	else
	{
		customerNumber = 0;
	}
}

void Data::setServiceTime(int newServiceTime)
{
	if (newServiceTime > 0)
	{
		serviceTime = newServiceTime;
	}
	else
	{
		serviceTime = 0;
	}
}

void Data::setTotalTime(int newTotalTime)
{
	if (newTotalTime > 0)
	{
		totalTime = newTotalTime;
	}
	else
	{
		totalTime = 0;
	}
}