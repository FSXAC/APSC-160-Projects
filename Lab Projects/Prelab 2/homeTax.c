/* Author: Mansur He
 * Date: 2016-01-21
 * Purpose: User inputs the price of their new home, program
 * calculates and outputs the tax they have to pay.
 */

#include <stdio.h>
#include <stdlib.h>

#define GROSS_TAX 0.05
#define REBATE_LOW 0.36
#define REBATE_MAX_VALUE 5000
#define PRICE_LOW 350000
#define PRICE_MID 450000

int main(void) {
  int price;
  double tax, rebate;

  printf("Enter the price of the property: $");
  scanf("%i", &price);

  if (price < 0) {
    printf("Error: you silly goose.\n\n");
  } else {
    tax = price * GROSS_TAX;

    if (price <= PRICE_LOW) {
      rebate = (REBATE_LOW * tax);
      if (rebate > REBATE_MAX_VALUE) {
        rebate = REBATE_MAX_VALUE;
      }
    } else if (price > PRICE_LOW && price < PRICE_MID) {
      rebate = 5000.0 *(PRICE_MID - price) / 100000;
    } else {
      rebate = 0;
    }

    tax -= rebate;

    printf("The tax you owe is $%.2f\n\n", tax);
  }
}
