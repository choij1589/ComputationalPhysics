// Least square fitting
// gcc -lm CH06-3.c -o CH06-3.out
#include <stdio.h>
#include <math.h>

#define N 100

double ftn(double x) {
	return sin(x);
}

int main() {
	const double h = 0.1;
	double aa, bb;
	double a11, a12, a21, a22, b1, b2;
	double x0[N], y0[N];

	for (int i = 0; i < N; i++) {
		x0[i] = h*i;
		y0[i] = h*i + ftn(x0[i])*0.01;
	}

	a11 = 0; a12 = 0; b1 = 0; b2 = 0;
	for (int  i = 0; i < N; i++) {
		a11 += x0[i]*x0[i];
		a12 += x0[i];
		b1 += x0[i]*y0[i];
		b2 += y0[i];
	}
	a21 = a12;
	a22 = N;

	aa = (a22*b1 - a12*b2)/(a11*a22 - a12*a21);
	bb = (a11*b2 - a21*b1)/(a11*a22 - a12*a21);

	printf("%f\t%f\n", aa, bb);

	return 0;
}
