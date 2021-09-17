// gcc Ch02-1.c -o Ch02-1.out
#include <stdio.h>
void main() {
	unsigned int sum = 0;
	for (unsigned int i=0; i<=10; i++) {
		sum += i;
	}
	printf("%d\n", sum);
}
