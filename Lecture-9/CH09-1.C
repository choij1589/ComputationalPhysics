// Runge-Kutta Method
// gcc -lm
#include <stdio.h>
#include <math.h>

double ftn(double x, double y) {
	return (pow(y, 2) - x);
}

double RungeKutta(double (*func)(double, double), const double init_x, const double init_y, const double end_x) {
	const unsigned int N = 1000;
	const double step = (end_x - init_x) / N;
	double x = init_x, y = init_y;
	double a = 1., b = 0., aa = 0., bb = 0.;	// Euler Method

	for (unsigned int i = 0; i <= N; i++) {
		x = init_x + i*step;
		y += a*step*(*func)(x, y) + b*step*(*func)(x+aa*step, y+bb*step*((*func)(x, y)));
	}

	return y;
}

	

int main() {
	double ftn(double, double);
	double res = RungeKutta(&ftn, 0., 0., 1.);
	
	printf("%.12lf\n", res);

	return 0;
}
