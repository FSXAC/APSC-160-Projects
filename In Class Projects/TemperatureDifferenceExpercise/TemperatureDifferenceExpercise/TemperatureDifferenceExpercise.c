/* Name: Mansur
 * Date: 2016-01-11
 * Purpose: Take in two values of temperature in celsius,
 * find the difference, and output the difference in fahrenheit
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  double celsius1, celsius2;

  printf("Enter first temperature: ");
  scanf("%lf", &celsius1);

  printf("Enter second temperature: ");
  scanf("%lf", &celsius2);

  printf("The temperature you have entered is %.1lf*C and %.1lf*C", celsius1, celsius2);
  printf("\nThe temperature difference in fahrenheit is %.1lf*F\n\n",
        (celsius2 - celsius1) * 1.8 + 32);

  system("pause");
  return 0;
}
