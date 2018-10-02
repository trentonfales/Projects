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

// Guard Code
#ifndef FUNCTIONS_H

#define FUNCTIONS_H 

#include <stdio.h>  // Import standard library
#include <stdlib.h> // rand(), srand()
#include <time.h>	// Import time

// Recommended Functions
void print_game_rules(void);
double get_bank_balace(void);
double get_wager_amount(double balance);
int check_wager_amount(double wager, double balance);
int roll_die(void);
int calculate_sum_dice(int die1_Value, int die2_value);
int is_win_loss_or_point(int sum_dice);
int is_point_loss_or_neither(int sum_dice, int point_value);
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);
void chatter_messages(int number_rolls);

// Added functions
void display_menu(void);
int get_option(void);
int validate_option(int option);
int determine_option_validity(void);
double wager_invalid(int check_wager, double wager, double balance);
int determine_roll(void);
void exit_play(char play, double balance);
void check_play_input_invalid(char play);
void check_balance_validity(double balance, char play);

#endif