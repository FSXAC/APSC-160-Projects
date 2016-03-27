// Riemann Sum Easy Calculator

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void rs(int rsType);
double inputd(char* msg[]);
double left(double y_i, double delta_x);
double right(double y_j, double delta_x);
double middle(double y_m, double delta_x);
double trapezoid(double y_i, double y_j, double delta_x);
double simpson(double y_i, double y_j, double delta_x);

int main(void) {
	while (1) {
		// CHANGE CALCULATION TYPE
		rs(3);
	}

	system("pause");
	return 0;
}

void rs(int rsType) {
	double y_i, y_j, y_m, delta_x;
	double sum;

	delta_x = inputd("delta x:");

	if (rsType == 1) {
		// left
		y_i = inputd("y (left): ");
		sum = left(y_i, delta_x);
	}
	else if (rsType == 2) {
		// right
		y_j = inputd("y (right): ");
		sum = right(y_j, delta_x);
	}
	else if (rsType == 3) {
		// middle
		y_m = inputd("y (middle): ");
		sum = middle(y_m, delta_x);
	}
	else if (rsType == 4) {
		// trapezoid
		y_i = inputd("y (left): ");
		y_j = inputd("y (right): ");
		sum = trapezoid(y_i, y_j, delta_x);
	}
	else if (rsType == 5) {
		// simpson
		y_i = inputd("y (left): ");
		y_j = inputd("y (right): ");
		y_m = inputd("y (middle): ");
		sum = simpson(y_i, y_m, y_j, delta_x);
	}

	printf("sum: %f\n\n\n", sum);
}

double left(double y_i, double delta_x) {
	return y_i*delta_x;
}

double right(double y_j, double delta_x) {
	return y_j*delta_x;
}

double middle(double y_m, double delta_x) {
	return y_m*delta_x;
}

double trapezoid(double y_i, double y_j, double delta_x) {
	return ((y_i + y_j) / 2)*delta_x;
}

double simpson(double y_i, double y_m, double y_j, double delta_x) {
	return (trapezoid(y_i, y_j, delta_x) + 2 * middle(y_m, delta_x)) / 2;
}

double inputd(char* msg[]) {
	double returnVal;
	printf("%s", msg);
	scanf("%lf", &returnVal);
	return returnVal;
}