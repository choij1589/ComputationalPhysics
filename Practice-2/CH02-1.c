// gcc CH02-1.c -lm -o CH02-1.out
#include <stdio.h>
#include <math.h>
void main() {
	unsigned int sum = 0;
	for (unsigned int i = 0; i <= 30; i++) {
		sum += (pow(i, 2) + 2*i);
	}
	printf("answer = %d\n", sum);
}
