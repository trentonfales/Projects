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

int main(void)
{
	double balance = 0.0,			// Used to keep track of the player's balance
		wager = 0.0;                // Used to keep track of the wager/bet inputted by the user
	int check_wager = 0,            // Used to determine if the wager is valid
		option = 0,                 // Used to determine the player's menu choice
		val_option = 0,				// Used to determine if the player's menu choice is valid
		roll = 0,					// Used to keep track of the player's roll (sum of two dice)
		point_value = 0,			// Used to keep track of the player's "set point"
		win_loss_or_point = 0,		// Used to determine if the player won, lost, or set the point after the first roll
		point_loss_neither = 0, 	// Used to determine if the player won, lost, or neither for every roll after the first of the hand
		number_rolls = 0;			// Used to count the number of rolls per turn
	char play = 0;					// Used to determine if the player wants to play another hand

	option = determine_option_validity(option);			// Display menu, get option, determine if valid or invalid
	val_option = validate_option(option);				// Executes menu options 1, 3, and 4

	while (val_option == 1 || val_option == 3)			// While option is 1 or 3:
	{													// ...
		option = determine_option_validity(option);		// Display menu, get option, determine if valid or invalid
		val_option = validate_option(option);			// Executes menu options 1, 3, and 4
	}

	while (val_option == 2) {											// While menu option is 2 (Play game)
		// Execute Game													
		srand((unsigned int)time(NULL));
		play = 'y';

		balance = get_bank_balace();									// Determine initial bank balance

		while (play == 'y') {											// While the user wants to play:
			wager = get_wager_amount(balance);							// Get the wager from the user
			roll = determine_roll();									// Determine the roll
			printf("\nRoll: %d\n", roll);								// Display roll
			win_loss_or_point = is_win_loss_or_point(roll);				// Determine if the first roll wins, loses, or sets the point
			while (win_loss_or_point == 1) {								// While the user wins on the first roll:
				balance = adjust_bank_balance(balance, wager, 1);				// Add wager to bank balance
				printf("\nCongratulations, you won!\n");						// Display congratulatory message
				printf("Bank balance = $%.2lf\n\n", balance);					// Display updated bank balance
				printf("Play another hand? (y/n)\n");							// Ask the user if they want to play another hand
				scanf(" %c", &play);											// Determine the user's answer
				check_play_input_invalid(play);									// Check answer to make sure it's valid
				exit_play(play, balance);										// If the user does not want to play again, exit the program
				system("cls");													// Clear the screen
				printf("Bank balance = $%.2lf\n", balance);						// Display current bank balance
				win_loss_or_point = 10;											// Update win_loss_or_point variable to avoid infinite loop
			}
			while (win_loss_or_point == 0) {								// While the user loses on the first roll:
				balance = adjust_bank_balance(balance, wager, 0);				// Subtract wager from bank balance
				printf("\nI'm sorry, you lost.\n");								// Display message notifying the user that they lost
				check_balance_validity(balance, play);							// Determine if balance = 0 (player is out of money)
				printf("Bank balance = $%.2lf\n\n", balance);					// Display updated bank balance
				printf("Play another hand? (y/n)\n");							// Ask the user if they want to play another hand
				scanf(" %c", &play);											// Determine the user's answer
				check_play_input_invalid(play);									// Check answer to make sure it's valid
				exit_play(play, balance);										// If the user does not want to play again, exit the program
				system("cls");													// Clear the screen
				printf("Bank balance = $%.2lf\n", balance);						// Display current bank balance
				win_loss_or_point = 10;											// Update win_loss_or_point variable to avoid infinitie loop
			}
			while (win_loss_or_point == -1) {								// While the user doesn't win or lose on the first roll:
				point_value = roll;												// Set the roll to the point value to get
				printf("Point is set to: %d\n\n", point_value);					// Display message notifying the user what the point has been set to
				roll = determine_roll();										// Determine the roll
				printf("\nRoll: %d\n", roll);									// Display roll
				while (roll != point_value && roll != 7) {						// While roll doesn't win or lose:
					chatter_messages(number_rolls);									// Call potential chatter messages depending on certain results
					roll = determine_roll();										// Determine the roll
					printf("Roll: %d\n", roll);										// Display roll
					number_rolls += 1;												// Update variable number_rolls for function chatter_messages(number_rolls)
				}
				if (roll == 7) {												// If player loses:
					balance = adjust_bank_balance(balance, wager, 0);				// Subtract wager from bank balance
					printf("\nI'm sorry, you lost.\n");								// Display message notifying the user that they lost
					check_balance_validity(balance, play);							// Determine if balance = 0 (player is out of money)
					printf("Bank balance = $%.2lf\n\n", balance);					// Display updated bank balance
					printf("Play another hand? (y/n)\n");							// Ask the user if they want to play another hand
					scanf(" %c", &play);											// Determine the user's answer
					check_play_input_invalid(play);									// Check answer to make sure it's valid
					exit_play(play, balance);										// If the user does not want to play, exit the program
					system("cls");													// Clear the screen
					printf("Bank balance = $%.2lf\n", balance);						// Display current bank balance
				}
				if (roll == point_value) {										// If player wins:
					balance = adjust_bank_balance(balance, wager, 1);				// Add wager to bank balance
					printf("\nCongratulations, you won!\n");						// Display congratulatory message
					printf("Bank balance = $%.2lf\n\n", balance);					// Display updated bank balance
					printf("Play another hand? (y/n)\n");							// Ask the user if they want to play another hand
					scanf(" %c", &play);											// Determine the user's answer
					check_play_input_invalid(play);									// Check answer to make sure it's valid
					exit_play(play, balance);										// If the user does not want to play, exit the program
					system("cls");													// Clear the screen
					printf("Bank balance = $%.2lf\n", balance);						// Display current bank balance
				}
				win_loss_or_point = 10;
			}
		}
	}

	return 0;
}