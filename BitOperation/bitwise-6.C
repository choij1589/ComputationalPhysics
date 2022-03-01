#include <stdio.h>

int main() {
	unsigned char num1 = 240;		// 1111 0000
	unsigned char num2 = 15;		// 0000 1111

	unsigned char num3, num4;

	num3 = num1 << 2;
	num4 = num2 >> 2;

	printf("%u\n", num3);	// 1100 0000
	printf("%u\n", num4);	// 0000 0011

	return 0;
}
