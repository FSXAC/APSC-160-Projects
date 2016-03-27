/* NAME: Mansur He
 * STUDENT ID: 44638154
 * LAB SECTION: L2F
 * UBC EMAIL: m.he@alumni.ubc.ca
 * 
 * PROGRAM PURPOSE: Make functions that print out triangles and
 * series of triangles out with any size.
 *
 * NOTE: I used symbolic constants for the characters 'X' and
 * 'O' as it makes writing and reading the code slightly
 * easier.
 */

#define _CRT_SECURE_NO_WARNINGS

// import libraries
#include <stdio.h>
#include <stdlib.h>

// symbolic constants
#define X 'X'
#define O 'O'

// function prototypes
void printChars(int nChars, char printChar);
void printTri(int size, char printChar);
void printPic(int size);

// main function
int main(void) {
	// TESTING the functions manually
	// Part 1
	printf("Part 1:\n");
	printTri(10, '#');

	// Part 2
	printf("\n\nPart 2:\n");
	printPic(10);

	// end of program
	system("pause");
	return 0;
}

/* Prints the given character the given number of times
 * on the screen.
 * Parameter: nChars - the number of character to print
 * Parameter: printChar - the character to print
 * Return: void
 */
void printChars(int nChars, char printChar) {
	int countChars = 0;

	while (countChars < nChars) {
		printf("%c ", printChar);
		countChars++;
	}
}

/* Prints an upright triangle with a given number as height 
 * on the screen.
 * Parameter: size - the height of the triangle
 * Parameter: printChar - the character to print
 * Return: void
 */
void printTri(int size, int printChar) {
	int row = 1;
	
	// size of the row is increased by 1 as it moves down
	for ( ; row <= size; row++) {
		printChars(row, printChar);
		printf("\n");
	}
}

/* Prints several triangle with decreasing size. The char
 * that makes the triangle toggle between X and O.
 * Parameter: size - the height of the largest triangle
 * Return: void
 */
void printPic(int size) {
	int n_triangle;
	int isCurrentCharX = 0;
	char currentChar = O;

	// decreasing in triangle size as n-th triangle is printed
	for (n_triangle = size; n_triangle > 0; n_triangle--) {
		printTri(n_triangle, currentChar);
		
		// toggles between O and X
		if (isCurrentCharX) {
			currentChar = O;
			isCurrentCharX = 0;
		} else {
			currentChar = X;
			isCurrentCharX = 1;
		}
	}
}