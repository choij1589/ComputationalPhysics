//==== Date: Sep. 23, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== gcc CH03-3.c -lm -o CH03-3.out

///////////////////////////////////////////////////////////////////////////
//==== Problem 3. Calculate the numerical values                     ====//
//==== a_n = (d^2/dx^2)(expx)|_(x_n)                                 ====//
//==== by use of the three-point formula with step size              ====//
//==== h=1/N, where x_n = n/N with 0 < n <= N (n is an integer)      ====//
//==== and N = 100. Then calculate the root-mean-square error sigma  ====//
//==== which is defined by sqrt(Sigma_n^N(a_n - a_n*)*2/N)           ====//
//==== where a_n* are the analytic values.                           ====//
//==== Use "%e" in the printf format string.                         ====//
//==== -> Write sigma in the summary report.                         ====//
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <math.h>

// function declarations
double d2expx(const double x);
double d2expx3p(const double x, const double step);

// entry point
int main() {
	const double N = 100.;
	const double step = 1./N;
	double var = 0.;
	for (unsigned int n = 1; n <= N; n++) {
		const double x_n = n/N;
		const double diff = d2expx3p(x_n, step) - d2expx(x_n);
		var += pow(diff, 2);
	}
	var /= N;
	const double sigma = sqrt(var);
	printf("sigma = %e\n", sigma);

	return 0;
}

// function definitions
double d2expx(const double x) {
	return exp(x);
}

double d2expx3p(const double x, const double step) {
	return (exp(x+step) - 2.*exp(x) + exp(x-step)) / (step*step);
}
