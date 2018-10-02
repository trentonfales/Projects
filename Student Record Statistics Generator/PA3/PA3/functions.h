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

#include <stdio.h>       // Import standard library
#include <math.h>        // Import mathematical library

double read_double(FILE *infile);
int read_integer(FILE *infile);
double calculate_sum(double num1, double num2, double num3, double num4, double num5);
double calculate_mean(double sum, int number);
double calculate_deviation(double number, double mean);
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);
double calculate_standard_deviation(double variance);
double find_max(double num1, double num2, double num3, double num4, double num5);
double find_min(double num1, double num2, double num3, double num4, double num5);
void print_double(FILE *outfile, double number);