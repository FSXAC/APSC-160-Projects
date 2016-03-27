// this program uses a 2D array to draw a line on the cmd screen
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// preprocessors
#define and &&
#define or ||
#define not !

// macros
#define pause system("pause")

// constants
const int MAX_COL = 100;
const int MAX_ROW = 21;
const int COL_INTERVAL = 5;
const int ROL_INTERVAL = 1;

// display character
const char BLANK = '.';
const char DOT = '#';
const char LINE[] = { '-', '|', '/', '\\' };

// function prototypes
int getint(char *msg);
int inRange(int num, int lower, int upper);
void drawLine(int x1, int y1, int x2, int y2, char **grid);
void displayGrid(char **grid);

// main function
int main(void) {
	// coord of endpoints of line
	int x1, y1, x2, y2;
	char **grid;

	// set up dynamic memory 2D array
	grid = malloc(MAX_ROW * sizeof(char*));
	for (int row = 0; row < MAX_ROW; row++) {
		grid[row] = malloc(MAX_COL * sizeof(char));
		
		// add blank chars to each element
		for (int col = 0; col < MAX_COL; col++) {
			grid[row][col] = BLANK;
		}
	}

	// ask the user for width and height
	x1 = getint("Enter starting X: ");
	y1 = getint("Enter starting Y: ");
	x2 = getint("Enter ending X: ");
	y2 = getint("Enter ending Y: ");

	// check all values are in range
	if (inRange(x1, 0, MAX_COL) and inRange(y1, 0, MAX_ROW) and
		inRange(y1, 0, MAX_COL) and inRange(y2, 0, MAX_ROW)) {

		// add the end points to the array
		grid[y1][x1] = DOT;
		grid[y2][x2] = DOT;

		// draw line between the two points
		drawLine(x1, y1, x2, y2, grid);

		// display the grid
		displayGrid(grid);
	}

	// end of program
	// free memory
	for (int i = 0; i < MAX_ROW; i++) {
		free(grid[i]);
	}
	free(grid);

	// end
	pause;
	return 0;
}

/*
 * Prints a message on the screen and get user integer inputs
 * PARAM: msg - string to be printed
 * RETURN: integer
 */
int getint(char *msg) {
	int returnVal;
	printf("%s", msg);
	scanf("%d", &returnVal);
	return returnVal; 
}

/* Check if a number is inside a lower or upper range
 * Lower is inclusive, upper is exclusive
 * PARAM: num - the number for testing
 * PARAM: lower - lower bound
 * PARAM: upper - upper bound
 * RETURN: 1 or 0 for true or false
 */
int inRange(int num, int lower, int upper) {
	if (num < upper and num >= lower) {
		return 1;
	}
	else {
		return 0;
	}
}

/* Intrapolates the lines between two points on a grid
 * PARAM: p1 - the vector for point 1
 * PARAM: p2 - the vector for point 2
 * PARAM: grid - the master grid
 * RETURN: void
 */
void drawLine(int x1, int y1, int x2, int y2, char **grid) {
	// relative coordinates
	int xi, yi, xf, yf;

	// get relative coord
	xi = min(x1, x2);
	xf = max(x1, x2);
	yi = min(y1, y2);
	yf = max(y1, y2);

	// four cases
	if (xi != xf and yi == yf) {
		// case 1 - horizontal (y is the same)
		printf("Horizontal line detected.\n");
		for (int i = xi + 1; i < xf; i++) {
			grid[yi][i] = LINE[0];
		}
	}
	else if (xi == xf and yi != yf) {
		// case 2 - vertical (x is the same)
		printf("Vertical line detected.\n"); 
		for (int i = yi + 1; i < yf; i++) {
			grid[i][xi] = LINE[1];
		}
	}
	else if (xi != xf and yi != yf) {
		// case 3 - slope
		printf("Sloped line detected.\n");

		// relative slope vars
		double slope, b;
		char slope_char;
		int xn, yn;

		// math
		slope = ((double) y2 - y1) / (x2 - x1);
		b = yi - slope * xi;

		// output number
		printf("Slope: %.3f\n", slope);
		printf("Y intercept: %.3f\n", b);

		// determine positive or negative slope
		if (slope > 0) {
			slope_char = LINE[3];
		}
		else {
			slope_char = LINE[2];
		}

		// determine if the slope is steep or flat
		if (abs(slope) > 1) {

			// slope is steep - use y count
			for (yn = yi + 1; yn < yf; yn++) {
				xn = (yn - b) / slope;

				// assign the values to the grid
				grid[yn][xn] = slope_char;
			}
		}
		else {

			// slope is flat - use x count
			for (xn = xi + 1; xn < xf; xn++) {
				yn = xn * slope + b;

				// assign the values to the grid
				grid[yn][xn] = slope_char;
			}
		}
	}
	else {
		// case 4 - point
		printf("Point detected.\n");
	}
}

/*
 * Prints the formatted array as a grid onto the cmd window
 * PARAM: grid - the grid itself
 * RETURN: void
 */
void displayGrid(char **grid) {
	// print top row (numerical labels)
	printf("     ");
	for (int i = 0; i < MAX_COL; i += COL_INTERVAL) {
		printf("%-5d", i);
	}
	printf("\n     ");
	for (int i = 0; i < MAX_COL; i += COL_INTERVAL) {
		printf("%-5c", '|');
	}

	// new line
	printf("\n");

	// display rest of the grid
	for (int row = 0; row < MAX_ROW; row++) {

		// starting with vertical numerical labels
		printf("%3d- ", row);

		// print the rest of the line
		for (int col = 0; col < MAX_COL; col++) {
			printf("%c", grid[row][col]);
		}

		// new line
		printf("\n");
	}
	printf("Printing complete.\n");
}