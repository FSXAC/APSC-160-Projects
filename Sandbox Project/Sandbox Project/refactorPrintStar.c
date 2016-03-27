/*
* Author: MANSUR HE
* Date: 2016-02-07
* Purpose: Prompts the user for the size of a square then draws
* a pattern consisting of a square of asterisks followed
* by a square of periods.
*/

#include <stdio.h>
#include <stdlib.h>

/* parameters:size
 * return: none
 */
void printLine(int size);
void printSquare(int size);

int main(void) {
	int size;
	printf("Enter size of square: ");
	scanf("%d", &size);

	printSquare(size);

	system("pause");
	return 0;
}

void printLine(int size) {
	int count = size;
	while (count-- > 0) {
		printf("*");
	}
	while (count++ < size) {
		printf(".");
	}
	printf("\n");
}

void printSquare(int size) {
	int count = 0;
	while (count++ < size) {
		printLine(size);
	}
}
