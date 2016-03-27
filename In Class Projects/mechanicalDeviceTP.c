/* Author: Mansur He
 * Date: 44638154
 * Purpose: Output if the mechanical device is working correctly or not.
 */

#include <stdio.h>
#include <stdlib.h>

// constants

#define T_MAX 300
#define T_MIN 5
#define P_MAX 150
#define T_WAT 250
#define P_WAT 100

int main(void) {
  double temperature, pressure;

  printf("Enter temperature: ");
  scanf("%lf", &temperature);

  printf("Enter pressure: ");
  scanf("%lf", &pressure);

  if (pressure <= 0) {
    printf("Error: 'pressure' input expected positive input.\n");
  } else {
    if (pressure <= P_WAT) {
      if (pressure > P_MAX) {
        printf("WARNING! Device not working normally!\n");
      } else if (temperature < T_MIN || temperature > T_MAX) {
        printf("WARNING! Device not working normally!\n");
      } else {
        printf("The device is working noramlly");
      }
    } else {
      if (temperature > T_WAT) {
        printf("WARNING! Device not working normally!\n");
      } else {
        printf("The device is working normally\n");
      }
    }
  }

  printf("End of program . . .\n\n");
  getchar();
  return 0;
}
