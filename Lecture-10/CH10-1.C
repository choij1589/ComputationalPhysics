// histogram of random number generation
// gcc
#include <stdio.h>
#include <stdlib.h>

#define n	1000000L
#define m	100L

int main() {
	long hist[m];
	FILE *file;

	for (int i = 0; i < m; i++)
		hist[i] = 0;

	for (int i = 0; i < n; i++) {
		double r = (double)rand()/RAND_MAX;
		int rand_num = int(r*m);
		hist[rand_num]++;
	}

	file = fopen("CH10-1.DAT", "w");
	for (int i = 0; i < m; i++) {
		fprintf(file, "%d\t%f\n", i, (double)hist[i]/n);
	}
	fclose(file);

	return 0;
}
