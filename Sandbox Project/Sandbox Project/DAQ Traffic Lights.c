// DAQ traffic lights

// imports
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <DAQlib.h>

// constants
// components
const int LEDS[] = { 0, 1, 2, 3, 4, 5 };

// logic
const int ON = 1;
const int OFF = 0;

// function prototypes
void setLED(int state);
void controlLED(int duration, int warning);
void trafficLights(void);

// main function
int main(void) {
	int setupNum;

	// setup daq
	printf("Enter setup num: ");
	scanf("%d", &setupNum);

	if (setupDAQ(setupNum)) {
		printf("DAQ initialzed successfully\n");

		// loop
		while (continueSuperLoop()) {
			trafficLights();
		}
	}
	else {
		printf("DAQ failed to initalize\n");
	}

	return 0;
}

void setLED(int state) {
	// 4 states and 6 LEDs
	int stateTable[4][6] = { 
		{ON, OFF, OFF, OFF, OFF, ON}, 
		{OFF, ON, OFF, OFF, OFF, ON},
		{OFF, OFF, ON, ON, OFF, OFF},
		{OFF, OFF, ON, OFF, ON, OFF}
	};

	// turns on and off the LED
	for (int led = 0; led < 6; led++) {
		digitalWrite(LEDS[led], stateTable[state][led]);
	}
}

void controlLED(int duration, int warning) {
	setLED(0);
	Sleep(duration);
	setLED(1);
	Sleep(warning);
	setLED(2);
	Sleep(duration);
	setLED(3);
	Sleep(warning);
}

void trafficLights() {
	controlLED(5000, 3000);
}