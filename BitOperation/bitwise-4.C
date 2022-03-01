#include <stdio.h>

int main() {
	unsigned char num1 = 4;		// 0000 0100
	unsigned char num2 = 4;		// 0000 0100
	unsigned char num3 = 4;		// 0000 0100
	unsigned char num4 = 4;		// 0000 0100
	unsigned char num5 = 4;		// 0000 0100

	num1 &= 5;		// 0000 0101
	num2 |= 2;		// 0000 0010
	num3 ^= 3;		// 0000 0011
	num4 <<= 2;		// 0001 1000
	num5 >>= 2;		// 0000 0001

	printf("%u\n", num1);
	printf("%u\n", num2);
	printf("%u\n", num3);
	printf("%u\n", num4);
	printf("%u\n", num5);

	return 0;
}
