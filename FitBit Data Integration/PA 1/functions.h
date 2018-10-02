/**********************************************************************************************
* Programmer: Trenton Fales                                                                   *
* Class: CptS 122 Spring 2018; Lab Section 9                                                  *
* Programming Assignment: 1                                                                   *
* Date: January 24, 2018                                                                      *
*                                                                                             *
*                                                                                             *
* Description: This program reads in a file called "FitbitData.csv" containing real Fitbit    *
*              data over a 24-hour period and computes the following:                         *
*                                                                                             *
*              1. Total calories burned                                                       *
*              2. Total distance traveled in miles                                            *
*              3. Total floors traveled                                                       *
*              4. Total steps taken                                                           *
*              5. Average heart rate                                                          *
*              6. Maximum steps taken in one minute                                           *
*                                                                                             *
*              This program then takes the calculations and writes them to an output file     *
*              called "Results.csv"                                                           *
**********************************************************************************************/

// Guard code
#ifndef FUNCTIONS_H

#include <stdio.h> // Import library
#include <string.h> // Import library
#include <stdlib.h> // Import library

typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;

FILE* open_infile(void);
FILE* open_outfile(void);
char* strtoke(char *str, const char *delim);
void readlines_and_parse(FILE *infile, FitbitData data[]);
double compute_total_cal(FitbitData data[]);
double compute_total_distance(FitbitData data[]);
int compute_total_floors(FitbitData data[]);
int compute_total_steps(FitbitData data[]);
double compute_avg_heartRate(FitbitData data[]);
int compute_max_steps(FitbitData data[]);
// void compute_longest_range_poor_sleep(FitbitData data[], char* pStart, char* pStop);
void write_stats_to_outfile(double total_cal, double total_dist, int total_floors, 
	int total_steps, double avg_heartRate, int max_steps, FILE *outfile);

#endif