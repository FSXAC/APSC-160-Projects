/* Author: Mansur He
 * Student Number: 44638154
 * Lab Section: L2F
 * Date: 2016-01-09
 * Purpose: Asks the user to enter a name and outputs 
 * a welcome message in the console
 */ 

// Standard Setup
#include <stdio.h>
#include <stdlib.h>

// Ignores scanf warning in console
#define _CRT_SECURE_NO_WARNINGS

// Main function
int main(void) {

	// name variable (string)
	char name[20];

	// asks for the name and outputs a welcome msg
	printf("Please enter your name: ");
	scanf("%s", &name);
	printf("\nHello! And welcome, %s, to APSC 160!", name);
	printf("\n*cue John William music*\n\n");

	// wait for user to close
	system("pause");
	return 0;
}