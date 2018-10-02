/**********************************************************************************************
* Programmer: Trenton Fales                                                                   *
* Class: CptS 121 Fall 2017; Lab Section 5                                                    *
* Programming Assignment: 6                                                                   *
* Date: November 6, 2017                                                                      *
*                                                                                             *
*                                                                                             *
* Description: This program is a Battleship simulation for two players. One being a computer. *
*                                                                                             *
*              The objective of the game is to sink all ships in your enemy's fleet. The      *
*              player to sink his/her enemy's fleet first wins. Both player's fleets consist  *
*              of 5 ships that are hidden from the enemy. Each ship may be differentiated by  *
*              its "size" (besides the Cruiser and Submarine) or number of cells it expands   *
*              on the game board. The Carrier has 5 cells, Battleship has 4 cells, Cruiser    *
*              has 3 cells. Submarine has 3 cells, and the Destroyer has 2 cells.             *
**********************************************************************************************/

#include "functions.h"

int main(void)
{
	char p1_board[NUM_ROWS][NUM_COLS] = { {'~'} },			// Used to represent Player 1's game board
		p2_board[NUM_ROWS][NUM_COLS] = { {'~'} },			// Used to represent Player 2's game board
		p2_display_board[NUM_ROWS][NUM_COLS] = { {'~'} };	// Used to display whether each target was a hit or miss
	int manual_or_automatic = 0,							// Used to determine if the player wants to place ships manually/automatically
		*row_start = 0,										// Used to determine what row a ship placement begins
		*col_start = 0,										// Used to determine what column a ship placement begins
		*target_x = 0,										// Used to determine the x_coordinate the player wants to use as a shot
		*target_y = 0,										// Used to determine the y_coordinate the player wants to use as a shot
		*comp_target_x = 0,									// Used to determine the x_coordinate the computer wants to use as a shot
		*comp_target_y = 0,									// Used to determine the y_coordinate the computer wants to use as a shot
		direction = 0,										// Used to determine whether the player wants to place their ship vertically or horizontally
		*hit = 0,											// Used to determine the number of hits per player
		*miss = 0,											// Used to determine the number of misses per player
		hit_or_miss = 0,									// Used to determine if the shot was a hit or a miss
		player = 1;											// Used to switch between player turns
	FILE *outfile = NULL;									// Used to write information to a file

	outfile = fopen("battleship.log", "w");					// Opens a file "battleship.org" to record turns

	srand((unsigned int)time(NULL));						// Used to produce random numbers

	welcome_screen();										// Displays the welcome screen
	system("pause");										// "Press any key to continue . . ."
	system("cls");											// Clear the screen

	init_board(p1_board, NUM_ROWS, NUM_COLS);				// Initialize Player 1's game board
	init_board(p2_board, NUM_ROWS, NUM_COLS);				// Initialize Player 2's game board
	init_board(p2_display_board, NUM_ROWS, NUM_COLS);		// Initialize an empty Player 2 board to display to Player 1 to keep ship placement hidden

	printf("Would you like to enter your ships in manually or have them randomly generated?\n1 = Manual, 2 = Automatic: ");
	scanf("%d", &manual_or_automatic);		// Determine if the player wants to enter their ships in manually or automatically

	if (manual_or_automatic == 1) // Manual
	{
		manually_place_all_ships(p1_board, row_start, col_start);
	}
	else // Automatic
	{
		randomly_place_all_ships(p1_board, row_start, col_start);
	}

	randomly_place_all_ships(p2_board, row_start, col_start);					// Generate random placement of ships for Player 2
	printf("Player 2 (Computer's) board has been generated.\n");				// Notify user that Player 2's board has been generated
	player = select_who_starts_first();											// Determine which player will begin
	printf("Player %d has randomly been selected to go first.\n\n", player);	// Notify the user which player has been chosen to begin

	while (hit != 17)		// While there are ship cells to be hit:
	{
		while (player == 1)		// While it is Player 1's turn:
		{
			printf("Player 1's Board:\n");											// Notify user the following board is Player 1's
			print_board(p1_board, NUM_ROWS, NUM_COLS);								// Display Player 1's board
			printf("\nPlayer 2's Board:\n");										// Notify user the following board is Player 2's 
			print_board(p2_display_board, NUM_ROWS, NUM_COLS);						// Display Player 2's board
			get_target(&target_x, &target_y);										// Get coordinates the player wants to hit
			hit_or_miss = check_shot(p2_board, &target_x, &target_y, &hit, &miss);	// Determine if the shot is a hit/miss
			output_current_move(outfile, 1, &target_x, &target_y, hit_or_miss);		// Write the current move to "battleship.log"
			update_board(&p2_display_board, hit_or_miss, &target_x, &target_y);		// Update board to show the shot has been taken at the given coordinates
			if (hit == 17)															// If all the ship cells are hit:
			{
				printf("Player 1 wins!\n\n");											// Notify user Player 1 wins!
				fprintf(outfile, "Player 1 wins, Player 2 loses\n");					// Write winner/loser to "battleship.log"
			}
			player += 1;		// Update player to change turns
			printf("\n");		// Newline
			system("pause");	// "Press any key to continue . . ."
			system("cls");		// Clear screen
		}
		while (player == 2)				// While it is Player 2's turn:
		{
			printf("Player 1's Board:\n");														// Notify user the following board is Player 1's
			print_board(p1_board, NUM_ROWS, NUM_COLS);											// Display Player 1's board
			printf("\nPlayer 2's Board:\n");													// Notify user the following board is Player 2's 
			print_board(p2_display_board, NUM_ROWS, NUM_COLS);									// Display Player 2's board
			computer_selects(&p1_board, &comp_target_x, &comp_target_y);						// Get computer's coordinates to shoot at Player 1
			printf("\nPlayer 2 selects: (%d,%d)\n", comp_target_x, comp_target_y);				// Display shot/coordinates to user
			hit_or_miss = check_shot(p1_board, &comp_target_x, &comp_target_y, &hit, &miss);	// Determine if shot is a hit/miss
			output_current_move(outfile, 2, &comp_target_x, &comp_target_y, hit_or_miss);		// Write the current move to "battleship.log"
			update_board(&p1_board, hit_or_miss, &comp_target_x, &comp_target_y);				// Update board to show the shot has been taken at the given coordinates
			if (hit == 17)																		// If all the ship cells are hit:
			{
				printf("Player 2 wins!\n\n");														// Notify user Player 2 wins!
				fprintf(outfile, "Player 2 wins, Player 1 loses\n");								// Write winner/loser to "battleship.log"
			}
			player -= 1;		// Update player to change turns
			printf("\n");		// Newline
			system("pause");	// "Press any key to continue . . ."
			system("cls");		// Clear screen
		}
	}
	fclose(outfile);	// Close the file "battleship.log"
	return 0;
}