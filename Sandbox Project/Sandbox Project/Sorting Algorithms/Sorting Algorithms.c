// this program showcases various sorting algorithms for an array

// imports
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// file locations
#define FILEINPUT "Sorting Algorithms\\Random Numbers.dat"

#define FILEOUTPUT_BUBBLE "Sorting Algorithms\\Sorted - Bubble.dat"
#define FILEOUTPUT_SELECTION "Sorting Algorithms\\Sorted - Selection.dat"

// constants
#define ARRAY_SIZE 12

// function prototyp
void makeRandomFile(int num);
void printList(int list[ARRAY_SIZE]);
void bubbleSort(int inputList[ARRAY_SIZE]);
void selectionSort(int list[ARRAY_SIZE]);

// main function
int main(void) {
	FILE* inputFile = fopen(FILEINPUT, "r");
	int randomList[ARRAY_SIZE];
	int scanIndex = 0;

	// generate a new list of random numbers
	// makeRandomFile(ARRAY_SIZE);

	// this will get the file and put it in an array
	if (inputFile != NULL) {
		while (fscanf(inputFile, "%d", &randomList[scanIndex]) == 1) {
			scanIndex++;
		}
	}
	else {
		printf("Error opening random numbers file.\n");
		return 1;
	}

	// closes the input file
	fclose(inputFile);
	
	// display unsorted data
	printf("Unsorted Data: \n");
	printList(randomList);

	// BUBBLE SORT
	printf("Bubble sort:\n");
	bubbleSort(randomList);

	// SELECTION SORT
	printf("Selection sort:\n");
	selectionSort(randomList);

	system("pause");
	return 0;
}

void makeRandomFile(int num) {
	// open a new file to put random values
	FILE* outputFile = fopen(FILEINPUT, "w");

	// random seed
	srand(time(NULL));

	// insert values
	for (int i = 0; i < num; i++) {
		int randomNumber = rand() % 100;
		fprintf(outputFile, "%d\n", randomNumber);
	}

	// save and close the file
	fclose(outputFile);
}

void writeArrayToFile(int list[ARRAY_SIZE], char directory[]) {
	FILE* outFile = fopen(directory, "w");
	for (int i = 0; i < ARRAY_SIZE; i++) {
		fprintf(outFile, "%d\n", list[i]);
	}
	fclose(outFile);
}

void printList(int list[ARRAY_SIZE]) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%5d", list[i]);
	}
	printf("\n");
}

// bubble sort function
void bubbleSort(int list[ARRAY_SIZE]) {
	int i, j, swap;

	// bubble sort algorithm
	for (i = 0; i < ARRAY_SIZE - 1; i++) {
		for (j = i + 1; j < ARRAY_SIZE; j++) {
			if (list[i] > list[j]) {
				swap = list[i];
				list[i] = list[j];
				list[j] = swap;
			}
		}
	}

	// output the sorted data to file
	writeArrayToFile(list, FILEOUTPUT_BUBBLE);

	// output the sorted data to screen
	printList(list);
}

// selection sort function
void selectionSort(int list[ARRAY_SIZE]) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		int minIndex = i;
		for (int j = i; j < ARRAY_SIZE; j++) {
			if (list[j] < list[minIndex]) {
				minIndex = j;
			}
		}

		// swap with minimum
		if (minIndex != i) {
			int swap = list[minIndex];
			list[minIndex] = list[i];
			list[i] = list[minIndex];
		}
	}

	// output the sorted data to file
	writeArrayToFile(list, FILEOUTPUT_SELECTION);

	// output the sorted data to screen
	printList(list);
}

