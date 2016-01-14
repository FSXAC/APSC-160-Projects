/* Author: Mansur
 * Date: 2016-01-13
 * Purpose: ask the user for initial velocity, initial position, and time
 * and the program outputs the position of the particle s(t)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// constants
#define K_CONSTANT 0.5
#define MASS 2.0

#define ANG_FREQ sqrt(K_CONSTANT / MASS)

// main function
int main(void) {
  double v_i, x_i, x_f, t, angular_f;

  // ask the user for initial values
  printf("Enter initial velocity (m/s): ");
  scanf("%lf", &v_i);

  printf("Enter initial position (m): ");
  scanf("%lf", &x_i);

  printf("Enter time (s): ");
  scanf("%lf", &t);

  // calculation
  x_f = x_i * cos(ANG_FREQ * t) + (v_i / ANG_FREQ) * sin(ANG_FREQ * t);

  // output
  printf("The position of the particle at t=%lfs with initial position and"
         " velocity %lfm and %lfm/s respectively is %lfm\n\n", t, v_i, x_i, x_f);

  // end
  /*printf("Press any key to continue . . .\n");
  getchar();*/

  system("pause");
  return 0;
}
