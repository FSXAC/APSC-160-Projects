/* Name: Mansur
 * Last Edited: 2016-01-10
 * Purpose: User enters temperature in Fahrenheit, program converts to Celsius
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
	float temp_f;
	printf("Enter Temperature (*F): ");
	scanf("%f", &temp_f);

	printf("It is %.1f degrees Celsius\n\n", (temp_f - 32) / 1.8);

	system("pause");
	return 0;
}