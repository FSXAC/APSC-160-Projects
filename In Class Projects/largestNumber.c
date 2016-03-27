/* Author: Mansur He
 * Date 2016-01-23
 * Purpose: finds the largest positive integer entered by the user
 * If user enters -1, the program stops accepting values
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int userValue = 0, largestValue = -1;
  _Bool isDone = 0;

  // keep looping until user enters -1
  while (!isDone) {

    // user input
    printf("Enter a positive number (enter \"-1\" to quit): ");
    scanf("%i", &userValue);

    // check if the number is -1
    if (userValue != -1) {

      // check if the number is bigger than the current largest value stored
      if (userValue > largestValue) {
        largestValue = userValue;
        printf("Largest value now is %i\n", largestValue);
      }

    } else {
      isDone = 1;
    }
  }

  // output
  if (largestValue == -1) {
    printf("Error: at least one positive value expected");
  } else {
    printf("The largest number out of series of numbers you've entered is %i\n\n",
           largestValue);
  }
  
  // end
  printf("Press any key to continue . . .\n");
  getchar();
  return 0;
}
