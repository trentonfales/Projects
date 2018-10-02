#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ExercisePlan
{
public:
	ExercisePlan(const int &goalSteps = 0,
		const string &newName = "",
		const string &newDate = ""); // constructor
	ExercisePlan(ExercisePlan &copy); // copy constructor
	~ExercisePlan(); // destructor

	ExercisePlan & operator= (const ExercisePlan &rhs);

	int getGoalSteps() const; // getter
	string getName() const; // getter
	string getDate() const; // getter

	void setGoalSteps(int newGoalSteps); // setter
	void setName(string newName); // setter
	void setDate(string newDate); // setter

	void editGoal();

private:
	int mGoalSteps;
	string mName;
	string mDate;
};

ostream & operator<< (ostream &lhs, const ExercisePlan &rhs);
fstream & operator<< (fstream &lhs, const ExercisePlan &rhs);
fstream & operator >> (fstream &lhs, ExercisePlan &rhs);