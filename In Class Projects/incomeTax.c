/* Author: Mansur
 * Date: 2016-01-20
 * Purpose: prompts user for income and prints income tax owing
 */

#include <stdio.h>
#include <stdlib.h>

#define BASE_CUTOFF 12500.0
#define MID_CUTOFF 65000.0
#define MID_RATE 0.24
#define HIGH_RATE 0.32
#define HIGH_BASE_TAX 12600.0

int main(void) {
  double income, taxOwing;

  printf("Please enter your income: ");
  scanf("%lf", &income);

  if (income <= BASE_CUTOFF) {
    taxOwing = 0.0;
  } else if (income > BASE_CUTOFF && income < MID_CUTOFF) {
    taxOwing = (income - BASE_CUTOFF) * MID_RATE;
  } else {
    taxOwing = HIGH_BASE_TAX + (income - MID_CUTOFF) * HIGH_RATE;
  }

  printf("Tax owing: $%.2f\n", taxOwing);

  printf("End of program . . .\n\n");
  getchar();
  return 0;
}
