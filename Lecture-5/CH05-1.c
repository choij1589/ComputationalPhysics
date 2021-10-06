// Bisection method, root finding
// gcc -lm CH05-1.c -o CH05-1.out
#include <stdio.h>
#include <math.h>

double ftn(double x) {
	return sin(x);
}

int main() {
	// guess the range first
	double a = -1., b = 0.5;
	double c;

	printf("a\tb\tftn(a)\tftn(c)\tftn(b)\n");
	do {
		c = (a+b)/2.;
		printf("%f\t%f\t%f\t%f\t%f\n", a, b, ftn(a), ftn(c), ftn(b));
		
		// check if the root is in the bisected range
		if (ftn(a) * ftn(c) < 0)
			b = c;
		else
			a  = c;
	}
	while (fabs(b-a) > 1e-6);

	return 0;
}
