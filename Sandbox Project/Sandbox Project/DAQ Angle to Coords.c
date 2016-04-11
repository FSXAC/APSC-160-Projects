// user plays with the arms on the DAQ simulator
// program converts voltage to coordinates

// imports
#include <stdio.h>
#include <stdlib.h>
#include <DAQlib.h>
#include <Windows.h>
#include <math.h>

// preprocessors
#define CLEAR system("cls")
#define PAUSE system("pause")
#define PI cos(-1);

// constants
const int DAQ_CHANNEL = 7;

// sensors
const int BASE = 0;
const int ELBOW = 1;

// equation constants
const double BASE_M = 0.06;
const double BASE_B = -150;
const double ELBOW_M = 0.06;
const double ELBOW_B = 30;

// length of arm
const double BASE_LENGTH = 8.5;
const double ELBOW_LENGTH = 8.5;

// debug
const int DEBUG = 1;

// function prototypes
int runArm(void);
double toAngle(double voltage);

// main program
int main(void) {

	// setup DAQ
	if (setupDAQ(DAQ_CHANNEL)) {
		runArm();
	}
	else {
		return 1;
	}
}

// main loop program for the DAQ
int runArm(void) {
	double base_voltage;
	double elbow_voltage;
	double base_angle;
	double elbow_relative_angle;
	double elbow_abs_angle;
	double x, y;

	while (continueSuperLoop()) {
		//Sleep(200);

		// read sensor data
		base_voltage = analogRead(BASE);
		elbow_voltage = analogRead(ELBOW);

		// convert voltage to angle
		base_angle = toAngle(base_voltage, BASE);
		elbow_relative_angle = toAngle(elbow_voltage, ELBOW);

		// convert relative elbow angle to abs angle
		elbow_abs_angle = elbow_relative_angle + base_angle - 180;

		// convert angles to coordinates
		x = BASE_LENGTH * cos(base_angle) + ELBOW_LENGTH * cos(elbow_relative_angle);
		y = BASE_LENGTH * sin(base_angle) + ELBOW_LENGTH * sin(elbow_relative_angle);

		// print sensor data to screen
		if (DEBUG) printf("Vb=%5.3f Ve=%5.3f\n"
			"Ab=%5.2f Ae=%5.2f Are=%5.2f\n"
			"x=%5.3f y=%5.3f",
			base_voltage, elbow_voltage, base_angle, elbow_relative_angle, elbow_abs_angle, x, y);
	}
}

/* This function converts a given voltage to relative angle
 * PARAM: double voltage - the voltage input
 * RETURN: double angle - the angle in radians
 */
double toAngle(double voltage, int sensor) {
	double angle;

	if (sensor == BASE) {
		// if the input voltage is base, use base equations
		angle = BASE_M * voltage * 1000 + BASE_B;
	}
	else {
		// use the elbow equation
		angle = ELBOW_M * voltage * 1000 + ELBOW_B;
	}
	
	// converts angle to radians
	angle = angle / 180 * PI;

	return angle;
}