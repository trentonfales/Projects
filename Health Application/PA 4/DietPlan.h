#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class DietPlan
{
public:
	DietPlan(const int &goalCal = 0,
		const string &newName = "",
		const string &newDate = ""); // constructor
	DietPlan(DietPlan &copy); // copy constructor
	~DietPlan(); // destructor

	DietPlan & operator= (const DietPlan &rhs);

	int getGoalCal() const; // getter
	string getName() const; // getter
	string getDate() const; // getter

	void setGoalCal(const int &newGoalCal); // setter
	void setName(const string &newName); // setter
	void setDate(const string &newDate); // setter

	void editGoal();

private:
	int mGoalCal;
	string mName;
	string mDate;
};

ostream & operator<< (ostream &lhs, const DietPlan &rhs);
fstream & operator<< (fstream &lhs, const DietPlan &rhs);
fstream & operator >> (fstream &lhs, DietPlan &rhs);