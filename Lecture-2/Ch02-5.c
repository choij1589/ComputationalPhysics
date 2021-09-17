// gcc Ch02-5.c -lm -o Ch02-5.out
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main() {
	char str[32];
	FILE* file;
	for (unsigned int m = 1; m <= 10; m++) {
		sprintf(str, "Ch02-5-%2.2d.dat\0", m);
		file = fopen(str, "w");
		for (unsigned int n = 0; n <= 10; n++) {
			fprintf(file, "%f\n", pow(sin(M_PI*n/10), m));
		}
		fclose(file);
	}
}
