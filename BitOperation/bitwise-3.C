#include <stdio.h>

int main() {
	unsigned char num1 = 3;		// 0000 0011
	unsigned char num2 = 24;	// 0001 1000

	printf("%u\n", num1 << 3);	// 0001 1000
	printf("%u\n", num2 >> 2);	// 0000 0110

	return 0;
}
