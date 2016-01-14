/* Name: Mansur
 * Last edited: 2016-01-10
 * Purpose: Simple quadratic solver using the quadratic formula
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	double a, b, c, det, root1, root2 ;
	printf("For the equation ax^2+bx+c, what are the 'a', 'b', and 'c' values?\n");
	scanf("%lf%lf%lf", &a, &b, &c);

	// calculations
	det = pow(b, 2) - 4 * a * c;

	if (det < 0) {
		// determinant is negative - no solution
		printf("\nNo solution is found for y = (%.4f)x^2+(%.4f)x+(%.4f)\n\n", a, b, c);
	} else if (det == 0) {
		// determinant is 0 - one solution
		root1 = (b + sqrt(det)) / (2 * a);
		printf("\nx = %f is the only root for y = (%.4fx^2)+(%.4fx)+(%.4f)\n\n", root1, a, b, c);
	} else {
		// determinant is positive - two solutions
		root1 = (b + sqrt(det)) / (2 * a);
		root2 = (b - sqrt(det)) / (2 * a);
		printf("\nx = %f and x=%f are the roots for y = (%.4fx^2)+(%.4fx)+(%.4f)\n\n", root1, 
			root2, a, b, c);
	};

	system("pause");
	return 0;
}