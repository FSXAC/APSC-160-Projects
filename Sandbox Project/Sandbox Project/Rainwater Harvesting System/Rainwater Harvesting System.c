// this is a almost complete simulation of APSC 101 module 7 project
// this do not have automatic optimization finding (for now, user inputs parameters)

// imports
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "constants.h"

// preprocessors
#define PAUSE system("pause")
#define MAX_STRING_LENGTH 81
#define SPEC_FILE_LEGNTH 24

// constants

// convenient constants
const char READ[] = "r";
const char WRITE[] = "w";

// specifications file dir
const char SPEC_FDIR[] = "Rainwater Harvesting System\\specifications.cfg";

// debug
const int DEBUG = 1;

// global specifications table
int specifications[SPEC_FILE_LEGNTH];

// global satisfaction table
int satisfaction[6];

// function prototypes
void calculateSatisfaction(int table[], int consumption, double relative_cost, int environmental, int maintenance, int on_demand_Q, int reliability);

// main function
int main(void) {
	// file reading
	FILE* spec_file = fopen(SPEC_FDIR, READ);
	char parameter[MAX_STRING_LENGTH];
	int parameter_value;
	int read_index = 0;

	// Read specifications from file
	// check that the file is opened correctly
	if (spec_file == NULL) {
		printf("specifications file failed to open\n");
		PAUSE;
		return 0;
	}
	else {
		// read file
		while (fscanf(spec_file, "%s %d", &parameter, &parameter_value) == 2) {
			if (DEBUG) printf("%s is set to %d\n", parameter, parameter_value);

			// store value to array
			specifications[read_index] = parameter_value;
			read_index++;
		}

		printf("End of file\n");

		// close file
		fclose(spec_file);
	}

	PAUSE;
	return 1;
}