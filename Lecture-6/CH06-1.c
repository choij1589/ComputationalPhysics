// Lagrange polynomial, interpolation
// gcc -lm CH06-1.c -o CH06-1.out
#include <stdio.h>
#include <math.h>
#define N 3

double ftn(double x) {
	return sin(x);
}

double L(double x, int i, double x0[N+1]) {
	double L0 = 1;
	for (int j = 0; j <= N; j++) {
		if (i != j)
			L0 *= (x-x0[j])/(x0[i]-x0[j]);
	}

	return L0;
}

int main() {
	const double h = 0.1;
	double x0[N+1], y0[N+1];
	double f, x, var;
	double ftn(double x);
	double L(double x, int i, double *x0);

	for (int i = 0; i <= N; i++) {
		x0[i] = h*i;
		y0[i] = ftn(x0[i]);
	}
	
	var = 0;
	for (int k = 0; k <= N*10; k++) {
		x = h*k/10;
		f = 0;
		for (int i = 0; i <=N; i++) {
			f += y0[i]*L(x, i, x0);
		}
		printf("%f\t%f\t%f\t%f\n", x, f, ftn(x), f-ftn(x));
		var += pow(f-ftn(x), 2);
	}

	printf("%e\n", sqrt(var/(N*10)));
}
