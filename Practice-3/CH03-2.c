//==== Date: Sep. 23, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== gcc CH03-2.c -o CH03-2.out

///////////////////////////////////////////////////////////////////////////
//==== Problem 1. By use of 'sizeof' function, find the size of      ====//
//==== the variable types 'int', 'long', 'float' and 'double'        ====//
//==== in the newton.snu.ac.kr server.                               ====//
//==== Submit the results int the summary page.                      ====//
//==== -> Write the results in the summary report.                   ====//
///////////////////////////////////////////////////////////////////////////
#include <stdio.h>

int main() {
	printf("size of int = %d\n", sizeof(int));
	printf("size of long = %d\n", sizeof(long));
	printf("size of float = %d\n", sizeof(float));
	printf("size of double = %d\n", sizeof(double));

	return 0;
}
