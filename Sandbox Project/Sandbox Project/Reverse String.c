// String reverser
// this works but it only works for strings with no spaces

#include <stdio.h>

// constants
#define MAX_CHAR 128

// function prototypes
void reverseString(char string[]);

// main function
int main(void) {
	char input_str[MAX_CHAR], output_str[MAX_CHAR];
	
	// ask user for string
	printf("Enter a sentence: ");
	scanf("%s", &input_str);

	reverseString(input_str, output_str);

	printf("\n%s\n", output_str);

	system("pause");
	return 0;
}

void reverseString(char input[], char output[]) {
	int length = getEndIndex(input);

	// reverse the index of each character
	for (int index = 0; index < length; index++) {
		output[index] = input[length - index - 1];
	}

	// but null at the end
	output[length] = '\0';
}

int getEndIndex(char string[]) {
	int index = 0;
	while (string[index] != '\0') {
		index++;
	}
	return index;
}