// 2nd-order integration (Simpson rule)
// gcc -lm CH04-3.c -o CH04-3.out
#include <stdio.h>
#include <math.h>

int main() {
	const double h=1e-2;
	double ifx, ifx0, ifx1, ifx2, ifx4;

	printf("n*h\tifx\tifx0\tifx1\tifx2\tifx4\n");
	for (unsigned int n = 0; n < 1000; n += 100) {
		ifx0 = 0; ifx1 = 0; ifx2 = 0; ifx4 = 0;
		for (unsigned int i = 0; i < n; i++)
			ifx0 += sin(0.+i*h) * h;
		
		for (unsigned int i = 0; i <= n; i++)
			ifx1 += sin(0+i*h) * h;
		ifx1 -= 1./2. * (sin(0) + sin(n*h)) * h;
		
		for (unsigned int i=1; i<n; i+=2) {
			ifx2 += 4./3. * sin(0+i*h)*h;
			ifx2 += 2./3. * sin(0+(i+1)*h)*h;
		}
		ifx2 += 1./3.*sin(0.)*h;
		ifx2 -= 1./3.*sin(n*h)*h;
		
		// add bode rule
		for (unsigned int i = 1; i <= n-1; i += 2) {
            if (n == 0) break; // termination does not work for n == 0?
			ifx4 += 64./45. * sin(0+i*h)*h;
        }
			
        for (unsigned int i = 2; i <= n-2; i += 4) {
			if (n == 0) break;
            ifx4 += 24./45. * sin(0+i*h)*h;
        }
        
		for (unsigned int i = 4; i <= n-4; i += 4) {
			if (n == 0) break;
            ifx4 += 28./45. * sin(0+i*h)*h;
        }
		
        ifx4 += 14./45.*(sin(0.)+sin(n*h))*h;
		
		ifx = 1 - cos(n*h);

		printf("%f\t%f\t%f\t%f\t%f\t%f\n", n*h, ifx, ifx0, ifx1, ifx2, ifx4);
	}
}
