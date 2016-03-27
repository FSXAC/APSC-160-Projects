// cafe ordering menu

#include <stdio.h>
#include <stdlib.h>

// prices
#define COFFEE_SM 1.19
#define COFFEE_MD 1.59
#define COFFEE_LG 1.79
#define LATTE_SM 1.69
#define LATTE_MD 1.99
#define LATTE_LG 2.19
#define TEA_SM 1.49
#define TEA_MD 1.69
#define TEA_LG 1.89
#define MLKSHK_SM 3.69
#define MLKSHK_LG 4.19
#define DGHNUT 0.99
#define MUFFIN 0.79
#define SNDWCH 4.99

// function prototypes
void printMenu(void);

// main function
int main(void) {
	int isDone = 0;
	int onMenu = 1;
	int userChoice;
	int sizable = 0;
	
	while (!isDone) {
		printMenu();

		// ask user for options
		while (onMenu) {
			printf("Your selection: ");
			scanf("%d", &userChoice);

			// options
			switch (userChoice){
			case 1:
				// ask for size
				sizable = 1;
				////// continue from here //////
			}

		}


		isDone = 1;
	}

	system("pause");
	return 0;
}

// simply prints the menu
void printMenu(void){
	printf("[1]\tCoffee\t\tSM $%.2f\tMD $%.2f\tLG $%.2f\n"
		"[2]\tLatte\t\tSM $%.2f\tMD $%.2f\tLG $%.2f\n"
		"[3]\tTea\t\tSM $%.2f\tMD $%.2f\tLG $%.2f\n"
		"[4]\tMilkshake\tSM $%.2f\t\t\tLG $%.2f\n"
		"[5]\tDoughnut\t   $%.2f\n"
		"[6]\tMuffin\t\t   $%.2f\n"
		"[7]\tSandwich\t   $%.2f\n",
		COFFEE_SM, COFFEE_MD, COFFEE_LG, 
		LATTE_SM, LATTE_MD, LATTE_LG, 
		TEA_SM, TEA_MD, TEA_LG,
		MLKSHK_SM, MLKSHK_LG, 
		DGHNUT, MUFFIN, SNDWCH);
}