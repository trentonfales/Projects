/**********************************************************************************************
* Programmer: Trenton Fales                                                                   *
* Class: CptS 121 Fall 2017; Lab Section 5                                                    *
* Programming Assignment: 3                                                                   *
* Date: September 22, 2017                                                                    *
*                                                                                             *
*                                                                                             *
* Description: This program processes numbers, corresponding to student records read in       *
*              from a file, and writes the required results to an output file.                *
*                                                                                             *
*              The student records consist of Student ID numbers, GPA's, class standing       *
*              (freshman-senior) corresponding to values (1-4), and student's age. This       *
*              program specifically computes the mean values for the student's GPA, class     *
*              standing and age, and writes those values to the output file. This program     *
*              also computes the minimum, maximum, and standard deviation of the GPA's,       *
*              and writes those values to the output file as well.                            *
**********************************************************************************************/

#include "functions.h"     // Import header file

/*
* Function: read_double(FILE *infile)
* Date: September 22, 2017
* Date Last Modified: September 22, 2017
* Description: Reads a double in from a file and returns the value
* Input Parameters: File
* Returns: A double read in from the file
* Preconditions: The file must be opened.
* Postconditions: The double value is returned.
*/

double read_double(FILE *infile)
{
	double number = 0.0;
	fscanf(infile, "%lf", &number);
	return number;
}

/*
* Function: read_integer(FILE *infile)
* Date: September 22, 2017
* Date Last Modified: September 22, 2017
* Description: Reads an integer in from a file and returns the value
* Input Parameters: File
* Returns: An integer read in from the file
* Preconditions: The file must be opened.
* Postconditions: The integer value is returned.
*/

int read_integer(FILE *infile)
{
	int number = 0;
	fscanf(infile, "%d", &number);
	return number;
}

/*
* Function: calculate_sum(double num1, double num2, double num3, double num4, double num5)
* Date: September 22, 2017
* Date Last Modified: September 22, 2017
* Description: Calculates the sum of 5 double values
* Input Parameters: 5 double values
* Returns: The sum of the values
* Preconditions: 5 double values need to be inputted.
* Postconditions: The sum is returned.
*/

double calculate_sum(double num1, double num2, double num3, double num4, double num5)
{
	double sum = 0.0;
	sum = num1 + num2 + num3 + num4 + num5;
	return sum;
}

/*
* Function: calculate_mean(double sum, int number)
* Date: September 22, 2017
* Date Last Modified: September 22, 2017
* Description: Calculates the mean of a sum of values
* Input Parameters: A sum of values, the number of values
* Returns: The mean of the values
* Preconditions: A sum of values must be calculated, the number of values must be known.
* Postconditions: The mean is returned.
*/

double calculate_mean(double sum, int number)
{
	double mean = 0.0;

	if (number == 0)
	{
		return -1.0;
	}

	else
	{
		mean = sum / number;
		return mean;
	}
}

/*
* Function: calculate_deviation(double number, double mean)
* Date: September 22, 2017
* Date Last Modified: September 22, 2017
* Description: Calculates the deviation of values from the mean
* Input Parameters: A value in a mean of values, the mean of values
* Returns: The deviation from the mean
* Preconditions: A mean must be calculated, a value within that mean must be known.
* Postconditions: The deviation is returned.
*/

double calculate_deviation(double number, double mean)
{
	double deviation = 0.0;
	deviation = number - mean;
	return deviation;
}

/*
* Function: calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
* Date: September 22, 2017
* Date Last Modified: September 22, 2017
* Description: Calculates the variance of deviations
* Input Parameters: 5 deviation values as doubles, an integer that corresponds to the number of deviations
* Returns: The variance
* Preconditions: The deviations must be calculated, the number of deviations must be known.
* Postconditions: The variance is returned.
*/

double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
{
	double variance = 0.0;
	variance = ((deviation1 * deviation1) + (deviation2 * deviation2)
		+ (deviation3 * deviation3) + (deviation4 * deviation4)
		+ (deviation5 * deviation5)) / number;
	return variance;
}

/*
* Function: calculate_standard_deviation(double variance)
* Date: September 22, 2017
* Date Last Modified: September 22, 2017
* Description: Calculates the standard deviation
* Input Parameters: Variance
* Returns: The standard deviation
* Preconditions: The variance must be known.
* Postconditions: The standard deviation is returned.
*/

double calculate_standard_deviation(double variance)
{
	double standard_deviation = 0.0;
	standard_deviation = sqrt(variance);
	return standard_deviation;
}

/*
* Function: find_max(double num1, double num2, double num3, double num4, double num5)
* Date: September 22, 2017
* Date Last Modified: September 22, 2017
* Description: Determines the maximum of a set of values
* Input Parameters: 5 numbers
* Returns: The maximum
* Preconditions: 5 doubles must be read in from a file.
* Postconditions: The maximum is returned.
*/

double find_max(double num1, double num2, double num3, double num4, double num5)
{
	double max = num1;

	if (num2 > max)
	{
		max = num2;
	}
	
	if (num3 > max)
	{
		max = num3;
	}

	if (num4 > max)
	{
		max = num4;
	}

	if (num5 > max)
	{
		max = num5;
	}

	return max;
}

/*
* Function: find_min(double num1, double num2, double num3, double num4, double num5)
* Date: September 22, 2017
* Date Last Modified: September 22, 2017
* Description: Determines the manimum of a set of values
* Input Parameters: 5 numbers
* Returns: The minimum
* Preconditions: 5 doubles must be read in from a file.
* Postconditions: The minimum is returned.
*/

double find_min(double num1, double num2, double num3, double num4, double num5)
{
	double min = num1;

	if (num2 < min)
	{
		min = num2;
	}

	if (num3 < min)
	{
		min = num3;
	}

	if (num4 < min)
	{
		min = num4;
	}

	if (num5 < min)
	{
		min = num5;
	}

	return min;
}

/*
* Function: print_double(FILE *outfile, double number)
* Date: September 22, 2017
* Date Last Modified: September 22, 2017
* Description: Writes a double to an output file
* Input Parameters: A double
* Returns: Nothing
* Preconditions: An output file must be open.
* Postconditions: The output file must be closed.
*/

void print_double(FILE *outfile, double number)
{
	fprintf(outfile, "%.2lf\n", number);
}