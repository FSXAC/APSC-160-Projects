/* Tic Tac Toe
 * Multiplayer for now/
 */

// libraries
#include <stdio.h>
#include <stdlib.h.>

// preprocessors
// logic
#define NOT !
#define AND &&
#define OR ||
// macros
#define PAUSE system("pause")
#define CLEAR system("cls");
#define SQUARE(x) x*x

// constants
const char VERSION[] = "version 0.21";

// board
const int BOARD_SIZE = 3;

// characters

const char X = 'X';
const char O = 'O';
const char BLANK = ' ';

// function prototypes
void game(void);
void printGrid(char grid[]);
char checkWin(char grid[], char currentPlayer);
int isSame(char x, char y, char z);
int countGrid(char grid[]);

// main function
int main(void) {
	// intro
	printf("Welcome to TIC TAC TOE by MANSUR HE - %s\n", VERSION);
	PAUSE;
	CLEAR;

	// play game
	game();

	// end of program
	PAUSE;
	return 0;
}

void game(void) {
	char *grid;
	char currentPlayer = O;
	char currentWin;
	char winner = BLANK;
	int playerInput;

	// set up dynamic memory 1D array for 2D grid
	grid = malloc(SQUARE(BOARD_SIZE) * sizeof(char*));
	for (int i = 0; i < SQUARE(BOARD_SIZE); i++) {
		grid[i] = BLANK;
	}

	// display grid
	printGrid(grid);

	while (countGrid(grid)) {

		// prompt
		printf("%c, It's your turn\nInput: ", currentPlayer);
		while (1) {
			// get user button
			playerInput = getch() - '0';

			// check if the board is occupied or not
			if (grid[playerInput - 1] != BLANK) {
				printf("Invalid play, try again\nInput: ", currentPlayer);
			}
			else {
				// add player marker to grid
				grid[playerInput - 1] = currentPlayer;
				break;
			}
		}

		
		// display grid
		CLEAR;
		printGrid(grid);

		// check win
		currentWin = checkWin(grid, currentPlayer);
		if (currentWin == O) {
			winner = O;
			break;
		}
		else if (currentWin == X) {
			winner = X;
			break;
		}

		// swap players
		if (currentPlayer == O) {
			currentPlayer = X;
		}
		else {
			currentPlayer = O;
		}
	}

	// game over
	if (winner != BLANK) {
		printf("Winner is %c!\n", winner);
	}
	else {
		// if no one wins
		printf("Tie game!\n");
	}

	// free memory
	free(grid);
}

/* Prints the grid*/
void printGrid(char grid[]) {
	printf("-------------\t\t--REFERENCE--\n");
	for (int i = 0; i < SQUARE(BOARD_SIZE); i += 3) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			printf("|%2c ", grid[i + j]);
		}
		printf("|\t\t");
		for (int j = 0; j < BOARD_SIZE; j++) {
			printf("|%2d ", i + j + 1);
		}
		printf("|\n");
		printf("-------------\t\t-------------\n");
	}
}

/* Check wins*/
char checkWin(char grid[], char currentPlayer) {
	int i;

	// check horizontal
	for (i = 0; i < SQUARE(BOARD_SIZE); i += 3) {
		//printf("H:%d %d %d\n", i, i + 1, i + 2);
		if (isSame(grid[i], grid[i + 1], grid[i + 2])) {
			return currentPlayer;
		}
	}

	// check vertical
	for (i = 0; i < BOARD_SIZE; i++) {
		//printf("V:%d %d %d\n", i, i + 3, i + 6);
		if (isSame(grid[i], grid[i + 3], grid[i + 6])) {
			return currentPlayer;
		}
	}

	// check diagonal
	if (isSame(grid[0], grid[4], grid[8]) OR
		isSame(grid[2], grid[4], grid[6])) {
		return currentPlayer;
	}

	// nothing
	return BLANK;
}

/*Compare 3 characters and returns true when they are all same*/
int isSame(char x, char y, char z) {
	if (x == y AND y == z AND x != BLANK) {
		return 1;
	}
	else {
		return 0;
	}
}

/* checks if the board is completed*/
int countGrid(char grid[]) {
	int count = 0;
	for (int i = 0; i < SQUARE(BOARD_SIZE); i++) {
		if (grid[i] == BLANK) {
			count++;
		}
	}
	return count;
}