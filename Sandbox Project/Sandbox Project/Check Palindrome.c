// this program checks if a string is a palindrome

#include <stdio.h>
#include <stdlib.h>

// main function
int main(void) {

	// two character arrays
	char str[64] , str_rev[64];

	// ask user for input string
	printf("Enter a string: ");
	scanf("%s", &str);

	// copy the string, then reverse it
	strcpy(str_rev, str);
	strrev(str_rev);

	// compare if the reversed string is the same as original
	if (strcmp(str, str_rev)) {
		printf("This is not a palindrome.\n");
	}
	else {
		printf("This is a palindrome.\n");
	}

	// end of program
	system("pause");
	return 0;
}