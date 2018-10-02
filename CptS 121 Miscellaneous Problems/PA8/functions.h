/**********************************************************************************************
* Programmer: Trenton Fales                                                                   *
* Class: CptS 121 Fall 2017; Lab Section 5                                                    *
* Programming Assignment: 8                                                                   *
* Date: December 6, 2017                                                                      *
*                                                                                             *
*                                                                                             *
* Description: This program solves each of the following problems.                            *
*                                                                                             *
*			   1. String Concatenation                                                        *
*              2. Binary Search                                                               *
*              3. Bubble Sort                                                                 *
*              4. Palindrome (Recursive)                                                      *
*              5. Sum of Primes                                                               *
*              6. Maximum Occurences                                                          *
**********************************************************************************************/

#include <stdio.h>
#include <string.h>

typedef struct occurences
{
	int num_occurences;
	double frequency;
} Occurences;

void my_str_n_cat(char *pDest, char *pSource);
int binary_search(int *arr, int target);
void bubble_sort(char *strings[], int num_strings);
int is_palindrome(char *string, int length);
int is_prime(int num);
int sum_primes(unsigned int n);
void maximum_occurences(char *string, Occurences *arr, int *num, char *character);