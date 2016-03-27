/* AUTHOR: MANSUR HE
 * DATE: 2016-02-07
 * PURPOSE: Draws geometry on the scree
 */

#include <stdio.h>
#include <stdlib.h>

void plot(int x1, int y1, int x2, int y2);
void preLine(int y);
void preSpace(int x);

int main(void) {
	system("echo off");

	while (1) {
		int x1, x2, y1, y2;
		printf("Enter the coordinates of the line (x1, y1), (x2, y2): ");
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		system("cls");
		plot(x1, y1, x2, y2);

		system("pause");
	}
	return 0;
}

void plot(int x1, int y1, int x2, int y2) {
	int min_y, min_x;
	int max_y, max_x;
	
	// find min, max of y
	if (y1 < y2) {
		min_y = y1;
		max_y = y2;
	}
	else if (y1 > y2) {
		min_y = y2;
		max_y = y1;
	}
	else {
		min_y = -1;
	}

	// find minimum x -- only if min_y == -1 (horizontal line)
	if (min_y) {
		if (x1 < x2) {
			min_x = x1;
			max_x = x2;
		}
		else if (x1 > x2) {
			min_x = x2;
			max_x = x1;
		}
		else {
			min_x = -1;
		}
	}

	// if no length (min_x and min_y are -1)
	if (min_x == -1 && min_y == -1) {
		// print empty lines before the first point
		preLine(y1);

		// print the space before the point
		preSpace(x1);

		// print dot
		printf("#\n");
	}
	// if horizontal line
	else if (min_y == -1){
		// print empty lines and space before the line
		preLine(y1);
		preSpace(x1);

		// draw line until x2
		for (int i = x1; i < x2; i++) {
			printf("#");
		}

		// draw the end point
		printf("#\n");
	}
	// if vertical line
	else if (min_x == -1) {
		preLine(min_y);
		for (int i = min_y; i <= max_y; i++) {
			preSpace(x1);
			printf("#\n");
		}
	}
	// if anything else
	else {
		// TEST - print the 2 end points
		preLine(min_y);
		preSpace(min_x);
		printf("#\n");
		preLine(max_y - min_y);
		preSpace(max_x);
		printf("#\n");
	}
}

void preLine(int y) {
	for (int i = 0; i < y - 1; i++) {
		printf("\n");
	}
}

void preSpace(int x) {
	for (int i = 0; i < x - 1; i++) {
		printf(" ");
	}
}