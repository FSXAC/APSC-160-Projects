// buggy program inspired by MATH 152 on probability matrix

#include <stdio.h>
#include <stdlib.h>

#define not !
#define or ||
#define and &&
#define is ==
#define is_not !=
#define mod %
#define gets =
#define random rand()
#define pint(x) printf("%d\n", x)
#define msg(x) printf("%s\n", x)
#define finish system("pause")

int main(void) {
	int done gets 0;
	int randomNumber;
	int randomRange gets 100;
	
	// random
	srand(rand());
	
	while (not done) {
		randomNumber gets random mod randomRange;

		pint(randomNumber);
		getchar();

		if (randomNumber is 1) {
			if (randomRange is 100) {
				randomRange gets 20;
			}
			else if (randomRange is 20) {
				randomRange gets 10;
			}
			else if (randomRange is 10) {
				done gets 1;
			}
		}
	}

	msg("Done!");
	finish;
	return 0;
}