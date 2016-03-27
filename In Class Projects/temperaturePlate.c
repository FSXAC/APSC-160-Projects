/* Author: Mansur He
 * Date: 2016-01-27
 * Purpose: Prompts the user for the separation between points on a rectangular
 * grid, superimposed on a plate. Prints the temperature at each point on the
 * grid in tabular format to two decimal places
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 60
#define PI acos(-1.0)

int main (void) {
  int x, y, deltaX, deltaY;
  double temperature;

  printf("Enter grid horizontal resolution: ");
  scanf("%d", &deltaX);

  printf("Enter grid vertical resolution: ");
  scanf("%d", &deltaY);

  // starting with Y
  for (y = HEIGHT; y >= 0; y -= deltaY) {

    printf("Y = %d\t\t", y);

    // iterates X on the same row
    for (x = 0; x <= WIDTH; x += deltaX) {
      temperature = 10 * sin(2 * PI * (double) x / WIDTH) *
      cos(2 * PI * (double) y / HEIGHT);

      printf("%6.2f", temperature);
    }
    printf("\n");

  }

  return 0;
}
