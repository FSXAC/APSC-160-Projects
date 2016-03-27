/* Author: Mansur He
 * Student ID: 44638154
 * Lab section: L2F
 * UBC E-mail: m.he@alumni.ubc.ca
 *
 * Purpose of program: 
 * User enters specific gravity and number of barrels of crude purchased,
 * program converts specific gravity to API gravity and output the amount
 * of crude oil purchased in cubic meters as well as whether if the crude
 * oil is light, medium, or heavy depending on the API value.
 *
 * !!!! NOTE !!!!
 * In the output section, the assignment sheet did not specify what
 * what happens when encoutering a NEGATIVE API gravity value. So in this
 * case, I made an extra boolean "if/else" branch that outputs "negative
 * value" at the end if the value of API gravity is less than 0.
 * (The T.A. advised me to make a note like this)
 */


// ignore scanf warning
#define _CRT_SECURE_NO_WARNINGS

// import libraries
#include <stdio.h>
#include <stdlib.h>

// constants
#define BARREL_TO_METER_CUBED 0.15891
#define CRUDE_LIGHT_CUTOFF 31.1
#define CRUDE_MEDIUM_CUTOFF 22.3

// main function
int main(void) {
	// variables
	double gravity_specific, gravity_API, amountMCubed;
	int barrels; 

	// user input 
	printf("Enter specific gravity of crude oil (kg/m^3): ");
	scanf("%lf", &gravity_specific);

	printf("Enter number of barrels of crude oil purchased: ");
	scanf("%d", &barrels);

	// API calculations
	gravity_API = 141.5 / (gravity_specific / 1000) - 131.5;

	// Amount calculations
	amountMCubed = barrels * BARREL_TO_METER_CUBED;

	// output
	if (gravity_API > CRUDE_LIGHT_CUTOFF) {
		// if more than 31.1 degrees API
		printf("You purchased %.2f cubic metres of Light Crude\n", 
			   amountMCubed);

	} else if (gravity_API > CRUDE_MEDIUM_CUTOFF &&
			   gravity_API <= CRUDE_LIGHT_CUTOFF) {
		// if more than 22.3 but not more than 31.1
		printf("You purchased %.2f cubic metres of Medium Crude\n",
			   amountMCubed);

	} else if (gravity_API < 0) {
		// negative API gravity (!!! REFER TO NOTES ABOVE !!!)
		printf("You purchased %.2f cubic metres of Crude"
			"(API gravity is negative)\n", amountMCubed);
	
	} else {
		// anything else OR negative numbers
		printf("You purchased %.2f cubic metres of Heavy Crude\n",
			   amountMCubed);
	}

	// end of program
	system("pause");
	return 0;
}