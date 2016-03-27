// Excercise 1
// Statistics Calculation

// imports
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// constants
#define DATA_SIZE 1

// macros
#define square(x) x*x

// function prototypes
double getMean(double data[]);
double getSampleVar(double data[]);
double getStdDev(double data[]);
double getMin(double data[]);

int main(void) {
	/*double data[20] = {
		95, 100, 97.5, 100, 100, 
		70, 100, 
		82, 75, 68, 72, 76, 82
	};*/
	double data[] = { 1.0 };

	// find average
	printf("Average: %.3f\n", getMean(data));

	// find sample variance
	printf("Sample Variance: %.3f\n", getSampleVar(data));

	// find standard deviation
	printf("Standard Deviation: %.3f\n", getStdDev(data));

	// find minimum
	printf("Minimum: %.3f\n", getMin(data));

	// end of program
	system("pause");
	return 0;
}

/*
 * Computes and returns the average of all the numbers in an array
 * PARAM: data - the array
 */
double getMean(double data[]) {
	int index;
	double sum = 0;
	
	// sum up all the number in the list
	for (index = 0; index < DATA_SIZE; index++) {
		sum += data[index];
	}

	// return sum / number of entries (average)
	return (sum / DATA_SIZE);
}

/*
 * Computes the sample variance 
 * PARAM: data - the array
 */
double getSampleVar(double data[]) {
	double mean = getMean(data);
	double numerator = 0;
	int index;

	for (index = 0; index < DATA_SIZE; index++) {
		numerator += square((data[index] - mean));
	}

	return (numerator / (mean - 1));
}

/*
 * Computes the standard deviation by square rooting
 * the sample variance
 * PARAM: data - the array
 */
double getStdDev(double data[]) {
	return sqrt(getSampleVar(data));
}

/* 
 * Finds the smallest number in an array and return it
 * PARAM: data - the array
 */
double getMin(double data[]) {
	double min = data[0];
	int index;
	
	for (index = 0; index < DATA_SIZE; index++) {
		if (data[index] < min) {
			min = data[index];
		}
	}

	return min;
}