#include <stdio.h>
#define N	3

int main() {
	double A[N][N] = {{1, 2, 3}, {2, 5, 3}, {1, 0, 8}};
	double x[N] = {1, 2, 3};
	double r;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				r = A[j][i]/A[i][i];
				for (int k = 0; k < N; k++) {
					A[j][k] -= r*A[i][k];
				}
				x[j] -= r*x[i];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		x[i] = x[i]/A[i][i];
		A[i][i] /= A[i][i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) printf("%6.2f", A[i][j]);
		printf("\t");
		printf("%6.2f", x[i]);
		printf("\n");
	}

	return 0;
}
