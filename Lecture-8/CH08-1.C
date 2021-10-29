// gcc
#include <stdio.h>

#define N	3

int main() {
	const double a = 2;
	double in[N][N] = {{1, 2, 3},
						{2, 5, 3},
						{1, 0, 8}};
	double out[N][N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			out[i][j] = a*in[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%6.2f", in[i][j]);
		}
		printf("\t");

		for (int j = 0; j < N; j++) {
			printf("%6.2f", out[i][j]);
		}
		printf("\n");
	}

	return 0;
}
