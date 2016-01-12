/* Name: Mansur
 * Last Edited: 2016-01-12
 * Purpose: Calculate delta-length due to thermal expansion given the needed variables
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	double length_initial, a, temp_change, length_change, length_final;

	printf("Enter intial length (m): ");
	scanf("%lf", &length_initial);

	printf("Enter coefficient of thermal expansion (x10^-6): ");
	scanf("%lf", &a);

	printf("Enter temperature change: ");
	scanf("%lf", &temp_change);

	length_change = length_initial * temp_change * a * 0.000001;
	length_final = length_change + length_initial;
	printf("\nDEBUG\ni=%lf - tc=%lf - a=%lf - ap=%lf\nf=%lf", length_initial, temp_change,
	       a, a * 0.000001, length_final);

	printf("\nDelta-L: %lfm\nFinal-L: %lfm\n\n", length_change, length_final);

	system("pause");
	return 0;
}
