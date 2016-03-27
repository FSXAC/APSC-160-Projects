// write to file a table of x and sin(x)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define directory "sineTable.dat"
#define PI acos(-1.0)

int main(void) {
  FILE* sineTable = fopen(directory, "w");
  int n, count = 0;
  double x;

  if (sineTable != NULL) {
    printf("Enter number 'n': ");
    scanf("%d", &n);

    fprintf(sineTable, "    x sin(x)\n");

    while (count < n) {
      x = ++count * PI / n;
      fprintf(sineTable, "%5.3f ", x);
      fprintf(sineTable, "%5.4f\n", sin(x));
    }

    fclose(directory);
    
  } else {
    printf("error opening");
  }
  return 0;
}
