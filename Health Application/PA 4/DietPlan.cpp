#include "DietPlan.h"

DietPlan::DietPlan(const int &goalCal, const string &newName, const string &newDate)
{
	if (goalCal < 0)
	{
		this->mGoalCal = 0;
	}
	else
	{
		this->mGoalCal = goalCal;
	}
	
	this->mName = newName;
	this->mDate = newDate;
}

DietPlan::DietPlan(DietPlan &copy)
{
	this->mGoalCal = copy.mGoalCal;
	this->mName = copy.mName;
	this->mDate = copy.mDate;
}

DietPlan::~DietPlan()
{

}

DietPlan & DietPlan::operator= (const DietPlan &rhs)
{
	if (this != &rhs)
	{
		this->mGoalCal = rhs.mGoalCal;
		this->mName = rhs.mName;
		this->mDate = rhs.mDate;
	}
	return (*this);
}

int DietPlan::getGoalCal() const
{
	return mGoalCal;
}

string DietPlan::getName() const
{
	return mName;
}

string DietPlan::getDate() const
{
	return mDate;
}

void DietPlan::setGoalCal(const int &newGoalCal)
{
	if (newGoalCal > 0)
	{
		mGoalCal = newGoalCal;
	}
	else
	{
		mGoalCal = 0;
	}
}

void DietPlan::setName(const string &newName)
{
	mName = newName;
}

void DietPlan::setDate(const string &newDate)
{
	mDate = newDate;
}

void DietPlan::editGoal()
{
	cout << "Please enter a new calories goal: ";
	cin >> this->mGoalCal;
	cout << (*this) << endl;
}

ostream & operator<< (ostream &lhs, const DietPlan &rhs)
{
	lhs << rhs.getName() << endl << rhs.getGoalCal() << endl << rhs.getDate();
	return lhs;
}

fstream & operator<< (fstream & lhs, const DietPlan & rhs)
{
	((ofstream &)(lhs)) << rhs.getName() << endl << rhs.getGoalCal() << endl << rhs.getDate();
	return lhs;
}

fstream & operator >> (fstream &lhs, DietPlan &rhs)
{
	char line[100] = "";
	lhs.getline(line, 100);
	rhs.setName(line);

	int goalCal = 0;
	lhs.getline(line, 100);
	goalCal = atoi(line);
	rhs.setGoalCal(goalCal);

	lhs.getline(line, 100);
	rhs.setDate(line);

	return lhs;
}