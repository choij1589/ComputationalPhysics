// histogram of random number generation
// gcc
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double uniform_generator(double min, double max) {
	double r = (double)rand()/RAND_MAX;
	return min+r*(max-min);
}

int main() {
	// seed
	srand(time(NULL));

	for (unsigned int i = 0; i <= 8; i++) {
		unsigned int max_iter = pow(10, i);
		double mean = 0.;
		for (unsigned int j = 0; j < max_iter; j++) {
			mean += uniform_generator(10., 20.)/max_iter;
		}
		printf("%d\t%f\n", i, mean);
	}
	return 0;
}
