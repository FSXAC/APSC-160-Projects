/* Name: Mansur
 * Date: 2016-01-10
 * Purpose: Compute and output the mass of a steel block given the
 * density and dimensions.
 */

#include <stdio.h>
#include <stdlib.h>

#define DENSITY_STEEL 7850.0

int main(void) {
	float width, length, height, volume;
	
	// user inputs
	printf("Enter width in meters:");
	scanf("%f", &width);
	
	printf("Enter length in meters:");
	scanf("%f", &length);
	
	printf("Enter height in meters:");
	scanf("%f", &height);
	
	// calculations
	volume = width * length * height;

	// output
	printf("\nThe volume of the steel block is %fm^3\nThe mass of the steel block is "
		   "%.1fkg\n\n", volume , volume * DENSITY_STEEL);
	
	system("pause");
	return 0;
}
	
