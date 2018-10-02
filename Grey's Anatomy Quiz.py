# -*- coding: utf-8 -*-
"""
Programmer: Trenton Fales
Class: CptS 111-02, Spring 2017
Programming Assignment #3
2/28/17

Description: This program runs a 10 question Grey's Anatomy fan quiz. There
are three different types of questions: multiple choice, numeric response,
and Boolean. This program starts with a brief introduction followed by 
numbered questions 1-10. The question informs the user of the type of input
it's looking to receive, gathers that input, then informs the user
whether that choice is correct or not. Finally, this program records the
user's score and informs the user of that score followed by a comment
based on how well they did.
"""

print("Are you a Grey's Anatomy fan? Let's find out, shall we?")

def q1():
    '''
    This function asks the first question in the Grey's Anatomy quiz, 
    gets an input, and returns a point if the question is correct while 
    returning zero points if the question is incorrect.
    '''
    # Inserted blank print statement to create spacing between questions.
    print()
    # Numeric response question.
    # Question source: https://www.buzzfeed.com/maevem2/the-hardest-greys-anatomy-quiz-you-will-ever-take-amq7
    print("1) How many hours do the interns work in their first shift? Please enter an integer.")
    ans = int(input())
    # 48 is the correct answer, therefore they will be given a point.
    if ans == 48:
        print("That's correct! Way to go!")
        return 1
    # Any number aside from 48 will receive zero points.
    else:
        print("Not quite. The interns work 48 hours in their first shift.")
        return 0
    
def q2():
    '''
    This function asks the second question in the Grey's Anatomy quiz, 
    gets an input, and returns a point if the question is correct while 
    returning zero points if the question is incorrect.
    '''
    # Inserted blank print statement to create spacing between questions.
    print()
    # Numeric response question.
    # Question source: https://www.buzzfeed.com/maevem2/the-hardest-greys-anatomy-quiz-you-will-ever-take-amq7
    print("2) How many residents joined Meredith, Cristina, Alex, and Izzie's class from the merger? Please enter an integer.")
    ans = int(input())
    # 4 is the correct answer, therefore they will be given a point.
    if ans == 4:
        print("Nice!")
        return 1
    # Any number aside from 4 will receive zero points.
    else:
        print("Yikes. The correct answer is 4.")
        return 0
    
def q3():
    '''
    This function asks the third question in the Grey's Anatomy quiz, 
    gets an input, and returns a point if the question is correct while 
    returning zero points if the question is incorrect.
    '''
    # Inserted blank print statement to create spacing between questions.
    print()
    # Numeric response question.
    # Question source: https://www.buzzfeed.com/maevem2/the-hardest-greys-anatomy-quiz-you-will-ever-take-amq7
    print("3) How many people died in the hospital shooting? Please enter an integer.")
    ans = int(input())
    # 11 is the correct answer, therefore they will be given a point.
    if ans == 11:
        print("Good job!")
        return 1
    # Any number aside from 11 will receive zero points.
    else:
        print("Nope! The correct answer is 11 people.")
        return 0
        
def q4():
    '''
    This function asks the fourth question in the Grey's Anatomy quiz, 
    gets an input, and returns a point if the question is correct while 
    returning zero points if the question is incorrect.
    '''
    # Inserted blank print statement to create spacing between questions.
    print()
    # Boolean question.
    print("4) The one they call 'McSteamy' is Derek Shepherd, true or false? Please enter 1 for True or 0 for False.")
    ans = int(input())
    # False is the correct answer so the user will recieve a point for entering '0'
    if ans == 0:
        print("Excellent!")
        return 1
    # An input of 1 (True) will be rewarded zero points.
    else:
        print("Wrong. 'McSteamy' is Mark Sloan.")
        return 0
        
def q5():
    '''
    This function asks the fifth question in the Grey's Anatomy quiz, 
    gets an input, and returns a point if the question is correct while 
    returning zero points if the question is incorrect.
    '''
    # Inserted blank print statement to create spacing between questions.
    print()
    # Boolean question.
    # Question source: https://www.buzzfeed.com/maevem2/the-hardest-greys-anatomy-quiz-you-will-ever-take-amq7
    print("5) Mark Sloan and Derek Shepherd have a fist fight over Addison Montgomery in Season 5, true or false? Please enter 1 for True and 0 for False.")
    ans = int(input())
    # False is the correct answer so the user will receive a point for entering '0'
    if ans == 0:
        print("Awesome!")
        return 1
    # An input of 1 (True) will be rewarded zero points.
    else:
        print("Not quite. Mark Sloan and Derek Shepherd fight over Lexie Grey.")
        return 0
        
def q6():
    '''
    This function asks the sixth question in the Grey's Anatomy quiz, 
    gets an input, and returns a point if the question is correct while 
    returning zero points if the question is incorrect.
    '''
    # Inserted blank print statement to create spacing between questions.
    print()
    # Multiple choice question.
    # Question source: https://www.buzzfeed.com/maevem2/the-hardest-greys-anatomy-quiz-you-will-ever-take-amq7
    print("6) Why was Cristina hospitalized in Season 2? Please enter a character A-E.")
    print("A) Post Traumatic Stress Disorder")
    print("B) Ectopic Pregnancy")
    print("C) Drowning")
    print("D) Intestical Rupture")
    print("E) Cardiac Arrhythmia")
    ans = str(input())
    if ans == 'B':
        print("Superb!")
        return 1
    else:
        print("Incorrect. The right answer is B) Ectopic Pregnancy")
        return 0
    
def q7():
    '''
    This function asks the seventh question in the Grey's Anatomy quiz, 
    gets an input, and returns a point if the question is correct while 
    returning zero points if the question is incorrect.
    '''
    # Inserted blank print statement to create spacing between questions.
    print()
    # Multiple choice question.
    # Question source: https://www.buzzfeed.com/maevem2/the-hardest-greys-anatomy-quiz-you-will-ever-take-amq7
    print("7) What did Izzie Stevens name her daughter? Please enter a character A-E.")
    print("A) Hannah")
    print("B) Cierra")
    print("C) Emma")
    print("D) Katie")
    print("E) Sarah")
    ans = str(input())
    if ans == 'E':
        print("Marvelous!")
        return 1
    else:
        print("Yikes. The correct answer E) Sarah")
        return 0
        
def q8():
    '''
    This function asks the eighth question in the Grey's Anatomy quiz, 
    gets an input, and returns a point if the question is correct while 
    returning zero points if the question is incorrect.
    '''
    # Inserted blank print statement to create spacing between questions.
    print()
    # Multiple choice question.
    # Question source: https://www.buzzfeed.com/maevem2/the-hardest-greys-anatomy-quiz-you-will-ever-take-amq7
    print("8) Who tells Meredith she is dead in the 'afterlife' after she drowns in Season 3? Please enter a character A-E.")
    print("A) Denny Duquette")
    print("B) Ellis Grey")
    print("C) Dylan Young")
    print("D) Bonnie Crasnoff")
    print("E) Nurse Fallon")
    ans = str(input())
    if ans == 'A':
        print("Outstanding!")
        return 1
    else:
        print("Not quite. The correct answer is A) Denny Duquette")
        return 0
    
def q9():
    '''
    This function asks the ninth question in the Grey's Anatomy quiz, 
    gets an input, and returns a point if the question is correct while 
    returning zero points if the question is incorrect.
    '''
    # Inserted blank print statement to create spacing between questions.
    print()
    # Multiple choice question.
    # Question source: https://www.buzzfeed.com/maevem2/the-hardest-greys-anatomy-quiz-you-will-ever-take-amq7
    print("9) What was the real name of Alex's facial reconstruction patient, and eventual girlfriend, in Season 4? Please enter a character A-E.")
    print("A) Olivia")
    print("B) Ava")
    print("C) Joanna")
    print("D) Rebecca")
    print("E) Jenn")
    ans = str(input())
    if ans == 'D':
        print("Wonderful!")
        return 1
    else:
        print("Nope! The correct answer is D) Rebecca")
        return 0
        
def q10():
    '''
    This function asks the tenth question in the Grey's Anatomy quiz, 
    gets an input, and returns a point if the question is correct while 
    returning zero points if the question is incorrect.
    '''
    # Inserted blank print statement to create spacing between questions.
    print()
    # Multiple choice question.
    # Question source: https://www.buzzfeed.com/maevem2/the-hardest-greys-anatomy-quiz-you-will-ever-take-amq7
    print("10) Who is Season 5's 'Patient X' given to the interns as a diagnostic exercise? Please enter a character A-E.")
    print("A) Lexie Grey")
    print("B) George O'Malley")
    print("C) Izzie Stevens")
    print("D) Mark Sloan")
    print("E) Alex Karev")
    ans = str(input())
    if ans == 'C':
        print("Magnificent!")
        return 1
    else:
        print("Wrong. The correct answer is C) Izzie Stevens")
        return 0
    
def main():
    '''
    Executes the program.
    '''
    # num1 - num10 will be used to calculate the user's score.
    num1 = q1()
    num2 = q2()
    num3 = q3()
    num4 = q4()
    num5 = q5()
    num6 = q6()
    num7 = q7()
    num8 = q8()
    num9 = q9()
    num10 = q10()
    # Calculation of the user's score.
    total = num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9 + num10
    if total >= 7:
        print()
        print("You scored %d questions correctly. Wow! That's really impressive! Congratulations :)" % (total))
    elif total >= 4:
        print()
        print("You scored %d questions correctly, that's not too shabby." % (total))
    else:
        print()
        print("You scored %d questions correctly, you must not be a very big fan." % (total))
        
main()
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    