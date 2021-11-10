//==== Date: Oct.28, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== gcc -lm EX09-2.C

//==== Problem 2. For functions y(x) and z(x), solve
//==== y' = x - y + z and z' = xyz by use of the  modified Euler method
//==== with the initial condition y(0) = 1 and z(0) = 0.5. (step size = 0.001)
//==== -> Write the values y(1) and z(1) in the summary report

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f1(double x, double y1, double y2) {
	return (x - y1 + y2);
}
double f2(double x, double y1, double y2) {
	return (x*y1*y2);
}

//==== method 0: Euler method
//==== method 1: modified Euler method
//==== method 2: mid-point method
//==== method 3: Heun method
void RungeKutta(double (*f1)(double, double, double), double (*f2)(double, double, double), const double init_x, const double init_y1, const double init_y2, const double step, const unsigned int N, const unsigned int method=0) {
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
	
	double x = init_x, y1 = init_y1, y2 = init_y2;
	for (unsigned int i = 0; i <= N; i++) {
		x = init_x + i*step;
		y1 += a*step*(*f1)(x, y1, y2) + b*step*(*f2)(x+alpha*step, y1+beta*step*(*f1)(x, y1, y2), y2+beta*step*(*f2)(x, y1, y2));
		y2 += a*step*(*f2)(x, y1, y2) + b*step*(*f2)(x+alpha*step, y1+beta+step*(*f1)(x, y1, y2), y2+beta+step*(*f2)(x, y1, y2));
	}

	printf("y1: %f, y2: %f\n", y1, y2);
}

int main() {
	const double init_x = 0., init_y1 = 1., init_y2 = 0.5, end_x = 1.;
	const double step = 0.001;
	const unsigned int N = (end_x - init_x) / step;
	RungeKutta(&f1, &f2, init_x, init_y1, init_y2, step, N, 1); // modified-Euler method

	return 0;
}


