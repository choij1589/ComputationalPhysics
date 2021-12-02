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
	// srand(0); // for debugging
	srand(time(NULL));
	
	const unsigned long max_iter = pow(10, 4);
	const unsigned long N = pow(2, 8);
	const unsigned long nbins = 100;
	long hist[nbins] = {0};

	// make gauss distribution
	double gaus[max_iter] = {0};
	for (unsigned long i = 0; i < max_iter; i++) {
		double temp[N] = {0};
		for (unsigned long j = 0; j < N; j++) temp[j] = uniform_generator(-0.5, 0.5);
		for (unsigned long j = 0; j < N; j++) gaus[i] += temp[(i*N+j)%N]; 
	}

	// to make histogram binning (avoid underflow & overflow)
	double min = 0., max = 0.;
	for (unsigned long i = 0; i < max_iter; i++) {
		if (gaus[i] > max) max = gaus[i];
		if (gaus[i] < min) min = gaus[i];
	}

	// scale gaussian outputs and fill the histogram
	// e.g. if the output is 1.3, than it goes to (1.3 - min)/(max-min) * total-bin-numbers
	for (unsigned long i = 0; i < max_iter; i++) hist[int((gaus[i]-min)/(max-min)*nbins)]++;

	// now calculate standard deviation
	double mean = 0.;
	for (unsigned long i = 0; i < max_iter; i++) mean += gaus[i]/max_iter;
	double var = 0.;
	for (unsigned long i = 0; i < max_iter; i++) var += pow(gaus[i] - mean, 2)/max_iter;
	double std = sqrt(var);
	
	// write the results
	FILE *file;
	file = fopen("EX10-3.DAT", "w");
	fprintf(file, "max:\t%f\tmin:\t%f\n", max, min);
	fprintf(file, "std:\t%f\n", std);
	for (unsigned int i = 0; i < nbins; i++) fprintf(file, "%d\t%d\n", i, hist[i]);
	fclose(file);
		
	return 0;
}
