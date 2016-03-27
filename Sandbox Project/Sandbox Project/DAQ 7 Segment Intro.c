// DAQ 7 segment intro program

#include <stdio.h>
#include <stdlib.h>
#include <DAQlib.h>
#include <Windows.h>

// preprocessors
#define AND &&
#define NOT !
#define OR ||
#define IS == 
#define ISNOT !=

// program logic constants
const int ON = 1;
const int OFF = 0;

// DAQ channel constants
// 7 segment lookup table
const int SEGMENTS[20] = {
	252, 96, 218, 242, 102, 182, 62, 224, 254, 230,
	253, 97, 219, 243, 103, 183, 63, 225, 255, 231
};

// switches
const int SWITCH_0 = 0;
const int SWITCH_1 = 1;

// function that is going to loop
void loop(void);

void writeDigit(int digit, int position);
void writeNumber(int number);
void clearDisplay(void);

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
	int counter = 0;
	int isSwitch0, isSwitch1;

	while (continueSuperLoop()) {
		isSwitch0 = digitalRead(SWITCH_0);
		isSwitch1 = digitalRead(SWITCH_1);
		
		// pauses the clock
		if (NOT isSwitch0) {
			writeNumber(counter);
			counter++;
		}
		else {
			printf("Clock is paused\n");
		}

		// reset clock
		if (isSwitch1) {
			counter = 0;	
			clearDisplay();
		}

		Sleep(1000);
	}
}

/*
 * Writes the digit to the DAQ display
 */
void writeDigit(int digit, int position) {
	displayWrite(SEGMENTS[digit], position);
}

/*
 * This resets the displays
 */
void clearDisplay(void) {
	printf("Resetting display\n");
	for (int pos = 0; pos < 8; pos++) {
		displayWrite(0, pos);
	}
}

/*
 * Writes a number to the DAQ segment display
 */
void writeNumber(int number) {
	int digit, num = number;
	int position = 0;

	while (num != 0) {
		digit = num % 10;
		writeDigit(digit, position);
		num /= 10;
		position++;
	}
}