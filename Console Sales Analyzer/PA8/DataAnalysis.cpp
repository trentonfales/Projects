#include "DataAnalysis.h"

void DataAnalysis::openFile()
{
	mCsvStream.open("data.csv", ios::in);
}

void DataAnalysis::processFile()
{
	char line[100] = "";
	int units = 0;
	string type = "";
	string transaction = "";

	mCsvStream.getline(line, 100);

	while (!mCsvStream.eof())
	{
		mCsvStream.getline(line, 100, ',');
		units = stoi(line);
		mCsvStream.getline(line, 100, ',');
		type = line;
		mCsvStream.getline(line, 100);
		transaction = line;

		if (transaction == "Purchased")
		{
			mTreePurchased.insert(type, units);
		}
		else
		{
			mTreeSold.insert(type, units);
		}
	}
}

void DataAnalysis::displayTrees()
{
	cout << "Purchased BST:" << endl;
	mTreePurchased.inOrderTraversal();

	cout << endl;

	cout << "Sold BST:" << endl;
	mTreeSold.inOrderTraversal();

	cout << endl;
}

void DataAnalysis::runAnalysis()
{
	openFile();
	processFile();
	displayTrees();

	cout << "Product that was purchased the least:" << endl;
	TransactionNode t1 = mTreePurchased.findSmallest();
	cout << "Type: " << t1.getData() << ", Units: " << t1.getUnits() << endl << endl;

	cout << "Product that was purchased the most:" << endl;
	TransactionNode t2 = mTreePurchased.findLargest();
	cout << "Type: " << t2.getData() << ", Units: " << t2.getUnits() << endl << endl;

	cout << "Product that was sold the least:" << endl;
	TransactionNode t3 = mTreeSold.findSmallest();
	cout << "Type: " << t3.getData() << ", Units: " << t3.getUnits() << endl << endl;

	cout << "Product that was sold the most:" << endl;
	TransactionNode t4 = mTreeSold.findLargest();
	cout << "Type: " << t4.getData() << ", Units: " << t4.getUnits() << endl << endl;

	mCsvStream.close();
}