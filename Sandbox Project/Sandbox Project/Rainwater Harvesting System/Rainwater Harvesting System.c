// this is a almost complete simulation of APSC 101 module 7 project
// this do not have automatic optimization finding (for now, user inputs parameters)

// import custom header lib
#include "constants.h"

// preprocessors
#define PAUSE system("pause")
#define MAX_STRING_LENGTH 81
#define SPEC_FILE_LEGNTH 24

// constants
#define SATIS_ATTRIBUTES 6

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
double satisfactions[SATIS_ATTRIBUTES];

// function prototypes
void getSatisfaction(double s_table[], double consumption, double relative_cost, double environmental, double maintenance, double on_demand_Q, double reliability);
double getOverallSatisfaction(double s_table[]);

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

	getSatisfaction(satisfactions, specifications[SPEC_COMSUMPTION], 59.22, 1, 16.8, 29, 356.2);
	getOverallSatisfaction(satisfactions);

	PAUSE;
	return 1;
}

/* Calculate all six aspects of satisfaction*/
void getSatisfaction(double s_table[], double consumption, double relative_cost, double environmental, double maintenance, double on_demand_Q, double reliability) {
	// calculates based on a formula
	double
		satis_consumption,
		satis_cost,
		satis_environment,
		satis_maintenance,
		satis_ODF,
		satis_reliability;

	// consumption
	if (consumption < SATISFACTION_MIN[S_CONSUMP]) {
		s_table[S_CONSUMP] = 0;
	}
	else if (consumption > SATISFACTION_MAX[S_CONSUMP]) {
		s_table[S_CONSUMP] = 1;
	}
	else {
		s_table[S_CONSUMP] = 0.5 * (1 - cos((consumption - SATISFACTION_MIN[S_CONSUMP]) / (SATISFACTION_MAX[S_CONSUMP] - SATISFACTION_MIN[S_CONSUMP]) * PI));
	}
	if (DEBUG) printf("getSatisfaction(): COM: %.4f%%\n", s_table[S_CONSUMP] * 100);

	// relative cost
	if (relative_cost < SATISFACTION_MIN[S_COST]) {
		s_table[S_COST] = 0;
	}
	else if (relative_cost > SATISFACTION_MAX[S_COST]) {
		s_table[S_COST] = 1;
	}
	else {
		s_table[S_COST] = 0.5 * (1 + cos((relative_cost - SATISFACTION_MIN[S_COST]) / (SATISFACTION_MAX[S_COST] - SATISFACTION_MIN[S_COST]) * PI));
	}
	if (DEBUG) printf("getSatisfaction(): CST: %.4f%%\n", s_table[S_COST] * 100);

	// environmental impact
	s_table[S_ENV] = environmental;
	if (DEBUG) printf("getSatisfaction(): ENV: %.4f%%\n", s_table[S_ENV] * 100);

	// maintenance
	if (maintenance < SATISFACTION_MIN[S_MAINTEN]) {
		s_table[S_MAINTEN] = 0;
	}
	else if (maintenance > SATISFACTION_MAX[S_MAINTEN]) {
		s_table[S_MAINTEN] = 1;
	}
	else {
		s_table[S_MAINTEN] = 0.5 * (1 + cos((maintenance - SATISFACTION_MIN[S_MAINTEN]) / (SATISFACTION_MAX[S_MAINTEN] - SATISFACTION_MIN[S_MAINTEN]) * PI));
	}
	if (DEBUG) printf("getSatisfaction(): MNT: %.4f%%\n", s_table[S_MAINTEN] * 100);

	// on demand flowrate
	if (on_demand_Q < SATISFACTION_MIN[S_ODF]) {
		s_table[S_ODF] = 0;
	}
	else if (on_demand_Q > SATISFACTION_MAX[S_ODF]) {
		s_table[S_ODF] = 1;
	}
	else {
		s_table[S_ODF] = 0.5 * (1 - cos((on_demand_Q - SATISFACTION_MIN[S_ODF]) / (SATISFACTION_MAX[S_ODF] - SATISFACTION_MIN[S_ODF]) * PI));
	}
	if (DEBUG) printf("getSatisfaction(): ODF: %.4f%%\n", s_table[S_ODF] * 100);

	// reliability
	if (reliability < SATISFACTION_MIN[S_RELIAB]) {
		s_table[S_RELIAB] = 0;
	}
	else if (reliability > SATISFACTION_MAX[S_RELIAB]) {
		s_table[S_RELIAB] = 1;
	}
	else {
		s_table[S_RELIAB] = 0.5 * (1.0 - cos((reliability - SATISFACTION_MIN[S_RELIAB]) / (SATISFACTION_MAX[S_RELIAB] - SATISFACTION_MIN[S_RELIAB]) * PI));
	}
	if (DEBUG) printf("getSatisfaction(): REL: %.4f%%\n", s_table[S_RELIAB] * 100);
}

/* Calculates a weighted overall satisfaction score */
double getOverallSatisfaction(double s_table[]) {
	double o_satisfaction = 0;

	for (int i = 0; i < SATIS_ATTRIBUTES; i++) {
		o_satisfaction += SATISFACTION_WEIGHT[i] * s_table[i];
		if (DEBUG) printf("getOverallSatisfaction(): pass %d, S=%.4f%%\n", i, o_satisfaction * 100);
	}
	
	return o_satisfaction;
}