// 0th-order integration
// gcc -lm CH04-1.c -o CH04-1.out
#include <stdio.h>
#include <math.h>

int main() {
	const double h = 1e-2;
	double ifx = 0, ifx0 = 0;
	
	printf("n*h\tifx\tifx0\n");
	for (unsigned int n = 0; n < 1000; n += 100) {
		ifx0 = 0;
		for (unsigned int i = 0; i < n; i++) {
			ifx0 += sin(i*h) * h;
		}
		ifx = 1 - cos(n*h);

		printf("%f\t%f\t%f\n", n*h, ifx, ifx0);
	}
}
