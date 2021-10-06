// Regular Falsi method, finding all roots
// gcc -lm CH05-3.c -o CH05-3.out
#include <stdio.h>
#include <math.h>

double ftn(double x) {
	return pow(x, 4)+2.*pow(x, 3)-13.*pow(x, 2)-14*x+24;
}

double RegularFalsi(double (*func)(double), double a, double b, const double err) {
	double c;
	while (b-a > err) {
		c = (a*(*func)(b) - b*(*func)(a)) / ((*func)(b) - (*func)(a));
		if (c-a <= err || b-c <= err)
			break;
		if ((*func)(a) * (*func)(b) < 0)
			b = c;
		else
			a = c;
	}

	return c;
}

int main() {
	const double dx=1e-1, err=1e-6;
	double ftn(double);

	for (double x=-5.; x<=5.; x+=dx) {
		if (ftn(x-dx/2.)*ftn(x+dx/2.) < 0.)
			printf("%f\n", RegularFalsi(&ftn, x-dx/2., x+dx/2., err));
	}


	return 0;
}
	
