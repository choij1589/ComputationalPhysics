//==== Date: Sep. 23, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== gcc CH03-1.c -lm -o CH03-1.out

///////////////////////////////////////////////////////////////////////////
//==== Problem 1. Calculate the numerical values (d/dx)(logx)|_(x=1) ====//
//==== by use of the 3-point and 5-point formulae with step size     ====//
//==== h=1e-i, where 1 <= i <= 8 (i is an integer).                 ====//
//==== Then, by comparing the results with the analytic value,       ====//
//==== find the major origin of the numerical errors.                ====//
//==== -> Write the calculated values with the difference from the   ====//
//==== analytic values and then, briefly discuss major origin        ====//
//==== of the numerical errors in the summary report.                ====//
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function declarations
double dlogx(const double x);						// returns the analytic valus of (d/dx)(logx)
double dlogx3p(const double x, const double step);	// returns the 3-point derivative of (d/dx)(logx)
double dlogx5p(const double x, const double step);	// returns the 5-point derivative of (d/dx)(logx)

// entry point
int main() {
	FILE *f;
	f = fopen("CH03-1.dat", "w");
	printf("step\tdlogx\tdlogx3p\tdlogx5p\tdiff3p\tdiff5p\n");
	fprintf(f, "step\tdlogx\tdlogx3p\tdlogx5p\tdiff3p\tdiff5p\n");
	for (int i = 1; i <= 8; i++) {
		const double step = 1. * pow(10., -i);

		const double dlogx_1 = dlogx(1.);
		const double dlogx3p_1 = dlogx3p(1., step);
		const double dlogx5p_1 = dlogx5p(1., step);
		
		printf("%e\t%e\t%e\t", step, dlogx_1, dlogx3p_1, dlogx5p_1);
		printf("%e\t%e\n", dlogx3p_1 - dlogx_1, dlogx5p_1 - dlogx_1);
		fprintf(f, "%e\t%e\t%e\t", step, dlogx_1, dlogx3p_1, dlogx5p_1);
		fprintf(f, "%e\t%e\n", dlogx3p_1 - dlogx_1, dlogx5p_1 - dlogx_1);
	}
	fclose(f);
	return 0;
}

// function definitions
double dlogx(const double x) {
	// check input condition
	if (!(x > 0.)) {
		printf("x should be positive, but got %f", x);
		exit(EXIT_FAILURE);
	}
	return 1./x;
}

double dlogx3p(const double x, const double step) {
	// check input conditions
	if (!(x > 0. && step > 0.)) {
		printf("x and step should be positive, but got %f%f", x, step);
		exit(EXIT_FAILURE);
	}
	return (log(x+step) - log(x-step))/(2*step);
}

double dlogx5p(const double x, const double step) {
	// check input conditions
	if (!(x> 0. && step > 0.)) {
		printf("x and step should be positive, but got %f%f", x, step);
		exit(EXIT_FAILURE);
	}
	return (-log(x+2.*step) + 8.*log(x+step) - 8.*log(x-step) + log(x-2.*step))/(12.*step);
}
