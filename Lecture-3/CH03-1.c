// gcc CH03-1.c -lm -o CH03-1.out
// forward 2-point formula, 1st-order derivative
#include <stdio.h>
#include <math.h>

void main() {
	const double h = 1e-5;
	double x, fx, dfx0, dfx2p;

	printf("x\tfx\tdfx0\tdfx2p\n");
	for (unsigned int i = 0; i < 10; i++) {
		x = (2*M_PI)*i / 10;
		fx = sin(x);
		dfx0 = cos(x);
		dfx2p = (sin(x+h) - sin(x)) / h;
		printf("%f\t%f\t%f\t%f\n", x, fx, dfx0, dfx2p);
	}
}
