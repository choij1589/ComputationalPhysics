//==== Date: Oct.15, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== gcc CH06-1.c -lm -o CH06-1.out

//==== Problem 1. Modify CH06-1.c to interpolate the function
//==== y = x^4-6x^3+7x^2+6x-8 with N=4 (N is defined in the code)
//==== and sampling range over [-8, 8] with the same sampling interval.

#include <stdio.h>
#include <math.h>

// # define N	3
#define N	4

double ftn(double x) {
	// return sin(x);
	return pow(x, 4) - 6*pow(x, 3) + 7*pow(x, 2) + 6*x - 8;
}

double L(double x, int i, double x0[N+1]) {
	int j;
	double L0 = 1;
	for (j = 0; j <= N; j++) {
		if (i != j)
			L0 *= (x-x0[j])/(x0[i]-x0[j]);
	}

	return L0;
}

int main() {
	int i, k;
	//double h = 0.1;
	double h = (8. - (-8.)) / (N+1);
	double x0[N+1], y0[N+1];
	double f, x, var;
	double ftn(double x);
	double L(double x, int i, double *x0);

	for (i = 0; i <= N; i++) {
		x0[i] = -8. + h*i;
		y0[i] = ftn(x0[i]);
	}
	var = 0;
	for (k = 0; k <= N*10; k++) {
		x = -8. + h*k / 10;
		f = 0;
		for (i = 0; i <= N; i++)
			f += y0[i]*L(x, i, x0);
		printf("%f\t%f\t%f\t%f\n", x, f, ftn(x), f-ftn(x));
		var += (f-ftn(x))*(f-ftn(x));
	}
	printf("%e\n", sqrt(var/(N*10)));

	return 0;
}
