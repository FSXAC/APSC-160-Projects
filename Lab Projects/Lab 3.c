/* NAME: MANSUR HE
 * STUDENT ID: 44638154
 * LAB SECTION: L2F
 * UBC EMAIL: m.he@alumni.ubc.ca
 * PURPOSE: User enters a number, the program prints out accordingly
 * to part 1-4 on the assignment sheet
 *
 * NOTE: I used FOR loops to do the iterative part since the size of the 
 * loop is KNOWN and in this case, a FOR loop is more appropriate
 */

// ignore warnings
#define _CRT_SECURE_NO_WARNINGS

// imports
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void partOne(int num);
void partTwo(int num);
void partThree(int num);
void partFour(int num);

// main function
int main(void) {
	int num;
	
	// ask for num
	printf("Enter a number in interval [1, 15]: ");
	scanf("%d", &num);

	// if num not in range(1, 15): ask again
	while (num > 15 || num < 1) {
		printf("Error: a value between 1 and 15 inclusively expected. "
			   "Try again.\n");
		printf("Enter a number in interval [1, 15]: ");
		scanf("%d", &num);
	}

	// once the num is correct:
	// partOne(num); **** Part one not in the final results
	partTwo(num);
	partThree(num);
	partFour(num);

	// end of program
	system("pause");
	return 0;
}

// functions
void partOne(int num) {
	// part 1 - simple just print out the number
	printf("You entered: %d\n", num);
}

void partTwo(int num) {
	// setup variable for the 1D grid
	int number;

	// part 2 - print out the countdown from user num
	printf("\nThis is the output of part 2:\n");

	// NOTE: I use FOR loop here because it is much more compact
	for (number = num ; number > 0; number--) {
		printf("%d ", number);
	}
	
	// end, and print new line
	printf("\n");
}

void partThree(int num) {
	// setup variables for 2D grid
	int row;
	int number;

	// part 3 - prints out 2D grid with height being num
	printf("\nThis is the output of part 3:\n");

	// loop for the row (goes down)
	for (row = 0; row < num; row++) {
		
		// loop for the column (goes right)
		for (number = num; number > 0; number--) {
			printf("%d ", number);
		}

		// prints new line
		printf("\n");
	}
}

void partFour(int num) {
	// part four - prints out 2D grid like part 3 except a new row starts
	// with a increment of 1

	// setup variables for the 2D grid
	int row;
	int number;

	printf("\nThis is the output of part 4:\n");

	// loop for the row (goes down)
	for (row = 0; row < num; row++) {

		// loop for the column (goes right)
		// starting value of first number of new row = num + row number
		for (number = num + row; number > row; number--) {
			printf("%d ", number);
		}

		// prints out new line
		printf("\n");
	}
}