/* AUTHOR: MANSUR HE
* DATE: 2015-02-07
* PURPOSE: user enters a number, print that number of starts out as a row
*/

#include <stdio.h>
#include <stdlib.h>

void printRowStar(int length);

int main(void) {
	int length = 0;
	
	while (length != -1) {
		printf("Enter length: ");
		scanf("%d", &length);

		printRowStar(length);
	}

	system("pause");
	return 0;
}

void printRowStar(int length) {
	for (; length > 0; length--) {
		printf("*");
	}
	printf("\n");
}