// memory allocation experiment with arrays

#include <stdio.h>

int main(void) {
	// pointer to array memory
	int *dynamicArray;

	// size of array
	int n;

	// ask for size
	printf("Enter size: ");
	scanf("%d", &n);

	// allocate memory for the array with size n
	dynamicArray = (int *)malloc(sizeof(int)*n);

	// add values to array & print it out
	printf("A = [");
	for (int i = 0; i < n; i++) {
		dynamicArray[i] = 3;
		printf("%d  ", dynamicArray[i]);
	}

	printf("]\n");

	// end of program
	system("pause");

	// free memory
	free(dynamicArray);

	return 0;
}