/* NAME: MANSUR HE
 * DATE: 2016-03-30
 * STUDENT ID: 44638154
 * SECTION: L2F
 * E-MAIL: m.he@alumni.ubc.ca
 *
 * 7 Segment Scrolling text display - DAQ module
 *
 * NOTE: characters that are unabled to be displayed are
 * substutuded by a dot
 */

// imports
#include <stdio.h>
#include <stdlib.h>
#include <DAQlib.h>
#include <string.h>
#include <Windows.h>

// ignore warning
#define _CRT_SECURE_NO_WARNINGS

// preprocessors
#define NOT !
#define AND &&
#define OR ||

// symbolic constants
#define MAX_CHAR_SPACE 81
#define DISPLAYS 8

// macros
#define PAUSE system("pause")

// constants
// ASCII
const int DIGIT_START = '0';
const int DIGIT_END = '9';
const int ALPHA_UPPER_START = 'A';
const int ALPHA_UPPER_END = 'Z';
const int ALPHA_LOWER_START = 'a';
const int ALPHA_LOWER_END = 'z';

// DAQ
const int DAQ_CHANNEL = 4;

// switches constants
const int SWITCH0 = 0;
const int SWITCH1 = 1;

// scrolling speed
const int DELAY_FAST = 500;
const int DELAY_SLOW = 1000;

// scrolling direction
const int LEFT = 0;
const int RIGHT = 1;

// string presets
const char PRESET_1[] = "PRESET STRING";
const char PRESET_2[] = "FLIGHT 77 IS DELAYED";

// function prototypes
void scrollMessage(void);
void shiftArray(int direction, char string[], char newCharacter);
void displayChar(char character, int position);
void displayString(char string[]);
void input(char string[]);

// main function
int main(void) {
	char userString[MAX_CHAR_SPACE];

	// display the options for string display
	printf("Select a string to display:\n"
		"[1]\t\"%s\"\n[2]\t\"%s\"\nEnter: ", PRESET_1, PRESET_2);


	// ask user for string input
	printf("Enter a message (80 characters max.): ");
	input(userString);

	// start DAQ
	if (setupDAQ(DAQ_CHANNEL)) {
		scrollMessage(userString);
	}
	else {
		printf("Error: DAQ could not be initialized successfully.\n");
		PAUSE;
		return 0;
	}
}

/* Main looping function
 * PARAM: msg - the message to be displayed
 * RETURN: void
 */
void scrollMessage(char msg[]) {
	// length of message
	int msgLength = strlen(msg);

	// array of current characters on display
	char onDisplay[DISPLAYS] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	char newChar;

	// msg index
	int msgIndex = 0;

	// switch states
	int switch_0;
	int switch_1;

	// speed
	int delay;

	// direction
	int direction;

	while (continueSuperLoop()) {
		// loop scrolling
		for (msgIndex = 0; msgIndex < msgLength + DISPLAYS; msgIndex++) {

			// get switch readings
			switch_0 = digitalRead(SWITCH0);
			switch_1 = digitalRead(SWITCH1);

			// set direction depends on switch 0
			if (switch_0) {
				direction = RIGHT;
			}
			else {
				direction = LEFT;
			}

			// set speed depends on switch 1
			if (switch_1) {
				delay = DELAY_FAST;
			}
			else {
				delay = DELAY_SLOW;
			}

			if (msgIndex < msgLength) {
				// if there are remaining uncovered letters
				if (direction == LEFT) {
					newChar = msg[msgIndex];
				}
				else {
					newChar = msg[msgLength - msgIndex - 1];
				}
			}
			else {
				// finish it off by filling with blanks
				newChar = ' ';
			}

			// shift all the characters down one
			shiftArray(direction, onDisplay, newChar);

			// display onDislay onto the 7 segment display
			displayString(onDisplay);
			Sleep(delay);
		}
	}
}

/* Shifts and array to the right or to the left
 * PARAM: direction - left or right
 * PARAM: charArray - the string to be manipulated
 * PARMA: newCharacter - the new character to be replacing the end one
 * RETURN: void
 */
void shiftArray(int direction, char string[], char newCharacter) {
	int index;

	if (direction == LEFT) {
		// shift everything to the left by 1
		for (index = 0; index < DISPLAYS - 1; index++) {
			string[index] = string[index + 1];
		}

		// add new character at the end of array
		string[DISPLAYS - 1] = newCharacter;
	}
	else {
		// shift everything to the right by 1
		for (index = DISPLAYS - 1; index > 0; index--) {
			string[index] = string[index - 1];
		}

		// add new character at the end of array
		string[0] = newCharacter;
	}
}

/* Displays a single character to the seven segment display
 * PARAM: character - the character (can be numbers, lower case
 * or uppercase alphabets)
 * PARAM: position - the position to be displayed on
 * RETURN: void
 */
void displayChar(char character, int position) {
	// look up table
	static int SEG_DIGITS[] = {
		252, 96, 218, 242, 102, 182, 190, 224, 254, 246
	};

	static int SEG_ALPHABETS[] = {
		// A-J
		238, 62, 156, 122, 158, 142, 188, 110, 12, 248,
		// K-U
		174, 28, 1, 42, 58, 206, 230, 10, 182, 30, 124,
		// V-Z
		1, 1, 1, 118, 218
	};

	// check if the character is a number or a letter
	if (character >= DIGIT_START AND character <= DIGIT_END) {
		// input is number
		displayWrite(SEG_DIGITS[character - '0'], position);
	}
	else if (character >= ALPHA_UPPER_START AND character <= ALPHA_UPPER_END) {
		// input is UPPERCASE
		displayWrite(SEG_ALPHABETS[character - ALPHA_UPPER_START], position);
	}
	else if (character >= ALPHA_LOWER_START AND character <= ALPHA_LOWER_END) {
		// input is lowercase
		displayWrite(SEG_ALPHABETS[character - ALPHA_LOWER_START], position);
	}
	else {
		displayWrite(0, position);
	}
}

/* Displays a whole string onto the seven segment display
 * PARAM: string - the string array to be displayed
 * RETURN: void
 */
void displayString(char string[]) {
	int index;
	for (index = DISPLAYS - 1; index >= 0; index--) {
		displayChar(string[index], DISPLAYS - index - 1);
	}
}

/* Ask user for a string input - will put everything in a string array
 * (including spaces)
 * PARAM: stringArray - empty string array to put the characters into
 * RETURN: void
 */
void input(char string[]) {
	char character;
	int i = 0;

	// loops through each character in the line using 'getchar()' which scans a single character at a time
	do {
		character = getchar();

		string[i] = character;
		i++;

		// keep looping until the end
	} while (character != '\n');

	// adds a null character at the end - every string needs this
	string[i - 1] = '\0';
}