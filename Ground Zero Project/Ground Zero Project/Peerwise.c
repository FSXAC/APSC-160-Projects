// testing code for peerwise

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MINUS -1
const int minus = -1;

int main(void) {
	
	int r = 5 MINUS;
	int s = 5 - minus;
	printf("%d\n%d\n", r, s);

	system("pause");
	return 0;
}