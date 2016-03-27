/* AUTHOR: MANSUR HE
 * DATE: 2016-02-09
 * PURPOSE: GAMBLE 24/7
 */

//int checkUserInput(int input, int choices[]);

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_LENGTH 20

// game vars
// pig dice:
#define PD_DEFAULT_SHORT 20
#define PD_DEFAULT_MED 50
#define PD_DEFAULT_LONG 100
#define PD_MAX_PLAYERS 4

// number guesser
#define NG_SM 30
#define NG_MD 50
#define NG_LG 100

int rollDice(int faces);
void pigDiceMain(void);
int pigDiceCheckWin(struct Player players, int goal);
void numberGuesser(void);

struct Player{
	char name;
	int score;
	int rolls;
	int isPlaying;
};

int main(void) {
	int gameMode = -1;
	int isDone = 0;

	while (!isDone) {
		system("cls");
		printf("Welcome to GAMBLE 24/7! Choose Your Game: \n"
			"[1]\tPig Dice\n"
			"[2]\tRock Paper Scissors\n"
			"[3]\tCrap\n"
			"[4]\tIsaac's Slots\n"
			"[5]\tNumber Guesser\n"
			"\n[0]\tQuit\n");

		printf("Enter choice: ");
		scanf("%d", &gameMode);

		if (gameMode == 1) {
			// pig dice
			pigDiceMain();
		}
		else if (gameMode == 2) {
			// rock papper scissors
		}
		else if (gameMode == 3) {
			// crap game
		}
		else if (gameMode == 4) {
			// isaac's slots
		}
		else if (gameMode == 5) {
			// number guesser
			numberGuesser();
		}
		else if (gameMode == 0) {
			printf("Goodbye!\n");
			isDone = 1;
		} 
		else {
			printf("Your input is invalid, try again.\n");
		}
	}

	system("pause");

	return 0;
}

void pigDiceMain(void) {
	// main game variables
	int isDone = 0;
	int userChoice = -1;

	// gameplay vars
	// game setup
	int currentPlayer = 0;
	int inputName;
	int gameLength;
	int numPlayers = 2;
	int dice = 1;
	int diceFaces = 6;
	int turnEnded = 0;
	int roll;
	int rollAgain;
	int rollSum = 0;
	int rollCount = 0;
	int goal;
	int winner;

	// game loop
	while (!isDone) {

		// main menu
		system("cls");
		printf("WELCOME TO PIG DICE GAME - PLEASE SELECT AN OPTION\n");
		printf("[1]\tMultiplayer\n"
			"[2]\tSingle player\n"
			"[3]\tInstructions\n"
			"\n[0]\tQuit game\n");

		printf("Enter choice: ");
		scanf("%d", &userChoice);

		// multiplayer
		if (userChoice == 1) {

			// ask how many players are playing
			system("cls");
			printf("How many players are playing? (2-%d) \n", 4);
			printf("Your choice: ");
			scanf("%d", &numPlayers);
			
			// player list setup
			struct Player playerList[PD_MAX_PLAYERS];

			for (int i = 0; i < numPlayers; i++) {
				// name inputs
				printf("\nPlayer %d, please enter your name: ", i + 1);
				scanf("%s", &inputName);

				// setup other attributes
				playerList[i].isPlaying = 1;
				playerList[i].score = 0;
				playerList[i].rolls = 0;
				playerList[i].name = inputName;
			}	

			// select game length
			printf("Choose length of game:\n"
				"[1]\tShort Game\n[2]\tMedium Game\n[3]\tLong Game\n");
			printf("Your choice: ");
			scanf("%d", &gameLength);

			// setup player score for game length
			if (gameLength == 2) {
				goal = PD_DEFAULT_MED;
				printf("Medium length game selected . . .\n"
					"First to 50 points win!\n");
			}
			else if (gameLength == 3) {
				goal = PD_DEFAULT_LONG;
				printf("Long length game selected . . .\n"
					"First to 100 points win!\n");
			}
			else {
				goal = PD_DEFAULT_SHORT;
				printf("Short length game (default) selected . . .\n"
					"First to 20 points win!\n");
			}

			// choose dice
			printf("\nDo you want to play with 1 die or 2 dice?\n");
			printf("Your choice: ");
			scanf("%d", &dice);

			if (dice == 2) {
				printf("2 dice selected . . .\n");
				diceFaces *= 2;
			}
			else {
				printf("1 die (default) selected . . .\n");
			}

			// start game
			system("pause");
			system("cls");

			// keep looping until one of the player's score is <= 0
			while (pigDiceCheckWin(playerList, goal)) {

				if (playerList[currentPlayer].isPlaying) {
					// print player names
					printf("#################### %s'S TURN ####################\n", 
						playerList[currentPlayer].name);

					roll = rollDice(diceFaces);
					rollSum += roll;
					rollCount++;
					printf("You rolled a %d!\n", roll);

					// if roll is not 1, player can continue rolling
					if (roll != 1) {
						printf("Roll again?\n[1] Again!\t[0]No thanks\n");
						scanf("%d", &rollAgain);

						// user ends turn
						if (!rollAgain) {
							turnEnded = 1;
						}
					}
					// player rolls a 1
					else {
						printf("Bad luck\n");
						turnEnded = 1;
						rollSum = 0;
						rollCount = 0;
					}

					// turn ended
					if (turnEnded) {
						printf("#################### TURN ENDED ####################\n");
						playerList[currentPlayer].score += rollSum;
						playerList[currentPlayer].rolls += rollCount;
						printf("%s's score is %d pts\n", 
							playerList[currentPlayer].name, 
							playerList[currentPlayer].score);
						currentPlayer = 2;

						// reset turns for next player
						system("pause");
						system("cls");
						turnEnded = 0;
						rollSum = 0;

						// cycle through the player list counter
						if (currentPlayer == PD_MAX_PLAYERS - 1) {
							currentPlayer = 0;
						}
						else {
							currentPlayer++;
						}
					}
				}
				else {
					// disabled players - just cycle to the next players
					if (currentPlayer == PD_MAX_PLAYERS - 1) {
						currentPlayer = 0;
					}
					else {
						currentPlayer++;
					}
				}
			}

			// end - determine results
			system("cls");
			winner = pigDiceCheckWin(playerList, goal) - 1;
			printf("#################### WINNER IS %s ####################\n", 
				playerList[winner].name);
			printf("Congratulations, %s, you win!\nYou rolled a total of %d times!\n"
			"You had %d extra points!\n\n", 
			playerList[winner].name, playerList[winner].rolls, playerList[winner].score - goal);
			system("pause");
			
		}
		else if (userChoice == 2) {
			// single player not developed yet
		}
		// instructions
		else if (userChoice == 3) {
			system("cls");
			printf("PIG DICE GAME INSTRUCTIONS\n\n"
				"Player 1 and player 2 starts off with 0 points and\n"
				"the goal of the game is to roll dice and gain points.\n"
				"The points are added by rolling the dice,\n"
				"but the points don't get added until the player\n"
				"has ended the turn. If the player rolls a '1' before\n"
				"the turn is ended, all rolls of the current turn are\n"
				"discarded\n\n"
				"Have fun!\n\n");
			system("pause");
		}
		// quit current game
		else if (userChoice == 0) {
			printf("Goodbye\n");
			system("pause");
			isDone = 1;
		}
	}
}

int pigDiceCheckWin(struct Player players[], int goal) {
	int length = sizeof(players) / sizeof(players[0]);
	int hasWon = 0;

	// check every player to see if their score is ok
	for (int i = 0; i < length; i++) {
		if (players[i].score >= goal) {
			hasWon = i + 1; 
		}
	}

	return hasWon;
}

void numberGuesser(void) {
	int isDone = 0;
	int menuInput;
	int difficulty;
	int guesses = 0;
	int randomRange;
	int randomNumber;
	int userGuess = -1;
	
	while (!isDone) {
		system("cls");
		printf("Welcome to the number guesser game!\n"
			"[1]\tPlay\n"
			"\n[0]\tQuit\n");
		printf("Your choice: ");
		scanf("%d", &menuInput);

		if (menuInput == 1) {
			// play game
			system("cls");
			printf("Choose difficulty:\n"
				"[1]\tEasy (range from 1 to 30)\n"
				"[2]\tMedium (range from 1 to 50)\n"
				"[3]\tHard (range from 1 to 100)\n");
			printf("Your choice: ");
			scanf("%d", &difficulty);

			// set var for difficulty
			if (difficulty == 2) {
				randomRange = NG_MD;
				printf("Medium difficulty selected. . .\n");
			}
			else if (difficulty == 3){
				randomRange = NG_LG;
				printf("Hard difficulty selected. . .\n");
			} 
			else {
				randomRange = NG_SM;
				printf("Easy difficulty (default) selected. . .\n");
			}

			// setup game
			guesses = 0;
			randomNumber = rollDice(randomRange);
			system("cls");

			// keep guessing until right
			while (userGuess != randomNumber) {
				printf("Guess a number between 1 and %d\n", randomRange);
				printf("Your guess: ");
				scanf("%d", &userGuess);

				guesses++;

				if (userGuess > randomNumber) {
					printf("Your guess is too high, try again.\n\n");
				}
				else if (userGuess < randomNumber) {
					printf("Your guess is too low, try again.\n\n");
				}
				else {
					printf("\n\n######### You guessed it right! ##########\n"
						"The number is %d\n"
						"It only took you %d tries!\n\n", randomNumber, guesses);
				}
			}

			// finishes
			system("pause");
		}
		else {
			// quit game
			printf("Goodbye\n");
			isDone = 1;
			system("pause");
		}
	}
}

int rollDice(int faces) {
	int roll;

	srand(time(NULL));
	roll = 1 + rand() % faces;

	return roll;
}