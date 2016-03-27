// use a function to return the number of even numbers in an array

#define LENGTH 20
#define RANDRANGE 100

int numberOfEvenNumbers(int list[]);

int main(void) {
	int numberList[LENGTH];

	// generate random numbers
	srand(1234);
	for (int i = 0; i < LENGTH; i++) {
		numberList[i] = rand() % RANDRANGE;

		printf("%5d", numberList[i]);
	}

	// use the functions
	printf("\nNumber of even numbers: %d\n", numberOfEvenNumbers(
		numberList, LENGTH));

	system("pause");
	return 0;
}

int numberOfEvenNumbers(int list[], int n) {
	int num = 0;
	for (int i = 0; i < n; i++) {
		if (list[i] % 2 == 0) {
			num++;
		}
	}

	return num;
}