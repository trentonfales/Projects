#include "FitnessAppWrapper.h"

FitnessAppWrapper::FitnessAppWrapper()
{

}

FitnessAppWrapper::~FitnessAppWrapper()
{

}

void FitnessAppWrapper::runApp()
{
	int option = 0;
	do
	{
		do
		{
			displayMenu();
			cin >> option;
		} while (option < 1 || option > 9);
		system("cls");

		switch (option)
		{
		case 1:
			loadWeeklyDietPlan();
			break;
		case 2: 
			loadWeeklyExercisePlan();
			break;
		case 3:
			storeWeeklyDietPlan();
			break;
		case 4:
			storeWeeklyExercisePlan();
			break;
		case 5:
			system("cls");
			displayWeeklyDietPlan();
			break;
		case 6:
			system("cls");
			displayWeeklyExercisePlan();
			break;
		case 7:
			editDietPlan();
			break;
		case 8:
			editExercisePlan();
			break;
		case 9:
			storeWeeklyDietPlan();
			storeWeeklyExercisePlan();
			break;
		}

	} while (option != 9);
}

void FitnessAppWrapper::displayMenu()
{
	cout << "1. Load weekly diet plan from file." << endl;
	cout << "2. Load weekly exercise plan from file." << endl;
	cout << "3. Store weekly diet plan to file." << endl;
	cout << "4. Store weekly exercise plan to file." << endl;
	cout << "5. Display weekly diet plan to screen." << endl;
	cout << "6. Display weekly exercise plan to screen." << endl;
	cout << "7. Edit daily diet plan." << endl;
	cout << "8. Edit daily exercise plan." << endl;
	cout << "9. Exit." << endl;
}

void FitnessAppWrapper::loadWeeklyDietPlan()
{
	mDietPlanStream.open("dietPlans.txt");
	loadWeeklyPlan(mDietPlanStream, mDietPlans);
	mDietPlanStream.close();
}
void FitnessAppWrapper::loadWeeklyExercisePlan()
{
	mExercisePlanStream.open("ExercisePlans.txt");
	loadWeeklyPlan(mExercisePlanStream, mExercisePlans);
	mExercisePlanStream.close();
}

void FitnessAppWrapper::storeWeeklyDietPlan()
{
	mDietPlanStream.open("dietPlans.txt");
	storeWeeklyPlan(mDietPlanStream, mDietPlans);
	mDietPlanStream.close();
}

void FitnessAppWrapper::storeWeeklyExercisePlan()
{
	mExercisePlanStream.open("exercisePlans.txt");
	storeWeeklyPlan(mExercisePlanStream, mExercisePlans);
	mExercisePlanStream.close();
}

void FitnessAppWrapper::displayWeeklyDietPlan()
{
	displayWeeklyPlan(mDietPlans);
}

void FitnessAppWrapper::displayWeeklyExercisePlan()
{
	displayWeeklyPlan(mExercisePlans);
}

bool FitnessAppWrapper::editDietPlan()
{
	system("cls");
	displayWeeklyDietPlan();
	cout << "Which plan would you like to edit? ";
	char planName[100] = "";
	cin.ignore();
	cin.getline(planName, 100);
	string stdPlanName = planName;

	bool success = false;
	for (int day = 0; day < 7; ++day)
	{
		if (stdPlanName == mDietPlans[day].getName())
		{
			success = true;
			mDietPlans[day].editGoal();
		}
	}

	return success;
}

bool FitnessAppWrapper::editExercisePlan()
{
	system("cls");
	displayWeeklyExercisePlan();
	cout << "Which plan would you like to edit? ";
	char planName[100] = "";
	cin.ignore();
	cin.getline(planName, 100);
	string stdPlanName = planName;

	bool success = false;
	for (int day = 0; day < 7; ++day)
	{
		if (stdPlanName == mExercisePlans[day].getName())
		{
			success = true;
			mExercisePlans[day].editGoal();
		}
	}

	return success;
}

void FitnessAppWrapper::loadDailyPlan(fstream &fileStream, DietPlan &plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadDailyPlan(fstream &fileStream, ExercisePlan &plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[])
{
	for (int day = 0; day < 7; ++day)
	{
		loadDailyPlan(fileStream, weeklyPlan[day]);
		char line[2];
		fileStream.getline(line, 2);
	}
}

void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[])
{
	for (int day = 0; day < 7; ++day)
	{
		loadDailyPlan(fileStream, weeklyPlan[day]);
		char line[2];
		fileStream.getline(line, 2);
	}
}

void FitnessAppWrapper::storeDailyPlan(fstream &fileStream, const DietPlan &plan)
{
	fileStream << plan << endl;
}

void FitnessAppWrapper::storeDailyPlan(fstream &fileStream, const ExercisePlan &plan)
{
	fileStream << plan << endl;
}

void FitnessAppWrapper::storeWeeklyPlan(fstream &fileStream, const DietPlan weeklyPlan[])
{
	for (int day = 0; day < 7; ++day)
	{
		storeDailyPlan(fileStream, weeklyPlan[day]);
		fileStream << endl;
	}
}

void FitnessAppWrapper::storeWeeklyPlan(fstream &fileStream, const ExercisePlan weeklyPlan[])
{
	for (int day = 0; day < 7; ++day)
	{
		storeDailyPlan(fileStream, weeklyPlan[day]);
		fileStream << endl;
	}
}

void FitnessAppWrapper::displayDailyPlan(const DietPlan &plan)
{
	cout << plan << endl;
}

void FitnessAppWrapper::displayDailyPlan(const ExercisePlan &plan)
{
	cout << plan << endl;
}

void FitnessAppWrapper::displayWeeklyPlan(const DietPlan weeklyPlan[])
{
	for (int day = 0; day < 7; ++day)
	{
		displayDailyPlan(weeklyPlan[day]);
		cout << endl;
	}
}

void FitnessAppWrapper::displayWeeklyPlan(const ExercisePlan weeklyPlan[])
{
	for (int day = 0; day < 7; ++day)
	{
		displayDailyPlan(weeklyPlan[day]);
		cout << endl;
	}
}