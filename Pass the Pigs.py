# -*- coding: utf-8 -*-
"""
Programmer: Trenton Fales
Class: CptS 111-02, Spring 2017
Programming Assignment #4
3/22/17

Description: This program runs a program that simulates the game "Pass the Pigs" in which
a player tosses two toy pigs that can land in a number of different positions. Depending on
which position the pigs lands in determines the number of points the player will get for that
turn. The winning score is determined by input from the user and the game ends once a player
exceeds the winning score.
"""

def display_game_rules():
    '''
    Prints out the rules of Pass the Pigs.
    '''
    print("Welcome to Pass the Pigs! The rules of the game are straightforward.")
    print("A player tosses two toy pigs, each of which has a dot on one side.")
    print("Each pig can land in one of six positions:")
    print("\n1. On its side")
    print("   A. Side with dot down")
    print("   B. Side with dot up")
    print("2. Razorback (on its back)")
    print("3. Trotter (on all four feet)")
    print("4. Snouter (balanced on front two feet and its snout)")
    print("5. Leaning jowler (balanced on one foot, snout, and ear)")
    print("   • Note: This is extremely rare!")
    print("\nAfter the pigs have come to rest, the player gains or loses points")
    print("based on the way the pigs land! This program will keep track of your")
    print("points for you. Good luck!")
    pass
    
def get_valid_winning_score():
    '''
    Prompts the users for a winning score between 0 and 100 and validates that score.
    '''
    print()
    score = int(input("Please enter the number of points representing a winning score (between 0 and 100): "))
    # Determines if the inputted score is valid or not.
    validity = is_valid_winning_score(score)
    # When the score is valid, the loop breaks and returns the input.
    while validity == True:
        print("That's a good score!")
        return score
        break
    #When the score is invalid, the loop repeats until a valid score is inputted, then returned.
    while validity == False:
        print("Invalid score. Please try again")
        score == -10
        print()
        score = int(input("Please enter the number of points representing a winning score (between 0 and 100): "))
        if score > 0 and score <= 100:
            print("That's a good score!")
            print()
            return score
            break
        
def is_valid_winning_score(score):
    '''
    Checks to see if the entered winning score is an integer > 0 and <= 100.
    '''
    if score > 0 and score <= 100:
        return True
    else:
        return False
            
def roll_pig():
    '''
    Roles one pig.
    '''
    import random
    total = 0
    for roll in range(1):
        num = random.randint(0,100)
        total += num
    # The following code is used to adjust for the frequency of each roll.
    if num > 0 and num <= 35:
        return 'SIDE'
    elif num > 35 and num <= 65:
        return 'SIDE-D'
    elif num > 65 and num <= 87:
        return 'RZR'
    elif num > 87 and num <= 96:
        return 'TROT'
    elif num > 96 and num <= 99:
        return 'SNOUT'
    else:
        return 'LEAN'
        
def determine_roll_result(pig1, pig2):
    '''
    Determines the roll result based on the two pigs' positions and returns a string representing the roll result.
    '''
    print()
    if pig1 == 'SIDE' and pig2 == 'SIDE':
        print("Sider--1 point!")
        return 'SIDER'
    elif pig1 == 'SIDE-D' and pig2 == 'SIDE-D':
        print("Sider--1 point!")
        return 'SIDER'
    elif pig1 == 'RZR' and pig2 == 'RZR':
        print("Double razorback! Not too shabby--20 points!")
        return 'DBL-RAZR'
    elif pig1 == 'TROT' and pig2 == 'TROT':
        print("Double trotter, way to go--20 points!")
        return 'DBL-TROT'
    elif pig1 == 'SNOUT' and pig2 == 'SNOUT':
        print("Double snouter, that's really impressive--40 points!!!")
        return 'DBL-SNOUT'
    elif pig1 == 'LEAN' and pig2 == 'LEAN':
        print("DOUBLE LEANING JOWLERRRRRRRRR--60 points!!!!!!!!!!!!!!")
        return 'DBL-LEAN'
    elif pig1 == 'SIDE' and pig2 == 'SIDE-D':
        chatter_message1()
        return 'PIGOUT'
    elif pig1 == 'SIDE-D' and pig2 == 'SIDE':
        chatter_message1()
        return 'PIGOUT'
    else:
        print("Mixed combo.")
        if pig1 == 'SIDE' and pig2 == 'RZR' or pig1 == 'RZR' and pig2 == 'SIDE':
            print("You got a sider and a razorback! 5 points.")
        elif pig1 == 'SIDE' and pig2 == 'TROT' or pig1 == 'TROT' and pig2 == 'SIDE':
            print("You got a sider and a trotter! 5 points.")
        elif pig1 == 'SIDE' and pig2 == 'SNOUT' or pig1 == 'SNOUT' and pig2 == 'SIDE':
            print("You got a sider and a snouter! 10 points.")
        elif pig1 == 'SIDE' and pig2 == 'LEAN' or pig1 == 'LEAN' and pig2 == 'SIDE':
            print("You got a sider and a leaning jowler! 15 points.")
        elif pig1 == 'SIDE-D' and pig2 == 'RZR' or pig1 == 'RZR' and pig2 == 'SIDE-D':
            print("You got a sider and a razorback! 5 points.")
        elif pig1 == 'SIDE-D' and pig2 == 'TROT' or pig1 == 'TROT' and pig2 == 'SIDE-D':
            print("You got a sider and a trotter! 5 points.")
        elif pig1 == 'SIDE-D' and pig2 == 'SNOUT' or pig1 == 'SNOUT' and pig2 == 'SIDE-D':
            print("You got a sider and a snouter! 10 points.")
        elif pig1 == 'SIDE-D' and pig2 == 'LEAN' or pig1 == 'LEAN' and pig2 == 'SIDE-D':
            print("You got a sider and a leaning jowler! 15 points.")
        elif pig1 == 'RZR' and pig2 == 'TROT' or pig1 == 'TROT' and pig2 == 'RZR':
            print("You got a razorback and a trotter! 10 points.")
        elif pig1 == 'RZR' and pig2 == 'SNOUT' or pig1 == 'SNOUT' and pig2 == 'RZR':
            print("You got a razorback and a snouter! 15 points.")
        elif pig1 == 'RZR' and pig2 == 'LEAN' or pig1 == 'LEAN' and pig2 == 'RZR':
            print("You got a razorback and a leaning jowler! 20 points.")
        elif pig1 == 'TROT' and pig2 == 'SNOUT' or pig1 == 'SNOUT' and pig2 == 'TROT':
            print("You got a trotter and a snouter! 15 points.")
        elif pig1 == 'TROT' and pig2 == 'LEAN' or pig1 == 'LEAN' and pig2 == 'TROT':
            print("You got a trotter and a leaning jowler!! 20 points.")
        elif pig1 == 'SNOUT' and pig2 == 'LEAN' or pig1 == 'LEAN' and pig2 == 'SNOUT':
            print("You got a snouter and a leaning jowler!!! 25 points.")
        return 'MIXED'
    
def calculate_total_roll_points(pig1, pig2, roll_result):
    '''
    Determines the total points rolled based on the both pigs' positions.
    '''
    points = 0
    if roll_result == 'SIDER':
        return 1
    elif roll_result == 'DBL-RAZR':
        return 20
    elif roll_result == 'DBL-TROT':
        return 20
    elif roll_result == 'DBL-SNOUT':
        return 40
    elif roll_result == 'DBL-LEAN':
        return 60
    elif roll_result == 'PIGOUT':
        return 0
    elif roll_result == 'MIXED':
        if pig1 == 'RZR' or pig2 == 'RZR':
            points += 5
        if pig1 == 'TROT' or pig2 == 'TROT':
            points += 5
        if pig1 == 'SNOUT' or pig2 == 'SNOUT':
            points += 10
        if pig1 == 'LEAN' or pig2 == 'LEAN':
            points += 15
        return points
        
def take_turn(p1_score, p2_score, score):
    '''
    Play's a single turn.
    '''
    pig1 = roll_pig()
    pig2 = roll_pig()
    roll_result = determine_roll_result(pig1, pig2)
    roll_points = calculate_total_roll_points(pig1, pig2, roll_result)
    if roll_points >= 15:
        chatter_message3()
    return roll_points
    
def chatter_message1():
    '''
    First of three "chatter" messages.
    '''
    print("Sorry, you rolled a PigOut! You get 0 points for this turn and it's the next player's turn. :(")
    print("Please select 'No' when asked to keep rolling. Cheating is bad karma!")
    
def chatter_message2():
    '''
    Second of three "chatter" messages.
    '''
    print()
    print("   Good move.")
    
def chatter_message3():
    '''
    Third of three "chatter" messages.
    '''
    print()
    print("   That's a lot of points you don't want to lose, time to cash them in!")
    print()
    
def menu_options(p1_score, p2_score, score):
    '''
    Determines whether or not a player wants to continue their turn.
    '''
    keep_going = str(input("Would you like to continue rolling? 'Yes' or 'No': "))
    return keep_going
    
def main():
    '''
    Drives the program.
    '''
    display_game_rules()
    score = get_valid_winning_score()
    p1_score = 0
    p2_score = 0
    while True:
        if p2_score > score:
            break
        print()
        print("Player 1's turn.")
        p1_score += take_turn(p1_score, p2_score, score)
        print("You have %d points total!" % (p1_score))
        keep_going = menu_options(p1_score, p2_score, score)
        if keep_going == 'No' or keep_going == 'no':
            chatter_message2()
        while keep_going == 'Yes' or keep_going == 'yes':
            p1_score += take_turn(p1_score, p2_score, score)
            print("You have %d points total!" % (p1_score))
            if p1_score >= score:
                print("Congratulations!!! You won!!!")
                break
            keep_going = menu_options(p1_score, p2_score, score)
            if keep_going == 'No' or keep_going == 'no':
                chatter_message2()
        if p1_score > score:
            break
        print()
        print("Player 2's turn.")
        p2_score += take_turn(p1_score, p2_score, score)
        print("You have %d points total!" % (p2_score))
        keep_going = menu_options(p1_score, p2_score, score)
        if keep_going == 'No' or keep_going == 'no':
            chatter_message2()
        while keep_going == 'Yes' or keep_going == 'yes':
            p2_score += take_turn(p1_score, p2_score, score)
            print("You have %d points total!" % (p2_score))
            if p2_score >= score:
                print("Congratulations!!! You won!!!")
                break
            keep_going = menu_options(p1_score, p2_score, score)
            if keep_going == 'No' or keep_going == 'no':
                chatter_message2()
 
main()
    




