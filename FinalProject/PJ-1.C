// CH11-1.C is the programs for MC simulation of the Ising model,
// where 10x10x10 spins are placed periodically on a cubic lattice.
// Each spin has either +1 or -1 spin state.

// Fill out the places marked by ? in the code and then, 
// modify the code to calculate sbar(H), where sbar is the
// normalized average value of s[NN][NN][NN] and H is magnetic field
// over the range [-200, 200].
// Temperature is 30K.

// -> Save the source code as PJ-1.C and submit it
// -> Specify the corrected syntax at the places marked by ? in the report.
// -> List sbar(H) in the report.
// -> By use of any graphic softward, plot sbar(H) in the report.

// gcc -lm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define J		(1e-3*1.60219e-19)
#define mu		(9.2741e-24)		// [J/T]
#define kB		(1.38062e-23)		// [J/K]

#define NN		10
#define nmax	100

void unititeration(double hh, double T, int s[NN][NN][NN], int chbd[NN][NN][NN][2]) {
	int i, j, k;
	int ii, jj, kk, nn, pp;
	double dE, r;
	static long idum=0;

	for (pp = 0; pp <= 1; pp++)
		for (i = 0; i < NN; i++)
		for (j = 0; j < NN; j++)
		for (k = 0; k < NN; k++)
			if (chbd[i][j][k][pp]) {
				nn = 0;
				for (ii = -1; ii <= 1; ii++)
				for (jj = -1; jj <= 1; jj++)
				for (kk = -1; kk <= 1; kk++)
					if (ii*ii+jj*jj+kk*kk == 1)
						nn += s[(i+ii+NN)%NN][(j+jj+NN)%NN][(k+kk+NN)%NN];
				// here is the modified parts
				dE = 2*s[i][j][k]*(-J*nn-mu*hh);
				//dE = 2*J*s[i][j][k]*nn + 2*hh*s[i][j][k];
				r = exp(-dE/(kB*T));
				// printf("dE: %f\tr: %f\n", dE, r);
				if ((double)rand()/RAND_MAX < r) s[i][j][k] *= -1;
			}
	return;
}

void linearfit(int x[nmax], int y[nmax], double *aa, double *bb) {
	int n;
	double a11, a12, a21, a22, b1, b2;
	a11 = 0;
	a12 = 0;
	b1 = 0;
	b2 = 0;
	for (n = 0; n < nmax; n++) {
		a11 += x[n]*x[n];
		a12 += x[n];
		b1 += x[n]*y[n];
		b2 += y[n];
	}
	a21 = a12;
	a22 = nmax;

	*aa = (a22*b1-a12*b2)/(a11*a22-a12*a21);
	*bb = (a11*b2-a21*b1)/(a11*a12-a12*a21);

	return;
}

double iteration(double hh, double T, int s[NN][NN][NN], int chbd[NN][NN][NN][2]) {
	int n, i, j, k, nn=0;
	int x[nmax], y[nmax];
	double aa, bb, ao, oo;

	do {
		oo = ao;
		ao = aa;

		for (n = 0; n < nmax; n++) {
			unititeration(hh, T, s, chbd);

			x[n] = n;
			y[n] = 0;
			for (i = 0; i < NN; i++)
			for (j = 0; j < NN; j++)
			for (k = 0; k < NN; k++)
				y[n] += s[i][j][k];
		}
		linearfit(x, y, &aa, &bb);
		nn++;
	} while(ao*aa > 0 || ao*oo > 0 || nn < 3);

	return bb/(NN*NN*NN);
}

int main() {
	int i, j, k, h, n, pp;
	int s[NN][NN][NN];
	int chbd[NN][NN][NN][2];

	for (i = 0; i < NN; i++)
	for (j = 0; j < NN; j++)
	for (k = 0; k < NN; k++) {
		pp = (i+j+k)%2;
		chbd[i][j][k][pp] = 1;
		chbd[i][j][k][1-pp] = 0;
	}

	for (i = 0; i < NN; i++)
	for (j = 0; j < NN; j++)
	for (k = 0; k < NN; k++)
		s[i][j][k] = -1;

	/*
	double T, H;
	printf("Temperature: "); scanf("%lf", &T);
	printf("Magnetic field: "); scanf("%lf", &H);
	printf("Magnesization state: %f\n", iteration(H, T, s, chbd));
	*/
	// To simulate at once
	const double T = 30; // K
	printf("Temperature\tMagnetic field\tMagnetisation state\n");
	for (double H = -200; H <= 200; H += 10) {
		printf("%f\t%f\t%f\n", T, H, iteration(H, T, s, chbd));
	}
	
	return 0;
}
