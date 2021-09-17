// gcc Ch02-3.c -o Ch02-3.out
#include <stdio.h>
void main() {
	unsigned int sum = 0;
	for (unsigned int i=0; i<=100; i++) {
		sum += i;
		if (sum == 45) {
			printf("%d\n", i);
			break;
		}
	}
}
