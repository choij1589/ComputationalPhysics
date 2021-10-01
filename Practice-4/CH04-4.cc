//==== Date: Sep. 30, 2021
//==== Author: Jin Choi
//==== Contact: choij@cern.ch
//==== g++ CH04-4.cc -lm -o CH04-4.out

//==== Problem 4. Calculate the area of the blue region by use of the
//==== Monte Carlo integral with n-times evaluation,
//==== where n = 2^k with 10 <= k <= 20 (k is an integer)
//==== -> List the calcuated results for each k in the summary report

//==== This script is to test the randomness between C and C++
#include <iostream>
#include <string>
#include <cmath>
#include <random>
#include <TCanvas.h>
#include <TH1D.h>

int main() {
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_real_distribution<> uniform(0., 1.);

	TCanvas* c = new TCanvas("c", "");
	TH1D* h = new TH1D("h", "", 1000, 0., 1.);
	h->SetStats(0);

	std::cout << "k\t" << "area" << std::endl;
	for (unsigned int k = 10; k <= 20; k++) {
		const unsigned long N = pow(2, k);
		unsigned long hit = 0, fail = 0;
		for (unsigned long i = 0; i < N; i++) {
			// Is it really uniform?
			const double x = uniform(generator);
			const double y = uniform(generator);

			h->Fill(x);

			// I wand bool...
			if ((pow(x-1./2., 2) + pow(y-1./2., 2) < pow(1./2., 2)) && 
				(pow(x-5./8., 2) + pow(y-5./8., 2) > pow(3./8., 2))
			)
				hit++;
			else
				fail++;
		}
		std::cout << k << "\t" 
			<< static_cast<double>(hit)/static_cast<double>(N) << std::endl;
	}

	c->cd();
	h->Draw();
	c->SaveAs("uniform_distribution.png");
}
