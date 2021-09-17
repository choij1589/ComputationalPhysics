// gcc Ch02-4.c -lm -o Ch02-4.out
#include <stdio.h>
#include <math.h>

void main() {
	const unsigned int N = 10;
	unsigned int data[N];
	float sum = 0, avg = 0, var = 0, std = 0;

	for (unsigned int i = 0; i < N; i++) {
		data[i] = i;
		sum += data[i];
	}
	avg = sum / N;
	
	for (unsigned int i = 0; i < N; i++) {
		var += pow((data[i] - avg), 2);
	}
	std = sqrt(var/N);
	
	printf("average: %f\n", avg);
	printf("stadard deviation: %f\n", std);
}
