// gcc CH03-3.c -lm -o CH03-3.out
// 3-point formula, 2nd-order derivative
#include <stdio.h>
#include <math.h>

void main() {
	const double h = 1e-5;
	double x, fx, ddfx0, ddfx3, ddfx5;

	printf("ddfx0\tddfx3\tddfx5\n");
	for (unsigned int i = 0; i < 10; i++) {
		x = (2*M_PI)*i / 10;
		fx = sin(x);
		ddfx0 = -sin(x);
		ddfx3 = (sin(x+h) - 2*sin(x) + sin(x-h)) / (h*h);
		ddfx5 = (-sin(x+2*h) + 16*sin(x+h) - 30*sin(x) + 16*sin(x-h) - sin(x-2*h)) / (12*h*h);
		printf("%f\t%f\t%f\n", ddfx0, ddfx3, ddfx5);
	}
}
