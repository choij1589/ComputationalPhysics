// 2. N identical particles - that are connected in series
// by the springs as shown below - move along the x axis,
// where all the particles have the mass m and all the springs
// have the spring constant k.
// For the case of N = 100, plot the resonance frequency w[(k/m)^(1/2)]
// with respect to the number n of the nodes for each corresponding mode.

// -> Save the source code as PJ-2.C and submit it.
// -> List w(n) in the report.
// -> By use of any graphic softward, plot w(n) in the report.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N	100

void Normalize(double *x) {
	double sum = 0.;
	for (int i = 0; i < N; i++) sum += pow(x[i], 2);
	for (int i = 0; i < N; i++) x[i] /= sqrt(sum);
	
	return;
}

void compare_vec(double *x1, double *x2) {
	for (int i = 0; i < N; i++) 
		printf("%f\t%f\n", x1[i], x2[i]);
	return;
}

double InnerProduct(double *Vec1, double *Vec2) {
	double out = 0;
	for (int i = 0; i < N; i++) out += Vec1[i]*Vec2[i];
	return out;
}

void MatrixProduct(double (*Matrix)[N], double *Vec, double *Out) {
	for (int i = 0; i < N; i++) Out[i] = 0.;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Out[i] += Matrix[i][j]*Vec[j];
	return;
}

double PowerMethod(double (*Matrix)[N], double *OutVec) {
	// Randomly generate the initial guess and normalize
	double x_0[N];
    for (int i = 0; i < N; i++) 
		x_0[i] = ((double)rand()/RAND_MAX)*2.-1.; //[-1, 1]
    Normalize(x_0);

	// iterate while the vector converges
	double x[N];
    for (int i = 0; i < N; i++) x[i] = x_0[i];
	int i = 0;
    while (true) {
        double next_x[N];
        MatrixProduct(Matrix, x, next_x);
        Normalize(next_x);

        // check whether the value converges
        bool is_converged = true, is_converged_flip = true;
        for (int i = 0; i < N; i++)
            if (fabs(x[i]-next_x[i]) > 1e-6) 
				is_converged = false;
		for (int i = 0; i < N; i++)
			if (fabs(x[i]+next_x[i]) > 1e-6)
				is_converged_flip = false;
        if (is_converged || is_converged_flip) break;

        // update for the next iteration
        for (int i = 0; i < N; i++) x[i] = next_x[i];
    }

	for (int i = 0; i < N; i++) OutVec[i] = x[i];

	// Finalize the eigenvalue
	double eigen_vec[N];
	MatrixProduct(Matrix, x, eigen_vec);
	return InnerProduct(x, eigen_vec) / InnerProduct(x, x);
}

void ModifyMatrix(double (*Matrix)[N], double *Vec, double lambda) {
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		Matrix[i][j] -= lambda*Vec[i]*Vec[j];
	return;
}

void GetAllEigenValues(double (*Matrix)[N], double *EigenValues) {
	for (int i = 0; i < N; i++) {
		double eigen_vec[N];
		EigenValues[i] = PowerMethod(Matrix, eigen_vec);
		ModifyMatrix(Matrix, eigen_vec, EigenValues[i]);
	}
	return;
}

int main() {
	// make matrix and initialize
	// set k = 1, m = 1, the matrix only have 1, 0, -1 components
	double Matrix[N][N];
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++) {
		if (i == j) Matrix[i][j] = 1.;
		else if (abs(i-j) == 1) Matrix[i][j] = -1.;
		else Matrix[i][j] = 0.;
	}

	double EigenValues[N];
	GetAllEigenValues(Matrix, EigenValues);
	printf("index, lambda\n");
	for (int i = 0; i < N; i++)
		printf("%d, %f\n", i, EigenValues[i]);
	
	return 0;
}
