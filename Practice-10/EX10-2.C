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
	
	const unsigned long max_iter = pow(10, 6);
	const unsigned long nbins = 100;
	FILE *file;
	long hist[nbins] = {0};

	for (unsigned int i = 0; i < max_iter; i++) {
		double gen = acos(uniform_generator(0., 2.) - 1);
		hist[int(gen*nbins/M_PI)]++;
	}

	file = fopen("EX10-2.DAT", "w");
	for (unsigned int i = 0; i < nbins; i++)
		fprintf(file, "%d\t%d\n", i, hist[i]);
	fclose(file);
		
	return 0;
}
