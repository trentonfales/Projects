#pragma once

#include "DietPlan.h"
#include "ExercisePlan.h"

using namespace std;

class FitnessAppWrapper
{
public:
	FitnessAppWrapper(); // constructor
	~FitnessAppWrapper(); // destructor

	void runApp();
	void displayMenu();

	void loadWeeklyDietPlan();
	void loadWeeklyExercisePlan();
	void storeWeeklyDietPlan();
	void storeWeeklyExercisePlan();
	void displayWeeklyDietPlan();
	void displayWeeklyExercisePlan();
	bool editDietPlan();
	bool editExercisePlan();

private:
	DietPlan mDietPlans[7];
	ExercisePlan mExercisePlans[7];
	fstream mDietPlanStream;
	fstream mExercisePlanStream;

	void loadDailyPlan(fstream &fileStream, DietPlan &plan);
	void loadDailyPlan(fstream &fileStream, ExercisePlan &plan);
	void loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
	void loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]);
	void storeDailyPlan(fstream &fileStream, const DietPlan &plan);
	void storeDailyPlan(fstream &fileStream, const ExercisePlan &plan);
	void storeWeeklyPlan(fstream &fileStream, const DietPlan weeklyPlan[]);
	void storeWeeklyPlan(fstream &fileStream, const ExercisePlan weeklyPlan[]);
	void displayDailyPlan(const DietPlan &plan);
	void displayDailyPlan(const ExercisePlan &plan);
	void displayWeeklyPlan(const DietPlan weeklyPlan[]);
	void displayWeeklyPlan(const ExercisePlan weeklyPlan[]);
};