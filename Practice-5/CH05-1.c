//==== Date: Oct.6, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== gcc CH05-1.c -lm -o CH05-1.out

//==== Problem 1. Modify CH05-2.c to find all the roots of
//==== x^4 - 6x^3 + 7x^2 + 6x - 8 = 0
//==== by use of the bisection method,
//==== where all the roots are within [-1, 6]

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototypes
double ftn(double x);
double BiSection(double (*func)(double), double a, double b, 
				 const double err, unsigned int *n_iter);

// entry point
int main() {
	const double dx = 0.1, err = 1e-12;
	double ftn(double x);

	for (double x=-2.; x<=7.; x+=dx) {
		double a = x-dx/2., b = x+dx/2.;
		if (ftn(a)*ftn(b) < 0) {
			unsigned int n_iter = 0;
			const double root = BiSection(&ftn, a, b, err, &n_iter);
			printf("%f\t%d\n", root, n_iter);
		}
	}

	return 0;
}

// function definitions
double ftn(double x) {
	return pow(x, 4)-6.*pow(x, 3)+7.*pow(x, 2)+6.*x-8;
}

double BiSection(double (*func)(double), double a, double b, 
		         const double err, unsigned int *n_iter) {
	double c;
	do {
		c = (a+b)/2.;
		if ((*func)(a) * (*func)(c) < 0)
			b = c;
		else
			a = c;

		(*n_iter)++;
	} while (b-a > err);

	return c;
}
		

