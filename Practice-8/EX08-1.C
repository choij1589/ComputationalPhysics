//==== Date: Oct.28, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== gcc EX08-1.C

//==== Problem 1. Get the angular velocity Omega of a rigid body
//==== having the moment of rotation inertia I = ((1, 3, 5), (1, 1, 4), (1, 3, 1))
//==== to make the angular momentum L = (1, 1, 1). Note that L = I X Omega
//==== -> Write Omega in the summary report

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	const unsigned int N = 3;

	// L = I x omega, omega = I^-1 x L
	const double I[N][N] = {{1, 3, 5}, {1, 1, 4}, {1, 3, 1}};
	const double L[N] = {1, 1, 1};
	double omega[N] = {0}; // all instances are initialized to 0

	// copy the instance first
	double temp_I[N][N];
	double temp_L[N];
	for (unsigned int i = 0; i < N; i++) {
		for (unsigned int j = 0; j < N; j++) {
			temp_I[i][j] = I[i][j];
		}
		temp_L[i] = L[i];
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
				temp_L[j] -= r*temp_L[i];
			}
		}
	}
	
	// get the solution
	for (unsigned int i = 0; i < N; i++) {
		omega[i] = temp_L[i]/temp_I[i][i];
	}

	for (unsigned int i = 0; i < N; i++) {
		printf("%6.2f", omega[i]);
		printf("\n");
	}

	return 0;
}


