// Neville recursive method
// gcc -lm CH06-2.c -o CH06-2.out
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

double Neville(double x, int i, int j, double x0[N+1], double y0[N+1]) {
	if (i == j)
		return (y0[i]);
	else
		return (((x-x0[j])*Neville(x, i, j-1, x0, y0)-(x-x0[i])*Neville(x, i+1, j, x0, y0))/(x0[i]-x0[j]));
}

int main() {
	double x, f;
	double x0[N+1], y0[N+1];
	FILE *file;

	file = fopen("CH06-2.dat", "r");
	for (int i = 0; i <= N; i++) {
		fscanf(file, "%lf", &x0[i]);
		fscanf(file, "%lf", &y0[i]);
	}
	fclose(file);

	file = fopen("CH06-2NEV.dat", "w");
	for (x = x0[0]; x <= x0[N]; x+= 0.1)
		fprintf(file, "%f\t%f\n", x, Neville(x, 0, N, x0, y0));
	fclose(file);
}
