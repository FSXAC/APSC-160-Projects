/* Author: Mansur He
 * Date: 2016-02-07
 * Purpose: Use functions to calculate the cost to ship a paracel depending on its weight
 */

// ignore warnings
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define LOW_KG 2.0
#define MED_KG 4.0
#define LOW_FLAT 3.0
#define HIGH_FLAT 4.5
#define MED_RATE 0.75
#define HIGH_RATE 0.95

// function prototypes
double calcCost(double weight) {
	double cost = LOW_FLAT;

	// if weight is above low but below med
	if (weight > LOW_KG && weight <= MED_KG) {
		cost += MED_RATE * (weight - LOW_KG);
	} else if (weight > MED_KG) {
		cost = HIGH_FLAT;
		cost += HIGH_RATE * (weight - MED_KG);
	}

	return cost;
}

int main(void) {
	while (1) {
		double weightKgs, cost;

		printf("Enter the weight of the paracel: ");
		scanf("%lf", &weightKgs);

		cost = calcCost(weightKgs);

		printf("Cost of shipping: %.2f\n", cost);
	}
	system("pause");
	return 0;
}