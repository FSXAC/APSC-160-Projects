/* Author: Mansur
 * Date: 2016-01-13
 * Purpose: ask the user for radius, returns volume
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI acos(-1.0)

int main(void) {
  double radius, volume;

  printf("Enter radius of the sphere (cm): ");
  scanf("%lf", &radius);

  // do the calculations
  volume = (4.0/3.0) * PI * pow(radius, 3.0);

  printf("The volume of sphere with radius %.4lfcm is %.4lfcm^3",
         radius, volume);

  printf("\n\nPress any key to continue . . .");
  getchar();

  return 0;
}
