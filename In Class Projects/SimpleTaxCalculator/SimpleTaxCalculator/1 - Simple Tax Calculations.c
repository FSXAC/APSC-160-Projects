/*
 * Author: Mansur	Date: 2016-01-08
 * purpose: User enters a price and the program outputs a cost including GST and PST
 */

#include <stdio.h>
#include <stdlib.h>

// global variables
#define PST 0.07
#define GST 0.05


// main unction
int main(void) {
	float price;
	float total;

	printf("Enter the cost of the article: ");
	scanf("%f", &price);

	total = price + (price * PST) + (price * GST);
	printf("The total cost is %.2f\n\n", total);

	system("pause");
	return 0;
}