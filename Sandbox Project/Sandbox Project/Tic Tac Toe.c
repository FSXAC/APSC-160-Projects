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
const char VERSION[] = "version 0.22";

// board
const int BOARD_SIZE = 3;

// characters
const char X = 'X';
const char O = 'O';
const char BLANK = ' ';

// function prototypes
int game(void);
void printGrid(char grid[]);
char checkWin(char grid[], char currentPlayer);
int isSame(char x, char y, char z);
int countGrid(char grid[]);
int strinput(char string[]);

// main function
int main(void) {
	// intro
	printf("Welcome to TIC TAC TOE by MANSUR HE - %s\n", VERSION);
	PAUSE;
	CLEAR;

	// play game
	while (game());

	// end of program
	PAUSE;
	return 0;
}

int game(void) {
	char *grid;
	char playerName_1[20], playerName_2[20];
	char currentPlayer;
	char winner = BLANK;
	char again;
	int playerInput;

	// ask for names
	printf("> Player 1, what is thy name?\n> My name is ");
	strinput(playerName_1);
	printf("> Player 2, what is thy name?\n> My name is ");
	strinput(playerName_2);

	// ask for symbol
	while (1) {
		printf("> %s, What symbol (X or O) are thou starting with?\n", playerName_1);
		currentPlayer = getch();
		if (currentPlayer == O OR currentPlayer - 32 == O) {
			currentPlayer = O;
			break;
		}
		else if (currentPlayer == X OR currentPlayer - 32 == X) {
			currentPlayer = X;
			break;
		}
	}

	// set up dynamic memory 1D array for 2D grid
	grid = malloc(SQUARE(BOARD_SIZE) * sizeof(char*));
	for (int i = 0; i < SQUARE(BOARD_SIZE); i++) {
		grid[i] = BLANK;
	}

	// display grid
	CLEAR;
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
		winner = checkWin(grid, currentPlayer);
		if (winner != BLANK){
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

	// ask if want to play again
	while (1) {
		printf("Rematch? (Y/N)\n");
		again = getch();

		if (again == 'y' OR again - 32 == 'y') {
			return 1;
		}
		else if (again == 'n' OR again - 32 == 'n') {
			return 0;
		}
		else {
			printf("Invalid input! Try again \n");
		}
	}
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

/* Get string input*/
int strinput(char string[]) {
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

	return i;
}