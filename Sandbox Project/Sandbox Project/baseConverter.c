/* AUTHOR: MANSUR HE
 * DATE: 2016-02-15
 * PURPOSE: Converts a number from base 10 to another base
 */

#include <stdio.h>

int main(void) {
	const char baseDigits[16] = {
		'0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	int unconvertedNumber;
	int convertedNumber[64];
	int nextDigit, base, indexRef = 0;

	// user input for the number in base 10
	printf("Enter number in base 10: ");
	scanf("%d", &unconvertedNumber);
	printf("Enter base to convert to: ");
	scanf("%d", &base);

	// check if base is inside a valid range
	if (base > 1 && base <= 16) {

		// conversion using a loop
		// using do loop so that at least 1 digit is converted even if user inputs 0
		do {
			convertedNumber[indexRef] = unconvertedNumber % base;
			indexRef++;
			unconvertedNumber = unconvertedNumber / base;
		} while (unconvertedNumber != 0);

		// display the array in reverse
		printf("The number in base %d: ", base);

		// using for loop and indexRef 
		for (--indexRef; indexRef >= 0; --indexRef) {
			nextDigit = convertedNumber[indexRef];
			printf("%c", baseDigits[nextDigit]);
		}

		printf("\n");
	}
	else {
		printf("Base entered is not valid.\n");
	}

	system("pause");
	return 0;
}
