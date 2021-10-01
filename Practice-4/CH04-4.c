//==== Date: Sep. 30, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== gcc CH04-4.c -lm -o CH04-4.out

//==== Problem 4. Calculate the area of the blue region by use of the
//==== Monte Carlo integral with n-times evaluation,
//==== where n = 2^k with 10 <= k <= 20 (k is an integer)
//==== -> List the calcuated results for each k in the summary report

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
	// Use current time as seed for random generator
	srand(time(NULL));

	printf("k\tarea\n");
	for (unsigned long k = 10; k <= 20; k++) {
		const unsigned long N = (long)pow(2, k);
		unsigned long hit = 0, fail = 0;
		for (unsigned long i = 0; i < N; i++) {
			// Is it really uniform?
			const double x = (double)rand()/RAND_MAX;
			const double y = (double)rand()/RAND_MAX;

			// I want bool...
			if ((pow(x-1./2., 2) + pow(y-1./2., 2) < pow(1./2., 2)) && 
				(pow(x-5./8., 2) + pow(y-5./8., 2) > pow(3./8., 2)))
				hit++;
			else
				fail++;
		}
		printf("%d\t%f\n", k, (double)hit/(double)N);
	}
}
