// Minesweeper program

// imports
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

// preprocessors
#define AND &&
#define OR ||
#define NOT !

// macros
#define PAUSE system("pause")
#define CLEAR system("cls")
#define ROLL(x) rand()%x

// game constants
const int CELL_BLANK = 0;
const int CELL_MINE = -1;

const char BLANK = ' ';
const char MINE = 'X';
const char FLAG = 'P';

const int HIDDEN = 0;
const int SHOW = 1;
const int SHOWFLAG = 2;

const int DEBUG = 0;

// grid properties
const int GRID_WIDTH = 10;
const int GRID_HEIGHT = 10;
const int MINES = 5;

// cell structure
struct cell {
	// can be number or mine (0 for blank, -1 for mine)
	int role;

	// can be 0 for hidden, 1 for show, 2 for flag
	int reveal;
};

// function prototypes
void minesweeper(void);
void clearGrid(struct cell **grid);
void flipGrid(struct cell **grid);
int sweepGrid(struct cell **grid, int startX, int startY);
void placeMines(struct cell **grid);
void placeNumbers(struct cell **grid);
int checkMines(struct cell **grid, int x, int y);
int checkWin(struct cell ** grid);
void displayGrid(struct cell **grid);
void drawLine(void);

// main function
int main(void) {
	// reset random seed
	srand(time(NULL));

	while (1) {
		minesweeper();
		PAUSE;
	}

	// end of program
	PAUSE;
	return 0;
}

/* Main game is located here*/
void minesweeper(void) {
	// grid array
	struct cell **grid;

	// loop
	int gameover = 0;

	// user input
	int inputX;
	int inputY;
	int firstInput = 1;

	// create the grid
	// set up dynamic memory 2D array
	grid = malloc(GRID_HEIGHT * sizeof(struct cell*));
	for (int row = 0; row < GRID_HEIGHT; row++) {
		grid[row] = malloc(GRID_WIDTH * sizeof(struct cell));
	}

	// reset grid
	clearGrid(grid);

	// place mines
	placeMines(grid);

	// place numbers
	placeNumbers(grid);

	while (NOT gameover) {
		// display grid
		displayGrid(grid);

		// ask for user input x
		do {
			printf("Enter X: \n");
			inputX = getch() - '0';
		} while (inputX >= GRID_WIDTH OR inputX < 0);
		if (DEBUG) printf("user entered %d for x\n", inputX);

		// ask for user input y
		do {
			printf("Enter Y: \n");
			inputY = getch() - '0';
		} while (inputY >= GRID_HEIGHT OR inputY < 0);
		if (DEBUG) printf("user entered %d for y\n", inputY);

		if (firstInput) {
			// user's first input will always be a blank space
			while (grid[inputY][inputX].role != CELL_BLANK) {
				if (DEBUG) {
					printf("inital gen not optimal; regenerating . . .\n");
					PAUSE;
				}				
				clearGrid(grid);
				placeMines(grid);
				placeNumbers(grid);
			}
			firstInput = 0;
		}

		// reveal the cell if the coord is correct
		if (grid[inputY][inputX].role != CELL_MINE) {
			grid[inputY][inputX].reveal = SHOW;

			// if blank cell
			if (grid[inputY][inputX].role == CELL_BLANK) {
				sweepGrid(grid, inputX, inputY);
			}

		}
		else {
			flipGrid(grid);
			displayGrid(grid);
			printf("Game over: You hit a bomb!!\n");
			gameover = 1;
		}

		// check win
		if (checkWin(grid) AND NOT gameover) {
			flipGrid(grid);
			displayGrid(grid);
			printf("You win!\n");
			gameover = 1;
		}
	}

	// free memory
	for (int i = 0; i < GRID_HEIGHT; i++) {
		free(grid[i]);
	}
	free(grid);
}

/* Completely clears the grid including mines and numbers
 * PARAM: grid
 * RETURN: void
 */
void clearGrid(struct cell **grid) {
	for (int row = 0; row < GRID_HEIGHT; row++) {
		for (int col = 0; col < GRID_WIDTH; col++) {
			// add blank chars to each element
			grid[row][col].role = CELL_BLANK;

			// set reveal for each cells
			grid[row][col].reveal = HIDDEN;
		}
	}
}

/* Completely reveals all cells in current grid
 * PARAM: grid
 * RETURN: void
 */
void flipGrid(struct cell **grid) {
	for (int row = 0; row < GRID_HEIGHT; row++) {
		for (int col = 0; col < GRID_WIDTH; col++) {
			// set reveal for each cells
			grid[row][col].reveal = SHOW;
		}
	}
}

/*Sweep the adjascent blank and number grids*/
int sweepGrid(struct cell **grid, int startX, int startY) {
	if (DEBUG) {
		printf("=== new recusive\n");
		PAUSE;
		displayGrid(grid);
	}

	for (int j = startY - 1; j <= startY + 1; j++) {
		for (int i = startX - 1; i <= startX + 1; i++) {

			// check not touching the bounds
			if (j >= 0 AND j < GRID_HEIGHT AND
				i >= 0 AND i < GRID_WIDTH AND

				// skip eigencell
				(i != startY OR j != startX) AND
			
				// skip show values
				(grid[j][i].reveal == HIDDEN)){

				if (DEBUG) printf("sweepGrid(): i=%d, j=%d\n", i, j);

				// recursive reveal
				if (grid[j][i].role == CELL_BLANK) {
					grid[j][i].reveal = SHOW;

					// recursive
					sweepGrid(grid, i, j);

					if (DEBUG) printf("BLANK\n");
				}
				else if (grid[j][i].role != CELL_MINE) {
					grid[j][i].reveal = SHOW;
					if (DEBUG) printf("NUM\n");
				}
				else {
					if (DEBUG) printf("NONE\n");
				}
			}
		}
	}
}

/* Randomly generates the mines to put all over the place
 * PARAM: grid
 * RETURN: void
 */
void placeMines(struct cell **grid) {
	int random_x;
	int random_y;

	for (int i = 0; i < MINES; i++) {
		// generate random values on the xy plane
		random_x = ROLL(GRID_WIDTH);
		random_y = ROLL(GRID_HEIGHT);

		// if the space is not already occupied by a mine, then add
		while (grid[random_y][random_x].role == CELL_MINE) {
			// generate more random values until it lands on a free one
			random_x = ROLL(GRID_WIDTH);
			random_y = ROLL(GRID_HEIGHT);
		}

		if (DEBUG)
			printf("placeMines(): randgen(%d): X = %d\tY= %d\n",
			i, random_x, random_y);

		// add mine to grid
		grid[random_y][random_x].role = CELL_MINE;
	}
}

/* Check each grid and its surroundings for mines
 * Put a number on the cell spot for number of mines around it
 */
void placeNumbers(struct cell **grid) {
	for (int i = 0; i < GRID_HEIGHT; i++) {
		for (int j = 0; j < GRID_WIDTH; j++) {
			if (grid[i][j].role != CELL_MINE) {
				// if the cell is not a mine itself
				grid[i][j].role = checkMines(grid, i, j);
			}
		}
	}
}

/* Checks a single location on the grid for number of
 * mines around it
 */
int checkMines(struct cell **grid, int iref, int jref) {
	int count = 0;
	for (int i = iref - 1; i <= iref + 1; i++) {
		for (int j = jref - 1; j <= jref + 1; j++) {
			if (i >= 0 AND i < GRID_HEIGHT AND
				j >= 0 AND j < GRID_WIDTH AND
				grid[i][j].role == CELL_MINE) {
				count++;
			}
		}
	}
	return count;
}

/* Check if the surrounding is shown or not
int checkShown(struct cell **grid, int x, int y) {
	if (DEBUG) printf("checkShown(): x=%d, y=%d\n", x, y);

	for (int i = y - 1; i <= y + 1; i++) {
		for (int j = x - 1; j <= x + 1; j++) {

			// check not touching the bounds
			if (i >= 0 AND i < GRID_HEIGHT AND
				j >= 0 AND i < GRID_WIDTH) {

				// check
				if (grid[i][j].reveal == HIDDEN) {
					printf("checkShown(): hidden cells found\n");
					return 0;
				}
			}
		}
	}
	
	// if no cell is hidden
	printf("checkShown(): all go\n");
	return 1;
}
*/

/* Check if the grid is completely uncovered*/
int checkWin(struct cell ** grid) {
	for (int j = 0; j < GRID_HEIGHT; j++) {
		for (int i = 0; i < GRID_WIDTH; i++) {
			if (grid[j][i].reveal == HIDDEN AND grid[j][i].role != CELL_MINE) {
				return 0;
			}
		}
	}
	return 1;
}

/* Displays the minesweeper grid on the screen
 * PARAM: grid - the grid
 * RETURN: void
 */
void displayGrid(struct cell **grid) {
	int gridValue;
	int gridShow;

	// clear screen
	if (NOT DEBUG) CLEAR;

	// draw horizontal reference ruler
	printf("   ");
	for (int i = 0; i < GRID_WIDTH; i++) {
		printf(" %2d ", i);
	}
	printf("\n");

	// draw horizontal ticks
	printf("   ");
	for (int i = 0; i < GRID_WIDTH; i++) {
		printf("  | ");
	}
	printf("\n");

	// draw grid
	for (int i = 0; i < GRID_HEIGHT; i++) {
		// draw vertical line
		if (NOT i) {
			drawLine(1);
		}
		else {
			drawLine(0);
		}

		// draw vertical reference ruler
		printf("%2d-", i);

		// draw the cells and vertical separators
		for (int j = 0; j < GRID_WIDTH; j++) {
			gridValue = grid[i][j].role;
			gridShow = grid[i][j].reveal;

			// display different types of cells
			if (gridShow == SHOW) {
				if (gridValue == CELL_BLANK) {
					// blank field
					printf("| %c ", BLANK);
				}
				else if (gridValue == CELL_MINE) {
					// mine
					printf("| %c ", MINE);
				}
				else {
					// numbers
					printf("| %d ", gridValue);
				}
			}
			else if (gridShow == SHOWFLAG) {
				// display grid
				printf("| - $");
			}
			else if (gridShow == HIDDEN) {
				// hidden cell
				printf("| - ");
			}
		}
		printf("|\n");
	}

	// finish the last line
	drawLine(1);
}

// draws the line that separates the grid horizontally
void drawLine(int isBorder) {
	printf("   ");
	for (int i = 0; i < GRID_HEIGHT; i++) {
		if (isBorder) {
			if (NOT i) {
				printf("|===");
			}
			else  {
				printf("====");
			}
		}
		else {
			if (NOT i) {
				printf("|---");
			}
			else {
				printf("+---");
			}
		}
	}
	printf("|\n");
}