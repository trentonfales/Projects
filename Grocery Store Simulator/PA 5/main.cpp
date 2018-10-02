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

int main(void)
{
	Queue normalLane, expressLane;
	int normalArrivalTime = 0, expressArrivalTime = 0, totalTime = 1, counter1 = 0, counter2 = 0, numMinutes = 0;
	int normalCustomerNumber = 0, expressCustomerNumber = 0, normalServiceTime = 0, expressServiceTime = 0, normalTotalTime = 0, expressTotalTime = 0,
		sumNormalServiceTime = 0, sumExpressServiceTime = 0;
	Data newData;

	srand((unsigned)time(0));

	cout << "Please enter the number of minutes you would like to run the simulation: ";
	cin >> numMinutes;
	cout << endl;

	normalServiceTime = rand() % 8 + 4; // Number between 3 and 8
	expressArrivalTime = rand() % 5 + 1; // Number between 1 and 5

	while (totalTime < numMinutes)
	{
		if (normalArrivalTime == 0)
		{
			++counter1;
			normalArrivalTime = rand() % 8 + 4;

			normalCustomerNumber = counter1;
			normalServiceTime = rand() % 8 + 4;
			normalTotalTime += normalServiceTime;
			newData.setCustomerNumber(normalCustomerNumber);
			newData.setServiceTime(normalServiceTime);
			newData.setTotalTime(normalTotalTime);
			normalLane.enqueue(newData);

			cout << "Normal Lane:" << endl;
			cout << "Customer #" << counter1 << endl;
			cout << "Arrival time: " << totalTime << " minutes" << endl;
			cout << "Time in line: " << normalServiceTime << " minutes" << endl;
			cout << "Total time for normal lane: " << normalTotalTime << " minutes" << endl << endl;
		}

		if (expressArrivalTime == 0)
		{
			++counter2;
			expressArrivalTime = rand() % 5 + 1;

			expressCustomerNumber = counter2;
			expressServiceTime = rand() % 5 + 1;
			expressTotalTime += expressServiceTime;
			newData.setCustomerNumber(expressCustomerNumber);
			newData.setServiceTime(expressServiceTime);
			newData.setTotalTime(expressTotalTime);
			expressLane.enqueue(newData);

			cout << "Express Lane:" << endl;
			cout << "Customer #" << counter2 << endl;
			cout << "Arrival time: " << totalTime << " minutes" << endl;
			cout << "Time in line: " << expressServiceTime << " minutes" << endl;
			cout << "Total time for express lane: " << expressTotalTime << " minutes" << endl << endl;
		}

		--normalArrivalTime;
		--expressArrivalTime;
		++totalTime;
		Sleep(500);
	}

	return 0;
}