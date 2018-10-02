#include "ExercisePlan.h"

ExercisePlan::ExercisePlan(const int &goalSteps, const string &newName, const string &newDate)
{
	if (goalSteps < 0)
	{
		this->mGoalSteps = 0;
	}
	else
	{
		this->mGoalSteps = goalSteps;
	}

	this->mName = "";
	this->mDate = "";
}

ExercisePlan::ExercisePlan(ExercisePlan &copy)
{
	this->mGoalSteps = copy.mGoalSteps;
	this->mName = copy.mName;
	this->mDate = copy.mDate;
}

ExercisePlan::~ExercisePlan()
{

}

ExercisePlan & ExercisePlan::operator= (const ExercisePlan &rhs)
{
	if (this != &rhs)
	{
		this->mGoalSteps = rhs.mGoalSteps;
		this->mName = rhs.mName;
		this->mDate = rhs.mDate;
	}
	return (*this);
}

int ExercisePlan::getGoalSteps() const
{
	return mGoalSteps;
}

string ExercisePlan::getName() const
{
	return mName;
}

string ExercisePlan::getDate() const
{
	return mDate;
}

void ExercisePlan::setGoalSteps(int newGoalSteps)
{
	if (newGoalSteps > 0)
	{
		mGoalSteps = newGoalSteps;
	}
	else
	{
		mGoalSteps = 0;
	}
}

void ExercisePlan::setName(string newName)
{
	mName = newName;
}

void ExercisePlan::setDate(string newDate)
{
	mDate = newDate;
}

void ExercisePlan::editGoal()
{
	cout << "Please enter a new steps goal: ";
	cin >> this->mGoalSteps;
	cout << (*this) << endl;
}

ostream & operator<< (ostream &lhs, const ExercisePlan &rhs)
{
	lhs << rhs.getName() << endl << rhs.getGoalSteps() << endl << rhs.getDate();
	return lhs;
}

fstream & operator<< (fstream &lhs, const ExercisePlan &rhs)
{
	((ofstream &)(lhs)) << rhs.getName() << endl << rhs.getGoalSteps() << endl << rhs.getDate();
	return lhs;
}

fstream & operator >> (fstream &lhs, ExercisePlan &rhs)
{
	char line[100] = "";
	lhs.getline(line, 100);
	rhs.setName(line);

	int goalSteps = 0;
	lhs.getline(line, 100);
	goalSteps = atoi(line);
	rhs.setGoalSteps(goalSteps);

	lhs.getline(line, 100);
	rhs.setDate(line);

	return lhs;
}