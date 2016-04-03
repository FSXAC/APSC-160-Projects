// Minesweeper program

// imports
#include <stdio.h>
#include <stdlib.h>

// preprocessors
#define AND &&
#define OR ||
#define NOT !

// macros
#define PAUSE system("pause")
#define CLEAR system("clear")

// game constants
const int CELL_BLANK = 0;
const int CELL_MINE = -1;
const int CELL_FLAG = -2;

// grid properties
const int GRID_WIDTH = 10;
const int GRID_HEIGHT = 10;
const int MINES = 10;

// function prototypes
void displayGrid(int grid[]);
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

/* Displays the minesweeper grid on the screen
 * PARAM: grid - the grid
 * RETURN: void
 */
void displayGrid(int **grid) {
	for (int i = 0; i < GRID_HEIGHT; i++) {
		// draw vertical line
		drawLine();

		// draw the cells and vertical separators
		for (int j = 0; j < GRID_WIDTH; j++) {
			printf("|% d ", grid[i][j]);
		}
		printf("|\n");
	}

	drawLine();
}

// draws the line that separates the grid horizontally
void drawLine(void) {
	for (int i = 0; i < GRID_HEIGHT; i++) {
		printf("+---");
	}
	printf("+\n");
}