// use a function to return the number of even numbers in an array

#define LENGTH 20
#define RANDRANGE 100

int toFind(int list[], int n);

int main(void) {
	int numberList[LENGTH];
	int numToFind = 1;

	// generate random numbers
	srand(1111);
	for (int i = 0; i < LENGTH; i++) {
		numberList[i] = rand() % RANDRANGE;

		printf("%5d", numberList[i]);
	}

	// use the functions
	printf("\nNumber of %d in the array: %d\n", toFind(numberList, LENGTH, numToFind));

	system("pause");
	return 0;
}

int toFind(int list[], int n, int findNum) {
	for (int i = 0; i < n; i++) {
		if (list[i] == findNum) {
			return i;
		}
	}

	return -1;
}