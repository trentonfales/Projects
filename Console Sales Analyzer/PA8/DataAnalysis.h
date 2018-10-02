#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "BST.h"

using namespace std;

class DataAnalysis
{
public:
	void runAnalysis(); // runs the program

private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	void openFile(); // opens file
	void processFile(); // loops line by line until end of file, separates each line into
	                    // appropriate fields, places fields into appropriate tree, and
	void displayTrees(); // displays contents of both BSTs
	// writes to the screen the trends we see in our tree, must
	//     display type and number of units that are least purchased and sold,
	//     and most purchased and sold

};