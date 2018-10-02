/**********************************************************************************************
* Programmer: Trenton Fales                                                                   *
* Class: CptS 121 Fall 2017; Lab Section 5                                                    *
* Programming Assignment: 4                                                                   *
* Date: October 5, 2017                                                                       *
*                                                                                             *
*                                                                                             *
* Description: This program is a "craps" game simulation.                                     *
*                                                                                             *
*              This program starts with a menu and allows the user to input a number that     *
*              corresponds to an option on the menu. Once the game has begun, the user will   *
*              be asked for an initial balance as well as a wager, or bet. The game will then *
*              roll a random number between 2 and 12 (corresponding to two dice values added  *
*              together), display the roll, and determine whether the user won, lost, or      *
*              set the point. The user enters a wager, or bet, before every roll, after it's  *
*              determined that they have either won or lost, and decided to play another      *
*              hand. The user can withdraw from the game at any point after a hand is over.   *
**********************************************************************************************/

#include "functions.h"		// Import header file

/*
* Function: display_menu(void)
* Date: October 1, 2017
* Date Last Modified: October 6, 2017
* Description: Displays the menu
* Input Parameters: None
* Returns: Nothing
* Preconditions: None
* Postconditions: None
*/

void display_menu(void)
{
	printf("1. Display game rules.\n");
	printf("2. Play game.\n");
	printf("3. Random joke.\n");
	printf("4. Exit.\n\n");
}

/*
* Function: get_option(void)
* Date: October 1, 2017
* Date Last Modified: October 6, 2017
* Description: Get's an option from the user
* Input Parameters: None
* Returns: Option as an integer
* Preconditions: The menu must be displayed
* Postconditions: Option is returned
*/

int get_option(void)
{
	int option = 0;
	scanf("%d", &option);
	printf("\n");
	return option;
}

/*
* Function: determine_option_validity(void)
* Date: October 1, 2017
* Date Last Modified: October 6, 2017
* Description: While option is invalid: display the menu,
*              get an option from user, clear screen
* Input Parameters: None
* Returns: Option as an integer
* Preconditions: Option must be invalid
* Postconditions: Corerect option is returned
*/

int determine_option_validity(void)
{
	int option = 0;
	do // Input validation loop
	{
		display_menu();
		option = get_option();
		system("cls");
	} while ((option < 1) || (option > 4));
	return option;
}

/*
* Function: validate_option(int option)
* Date: October 1, 2017
* Date Last Modified: October 6, 2017
* Description: If option is 1: Display the rules
*              If option is 2: return 2
*   		   If option is 3: Display question and answer (joke)
*    		   If option is 4: Exit program
* Input Parameters: option
* Returns: Integers 1, 2, and 3 depending on choice of option
* Preconditions: Option must be valid
* Postconditions: 1 of 3 integers is returned
*/

int validate_option(int option)
{
	switch (option)
	{
	case 1: 
		print_game_rules();
		return 1;
	case 2: 
		return 2;
	case 3: 
		printf("\nQUESTION: \tWhy didn't they play poker in the jungle?\n");
		printf("ANSWER: \tToo many cheetahs\n\n");
		return 3;
	case 4: 
		exit(option);
		break;
	}
}

/*
* Function: print_game_rules(void)
* Date: October 1, 2017
* Date Last Modified: October 6, 2017
* Description: Prints the game rules
* Input Parameters: None
* Returns: Nothing
* Preconditions: Menu choice must be 1
* Postconditions: None
*/

void print_game_rules(void)
{
	printf("\t\t\t\tWelcome to \"Craps!\"\n\n");
	printf("Rules:\n");
	printf("\tA player rolls two dice. Each die has six faces. These faces contain\n");
	printf("\t1, 2, 3, 4, 5, and 6 spots. After the dice have come to rest, the sum\n");
	printf("\tof the spots on the two upward faces is calculated. If the sum is 7 or\n");
	printf("\t11 on the first throw, the player wins. If the sum is 2, 3, or 12 on\n");
	printf("\tthe first throw (called \"craps\"), the player loses (i.e. the \"house\"\n");
	printf("\twins). If the sum is 4, 5, 6, 8, or 10 on the first throw, then the sum\n");
	printf("\tbecomes the player's \"point.\" To win, you must continue rolling the\n");
	printf("\tdice until you \"make your point.\" The player loses by rolling a 7\n");
	printf("\tbefore making the point.\n\n");
}

/*
* Function: get_bank_balace(void)
* Date: October 1, 2017
* Date Last Modified: October 6, 2017
* Description: Gets the initial bank balance from the user
* Input Parameters: None
* Returns: Balance as a double
* Preconditions: Menu choice must be 2
* Postconditions: Balance must be returned
*/

double get_bank_balace(void)
{
	double balance = 0.0;
	printf("Enter initial bank balance: ");
	scanf("%lf", &balance);
	while (balance <= 0) {
		system("cls");
		printf("Invalid bank balance. \nPlease enter a value greater than $0.00. ");
		scanf("%lf", &balance);
	}
	return balance;
}

/*
* Function: get_wager_amount(double balance)
* Date: October 1, 2017
* Date Last Modified: October 6, 2017
* Description: Gets a wager from the user
* Input Parameters: balance
* Returns: Wager as a double
* Preconditions: Menu choice must be 2
* Postconditions: Wager must be returned
*/

double get_wager_amount(double balance)
{
	int check_wager = 0;
	double wager = 0.0;
	printf("Enter wager amount: ");
	scanf("%lf", &wager);
	check_wager = (int)check_wager_amount((double)wager, (double)balance);
	wager = wager_invalid((int)check_wager, (double)wager, (double)balance);
	return wager;
}

/*
* Function: check_wager_amount(double wager, double balance)
* Date: October 1, 2017
* Date Last Modified: October 6, 2017
* Description: Checks whether wager is valid or invalid
* Input Parameters: wager, balance
* Returns: 0 if invalid, 1 if valid
* Preconditions: Menu choice must be 2
* Postconditions: 1 of 2 integers must be returned
*/

int check_wager_amount(double wager, double balance)
{
	if (wager > balance) {
		return 0;
	}
	else {
		return 1;
	}
}

/*
* Function: wager_invalid(int check_wager, double wager, double balance)
* Date: October 1, 2017
* Date Last Modified: October 6, 2017
* Description: While wager is invalid: display a message notifying the user,
*              gets new wager, checks if valid or invalid
* Input Parameters: check_wager, wager, balance
* Returns: Valid wager
* Preconditions: Menu choice must be 2, wager must be invalid
* Postconditions: Valid wager must be returned
*/

double wager_invalid(int check_wager, double wager, double balance)
{
	while (check_wager == 0) {
		printf("\nInvalid wager. Exceeds balance amount.\n");
		wager = (double)get_wager_amount((double)balance);
		check_wager = (int)check_wager_amount((double)wager, (double)balance);
	}
	return wager;
}

/*
* Function: roll_die(void)
* Date: October 1, 2017
* Date Last Modified: October 6, 2017
* Description: Rolls a single die
* Input Parameters: None
* Returns: Value of the die
* Preconditions: Menu choice must be 2
* Postconditions: Die value must be returned
*/

int roll_die(void)
{
	int dieValue = 0;
	dieValue = rand() % 6 + 1;
	return dieValue;
}

/*
* Function: determine_roll(void)
* Date: October 1, 2017
* Date Last Modified: October 6, 2017
* Description: Rolls two die and determines the sum
* Input Parameters: None
* Returns: Sum of the dice
* Preconditions: Menu choice must be 2
* Postconditions: Sum of the dice must be returned
*/

int determine_roll(void)
{
	int die1 = 0, die2 = 0, sum_dice = 0;
	die1 = roll_die();												
	die2 = roll_die();												
	sum_dice = calculate_sum_dice(die1, die2);
	return sum_dice;
}

/*
* Function: calculate_sum_dice(int die1_value, int die2_value)
* Date: October 1, 2017
* Date Last Modified: October 6, 2017
* Description: Sums two dice
* Input Parameters: die1_value, die2_value
* Returns: Sum of the dice
* Preconditions: Menu choice must be 2, two die must
*                be rolled
* Postconditions: Sum of the dice must be returned
*/

int calculate_sum_dice(int die1_value, int die2_value)
{
	int sum = 0;
	sum = die1_value + die2_value;
	return sum;
}

/*
* Function: is_win_loss_or_point(int sum_dice)
* Date: October 1, 2017
* Date Last Modified: October 6, 2017
* Description: Determines whether the first roll 
*              was a win, loss, or setting of the point
* Input Parameters: sum_dice
* Returns: 1, 0, or -1 depending on the result
* Preconditions: Menu choice must be 2, two die must
*                be rolled and summed 
* Postconditions: 1 of 3 integers must be returned
*/

int is_win_loss_or_point(int sum_dice)
{
	if (sum_dice == 7 || sum_dice == 11) {
		return 1;
	}
	else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12) {
		return 0;
	}
	else {
		return -1;
	}
}

/*
* Function: is_point_loss_or_neither(int sum_dice, int point_value)
* Date: October 1, 2017
* Date Last Modified: October 6, 2017
* Description: Determines whether the second+ rolls
*              are a win, loss, or neither
* Input Parameters: sum_dice, point_value
* Returns: 1, 0, or -1 depending on the result
* Preconditions: Menu choice must be 2, two die must
*                be rolled and summed
* Postconditions: 1 of 3 integers must be returned
*/

int is_point_loss_or_neither(int sum_dice, int point_value)
{
	if (sum_dice == point_value) {
		return 1;
	}
	else if (sum_dice == 7) {
		return 0;
	}
	else {
		return -1;
	}
}

/*
* Function: adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
* Date: October 1, 2017
* Date Last Modified: October 6, 2017
* Description: Adjusts the bank balance based on a win or loss
* Input Parameters: bank_balance, wager_amount, add_or_subtract
* Returns: bank_balance
* Preconditions: Player must have won or lost the hand
* Postconditions: bank_balance must be returned
*/

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
	if (add_or_subtract == 1) {
		bank_balance += wager_amount;
		return bank_balance;
	}
	else if (add_or_subtract == 0) {
		bank_balance -= wager_amount;
		return bank_balance;
	}
	else {
		return bank_balance;
	}
}

/*
* Function: chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
* Date: October 1, 2017
* Date Last Modified: October 6, 2017
* Description: Displays various messages depending on certain results
* Input Parameters: number_rolls
* Returns: Nothing
* Preconditions: None
* Postconditions: None
*/

void chatter_messages(int number_rolls)
{
	if (number_rolls == 2) {
		printf("You got this!\n");
	}
	if (number_rolls == 4) {
		printf("One more, let's go.\n");
	}
	if (number_rolls == 7) {
		printf("How have you not sevened-out yet!?\n");
	}
}

/*
* Function: exit_play(char play, double balance)
* Date: October 5, 2017
* Date Last Modified: October 6, 2017
* Description: While the player no longer wants to play, the program will tell the player
*              their exit balance and exit the program.
* Input Parameters: play, balance
* Returns: Nothing
* Preconditions: Player must choose not to play again
* Postconditions: Program must close
*/

void exit_play(char play, double balance) {
	if (play == 'n') {										
		printf("\nYou cashed out with $%.2lf\n\n", balance);	
		exit(play);										
	}
}

/*
* Function: check_play_input_invalid(char play)
* Date: October 5, 2017
* Date Last Modified: October 6, 2017
* Description: While the player enters an invalid response to
*              the question asking if they want to play another
*              hand, the player will be prompted to enter an
*              input until it is valid.
* Input Parameters: play
* Returns: Nothing
* Preconditions: Player must enter an invalid input
* Postconditions: Player must enter a valid input
*/

void check_play_input_invalid(char play) {
	while (play != 'y' && play != 'n') {				
		printf("Play another hand? (y/n)\n");			
		scanf(" %c", &play);							
		printf("\n");									
	}
}

/*
* Function: check_balance_validity(double balance, char play)
* Date: October 5, 2017
* Date Last Modified: October 6, 2017
* Description: If the player runs out of money, it will
*              notify them and exit the program.
* Input Parameters: balance, play
* Returns: Nothing
* Preconditions: Player must have a 0 balance
* Postconditions: Program must exit
*/

void check_balance_validity(double balance, char play) {
	if (balance == 0) {										
		printf("\nYou cashed out with $%.2lf\n\n", balance);		
		exit(play);												
	}	
}