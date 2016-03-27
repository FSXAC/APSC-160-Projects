// find two smallest number of of an array and print it onto the screen

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(void) {
	int data[] = { 5, 3, -12, -17, 6, 12, -1, 8, 19, 31 };
	int index = 0;
	int smallest, secondSmallest;

	smallest = data[0];
	for (; index < SIZE; index++) {
		if (data[index] < smallest) {
			secondSmallest = smallest;
			smallest = data[index];
		}
	}

	printf("Smallest: %d\nSecond Smallest: %d\n", smallest, secondSmallest);

	system("pause");
	return 0;
}