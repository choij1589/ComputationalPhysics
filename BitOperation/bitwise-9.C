#include <stdio.h>

int main() {
	unsigned char flag = 7;		// 0000 0111
	flag &= ~2;					// 1111 1101

	printf("%u\n", flag);		// 0000 0101

	if (flag & 1)   printf("0000 0001은 켜져 있음\n");
    else            printf("0000 0001은 꺼져 있음\n");

    if (flag & 2)   printf("0000 0010은 켜져 있음\n");
    else            printf("0000 0010은 꺼져 있음\n");

    if (flag & 4)   printf("0000 0100은 켜져 있음\n");
    else            printf("0000 0100은 꺼져 있음\n");
	
	return 0;
}
