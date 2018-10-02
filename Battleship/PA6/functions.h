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

//Guard Code
#ifndef FUNCTIONS_H

#include <stdio.h>		// Import standard library
#include <stdlib.h>		// rand(), srand()
#include <time.h>		// Import time

#define NUM_ROWS 10
#define NUM_COLS 10

typedef enum
{
	VERTICAL, HORIZONTAL
}Dir;

void welcome_screen(void);
void init_board(char board[][NUM_COLS], int rows, int cols);
void print_board(char board[][NUM_COLS], int rows, int cols);
void input_start_point(char ship_name[], int *row_start, int *col_start);
int input_direction(void);
void manually_place_ship(char board[][NUM_COLS], int length, char ship_symbol, int *row_start, int *col_start, int direction);
void manually_place_all_ships(char board[][NUM_COLS], int row_start, int col_start);
Dir get_direction(void);
void generate_start_point(int ship_length, Dir direction, int rows, int cols, int *row_start, int *col_start);
void place_ship(char board[][NUM_COLS], int length, char ship_symbol, int row_start, int col_start, Dir direction);
void randomly_place_all_ships(char board[][NUM_COLS], int row_start, int col_start);
int select_who_starts_first(void);
void get_target(int *target_x, int *target_y);
int check_shot(char board[][NUM_COLS], int *target_x, int *target_y, int *hit, int *miss);
void update_board(char board[][NUM_COLS], int hit_or_miss, int *target_x, int *target_y);
void computer_selects(char board[][NUM_COLS], int *comp_target_x, int *comp_target_y);
void output_current_move(FILE *outfile, int player, int *target1, int *target2, int hit_or_miss);

#endif