//==== Date: Oct.14, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== gcc CH06-2.c -lm -o CH06-2.out

//==== Problem 2. Modify #1 to use the Neville recursive method.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N	4

double ftn(double x) {
	// return sin(x);
	return pow(x, 4) - 6*pow(x, 3) + 7*pow(x, 2) + 6*x - 8;
}

double Nev(double x, int i, int j, double x0[N+1], double y0[N+1]) {
	if (i > j)
		// ill defined
		exit(EXIT_FAILURE);
	else if (i == j)
		return y0[i];
	else
		return ((x-x0[j])*Nev(x, i, j-1, x0, y0) - (x-x0[i])*Nev(x, i+1, j, x0, y0)) / (x0[i]-x0[j]);
}


int main() {
	double x0[N+1], y0[N+1];
	const double step = 16. / (N+1); // equal spacing [-8, 8]
	double ftn(double x);
	for (int i = 0; i <= N; i++) {
		x0[i] = -8. + step*i;
		y0[i] = ftn(x0[i]);
	}

	double std = 0.;
	unsigned int grid = 0;
	for (double x = -8.; x <= 8.; x += 0.1) {
		grid++;
		const double f = Nev(x, 0, N, x0, y0);
		printf("%f\t%f\t%f\t%f\n", x, f, ftn(x), f-ftn(x));
		std += pow(f - ftn(x), 2);
	}
	std = sqrt(std/grid);
	printf("%e\n", std);
	return 0;
}
