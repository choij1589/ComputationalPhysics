// gcc CH03-4a.c -lm -o CH03-4a.out
// comparison between float and double
#include <stdio.h>
#include <math.h>

void main() {
	const double h = 1e-2;
	double x, fx, ddfx0, ddfx3, ddfx5;

	printf("x\tdouble error\tfloat error\n");
	for (unsigned int i = 0; i < 10; i++) {
		x = (2*M_PI)*i / 10;
		fx = sin(x);
		ddfx0 = -sin(x);
		ddfx5 = (-sin(x+2*h) + 16*sin(x+h) - 30*sin(x) + 16*sin(x-h) - sin(x-2*h)) / (12*h*h);
		printf("%f\t%e\t%e\n", x, ddfx5-ddfx0, (float)ddfx5-(float)ddfx0);
	}
}
