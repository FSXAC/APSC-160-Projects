#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

void print2d(int list[SIZE][SIZE]);

int main(void) {
	int numbers[][SIZE] = {
		{ 1, 2, 3, 4 },
		{5, 6, 7, 8},
		{0, 1, 0, 1},
		{5, 4, 3, 2}
	};

	for (int i = 0; i < 10; i++) 
	print2d(numbers);

	system("pause");
	return 0;
}

void print2d(int list[SIZE][SIZE]) {
	static int count = 0;
	
	// print grid
	printf("pass %d\n", count);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%3d", list[i][j]);
		}
		printf("\n");
	}

	count++;
}