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

#include "functions.h" // Import header file

int main(void)
{
	FitbitData data[1440]; // Size 1440 array of structs to store data from file
	FILE* infile = NULL; // Store file "FitbitData.csv" for mode read
	FILE* outfile = NULL; // Store file "Results.csv" for mode write
	double total_cal = 0, total_dist = 0, avg_heartRate = 0;
	int total_floors = 0, total_steps = 0, max_steps = 0;
	char pStart[9] = { NULL }, pStop[9] = { NULL };

	infile = open_infile(); // Open "FitbitData.csv" file for reading
	outfile = open_outfile(); // Open "Results.csv" file for writing
	readlines_and_parse(infile, data); // Process file
	total_cal = compute_total_cal(data); // Compute total number of calories burnt
	printf("Total calories: %lf\n", total_cal); // Display total calories burnt to user
	total_dist = compute_total_distance(data); // Compute total distance covered
	printf("Total distance: %lf\n", total_dist); // Display total distance covered to user
	total_floors = compute_total_floors(data); // Compute number of floors walked
	printf("Total floors: %d\n", total_floors); // Display number of floors walked to user
	total_steps = compute_total_steps(data); // Compute total number of steps taken
	printf("Total steps: %d\n", total_steps); // Display total number of steps taken to user
	avg_heartRate = compute_avg_heartRate(data); // Compute average heart rate 
	printf("Average heart rate: %lf\n", avg_heartRate); // Display average heart rate to user
	max_steps = compute_max_steps(data); // Compute maximum number of steps taken in one minute
	printf("Maximum steps in one minute: %d\n", max_steps); // Display maximum number of steps to user
	/*compute_longest_range_poor_sleep(data, pStart, pStop);
	printf("Start of poor sleep: %s, End of poor sleep: %s\n", pStart, pStop);*/
	printf("\nWriting stats to \"Results.csv\"...\n"); // Notify user that stats are being written to "Results.csv"
	write_stats_to_outfile(total_cal, total_dist, total_floors, total_steps, avg_heartRate, max_steps, outfile); // Write stats to "Results.csv"

	fclose(infile); // Close "FitbitData.csv"
	fclose(outfile); // Close "Results.csv"

	printf("Closing files.\n\n"); // Notify user that the files have been closed

	return 0;
}