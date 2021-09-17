// gcc Ch02-2.c -o Ch02-2.out
#include <stdio.h>
void main() {
	unsigned int sum[10];
	FILE* file;
	
	sum[0] = 0;
	for (unsigned int i=1; i<=10; i++) {
		sum[i] = sum[i-1] + i;
	}

	file = fopen("output.dat", "w");
	for (unsigned int i=1; i <=10; i++) {
		fprintf(file, "%d\n", sum[i]);
	}
	fclose(file);
}
