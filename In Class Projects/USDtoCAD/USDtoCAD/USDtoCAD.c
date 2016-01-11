/* Name: Mansur
 * Date: 2016-01-11
 * Purpose: User enters the conversion rate of USD to CAD and the amount in
 * USD, the program converts from USD to CAD and prints out to 2 decimal
 * places
 */

 #include <stdio.h>
 #include <stdlib.h>

 int main(void) {
   double conversionRate, usd;

   printf("Enter conversion rate of USD to CAD: ");
   scanf("%lf", &conversionRate);

   printf("Enter USD: ");
   scanf("%lf", &usd);

   printf("Amount in USD: %.2lf\nAmount in CAD: %.2lf\nConversion Rate: %.2lf\n\n",
         usd, usd * conversionRate, conversionRate);

   system("pause");
   return 0;
 }
