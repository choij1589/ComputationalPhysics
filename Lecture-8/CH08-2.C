// gcc
#include <stdio.h>
#define N	3

int main() {
	double A[N][N] = {{1, 2, 3}, {2, 5, 3}, {1, 0, 8}};
	double B[N][N] = {{1, 2, 3}, {2, 5, 3}, {1, 0, 8}};
	double out[N][N] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				out[i][j] += A[i][k]*B[k][j];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) printf("%3.f", A[i][j]);
		printf("\t");
		for (int j = 0; j < N; j++) printf("%3.f", B[i][j]);
		printf("\t");
		for (int j = 0; j < N; j++) printf("%3.f", out[i][j]);
		printf("\n");
	}
	
	return 0;
}
