// Secant method, root finding
// gcc -lm CH05-4.c -o CH05-4.out
#include <stdio.h>
#include <math.h>

double ftn(double x) {
	return sin(x);
}

int main() {
	double x0 = -1., x1 = 0.5, x2 = 0.;
	double ftn(double);

	do {
		x2 = (x0*ftn(x1) - x1*ftn(x0)) / (ftn(x1) - ftn(x0));
		printf("%f\t%f\t%f\t%f\t%f\n", x0, x1, x2, ftn(x0), ftn(x1));
		x0 = x1;
		x1 = x2;
	} while (fabs(x1-x0) > 1e-12);
}
