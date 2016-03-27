// DAQ intro program

#include <stdio.h>
#include <stdlib.h>
#include <DAQlib.h>

// preprocessors
#define AND &&
#define NOT !
#define OR ||
#define IS == 

// program logic constants
const int ON = 1;
const int OFF = 0;
const int TRUE = 1;
const int FALSE = 0;

// DAQ channel constants
// LEDs
const int LED_0 = 0;
const int LED_1 = 1;
const int LED_2 = 2;

// switches
const int SWITCH_0 = 0;
const int SWITCH_1 = 1;

// function that is going to loop
void loop(void);

// function that controls all three LEDs at once
void changeLED(int led_0, int led_1, int led_2);

int main(void) {
	// setupnum: 0 for hardware, 1-7 for simulators
	int setupNum;

	printf("Enter channel for DAQ initialization: ");
	scanf("%d", &setupNum);

	// setup daq
	if (setupDAQ(setupNum)) {
		// start the program loop after setup
		printf("DAQ initialized successfully\n");
		loop();
		printf("DAQ loop ended by the user\n");
	}
	else {
		// quits if setup failed
		printf("DAQ has failed to initialize . . .\n");
	}

	system("pause");
	return 0;
}


/*
 * Function to perform work once DAQ is initialised properly
 */
void loop(void) {
	int isSwitch_0;
	int isSwitch_1;

	while (continueSuperLoop())
	{
		// read signals
		isSwitch_0 = digitalRead(SWITCH_0);
		isSwitch_1 = digitalRead(SWITCH_1);

		// AND statements
		if (isSwitch_0 AND NOT isSwitch_1) {
			changeLED(ON, OFF, OFF);
		}
		else if (NOT isSwitch_0 AND isSwitch_1) {
			changeLED(OFF, ON, OFF);
		}
		else if (isSwitch_0 AND isSwitch_1) {
			changeLED(OFF, OFF, ON);
		}
		else {
			changeLED(OFF, OFF, OFF);
		}
	}
} 

/*
 * Function to write digital signals to all three LEDs
 */
void changeLED(int led_0, int led_1, int led_2) {
	digitalWrite(LED_0, led_0);
	digitalWrite(LED_1, led_1);
	digitalWrite(LED_2, led_2);
}