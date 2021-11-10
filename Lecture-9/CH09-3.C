// Relexation method
// gcc -lm
#include <stdio.h>
#include <math.h>

#define N	99
#define d(x)	(sin(2*M_PI*(x)))

int main() {
	FILE *file;
	double h = 1./(N+1), a = 1., b = 1., c = 1.;
	double alpha =  0., beta = 0., r;
	double A[N][N] = {0.};
	double X[N];

	for (int i = 0; i < N; i++)
		A[i][i] = h*h*c - 2.*a;
	
	for (int i = 0; i < N; i++)
		A[i-1][i] = a+0.5*b*h;

	for (int i = 0; i < N; i++)
		A[i][i-1] = a-0.5*b*h;

	for (int i = 0; i < N; i++)
		X[i] = h*h*d(h*i);
	X[1] -= (a-0.5*b*h)*alpha;
	X[N-1] -= (a+0.5*b*h)*beta;

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
		if (i != j) {
			r = A[j][i] / A[i][i];
			for (int k = 0; k < N; k++)
				A[j][k] -= r*A[i][k];
			X[j] -= r*X[i];
		}

	for (int i = 0; i < N; i++) {
		X[i] = X[i]/A[i][i];
		printf("%f\n", X[i]);
	}


	return 0;
}
