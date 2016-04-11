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