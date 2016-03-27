// prints matrix that already exist in a 2D array

#include <stdio.h>

#define row 4
#define col 5

void printMatrix(double M[][col]);

int main(void) {

	double M1[row][col] = {
		{ 1, 2, 3, 4, 5 },
		{ 2, 3, 4, 5, 6 },
		{ 9, 8, 7, 6, 5 },
		{ 0, 1, 0, 1, 0 } };

	double M2[row][col] = {
		{ 1, 2, 3 },
		{ 2, 3, 4, 5 },
		{ 9, 9, 9 }
	};

	double M3[row][col] = {
		[0][0] = 5,
		[1][1] = 4,
		[2][2] = 3
	};

	// display 
	printf("M1:\n");
	printMatrix(M1);

	printf("\n\nM2:\n");
	printMatrix(M2);

	printf("\n\nM3:\n");
	printMatrix(M3);

	system("pause");
	return 0;
}

void printMatrix(double M[][col]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%10f", M[i][j]);
		}
		printf("\n");
	}
}