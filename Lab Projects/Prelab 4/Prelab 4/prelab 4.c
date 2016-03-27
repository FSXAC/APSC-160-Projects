/* AUTHOR: MANSUR
 * DATE: 2016-02-15
 * PURPOSE: Prelab 4 stuff
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define PASCAL_MAX 12

int factorize(int number);
int n_choose_r(int n, int r);
int getInputInRange(int min, int max);

int main(void) {
	// exercise 1
	int number;
	printf("Enter number: ");
	scanf("%d", &number);
	printf("%d! = %d\n", number, factorize(number));

	// exercise 2
	int n, r;
	printf("Enter n: ");
	scanf("%d", &n);

	printf("Enter r: ");
	scanf("%d", &r);
	
	printf("C(%d, %d)=%d\n", n, r, n_choose_r(n, r));

	// exercise 3
	int min, max;
	printf("Enter min: ");
	scanf("%d", &min);

	printf("Emter max: ");
	scanf("%d", &max);

	printf("%d is in range of [%d, %d]\n", getInputInRange(min, max), min, max);

	system("pause");
	return 0;
}

// exercise 1
int factorize(int number) {
	int factorial = 1;
	if (number > 0) {
		for (; number > 0; number--){
			factorial *= number;
		}
	}
	return factorial;
}

// exercise 2
int n_choose_r(int n, int r) {
	return factorize(n) / (factorize(r) * factorize(n - r));	
}

// exercise 3
int getInputInRange(int min, int max) {
	int userInput;
	do {
		printf("Enter a value between %d and %d: ", min, max);
		scanf("%d", &userInput);
	} while (userInput < min || userInput > max && printf("Error: try again\n"));
	return userInput;
}