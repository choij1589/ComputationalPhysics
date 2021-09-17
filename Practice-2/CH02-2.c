// gcc CH02-2.c -lm -o CH02-2.out
#include <stdio.h>
#include <math.h>

void main() {
	unsigned int sum = 0;
	unsigned int i = 0;
	do {
		i++;
		sum += (pow(i, 2) + 2*i);
	} while (sum != 2091);
	printf("answer = %d\n", i);
}
