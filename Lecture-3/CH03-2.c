// gcc CH03-2.c -lm -o CH03-2.out
// 2, 3, 5-point formulat, 1st-order derivative
#include <stdio.h>
#include <math.h>

void main() {
	const double h = 1e-5;
	double x, fx, dfx0, dfx2p, dfx2m, dfx3, dfx5;

	printf("dfx0\tdfx2p\tdfx2m\tdfx3\tdfx5\n");
	for (unsigned int i = 0; i < 10; i++) {
		x = (2*M_PI)*i / 10;
		fx = sin(x);
		dfx0 = cos(x);
		dfx2p = (sin(x+h) - sin(x)) / h;
		dfx2m = (sin(x) - sin(x-h)) / h;
		dfx3 = (sin(x+h) - sin(x-h)) / (2*h);
		dfx5 = (-sin(x+2*h) + 8*sin(x+h) - 8*sin(x-h) + sin(x - 2*h)) / (12*h);
		printf("%f\t%f\t%f\t%f\t%f\n", dfx0, dfx2p, dfx2m, dfx3, dfx5);
	}
}
