// gcc - lm
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
	
	const unsigned long max_iter = 10000;
	double Q[21] = {0};

	double distribution[max_iter];
	for (unsigned long i = 0; i < max_iter; i++)
		distribution[i] = uniform_generator(-1., 1.);

	for (int n = -10; n <= 10; n++)
		for (unsigned long i = 0; i < max_iter; i++)
			Q[n+10] += distribution[i]*distribution[(i+n)%max_iter];
	
	FILE *file;
	file = fopen("EX10-4.DAT", "w");
	for (int n = -10; n <= 10; n++)
		fprintf(file, "%d\t%f\n", n, Q[n+10]);
	fclose(file);
		
	return 0;
}
