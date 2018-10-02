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

#include "equations.h"

int main(void)
{
	/****** THE FOLLOWING IS ADAPTED FROM ANDY'S EXAMPLE OF PA1 ******/
	int R1 = 0.0,	                /* Stores the first resistor value entered by the user for equation (6) */
		R2 = 0.0,                   /* Stores the second resistor value entered by the user for equation (6) */
		R3 = 0.0,                   /* Stores the third resistor value entered by the user for equation (6) */
		a = 0;	                 	/* Stores the value for the user inputted a coefficient in equation (8) */

	char plaintext_character = 0.0, /* Stores the character inputted by the user for use in equation (3) */
		encoded_character = 0.0;    /* Stores the result of the encoding from equation (3) */

	double mass = 0.0,              /* Stores the mass in grams of the value inputted by the user for equation (1) */
		acceleration = 0.0,         /* Stores the acceleration in m/s^2 of the value inputted by the user for equation (1) */
		force = 0.0,                /* Stores the result of equation (1) */
		radius = 0.0,               /* Stores the radius of the cylinder inputted by the user for equation (2) */
		height = 0.0,               /* Stores the height of the cylinder inputted by the user for equation (2) */
		volume_cylinder = 0.0,      /* Stores the result of equation (2) */
		mass1 = 0.0,                /* Stores the input mass1 for an object entered by the user for equation (4) */
		mass2 = 0.0,                /* Stores the input mass2 for an object entered by the user for equation (4) */
		distance = 0.0,             /* Stores the input distance entered by the user for equation (4) */
		force_gravity = 0.0,        /* Stores the result of the gravity force for equation (4) */
		theta = 0.0,                /* Stores the angle in radians inputted by the user for equation (5) */
		tan_theta = 0.0,			/* Stores the result of sin / cos for equation (5) */
		parallel_resistance = 0.0,  /* Stores the result of the total parallel resistance equation (6) */
		x1 = 0.0,					/* Stores the x1 value inputted by the user for equation (7) */
		x2 = 0.0,					/* Stores the x2 value inputted by the user for equation (7) */
		y1 = 0.0,					/* Stores the y1 value inputted by the user for equation (7) */
		y2 = 0.0,					/* Stores the y2 value inputted by the user for equation (7) */
		x = 0.0,                    /* Stores x value inputted by user for equation (8) */
		z = 0.0,                    /* Stores z value inputted by user for equation (8) */
		y = 0.0;                    /* Stores the result of the general equation (8) */
		/****** END OF ADAPTION ******/

	// 1. Newton's Second Law of Motion
	// Get mass and acceleration from user
	printf("Please enter the mass and acceleration (both floating-point values) for use in Newton's Second Law: ");
	scanf("%lf%lf", &mass, &acceleration);
	force = (double) calculate_newtons_2nd_law((double) mass, (double) acceleration);
	// Display the results
	printf("Newton's Second Law: force = mass * acceleration = %.2lf * %.2lf = %.2lf\n\n", mass, acceleration, force);

	// 2. Volume of a cylinder
	// Get radius and height from user
	printf("Please enter the radius and height (both floating-point values) for use in a volume of cylinder equation: ");
	scanf("%lf%lf", &radius, &height);
	volume_cylinder = (double) calculate_volume_cylinder((double) radius, (double) height);
	// Display the results
	printf("Volume of a cylinder: volume_cylinder = PI * radius^2 * height = %lf * %.2lf^2 * %.3lf = %.2lf\n\n", PI, radius, height, volume_cylinder);

	// 3. Character encoding
	// Get plaintext_character from user
	printf("Please enter a plaintext character for use in charcter encoding: ");
	scanf(" %c", &plaintext_character);
	encoded_character = (char) perform_character_encoding((char) plaintext_character);
	// Display the results
	printf("Character encoding: encoded_character = 10 + (plaintext_character - 'a') + 'A' = 10 + (%c - 'a') + 'A' = %c\n\n", plaintext_character, encoded_character);

	// 4. Gravity
	// Get mass1, mass2 and distance from the user
	printf("Please enter two masses and a distance (all floating-point values) for use in a gravity equation: ");
	scanf("%lf%lf%lf", &mass1, &mass2, &distance);
	force = (double) calculate_gravity_force((double) mass1, (double) mass2, (double) distance);
	// Display the results
	printf("Gravity: force = G * mass1 * mass2 / distance^2, where G is the gravitational constant with value 6.67 * 10^-11\n");
	printf("= %.13lf * %.2lf * %.2lf / %.2lf^2 = %.2lf\n\n", G, mass1, mass2, distance, force);

	// 5. Tangent
	// Get theta from user
	printf("Please enter a floating point, theta, for use in calculating tan(theta): ");
	scanf("%lf", &theta);
	tan_theta = (double) calculate_tangent((double) theta);
	// Display the results
	printf("Tangent: tan_theta = sin(theta) / cos(theta) = sin(%.2lf) / cos(%.2lf) = %.2lf\n\n", theta, theta, tan_theta);

	// 6. Total parallel resistance
	// Get resistors R1, R2, and R3 from user
	printf("Please enter 3 integers that represent resistor values for use in a total parallel resistance equation: ");
	scanf("%d%d%d", &R1, &R2, &R3);
	parallel_resistance = (double)calculate_parallel_resistance((int) R1, (int) R2, (int) R3);
	// Display results
	printf("Total parallel resistance: parallel_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3) = 1 / (1 / %d + 1 / %d + 1 / %d) = %.2lf\n\n", R1, R2, R3, parallel_resistance);

	// 7. Distance between two points
	// Get x1, y1, x2, y2 from user
	printf("Please enter two coordinate points (x1 y1 x2 y2) to be used in a distance equation: ");
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	distance = (double) calculate_distance_between_2pts((double) x1, (double) y1, (double) x2, (double) y2);
	// Display results
	printf("Distance between two points: distance = sqrt((x2 - x1)^2 + (y2 - y1)^2) = distance = sqrt((%.2lf - %.2lf)^2 + (%.2lf - %.2lf)^2) = %.2lf\n\n", x1, x2, y1, y2, distance);

	// 8. General equation
	// Get x, y and z
	printf("Please enter an integer a, then floating-points x, and z to be used in a general equation: ");
	scanf("%d%lf%lf", &a, &x, &z);
	y = (double) calculate_general_equation((int) a, (double) x, (double) z);
	// Display the results
	printf("General equation: y = (7 / 5) * x / a + z - a / (a %% 2) + PI = y = (7 / 5) * %.2lf / %d + %.2lf - %d / (%d %% 2) + PI = %.2lf\n\n", x, a, z, a, a, y);

	return 0;
}