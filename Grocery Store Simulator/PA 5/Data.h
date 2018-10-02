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

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Data
{
public:
	Data(); // constructor
	Data(Data &copy); // copy constructor
	~Data(); // destructor

	int getCustomerNumber() const; // getter
	int getServiceTime() const; // getter
	int getTotalTime() const; // getter

	void setCustomerNumber(int newCustomerNumber); // setter
	void setServiceTime(int newServiceTime); // setter
	void setTotalTime(int newTotalTime); // setter
private:
	int customerNumber;
	int serviceTime;
	int totalTime;
};