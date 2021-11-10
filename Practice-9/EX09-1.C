//==== Date: Oct.28, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== gcc -lm EX09-1.C

//==== Problem 1. For a function y(x), solve y' = x^2*sin(y) + y
//==== by use of a) Euler method, b) modified Euler method,
//==== c) mid-point method and d) Heun method with ititail contidion
//==== y(0) = 2 and the step size 0.001
//==== -> List the values y(10) obtained by each methods in the summary report.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double ftn(double x, double y) {
	return (pow(x, 2)*sin(y) + y);
}

//==== method 0: Euler method
//==== method 1: modified Euler method
//==== method 2: mid-point method
//==== method 3: Heun method
double RungeKutta(double (*func)(double, double), const double init_x, const double init_y, const double step, const unsigned int N, const unsigned int method=0) {
	// end_x = init_x + N*step
	double a, b, alpha, beta;
	if (method == 0) {
		printf("[RungeKutta] Using Euler method...\n");
		a = 1.; b = 0.; alpha = 0.; beta = 0.;
	}
	else if (method == 1) {
		printf("[RungeKutta] Using modified Euler method...\n");
		a = 0.5; b = 0.5; alpha = 1.; beta = 1.;
	}
	else if (method == 2) {
		printf("[RungeKutta] Using mid-point method...\n");
		a = 0.; b = 1.; alpha = 0.5; beta = 0.5;
	}
	else if (method == 3) {
		printf("[RungeKutta] Using Heun method...\n");
		a = 0.25; b = 0.75; alpha = 2./3.; beta = 2./3.;
	}
	else {
		printf("[RungeKutta] Wrong method number %d\n", method);
		exit(EXIT_FAILURE);
	}
	
	double x = init_x, y = init_y;
	for (unsigned int i = 0; i <= N; i++) {
		x = init_x + i*step;
		y += a*step*(*func)(x, y) + b*step*(*func)(x+alpha*step, y+beta*step*(*func)(x, y));
	}

	return y;
}

int main() {
	const double init_x = 0., init_y = 2., end_x = 10.;
	const double step = 0.001;
	const unsigned int N = (end_x - init_x) / step;
	double y0 = RungeKutta(&ftn, init_x, init_y, step, N, 0);
	double y1 = RungeKutta(&ftn, init_x, init_y, step, N, 1);
	double y2 = RungeKutta(&ftn, init_x, init_y, step, N, 2);
	double y3 = RungeKutta(&ftn, init_x, init_y, step, N, 3);

	printf("Euler: %f\n", y0);
	printf("Modified Euler: %f\n", y1);
	printf("Mid-point: %f\n", y2);
	printf("Heun: %f\n", y3);

	return 0;
}


