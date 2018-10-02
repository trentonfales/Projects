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

void welcome_screen(void)
{
	printf("***** Welcome to Battleship! *****\n\n");
	printf("Rules of the Game:\n");
	printf("\tObjective: Be the first to sink all 5 of your opponent's ships.\n\n");
	printf("\tShips:\n");
	printf("\t1. Carrier: \t5 spaces\n");
	printf("\t2. Battleship: \t4 spaces\n");
	printf("\t3. Cruiser: \t3 spaces\n");
	printf("\t4. Submarine: \t3 spaces\n");
	printf("\t5. Destroyer: \t2 spaces\n\n");
	printf("\tSteps:\n");
	printf("\t1. Place your ships on the game board. (Horizontally or Vertically)\n");
	printf("\t2. On your turn, select a coordinate you want to shoot.\n");
	printf("\t3. If the enemy has a ship on that coordinate, it's a hit!\n");
	printf("\t   Otherwise, it's a miss.\n");
	printf("\t4. Alternate players.\n");
	printf("\t5. Repeat steps 2-5 until all of a player's ships have sank.\n\n");
}

void init_board(char board[][NUM_COLS], int rows, int cols)
{
	int row_index = 0, col_index = 0;

	for (; row_index < rows; ++row_index)
	{
		for (col_index = 0; col_index < cols; ++col_index)
		{
			board[row_index][col_index] = '~';
		}
	}
}

void print_board(char board[][NUM_COLS], int rows, int cols)
{
	int row_index = 0, col_index = 0;

	for (; row_index < rows; ++row_index)
	{
		for (col_index = 0; col_index < cols; ++col_index)
		{
			printf("%c ", board[row_index][col_index]);
		}
		printf("\n");
	}
	printf("\n");
}

void input_start_point(char ship_name[], int *row_start, int *col_start)
{
	int row_st = 0, col_st = 0;
	printf("Please enter a coordinate in which your %s will start.\n", ship_name);
	printf("You will then choose if you want to move right horizontally or down vertically.\n");
	scanf("%d%d", &row_st, &col_st);
	*row_start = row_st;
	*col_start = col_st;
}

int input_direction(void)
{
	int direction = 0;
	printf("Would you like to place your ship vertically or horizontally?\n1 = Vertical, 2 = Horizontal\n");
	scanf("%d", &direction);
	return direction;
}

void manually_place_ship(char board[][NUM_COLS], int length, char ship_symbol, int *row_start, int *col_start, int direction)
{
	int index = 0;

	while (index < length)
	{
		if (direction == 1)
		{
			board[*row_start + index - 1][*col_start - 1] = ship_symbol;
		}
		else // Horizontal
		{
			board[*row_start - 1][*col_start + index - 1] = ship_symbol;
		}
		++index;
	}
}

void manually_place_all_ships(char board[][NUM_COLS], int row_start, int col_start)
{
	int direction = 0;
	char carrier[] = "Carrier (5)",
		battleship[] = "Battleship (4)",
		cruiser[] = "Cruiser (3)",
		sub[] = "Submarine (3)",
		destroyer[] = "Destroyer (2)";
	printf("\n");
	print_board(board, NUM_ROWS, NUM_COLS);
	input_start_point(&carrier, &row_start, &col_start);
	direction = input_direction();
	manually_place_ship(board, 5, 'C', &row_start, &col_start, direction);
	system("cls");
	print_board(board, NUM_ROWS, NUM_COLS);
	input_start_point(&battleship, &row_start, &col_start);
	direction = input_direction();
	manually_place_ship(board, 4, 'B', &row_start, &col_start, direction);
	system("cls");
	print_board(board, NUM_ROWS, NUM_COLS);
	input_start_point(&cruiser, &row_start, &col_start);
	direction = input_direction();
	manually_place_ship(board, 3, 'R', &row_start, &col_start, direction);
	system("cls");
	print_board(board, NUM_ROWS, NUM_COLS);
	input_start_point(&sub, &row_start, &col_start);
	direction = input_direction();
	manually_place_ship(board, 3, 'S', &row_start, &col_start, direction);
	system("cls");
	print_board(board, NUM_ROWS, NUM_COLS);
	input_start_point(&destroyer, &row_start, &col_start);
	direction = input_direction();
	manually_place_ship(board, 2, 'D', &row_start, &col_start, direction);
	system("cls");
	print_board(board, NUM_ROWS, NUM_COLS);
	printf("\n");
	system("pause");
}

Dir get_direction(void)
{
	Dir direction = VERTICAL;
	direction = (Dir) (rand() % 2);
	return direction;
}

void generate_start_point(int ship_length, Dir direction, int rows, int cols, int *row_start, int *col_start)
{
	if (direction == HORIZONTAL)
	{
		*row_start = rand() % rows;
		*col_start = rand() % (cols - ship_length + 1);
	}
	if (direction == VERTICAL)
	{
		*row_start = rand() % (rows - ship_length + 1);
		*col_start = rand() % cols;
	}
}

void place_ship(char board[][NUM_COLS], int length, char ship_symbol, int row_start, int col_start, Dir direction)
{
	int index = 0;

	while (index < length)
	{
		if (direction == VERTICAL)
		{
			board[row_start + index][col_start] = ship_symbol;
		}
		else
		{
			board[row_start][col_start + index] = ship_symbol;
		}
		++index;
	}
}

void randomly_place_all_ships(char board[][NUM_COLS], int row_start, int col_start)
{
	Dir direction = 0;
	direction = get_direction();
	generate_start_point(5, direction, NUM_ROWS, NUM_COLS, &row_start, &col_start);
	place_ship(board, 5, 'C', row_start, col_start, direction);
	direction = get_direction();
	generate_start_point(4, direction, NUM_ROWS, NUM_COLS, &row_start, &col_start);
	place_ship(board, 4, 'B', row_start, col_start, direction);
	direction = get_direction();
	generate_start_point(3, direction, NUM_ROWS, NUM_COLS, &row_start, &col_start);
	place_ship(board, 3, 'R', row_start, col_start, direction);
	direction = get_direction();
	generate_start_point(3, direction, NUM_ROWS, NUM_COLS, &row_start, &col_start);
	place_ship(board, 3, 'S', row_start, col_start, direction);
	direction = get_direction();
	generate_start_point(2, direction, NUM_ROWS, NUM_COLS, &row_start, &col_start);
	place_ship(board, 2, 'D', row_start, col_start, direction);
	system("cls");
}

int select_who_starts_first(void)
{
	int num = 0;
	num = rand() % 2 + 1;
	if (num == 1) {
		return 1;
	}
	if (num == 2) {
		return 2;
	}
}

void get_target(int *target_x, int *target_y)
{
	int x = 0, y = 0;
	printf("\nEnter a target: ");
	scanf("%d%d", &x, &y);
	*target_x = x;
	*target_y = y;
	system("cls");
}

int check_shot(char board[][NUM_COLS], int *target_x, int *target_y, int *hit, int *miss)
{
	if (board[*target_x - 1][*target_y - 1] != '~')
	{
		printf("(%d,%d) is a hit!\n\n", *target_x, *target_y);
		*hit += 1;
		return 1;
	}
	else
	{
		printf("(%d,%d) is a miss.\n\n", *target_x, *target_y);
		*miss += 1;
		return 0;
	}
}

void update_board(char board[][NUM_COLS], int hit_or_miss, int *target_x, int *target_y)
{
	if (hit_or_miss == 1) // hit
	{
		board[*target_x - 1][*target_y - 1] = '*';
	}
	else // miss
	{
		board[*target_x - 1][*target_y - 1] = 'm';
	}
}

void computer_selects(char board[][NUM_COLS], int *comp_target_x, int *comp_target_y)
{
	int x = 0, y = 0;
	x = rand() % 10 + 1;
	y = rand() % 10 + 1;
	*comp_target_x = x;
	*comp_target_y = y;
}

void output_current_move(FILE *outfile, int player, int *target1, int *target2, int hit_or_miss)
{
	if (hit_or_miss == 1)
	{
		fprintf(outfile, "Player %d: (%d,%d) \"hit\"\n", player, *target1, *target2);
	}
	else
	{
		fprintf(outfile, "Player %d: (%d,%d) \"miss\"\n", player, *target1, *target2);
	}
}