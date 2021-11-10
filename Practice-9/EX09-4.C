//==== Date: Oct.28, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== gcc -lm EX09-4.C

//==== Problem 4. For a function x(t), solve
//==== cos(2pit)x'' + 2x' + 4x = sin(2pit)exp(-t)
//==== by the relaxation method wiht the boundary condition
//==== x(0) = 1 and x(2) = 1. (step size = 0.01)
//==== -> Write the value x(1) in the summary report.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	const double alpha = 1., beta = 1.;
	const double step = 0.01;
	const unsigned int N = (2. - 0.) / step;
	double A[N][N] = {0.};
	double X[N];

	// initialze matrix
	for (unsigned int i = 0; i < N; i++) {
		double t = 0. + (i+1)*step;
		const double a = cos(2.*M_PI*t), b = 2., c = 4., d = sin(2.*M_PI*t)*exp(-t);
		A[i][i] = -2.*a + c*pow(step, 2);
		if (i != 0) A[i][i-1] = a - (0.5)*b*step;
		if (i != N-1) A[i][i+1] = a + (0.5)*b*step;
		X[i] = d*pow(step, 2);
	}
	X[0] -= alpha*(cos(2.*M_PI*0) - (0.5)*2.*step);
	X[N-1] -= beta*(cos(2.*M_PI*0) + (0.5)*2.*step);

	for (unsigned int i = 0; i < N; i++){
		for (unsigned int j = 0; j < N; j++) {
			if (i != j) {
				double r = A[j][i] / A[i][i];
				for (unsigned int k = 0; k < N; k++)
					A[j][k] -= r*A[i][k];
				X[j] -= r*X[i];
			}
		}
	}

	for (unsigned int i = 0; i < N; i++) {
		X[i] = X[i] / A[i][i];
		printf("%f\n", X[i]);
	}
	return 0;
}


