//==== Date: Sep. 23, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== gcc CH03-4.c -lm -o CH03-4.out

///////////////////////////////////////////////////////////////////////////
//==== Problem 4. Repeat #3 for N = 2^k,                             ====//
//==== where 1 <= k <= 8 (k is an integer) and then,                 ====//
//==== print out the values sig*N, sig*N^2, sig*N^3, sig*N^4         ====//
//==== for each k per line.                                          ====//
//==== h=1/N, where x_n = n/N with 0 < n <= N (n is an integer)      ====//
//==== -> List the values sig*N, sig*N^2, sig*N^3, sig*N^4           ====//
//==== for each k and then write the value m for the relation        ====//
//==== sig*N^m ~ const. in the summary report.                       ====//
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <math.h>

// function declarations
double d2expx(const double x);
double d2expx3p(const double x, const double step);
double sigma(const double N);

// entry point
int main() {
	FILE *f;
	f = fopen("CH03-4.dat", "w");
	printf("k\tsig*N\tsig*N^2\tsig*N^3\tsig*N^4\n");
	fprintf(f, "k\tsig*N\tsig*N^2\tsig*N^3\tsig*N^4\n");

	const unsigned int max_k = 8;
	double pow1[max_k], pow2[max_k], pow3[max_k], pow4[max_k]; // arrays to store sig*N^k's
	for (unsigned int k = 0; k < max_k; k++) {
		const double N = pow(2, k+1);
		const double sig = sigma(N);
		pow1[k] = sig*pow(N, 1);
		pow2[k] = sig*pow(N, 2);
		pow3[k] = sig*pow(N, 3);
		pow4[k] = sig*pow(N, 4);
		printf("%d\t%e\t%e\t%e\t%e\n", k+1, pow1[k], pow2[k], pow3[k], pow4[k]);
		fprintf(f, "%d\t%e\t%e\t%e\t%e\n", k+1, pow1[k], pow2[k], pow3[k], pow4[k]);
	}
	
	// now calculate mean and std for each array
	double mean1 = 0., mean2 = 0., mean3 = 0., mean4 = 0.;
	double var1 = 0., var2 = 0., var3 = 0., var4 = 0.;
	for (unsigned int k = 0; k < max_k; k++) {
		mean1 += pow1[k]/max_k;
		mean2 += pow2[k]/max_k;
		mean3 += pow3[k]/max_k;
		mean4 += pow4[k]/max_k;
	}

	for (unsigned int k = 0; k < max_k; k++) {
		var1 += pow(pow1[k] - mean1, 2)/max_k;
		var2 += pow(pow2[k] - mean2, 2)/max_k;
		var3 += pow(pow3[k] - mean3, 2)/max_k;
		var4 += pow(pow4[k] - mean4, 2)/max_k;
	}
	double std1, std2, std3, std4;
	printf("mean\t%e\t%e\t%e\t%e\n", mean1, mean2, mean3, mean4);
	printf("std\t%e\t%e\t%e\t%e\n", sqrt(var1), sqrt(var2), sqrt(var3), sqrt(var4));
	fprintf(f, "mean\t%e\t%e\t%e\t%e\n", mean1, mean2, mean3, mean4);
	fprintf(f, "std\t%e\t%e\t%e\t%e\n", sqrt(var1), sqrt(var2), sqrt(var3), sqrt(var4));

	fclose(f);

	return 0;
}

// function definitions
double d2expx(const double x) {
    return exp(x);
}

double d2expx3p(const double x, const double step) {
    return (exp(x+step) - 2*exp(x) + exp(x-step)) / (step*step);
}

double sigma(const double N) {
	const double step = 1/N;
	double var = 0.;
	for (unsigned int n = 1; n <= N; n++) {
		const double x_n = n/N;
		const double diff = d2expx3p(x_n, step) - d2expx(x_n);
		var += pow(diff, 2);
	}
	var /= N;
	return sqrt(var);
}
