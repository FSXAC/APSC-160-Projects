// Experimenting with string inputs and string manipulations

#include <stdio.h>
#include <stdlib.h>

#define PAUSE system("pause");

// function prototype
void input(char stringArray[]);

// main function
int main(void) {
	char myString[81];

	// get user input for string
	printf("Enter a string: ");
	input(myString);

	// print the string user inputted
	printf("Your string is: %s\n", myString);

	PAUSE;
	return 0;
}

void input(char stringArray[]) {
	char character;
	int i = 0;

	// loops through each character in the line using 'getchar()' which scans a single character at a time
	do {
		character = getchar();
		stringArray[i] = character;
		i++;

		// keep looping until the end
	} while (character != '\n');

	// adds a null character at the end - every string needs this
	stringArray[i - 1] = '\0';
}