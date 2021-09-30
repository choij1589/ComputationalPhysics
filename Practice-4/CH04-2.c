//==== Date: Sep. 30, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== gcc CH04-2.c -lm -o CH04-2.out

//==== Problem 2. Repeat #1 with the step size h = 0.1/2^j,
//==== where 0 <= j < 10 (j is an integer)
//==== -> List the values of sigma/h^2 for each j in the summary report

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MY_N 10

// function declarations
// reusing from CH04-1.c
double i_exps_anal(const double start, const double end);
double i_exps_trip(const double start, const double end, const double step);
double rms_error(double analytics[], double approxs[]);

// entry point
int main() {
	// initialize arrays
	double analytics[MY_N], approxs[MY_N];
	
	// iteration for the step size
	printf("step\tsigma\n");
	for (unsigned int j = 0; j < 10; j++) {
		const double step = 0.1/pow(2, j);

		// iteration for the end point
		for (unsigned int i = 0; i < 10; i++) {
			const double start = 0.;
			const double end = (i+1)/MY_N;
			analytics[i] = i_exps_anal(start, end);
			approxs[i] = i_exps_trip(start, end, step);
		}
		const double sigma = rms_error(analytics, approxs);
		printf("%e\t%e\n", step, sigma/pow(step, 2));
	}
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

double rms_error(double analytics[MY_N], double approxs[MY_N]) {
	// check the size of the array first
	// if ((sizeof(analytics)/sizeof(double)) != (sizeof(approxs)/sizeof(double))) {
	//	printf("both array should have the same size\n");
	//	printf("%d\t%d\t%d\n", sizeof(analytics)/sizeof(double), sizeof(approxs)/sizeof(double), size);
	//	exit(EXIT_FAILURE);
	//}

	// not calculate the rms error
	double sigma = 0.;
	for (unsigned int i = 0; i < MY_N; i++)
		sigma += pow(analytics[i] - approxs[i], 2)/MY_N;
	sigma = sqrt(sigma);

	return sigma;
}
