// reads files and get grade numbers
#include <stdio.h>
#include <stdlib.h>

#define directoryRead "grades.dat"
#define directoryWrite "results.dat"

int main(void) {
  FILE* getGrades = fopen(directoryRead, "r");
  FILE* putGrades = fopen(directoryWrite, "w");
  int studentID, midterm, final, grade, passed;

  if (getGrades != NULL && putGrades != NULL) {
    while (fscanf(directoryRead, "%d%d%d", &studentID, &midterm, &final) == 3) {
      passed = 0;
      grade = 0.3*midterm + 0.7*final;

      if (grade >= 50) {
        passed = 1;
      }

      fprintf("%d %d %d %d %d", studentID, midterm, final, grade, passed);
    }

    fclose(getGrades);
    fclose(putGrades);
  } else {
    printf("Error opening file\n")
  }

  return 0;
}
