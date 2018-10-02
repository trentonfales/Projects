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

#include "functions.h"

void my_str_n_cat(char *pDest, char *pSource)
{
	int index = 0,
		count = 0;
	// Counts the # of characters in pDest excluding the null character
	while (pDest[index] != '\0')
	{
		++count;
		++index;
	}
	// Concatenates the strings
	for (index = 0; pDest[index] != '\0'; ++index)
	{
		pDest[index + count] = pSource[index];
	}
	return *pDest;
}

int binary_search(int *arr, int target)
{
	int left = 1,
		right = 27,
		found = 0, // False
		targetindex = -1,
		mid;
	while (found == 0 && left <= right)
	{
		mid = (left + right) / 2;
		if (target == arr[mid]) {
			found = 1; // True
			targetindex = mid;
		}
		else if (target < arr[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return targetindex;
}

void bubble_sort(char *strings[], int num_strings)
{
	int U = 0,
		C = 0,
		passes = 1,
		temp = 0;
	U = num_strings - 1;
	while (U > 1)
	{
		C = 1;
		while (C <= U)
		{
			if (*strings[C] < *strings[C - 1])
			{
				temp = strings[C];
				strings[C] = strings[C - 1];
				strings[C - 1] = temp;
			}
			C += 1;
		}
		U -= 1;
	}
}

int is_palindrome(char *string, int length)
{
	int index = 0,
		palindrome = 0;
	if (length == 1)
		return 1;
	else if (length == 2 && (string[index] == string[length - 1]))
		return 1;
	else if (string[index] == string[length - 1])
		palindrome = is_palindrome(string + 1, length - 2);
	else if (string[index] != string[length - 1])
		return 0;
}

// The function is_prime was adapted from: https://stackoverflow.com/questions/5281779/c-how-to-test-easily-if-it-is-prime-number
int is_prime(int num)
{
	int i = 0;
	if (num % 2 == 0 && num > 2)
		return 0;
	for (i = 3; i < num / 2; i += 2)
	{
		if (num % i == 0)
			return 0;
	}
	return 1;
}

int sum_primes(unsigned int n)
{
	int counter = 0,
		sum = 2;
	for (counter = 3; counter <= n; ++counter)
	{
		if (is_prime(counter) == 1)
			sum += counter;
	}
	return sum;
}

void maximum_occurences(char *string, Occurences *arr, int *num, char *character)
{
	int highest_num_occ = 0,
		total = 0,
		index = 0;
	while (string[index] != '\0')
	{
		arr[(int)string[index]].num_occurences += 1;
		++total;
		++index;
	}
	for (index = 0; index < 127; ++index)
	{
		if (arr[index].num_occurences > arr[index + 1].num_occurences)
		{
			num = arr[index].num_occurences;
			character = (char)index;
		}
	}

}