// Minesweeper program

// imports
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// preprocessors
#define AND &&
#define OR ||
#define NOT !

// macros
#define PAUSE system("pause")
#define CLEAR system("clear")
#define ROLL(x) rand()%x

// game constants
const int CELL_BLANK = 0;
const int CELL_MINE = -1;
const int CELL_FLAG = -2;

const char BLANK = ' ';
const char MINE = 'X';
const char FLAG = 'P';

// grid properties
const int GRID_WIDTH = 10;
const int GRID_HEIGHT = 10;
const int MINES = 10;

// function prototypes
void placeMines(int **grid);
void displayGrid(int **grid);
void drawLine(void);

// main function
int main(void) {
	// grid array
	int **grid;

	// create the grid
	// set up dynamic memory 2D array
	grid = malloc(GRID_HEIGHT * sizeof(int*));
	for (int row = 0; row < GRID_HEIGHT; row++) {
		grid[row] = malloc(GRID_WIDTH * sizeof(int));

		// add blank chars to each element
		for (int col = 0; col < GRID_WIDTH; col++) {
			grid[row][col] = CELL_BLANK;
		}
	}

	// reset random seed
	srand(time(NULL));

	// place mines
	placeMines(grid);

	// display grid
	displayGrid(grid);

	// end of program
	// free memory
	for (int i = 0; i < GRID_HEIGHT; i++) {
		free(grid[i]);
	}
	free(grid);

	// end
	PAUSE;
	return 0;
}

/* Randomly generates the mines to put all over the place
 * PARAM: grid
 * RETURN: void
 */
void placeMines(int **grid) {
	int random_x;
	int random_y;

	for (int i = 0; i < MINES; i++) {
		// generate random values on the xy plane
		random_x = ROLL(GRID_WIDTH);
		random_y = ROLL(GRID_HEIGHT);

		printf("placeMines(): randgen(%d): X = %d\tY= %d\n",
			i, random_x, random_y);

		// if the space is not already occupied by a mine, then add
		while (grid[random_y][random_x] == CELL_MINE) {
			// generate more random values until it lands on a free one
			random_x = ROLL(GRID_WIDTH);
			random_y = ROLL(GRID_HEIGHT);
		}

		// add mine to grid
		grid[random_y][random_x] = CELL_MINE;
	}
}

/* Displays the minesweeper grid on the screen
 * PARAM: grid - the grid
 * RETURN: void
 */
void displayGrid(int **grid) {
	int gridValue;

	for (int i = 0; i < GRID_HEIGHT; i++) {
		// draw vertical line
		drawLine();

		// draw the cells and vertical separators
		for (int j = 0; j < GRID_WIDTH; j++) {
			gridValue = grid[i][j];

			// display different types of cells
			if (gridValue == CELL_BLANK) {
				// blank field
				printf("| %c ", BLANK);
			}
			else if (gridValue == CELL_MINE) {
				// mine
				printf("| %c ", MINE);
			}
			else if (gridValue == CELL_FLAG) {
				// flag
				printf("| %c ", FLAG);
			}
			else {
				// numbers
				printf("| %d ", gridValue);
			}
		}
		printf("|\n");
	}

	// finish the last line
	drawLine();
}

// draws the line that separates the grid horizontally
void drawLine(void) {
	for (int i = 0; i < GRID_HEIGHT; i++) {
		printf("+---");
	}
	printf("+\n");
}