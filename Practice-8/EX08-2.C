//==== Date: Oct.28, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== gcc EX08-2.C

//==== Problem 2. Find the inverse matrix of the above moment of inertia
//==== -> Write the inverse matrix in the summary report

//==== In this problem, I will extend the Gauss-Jordan elimination
//==== e.g. by solving 3 linear equations,
//==== I x ((x11, x12, x13), (x21, x22, x23), (x31, x32, x33)) = ((1, 0, 0), (0, 1, 0), (0, 0, 1))
//==== the X will be the inverse of the matrix
#include <stdio.h>
#include <stdlib.h>

int main() {
	const unsigned int N = 3;

	// L = I x omega, omega = I^-1 x L
	const double I[N][N] = {{1, 3, 5}, {1, 1, 4}, {1, 3, 1}};
	double x1[N] = {1, 0, 0};
	double x2[N] = {0, 1, 0};
	double x3[N] = {0, 0, 1};

	// copy the instance first
	double temp_I[N][N];
	for (unsigned int i = 0; i < N; i++) {
		for (unsigned int j = 0; j < N; j++) {
			temp_I[i][j] = I[i][j];
		}
	}

	// Now imply Gauss-Jordan elimination
	// make the matrix diagonal
	for (unsigned int i = 0; i < N; i++) {
		for (unsigned int j = 0; j < N; j++) {
			if (i != j) {
				double r = temp_I[j][i] / temp_I[i][i];
				for (unsigned int k = 0; k < N; k++) {
					temp_I[j][k] -= r*temp_I[i][k];
				}
				x1[j] -= r*x1[i];
				x2[j] -= r*x2[i];
				x3[j] -= r*x3[i];
			}
		}
	}
	
	// get the solution
	for (unsigned int i = 0; i < N; i++) {
		x1[i] /= temp_I[i][i];
		x2[i] /= temp_I[i][i];
		x3[i] /= temp_I[i][i];
	}
	
	double invI[N][N] = {0};
	for (unsigned int i = 0; i < N; i++) {
		invI[i][0] = x1[i];
		invI[i][1] = x2[i];
		invI[i][2] = x3[i];
	}

	for (unsigned int i = 0; i < N; i++) {
		for (unsigned int j = 0; j < N; j++)
			printf("%6.2f", invI[i][j]);
		printf("\n");
	}

	return 0;
}


