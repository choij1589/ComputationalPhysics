//gcc -lm -lfftw3
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <fftw3.h>

int main() {
	const unsigned int n = 128;
	FILE *file;
	
	fftw_complex *in      = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*n);
	fftw_complex *out     = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*n);
	fftw_plan    forward  = fftw_plan_dft_1d(n, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_plan    backward = fftw_plan_dft_1d(n, out, in, FFTW_BACKWARD, FFTW_ESTIMATE);

	for (unsigned int i = 0; i < n; i++) {
		if (i == n/2)
			in[i][0] = 1.;
		else
			in[i][0] = 0.;
		in[i][1] = 0.;
	}

	file = fopen("EX7-3ORIGINAL.DAT", "w");
	for (unsigned int i = 0; i < n; i++) {
		fprintf(file, "%d\t%.3f+%.3fi\n", i, in[i][0], in[i][1]);
	}
	fclose(file);

	fftw_execute(forward);

	file = fopen("EX7-3FORWARD.DAT", "w");
	for (unsigned int i = 0; i < n; i++) {
		// now apply angular frequency cutoff
		if ((double)i*2.*M_PI/(double)n > M_PI/8.) {
			out[i][0] = 0.;
			out[i][1] = 0.;
		}
		
		fprintf(file, "%d\t%.3f+%.3fi\n", i, out[i][0], out[i][1]);
	}

	fftw_execute(backward);

	file = fopen("EX7-3BACKWARD.DAT", "w");
	for (unsigned int i = 0; i < n; i++) {
		fprintf(file, "%d\t%.3f+%.3fi\n", i, in[i][0], out[i][0]);
	}
	fclose(file);

	fftw_destroy_plan(forward);
	fftw_destroy_plan(backward);
	fftw_free(in);
	fftw_free(out);

	return 0;
}
