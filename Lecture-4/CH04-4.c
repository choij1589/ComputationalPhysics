// Monte-Carlo integration
// gcc -lm CH04-4.c -o CH04-4.out
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
	// Use current time as seed for random generator
	srand(time(NULL));
	const long N = 1000000L;

	printf("n\tPI\n");
	for (long n = 1; n <= N; n *= 10) {
		long hit = 0, fail = 0;
		for (long i = 0; i < n; i++) {
			const double x = (double)rand()/RAND_MAX;
			const double y = (double)rand()/RAND_MAX;

			if (pow(x, 2) + pow(y, 2) <= 1) 
				hit++;
			else
				fail++;
		}
		printf("%ld\t%f\n", n, 4*(double)hit/(double)n);
	}
	return 0;
}
