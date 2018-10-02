/**********************************************************************************************
* Programmer: Trenton Fales                                                                   *
* Class: CptS 121 Fall 2017; Lab Section 5                                                    *
* Programming Assignment: 2                                                                   *
* Date: September 11, 2017                                                                    *
*                                                                                             *
* ****************** THE FOLLOWING IS ADAPTED FROM ANDY'S EXAMPLE OF PA1 ******************** *
*                                                                                             *
* Description: This program evaluates a variety of equations that first prompts               *
*              the user for inputs to the equations and evaluates them based on those inputs  *
*              using functions.                                                               *
*                                                                                             *
*              Inputs:  R1, R2, R3, a, plaintext_char, mass, acceleration, radius, height,    *
*                       mass1, mass2, distance, theta, x1, y1, x2, y2, x, z                   *
*              Constants: PI, G                                                               *
*              Computations: See relevant forumulas                                           *
*              Outputs: force, volume_cylinder, encoded_charcter, tan_theta,                  *
*                       parallel_resistance, distance, y                                      *
*                                                                                             *
* Relevant Formulas:                                                                          *
*                                                                                             *
*          (1)Newton's 2nd Law: force_newton = mass_newton * acceleration                     *
*          (2)Volume of a cylinder: volume_cylinder = PI * radius^2 * cylinder_height         *
*          (3)Character encoding: encoded_character = 10 + (plaintext_character - 'a') + 'A'  *
*          (4)Gravity: force = G * mass1 * mass2 / distance^2                                 *
*          (5)Tangent: tan_theta = sin (theta) / cos (theta)                                  *
*          (6)Total parallel resistance: parallel_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3) *
*          (7)Distance between two points: distance_points = square root of ((x1 - x2)^2 +    *
*                                                                            (y1 - y2)^2)     *
*          (8)General equation:  y = (7 / 5) * x / a + z - a / (a % 2) + PI                   *
**********************************************************************************************/

#include "equations.h"               // Import header file

/*
* Function: calculate_newtons_2nd_law(double mass, double acceleration)
* Date: September 11, 2017
* Date Last Modified: September 11, 2017
* Description: Calculates a force in newtons based on a mass and acceleration inputted by the user
* Input Parameters: Mass, acceleration
* Returns: A force in newtons
* Preconditions: Mass and acceleration entered in by the user as a double.
* Postconditions: Force in Newtons is returned.
*/

double calculate_newtons_2nd_law(double mass, double acceleration)
{
	double force = 0.0;
	// Calculate force
	force = mass * acceleration;
	return force;
}

/*
* Function: calculate_volume_cylinder(double radius, double height)
* Date: September 11, 2017
* Date Last Modified: September 11, 2017
* Description: Calculates the volume of a cylinder based on a radius and height inputted by the user
* Input Parameters: Radius, height
* Returns: The volume of a cylinder (volume_cylinder)
* Preconditions: Cylinder radius and height entered in by the user as a double.
* Postconditions: The volume of the cylinder is returned.
*/

double calculate_volume_cylinder(double radius, double height)
{
	double volume_cylinder = 0.0;
	// Calculate volume
	volume_cylinder = PI * radius * radius * height;
	return volume_cylinder;
}

/*
* Function: perform_character_encoding(char plaintext_character)
* Date: September 11, 2017
* Date Last Modified: September 11, 2017
* Description: Calculates an encoded character based on a character inputted by the user
* Input Parameters: A plaintext character (plaintext_character)
* Returns: The encoded character (encoded_character)
* Preconditions: A plaintext character is entered in by the user.
* Postconditions: An encoded character is returned.
*/

char perform_character_encoding(char plaintext_character)
{
	char encoded_character = 0;
	// Calculate encoded character
	encoded_character = 10 + (plaintext_character - 'a') + 'A';
	return encoded_character;
}

/*
* Function: calculate_gravity_force(double mass1, double mass2, double distance)
* Date: September 11, 2017
* Date Last Modified: September 11, 2017
* Description: Calculates a gravitational force based on two masses and their distance between each other inputted by the user
* Input Parameters: Two masses (mass1, mass2) and a distance
* Returns: Gravitational force (force)
* Preconditions: Two masses and a distance are entered in by the user as doubles.
* Postconditions: Gravitational force is returned.
*/

double calculate_gravity_force(double mass1, double mass2, double distance)
{
	double force = 0.0;
	// Calculate gravity
	force = G * mass1 * mass2 / (distance * distance);
	return force;
}

/*
* Function: calculate_tangent(double tan_theta)
* Date: September 11, 2017
* Date Last Modified: September 11, 2017
* Description: Calculates the tangent of a theta inputted by the user
* Input Parameters: Theta
* Returns: Tangent of theta (tan_theta)
* Preconditions: Theta entered in by the user as a double.
* Postconditions: Tangent of inputted theta is returned.
*/

double calculate_tangent(double theta)
{
	double tan_theta = 0.0;
	// Calculate tangent(theta)
	tan_theta = sin(theta) / cos(theta);
	return tan_theta;
}

/*
* Function: calculate_parallel_resistance(int R1, int R2, int R3)
* Date: September 11, 2017
* Date Last Modified: September 11, 2017
* Description: Calculates a parallel resistance based on three resistances inputted by the user
* Input Parameters: Three resistances (R1, R2, R3)
* Returns: The parallel resistance (parallel_resistance)
* Preconditions: Three resistor values are entered in by the user as integers.
* Postconditions: The parallel_resistance is returned.
*/

double calculate_parallel_resistance(int R1, int R2, int R3)
{
	double parallel_resistance = 0.0;
	// Calculate total parallel resistance
	parallel_resistance = (double)1 / (1 / (double)R1 + 1 / (double)R2 + 1 / (double)R3);
	return parallel_resistance;
}

/*
* Function: calculate_distance_between_2pts(double x1, double y1, double x2, double y2)
* Date: September 11, 2017
* Date Last Modified: September 11, 2017
* Description: Calculates a distance between two points inputted by the user
* Input Parameters: Two coordinates (x1, y1, x2, y2)
* Returns: Distance (distance)
* Preconditions: Two coordinates (4 points) are entered in by the user as doubles. 
* Postconditions: The distance between the two points is returned.
*/

double calculate_distance_between_2pts(double x1, double y1, double x2, double y2)
{
	double distance = 0.0;
	// Calculate distance
	distance = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
	return distance;
}

/*
* Function: calculate_general_equation(int a, double x, double z)
* Date: September 11, 2017
* Date Last Modified: September 11, 2017
* Description: Calculates a value (y) of a general equation based on an integer (a) and two doubles (x, z) inputted by the user
* Input Parameters: An integer (a) and two doubles (x, z)
* Returns: The solution (y)
* Preconditions: An integer and two double values are entered in by the user.
* Postconditions: A double value is returned.
*/

double calculate_general_equation(int a, double x, double z)
{
	double y = 0.0;
	// Calculate y for the general equation y = (7 / 5) * x / a + z - a / (a % 2) + PI
	y = ((double)7 / 5) * x / a + z - a / (a % 2) + PI;
	return y;
}