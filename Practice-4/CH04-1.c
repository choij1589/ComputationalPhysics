//==== Date: Sep. 29, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== gcc CH04-1.c -lm -o CH04-1.out

//==== Problem 1. By use of the trapezoidal rule
//==== with the step size h = 0.1, calculate the numerical values
//==== Integral(0 to x_i) exp(s)ds for x_i = i/N with 1 <= i <= N
//==== (i is an integer) and N = 10. Calculate the root-mean-square
//==== error sigma (as defined in the homework of Ch.03) from the
//==== analytic values.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function declarations
double i_exps_anal(const double start, const double end);
double i_exps_trip(const double start, const double end, const double step);


// entry point
int main() {
	const double step = 0.1;
	const double N = 10.;
	double sigma = 0.;
	printf("upper bound\tanalytic\ttrapezoidal\n");
	for (unsigned int i = 1; i <= 10; i++) {
		const double start = 0.;
		const double end = i/N;
		// want to use cout...
		printf("%f\t%f\t%f\n", end, i_exps_anal(start, end), i_exps_trip(start, end, step));
		sigma += pow(i_exps_anal(start, end)-i_exps_trip(start, end, step), 2) / N;
	}
	sigma = sqrt(sigma);
	printf("standard deviation = %f\n", sigma);
}

// function definitions
double i_exps_anal(const double start, const double end) {
	return exp(end) - exp(start);
}

double i_exps_trip(const double start, const double end, const double step) {
	// check whether (b-a)/h is an integer
	double n_trips = (end-start)/step;
	const double epsilon = 1e-6;
	if (fabs(n_trips - floor(n_trips+0.5)) > epsilon) {
		printf("range %e is not an integral multiple of the step size %e\n", end-start, step);
		exit(EXIT_FAILURE);
	}

	double out = 0.;
	for (unsigned int i = 0; i <= n_trips; i++) {
		out += exp(start+i*step)*step;
	}
	out -= 1./2.*(exp(start)+exp(end))*step;

	return out;
}
