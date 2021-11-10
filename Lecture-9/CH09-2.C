// Shooting Method
// gcc -lm
#include <stdio.h>
#include <math.h>

#define ftn(x, y)	((y)*(y)-(x))

double shooting(double y) {
	const unsigned int N = 1000;
	const double h = 1./N;
	double x = 0.;
	double a = 1., b = 0., aa = 0., bb = 0.;	// Euler?

	for (unsigned int i = 0; i <= N; i++) {
		x = i*h;
		y += a*h*ftn(x, y) + b*h*ftn(x+aa*h, y+bb*h*ftn(x, y));
	}
	
	return y;
}

double secant(double (*func)(double), double x0, double x1, double err) {
	double x2, f0, f1;

	do {
		f0 = (*func)(x0);
		f1 = (*func)(x1);
		x2 = (x0*f1 - x1*f0) / (f1-f0);
		x0 = x1;
		x1 = x2;
	} while (fabs(x1 - x0) > err);

	return x1;
}

int main() {
	double y, dy=1e-3, err=1e-0;
	double a, b, c;
	int num;
	FILE *file;

	// for checking up the initial guess for root finding
	file = fopen("CH09-2.DAT", "w");
	for (y = 0.; y <= 1.; y += dy)
		fprintf(file, "%f\t%f\n", y, shooting(y));
	fclose(file);

	for (y = 0.; y <= 1.; y += dy) {
		if (shooting(y-dy/2.)*shooting(y+dy/2) < 0.)
			printf("%f\n", secant(&shooting, y-dy/2., y+dy/2, err));
	}

	return 0;
}
