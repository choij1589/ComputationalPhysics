//==== Date: Oct.28, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== gcc -lm EX08-4.C

//==== Problem 4. Find all the principal axes
//==== of the above moment of inertia from the results of #3
//==== -> Write the principal axes in the summary report

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	const unsigned int N = 3;

	int indp, indm;
	double ll, xx, err=1e-6;

	double M[N][N] = {{1, 3, 5}, {1, 1, 4}, {1, 3, 1}};
	double x1[N], x2[N];

	for (int i = 0; i < N; i++) {
		// get the eigenvectors first
		for (int j = 0; j < N; j++)
			x1[j] = sqrt(1./N);

		do {
			for (int j = 0; j < N; j++) {
				x2[j]  = 0.;
				for (int k = 0; k < N; k++) {
					x2[j] += M[j][k] * x1[k];
				}
			}

			xx = 0.;
			for (int j = 0; j < N; j++) xx += x2[j]*x2[j];
			xx = sqrt(xx);

			for (int j = 0; j < N; j++) x2[j] /= xx;
			
			indp = 0;
			for (int j = 0; j < N; j++)
				if (fabs(x1[j]-x2[j]) < err) indp++;

			indm = 0;
			for (int j = 0; j < N; j++)
				if (fabs(x1[j]+x2[j]) < err) indm++;

			for (int j = 0; j < N; j++)
				x1[j] = x2[j];
		} while (indp < N && indm < N);
		
		printf("(%f %f %f)\t", x1[0], x1[1], x1[2]);

		// now get the eigenvalues
		for (int j = 0; j < N; j++) {
			x2[j] = 0.;
			for (int k = 0; k < N; k++) {
				x2[j] += M[j][k] * x1[k];
			}
		}
		
		ll = 0.; xx = 0;
		for (int j = 0; j < N; j++) {
			ll += x1[j]*x2[j];
			xx += x1[j]*x1[j];
		}
		ll /= xx;

		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				M[j][k] -= ll*x1[j]*x1[k];

		printf("%f\n", ll);
	}

	return 0;
}


