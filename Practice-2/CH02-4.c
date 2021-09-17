// gcc CH02-4.c -lm CH02-4.out
#include <stdio.h>
#include <math.h>

void main() {
	const unsigned int N = 10000;
	float sum = 0, avg = 0, var = 0, std = 0;
	
	// first calculate the sum
	for (unsigned int i = 0; i < N; i++) {
		sum += sin(2*M_PI*i/N);
	}
	avg = sum / N;

	// now calcualte the variance & standard deviation
	for (unsigned int i = 0; i < N; i++) {
		var += (pow(sin(2*M_PI*i/N) - avg, 2) / N);
	}
	std = sqrt(var);

	printf("average = %f\n", avg);
	printf("stadard deviation = %f\n", std);
}
