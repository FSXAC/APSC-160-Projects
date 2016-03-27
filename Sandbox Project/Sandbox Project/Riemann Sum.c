// calculates the riemann sum using arrays with given size

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define length(x) (sizeof(x) / sizeof((x)[0]))

double inlf(char *msg[]);
int ind(char *msg[]);

double calcRS(double y_list[], int increment, int n, double delta_x, int startIndex);

double leftRS(double y_list[], int increment, int n, double delta_x);
double rightRS(double y_list[], int increment, int n, double delta_x);
double middleRS(double y_list[], int increment, int n, double delta_x);
double trapezoidRS(double y_list[], int increment, int n, double delta_x);
double simpsonsRS(double y_list[], int increment, int n, double delta_x);
double simpsonsRSNEW(double y_list[], int arraySize, double delta_x);

int main(void) {
	double lower, upper, increment;
	int dataSize, subintervalSize;
	double *x_list, *y_list;
	int doOperations;

	while (1) {
		doOperations = 1;

		lower = inlf("\n\n\nEnter lower bound: ");

		do {
			upper = inlf("Enter upper bound: ");
		} while (upper == lower && printf("Upper cannot equal to lower bound.\n"));

		do {
			increment = inlf("Enter increment (delta x): ");
		} while (increment == 0 && printf("increment cannot be 0.\n"));

		// calculate data size
		subintervalSize = ((upper - lower) / increment);
		dataSize = subintervalSize + 1;

		// create array
		x_list = (double *)malloc(sizeof(double)*dataSize);
		y_list = (double *)malloc(sizeof(double)*dataSize);

		// fill the x_list array with preset values
		// lower bound
		x_list[0] = lower;
		printf("\nf(x) when x = %.3f", lower);
		y_list[0] = inlf(": ");
		
		// all values in between
		for (int i = 1; i < dataSize - 1; i++) {
			x_list[i] = lower + i * increment;
			printf("\nf(x) when x = %.3f", x_list[i]);
			y_list[i] = inlf(": ");
		}

		// upper bound
		x_list[dataSize - 1] = upper;
		printf("\nf(x) when x = %.3f", upper);
		y_list[dataSize - 1] = inlf(": ");

		// print the array to the screen
		// x list
		printf("\nx list: \n");
		for (int i = 0; i < dataSize; i++) {
			printf("%.3f ", x_list[i]);
		}

		// y list
		printf("\ny list: \n");
		for (int i = 0; i < dataSize; i++) {
			printf("%.3f ", y_list[i]);
		}

		// ask for operation
		while (doOperations) {
			// ask for n
			int sum_n;

			do {
				sum_n = ind("\n\n\nEnter valid N for riemann sums (0 for new): ");
				if (sum_n == 0) {
					doOperations = 0;
					break;
				}
			} while (subintervalSize % sum_n);	
			if (!doOperations) {
				break;
			}

			// print menu
			printf("[1]\tLeft Riemann Sum\n"
				"[2]\tRight Riemann Sum\n");

			// eligible for middle rule if n is smaller than subinterval size
			if (sum_n != subintervalSize) {
				printf("[3]\tMiddle Riemann Sum\n");
			}
			else {
				printf("\n");
			}

			printf("[4]\tTrapezoid Rule\n");

			// eligible for simpsons rule if n is even and satisfies for Mn
			if ((sum_n % 2 == 0) && (sum_n != subintervalSize)) {
				printf("[5]\tSimpsons Rule\n\n");
			}
			else {
				printf("\n");
			}

			int operationInput = ind("Select: ");

			int fincrement = (subintervalSize / sum_n);
			double fdelta_x = (subintervalSize / sum_n * increment);
			double approxArea = -1;

			// do different things based on input
			switch (operationInput) {
			case 1:
				// perform left riemann sum
				approxArea = leftRS(y_list, fincrement, sum_n, fdelta_x);
				break;
			case 2:
				// perform right riemann sum
				approxArea = rightRS(y_list, fincrement, sum_n, fdelta_x);
				break;
			case 3:
				// perform middle riemann sum
				approxArea = middleRS(y_list, fincrement, sum_n, fdelta_x);
				break;
			case 4:
				// perform trapezoid rule
				approxArea = trapezoidRS(y_list, fincrement, sum_n, fdelta_x);
				break;
			case 5:
				// perform simpson's rule
				approxArea = simpsonsRSNEW(y_list, dataSize, fdelta_x);
				break;
			default:
				// invalid input
				printf("Invalid input!\n");
				break;
			}

			printf("Area = %.4f", approxArea);
		}

		// free up memory
		free(x_list);
		free(y_list);
	}
}

double inlf(char *msg[]) {
	double returnVal;
	printf("%s", msg);
	scanf("%lf", &returnVal);
	return returnVal;
}

int ind(char *msg[]) {
	int returnVal;
	printf("%s", msg);
	scanf("%d", &returnVal);
	return returnVal;
}

double leftRS(double y_list[], int increment, int n, double delta_x) {
	int index = 0;
	return calcRS(y_list, increment, n, delta_x, index);
}

double rightRS(double y_list[], int increment, int n, double delta_x) {
	return calcRS(y_list, increment, n, delta_x, increment);
}

double middleRS(double y_list[], int increment, int n, double delta_x) {
	int index = increment / 2;
	return calcRS(y_list, increment, n, delta_x, index);
}

double trapezoidRS(double y_list[], int increment, int n, double delta_x) {
	int indexLeft = 0;
	int indexRight = increment;
	double leftArea = calcRS(y_list, increment, n, delta_x, indexLeft);
	double rightArea = calcRS(y_list, increment, n, delta_x, indexRight);
	return (leftArea + rightArea) / 2;
}

double simpsonsRS(double y_list[], int increment, int n, double delta_x) {
	int indexLeft = 0;
	int indexRight = increment;
	int indexMid = increment / 2;
	double trapezoidArea = trapezoidRS(y_list, increment, n, delta_x, indexLeft);
	double middleArea = middleRS(y_list, increment, n, delta_x, indexLeft);
	return (trapezoidArea + 2 * middleArea) / 3;
}

double simpsonsRSNEW(double y_list[], int arraySize, double delta_x) {
	double area = 0;
	for (int i = 0; i < arraySize; i++) {
		if ((i == 0) && (i == arraySize - 1)) {
			area += y_list[i];
		}
		else {
			if (i % 2) {
				area += 4 * y_list[i];
			}
			else {
				area += 2 * y_list[i];
			}
		}
	}
	return (area * delta_x / 3);
}

/*
* PARAM: y_list: the list of f(x)
* PARAM: increment: how much subintervals moved each time
* PARAM: n: how many times
* PARAM: delta_x: width of the area
* PARAM: startIndex: where FOR loop starts (0 for Left, increment for right, 
*                    increment / 2 for middle)
*/
double calcRS(double y_list[], int increment, int n, double delta_x, int startIndex) {
	double totalArea = 0, subArea;
	int index = startIndex;

	for (int i = 0; i < n; i++) {
		// calculate the area of that section
		subArea = delta_x * y_list[index];
		totalArea += subArea;
		printf("subarea %d = %.3f\n", i + 1, subArea);

		index += increment;
	}

	return totalArea;
}