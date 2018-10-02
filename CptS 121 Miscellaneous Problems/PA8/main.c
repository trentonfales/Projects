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

int main(void)
{
	// Task 1: String Concatenation
	char str1[100] = "with this one.",
		str2[100] = "The force is strong...";
	printf("Task 1\n");
	printf("Source string: %s\n", str1);
	printf("Destination string: %s\n", str2);
	my_str_n_cat(str2, str1);
	printf("Concatenated strings: %s\n\n", str2);

	// Task 2: Binary Search
	int n[27] = { 12, 15, 18, 25, 33, 46, 47, 49, 50, 53, 54, 57, 59, 61, 63, 66, 68, 71, 74, 78, 81, 83, 88, 90, 94, 97, 99 };
	int targetindex = 0;
	targetindex = binary_search(n, 33);
	printf("Task 2\n");
	printf("List: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, \n      %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", 
		n[0], n[1], n[2], n[3], n[4], n[5], n[6], n[7], n[8], n[9], n[10], n[11], n[12], n[13], n[14], n[15], n[16], n[17], n[18], n[19], n[20],
		n[21], n[22], n[23], n[24], n[25], n[26]);
	printf("Target: %d\n", 33);
	printf("Target index: %d\n\n", targetindex);

	// Task 3: Bubble Sort
	char *a1 = "Bears", *a2 = "Ducks", *a3 = "Apes", *a4 = "Cougars", *a5 = "Elephants";
	char * animals[5] = { a1, a2, a3, a4, a5 };
	printf("Task 3\n");
	printf("Unsorted list: %s, %s, %s, %s, %s\n", animals[0], animals[1], animals[2], animals[3], animals[4]);
	bubble_sort(animals, 5);
	printf("Sorted list: %s, %s, %s, %s, %s\n\n", animals[0], animals[1], animals[2], animals[3], animals[4]);

	// Task 4: Palindrome (Recursive)
	char *word1 = "boxer";
	char *word2 = "anna";
	int palindrome = 0;
	printf("Task 4\n");
	palindrome = is_palindrome(word1, 5);
	if (palindrome == 1)
		printf("The word \"%s\" is a palindrome.\n", word1);
	else
		printf("The word \"%s\" is not a palindrome.\n", word1);
	palindrome = is_palindrome(word2, 4);
	if (palindrome == 1)
		printf("The word \"%s\" is a palindrome.\n", word2);
	else
		printf("The word \"%s\" is not a palindrome.\n", word2);

	// Task 5: Sum of Primes
	int number = 7,
		sum = 0;
	printf("\nTask 5\n");
	sum = sum_primes(number);
	printf("Sum of primes between 2 and %d: %d\n\n", number, sum);

	// Task 6: Maximum Occurences
	char *string_ex = "test string";
	Occurences *st_arr[128] = { 0, 0 };
	int *num_occ = 0;
	char *character = 0;
	maximum_occurences(&string_ex, &st_arr, &num_occ, &character);
	printf("Task 6\n");
	printf("String: %s\n", string_ex);
	printf("Highest occuring letter: %c\n", character);
	printf("Occurs %d times\n", num_occ);

	return 0;
}