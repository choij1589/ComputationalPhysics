// Bisection method, finding all roots
// gcc -lm CH05-5.c -o CH05-5.out
#include <stdio.h>
#include <math.h>

double ftn(double x) {
	return pow(x, 4)+2.*pow(x, 3)-13.*pow(x, 2)-14.*x+24;
}

int main() {
	const double dx = 1e-1, err=1e-6;
	double ftn(double x);

	for (double x=-5.; x<=5.; x+=dx) {
		if (ftn(x-dx/2.)*ftn(x+dx/2.) < 0.) {
			// initialize variables
			double a = x-dx/2.;
			double b = x+dx/2.;
			double c;
			unsigned int n_iter = 0;
			do {
				c = (a+b)/2.;

				if (ftn(a)*ftn(c) <= 0)
					b = c;
				else
					a = c;

				n_iter++;
			} while (fabs(a-b) > err);
			printf("%f\t%d\n", (a+b)/2, n_iter);
		}
	}

	return 0;
}
