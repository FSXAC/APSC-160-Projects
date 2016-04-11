// user plays with the arms on the DAQ simulator
// program converts voltage to coordinates

// imports
#include <stdio.h>
#include <stdlib.h>
#include <DAQlib.h>
#include <Windows.h>

// preprocessors
#define CLEAR system("cls")
#define PAUSE system("pause")

// constants
const int DAQ_CHANNEL = 7;

// sensors
const int SENSOR_0 = 0;
const int SENSOR_1 = 1;

// debug
const int DEBUG = 1;

// function prototypes
int runArm(void);

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
	double sensor_0_reading;
	double sensor_1_reading;

	while (continueSuperLoop()) {
		// read sensor data
		sensor_0_reading = analogRead(SENSOR_0);
		sensor_1_reading = analogRead(SENSOR_1);

		// filter out non sense data
		if (sensor_0_reading < 0) {
			sensor_0_reading = 0;
		}

		if (sensor_1_reading < 0) {
			sensor_1_reading = 0;
		}
		
		// print sensor data to screen
		if (DEBUG) {
			printf("S0: %.3f\tS1:%.3f\n", sensor_0_reading, sensor_1_reading);
		}
	}
}