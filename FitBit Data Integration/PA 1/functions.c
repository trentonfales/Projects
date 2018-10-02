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

// This function opens the file "FitbitData.csv" for reading mode
FILE* open_infile(void)
{
	FILE* infile = NULL;
	printf("Opening file...\n");
	infile = fopen("FitbitData.csv", "r");
	if (infile != NULL)
	{
		printf("File was opened successfully.\n\n");
	}
	return infile;
}

// This function creates and opens an output file titled "Results.csv"
FILE* open_outfile(void)
{
	FILE* outfile = NULL;
	outfile = fopen("Results.csv", "w");
	return outfile;
}

/**************************************************************************************************
THE FOLLOWING FUNCTION WAS TAKEN FROM
"https://stackoverflow.com/questions/42315585/split-string-into-tokens-in-c-when-there-are-2-delimiters-in-a-row" 
***************************************************************************************************/
char* strtoke(char *str, const char *delim)
{
	static char *start = NULL;
	char *token = NULL;
	if (str) start = str;
	if (!start) return NULL;
	token = start;
	start = strpbrk(start, delim);
	if (start) *start++ = '\0';
	return token;
}

// This function will read in each line from the file, parse that line to
// organize and separate the different fields, and then place those segments
// into their corresponding fields inside of the array of structs called "data"
// with the correct types
void readlines_and_parse(FILE *infile, FitbitData data[])
{
	char line[100] = "", *pTokens[7] = { NULL };
	int index = 0, sleep = 0;
	double calories = 0.0, distance = 0.0;
	unsigned int floors, heartRate, steps;
	fgets(line, 100, infile);
	while (index < 1440)
	{
		// Read each line from the file
		fgets(line, 100, infile);
		// Parse each line
		pTokens[0] = strtoke(line, ",");
		pTokens[1] = strtoke(NULL, ",");
		pTokens[2] = strtoke(NULL, ",");
		pTokens[3] = strtoke(NULL, ",");
		pTokens[4] = strtoke(NULL, ",");
		pTokens[5] = strtoke(NULL, ",");
		pTokens[6] = strtoke(NULL, ",");
		// Store appropriate data to FitbitData array
		strcpy(data[index].minute, pTokens[0]);
		calories = atof(pTokens[1]);
		data[index].calories = calories;
		distance = atof(pTokens[2]);
		data[index].distance = distance;
		floors = atoi(pTokens[3]);
		data[index].floors = floors;
		heartRate = atoi(pTokens[4]);
		data[index].heartRate = heartRate;
		steps = atoi(pTokens[5]);
		data[index].steps = steps;
		sleep = atoi(pTokens[6]);
		data[index].sleepLevel = sleep;
		++index;
	}
}

// This function will compute the total number of calories burned in the 24-hour period
double compute_total_cal(FitbitData data[])
{
	double total = 0.0;
	int index = 0;

	while (index < 1440) // iterate through data array of structs
	{
		total += data[index].calories;
		++index;
	}
	return total;
}

// This function will compute the total distance traveled in miles in the 24-hour period
double compute_total_distance(FitbitData data[])
{
	double total = 0.0;
	int index = 0;

	while (index < 1440) // iterate through data array of structs
	{
		total += data[index].distance;
		++index;
	}
	return total;
}

// This function will compute the total number of floors traveled in the 24-hour period
int compute_total_floors(FitbitData data[])
{
	int total = 0, index = 0;

	while (index < 1440) // iterate through data array of structs
	{
		total += data[index].floors;
		++index;
	}
	return total;
}

// This function will compute the total number of steps taken in the 24-hour period
int compute_total_steps(FitbitData data[])
{
	int total = 0, index = 0;

	while (index < 1440) // iterate through data array of structs
	{
		total += data[index].steps;
		++index;
	}
	return total;
}

// This function will compute the average heart rate in the 24-hour period
double compute_avg_heartRate(FitbitData data[])
{
	double total = 0, avg = 0;
	int index = 0, count = 0;

	while (index < 1440) // iterate through data array of structs
	{
		total += data[index].heartRate;
		++index;
		if (data[index].heartRate != NULL) // heart rate field is not empty
		{
			++count; // increase count used to compute average
		}
	}
	avg = total / count;
	return avg;
}

// This function will compute the max number of steps in a single minute taken
// over the 24-hour period
int compute_max_steps(FitbitData data[])
{
	int index = 438, max = data[index].steps;

	while (index < 1439) // iterate through data array of structs
	{
		if (data[index + 1].steps > max)
		{
			max = data[index].steps;
		}
		++index;
	}
	return max;
}

//void compute_longest_range_poor_sleep(FitbitData data[], char pStart[], char pStop[])
//{
//	int index = 0, length = 0, counter = 0;
//	while (index < 1440)
//	{
//		if (data[index].sleepLevel > 1 && length == 0) // start of poor sleep
//		{
//			++length;
//			counter = index;
//			pStart = data[index].minute;
//			while (data[counter].sleepLevel > 1 && length != 0) // continued poor sleep
//			{
//				++length;
//				++counter;
//				pStop = data[counter].minute;
//			}
//		}
//		++index;
//	}
//}

// This function will write the appropriate statistics to the outfile called "Results.txt"
void write_stats_to_outfile(double total_cal, double total_dist, int total_floors, 
	int total_steps, double avg_heartRate, int max_steps, FILE *outfile)
{
	fprintf(outfile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	fprintf(outfile, "%lf,%lf,%d,%d,%lf,%d", total_cal, total_dist, total_floors, total_steps, avg_heartRate, max_steps);
}