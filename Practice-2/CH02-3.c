// gcc CH02-3.c -lm -o CH02-3.out
#include <stdio.h>
#include <math.h>

void main() {
	float sum = 0;
	for (unsigned int i = 1; i <= 10; i++) {
		sum += pow(0.5, pow(i, 2));
	}
	printf("answer = %f\n", sum);
}
