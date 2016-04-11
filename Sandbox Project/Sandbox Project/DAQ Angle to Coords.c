// user plays with the arms on the DAQ simulator
// program converts voltage to coordinates

// imports
#include <stdio.h>
#include <stdlib.h>
#include <DAQlib.h>
#include <Windows.h>
#include <math.h>

// preprocessors
#define NOT !
#define OR ||
#define CLEAR system("cls")
#define PAUSE system("pause")
#define PI cos(-1);

// constants
const int DAQ_CHANNEL = 7;

// sensors
const int BASE = 0;
const int ELBOW = 1;

// switches
const int SWITCH_0 = 0;

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
double radian(double degrees);

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
	double base_angle_rad;
	double elbow_relative_angle;
	double elbow_abs_angle;
	double elbow_abs_angle_rad;
	double x, y;
	double min_x, max_x, min_y, max_y;
	int mode;
	int calibration_flag = 1;

	while (continueSuperLoop()) {
		// sleep
		//Sleep(300);

		// mode switching
		mode = digitalRead(SWITCH_0);

		// read sensor data
		base_voltage = analogRead(BASE);
		elbow_voltage = analogRead(ELBOW);

		// filter out negative voltages
		if (base_voltage <= 0 OR elbow_voltage <= 0) {
			if (DEBUG) printf("Error: arm position not possible in real life\n");
		}
		else {
			// convert voltage to angle
			base_angle = toAngle(base_voltage, BASE);
			elbow_relative_angle = toAngle(elbow_voltage, ELBOW);

			// convert relative elbow angle to abs angle
			elbow_abs_angle = elbow_relative_angle + base_angle - 180;

			// converts angles to radians
			base_angle_rad = radian(base_angle);
			elbow_abs_angle_rad = radian(elbow_abs_angle);

			// convert angles to coordinates
			x = BASE_LENGTH * cos(base_angle_rad) + ELBOW_LENGTH * cos(elbow_abs_angle_rad);
			y = BASE_LENGTH * sin(base_angle_rad) + ELBOW_LENGTH * sin(elbow_abs_angle_rad);

			// check if the calibration mode is on or not
			if (NOT mode) {
				// finds maximum and minimum of x and y
				if (calibration_flag) {
					min_x = x;
					min_y = y;
					max_x = x;
					max_y = y;
					calibration_flag = 0;
				}
				else {
					// set bounds for x
					if (x < min_x) {
						min_x = x;
					}
					else if (x > max_x) {
						max_x = x;
					}

					// set bounds for y
					if (y < min_y) {
						min_y = y;
					}
					else if (y > max_y) {
						max_y = y;
					}
				}
			}
			else {
				// calibration mode is off - normalize coordinates
				x = (x - min_x) / (max_x - min_x);
				y = (y - min_y) / (max_y - min_y);
			}

			// print sensor data to screen
			if (DEBUG) {
				printf("\nVb=%5.3f Ve=%5.3f\n"
					"Ab=%5.2f Are=%5.2f Ae=%5.2f\n"
					"x=%5.3f y=%5.3f\n",
					base_voltage, elbow_voltage, base_angle, elbow_relative_angle, elbow_abs_angle, x, y);
				if (NOT mode) {
					printf("minx=%5.3f miny=%5.3f\nmaxx=%5.3f maxy=%5.3f\n",
						min_x, min_y, max_x, max_y);
				}
			}
		}
	}
}

/* This function converts a given voltage to relative angle
 * PARAM: double voltage - the voltage input
 * RETURN: double angle - the angle in degrees
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

	return angle;
}

/* Converts degrees into radians*/
double radian(double degrees) {
	return degrees / 180 * PI;
}