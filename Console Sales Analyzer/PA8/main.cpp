/**********************************************************************************************
* Programmer: Trenton Fales                                                                   *
* Class: CptS 122 Spring 2018; Lab Section 9                                                  *
* Programming Assignment: 8                                                                   *
* Date: April 13th, 2018                                                                      *
*                                                                                             *
*                                                                                             *
* Description: This program implements a system for detecting trends in consumer products     *
*              over a 48 hour period using two separate BSTs. One that represents items       *
*              "purchased" which indicates that a certain retail store bought units of the    *
*              product from a supplier, and one that represents "sold" which indicates        *
*              that a certain retail store sold that many units of a product. The information *
*              came from the file "data.csv" which was imported into the program and          *
*              processed. The program will output the two separate BSTs in order, followed by *
*              the product type and number of units that was purchased the least and most, as *
*              well as the product type and number of units that were sold the least and most.*
**********************************************************************************************/

#include "DataAnalysis.h"

int main(void)
{
	DataAnalysis obj;
	obj.runAnalysis();

	return 0;
}