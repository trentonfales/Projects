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

#include <stdio.h>              // Import standard library
#include <math.h>               // Import mathematical library

#define PI 3.141592653          // Mathematical value pi used for relevant equations
#define G 0.000000000067        // Gravitational constant used for relevant equations

double calculate_newtons_2nd_law(double mass, double acceleration);
double calculate_volume_cylinder(double radius, double height);
char perform_character_encoding(char plaintext_character);
double calculate_gravity_force(double mass1, double mass2, double distance);
double calculate_tangent(double theta);
double calculate_parallel_resistance(int r1, int r2, int r3);
double calculate_distance_between_2pts(double x1, double y1, double x2, double y2);
double calculate_general_equation(int a, double x, double z);