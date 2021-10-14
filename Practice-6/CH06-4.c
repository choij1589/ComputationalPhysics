//==== Date: Oct.14, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== gcc CH06-3.c -lm -o CH06-3.out

//==== Problem 4. Modify #3 to perform linear fitting with x = ay + b

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void least_square_fit(double arr_x[], double arr_y[], const unsigned int n_arr,
					 double *a, double *b) {
	double a11 = 0., a12 = 0., a21 = 0., a22 = 0.;
	double b1 = 0., b2 = 0.;
	for (unsigned int i = 0; i < n_arr; i++) {
		a11 += pow(arr_y[i], 2); a12 += arr_y[i];
		a21 += arr_y[i]; a22 += 1.;
		b1 += arr_x[i]*arr_y[i]; b2 += arr_x[i];
	}
	// check whether the matrix is invertible
	if (a11*a22 - a12*a21 == 0) {
		printf("determinant of the matrix is 0, not invertible matrix");
		exit(EXIT_FAILURE);
	}

	// update values
	*a = (a22*b1 - a12*b2)/(a11*a22 - a12*a21);
	*b = (a11*b2 - a21*b1)/(a11*a22 - a12*a21);
}

int main() {
	// read CH06-2.DAT and store in arrays
	const unsigned int N = 11;		// total 11 data-points
	double arr_x[N], arr_y[N];
	FILE *file;
	file= fopen("CH06-2.DAT", "r");
	for (unsigned int i = 0; i < N; i++) {
		fscanf(file, "%lf", &arr_x[i]);
		fscanf(file, "%lf", &arr_y[i]);
	}
	fclose(file);

	double a, b;
	least_square_fit(arr_x, arr_y, N, &a, &b);
	printf("%f\t%f\n", a, b);

}


