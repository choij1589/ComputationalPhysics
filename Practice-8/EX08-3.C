//==== Date: Oct.28, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== gcc -lm EX08-3.C

//==== Problem 3. Find all the eigenvalues of the
//==== above moment of inertia by use of
//==== power (& deflation) method
//==== -> Write the eigenvalues in the summary report.

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


