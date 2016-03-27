/* Author: Mansur He
 * Date: 2016-01-21
 * Purpose: asks for year, calculates whether if the year is a leap year or not
 */

#include <stdio.h>
#include <stdlib.h>

#define YEAR_INVENTED 1582

// main program
int main(void) {
  int input_year;

  // uesr input
  printf("Enter a year after 1582: ");
  scanf("%i", &input_year);

  if (input_year < YEAR_INVENTED) {
    puts("Error: expected year greater than when invented");
  } else {
    if ((input_year % 4 == 0) && !((input_year % 100 == 0)
     && (input_year % 400 != 0))) {
      puts("The year is an leap year");
    } else {
      puts("The year is not a leap year");
    }
  }

  printf("End of program . . .\n");
  getchar();
  return 0;
}
