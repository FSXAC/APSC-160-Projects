/* Author: Mansur He
 * Date 2016-01-22
 * Purpose: calculates the average of numbers entered by user
 * If user enters -1, the program stops accepting values
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int sum = 0, nextVal = -1, count = 0;

  printf("This program calculates the average number"
         " entered by the user.\n\nEnter -1 to stop.\n");

  printf("Enter positive integer: ");
  scanf("%i", &nextVal);

  while (nextVal != -1) {
    sum += nextVal;
    count++;

    printf("Enter positive integer: ");
    scanf("%i", &nextVal);
  }

  if (!count) {
    printf("Error: at least one positive integer expected.");
  } else {
    printf("Average: %lf", (double) sum / count);
  }

  return 0;
}
