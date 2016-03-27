/* AUTHOR: MANSUR HE
 * DATE: 2016-02-07
 * PURPOSE: User enters number, function calculates the factorial
 */

#include <stdio.h>
#include <stdlib.h>

int factorial(int num);

int main(void) {
	int num;
	printf("Enter the number for factorization: ");
	scanf("%d", &num);

	printf("%d!=%li\n", num, factorial(num));

	system("pause");
	return 0;
}

long factorial(int num) {
	long numF = 1;
	while (num > 0) {
		numF *= num--;
	}

	return numF;
}