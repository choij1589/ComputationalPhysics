#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double GetIntegrand(double s, double z, double phi_prime) {
	// Define constants
    const double s_prime = 0.01;        // [m]
	const double lambda = 1e-9;			// [C/m]
	
	return (s_prime*lambda)/sqrt(pow(s, 2)+pow(s_prime, 2)+pow(z, 2)-2.*fabs(s)*s_prime*cos(phi_prime));
}

double GetPotential(double s, double z) {
	// Define constants
    const double c_coulomb = 8.99*1e9;  // [N*m^2/C^2]
	const unsigned int N = 1000;
	const double h = 2.*M_PI/N;

	// Use trapezoidal method for integration
	double sum = 0.;
	for (unsigned int n = 0; n < N; n++) {
		sum += GetIntegrand(s, z, n*h);
	}
	sum += (h/2.)*(GetIntegrand(s, z, 0.)+GetIntegrand(s, z, 2.*M_PI));
	sum *= c_coulomb;

	return sum;
}

double GetSField(double s, double z) {
	const double delta_s = 1e-9;
	// To avoid singularity
	// if (s < delta_s) return 0.;

	// Use three point method for derivative
	return -(GetPotential(s+delta_s, z)-GetPotential(s-delta_s, z))/(2.*delta_s);
}

double GetZField(double s, double z) {
	// Use three point method for derivative
	const double delta_z = 1e-9;
	return -(GetPotential(s, z+delta_z)-GetPotential(s, z-delta_z))/(2.*delta_z);
}

double Shoot(double s, double sdot, double z, double zdot, bool verbose) {
	const double unit_charge = 1.60217662e-19;  // [C]
	const double unit_mass = 9.1098356e-31; // [kg]
	const double delta_t = 1e-15;

	double theta = atan(s/z);

	if (verbose) printf("s\tsdot\tz\tzdot\ttheta\n");
	while (true) {
		// update interchangably
		s += sdot*delta_t;
		z += zdot*delta_t;
		sdot += -unit_charge/unit_mass*GetSField(s, z);
		zdot += -unit_charge/unit_mass*GetZField(s, z);
		double this_theta = atan(s/z);

		if (verbose) printf("%e\t%e\t%e\t%e\t%e\n", s, sdot, z, zdot, theta);

		if (fabs(theta-this_theta) < 10e-16) break;

		theta = this_theta;
	}

	return theta;
}


int main() {
	double z = -1.; // [m]
	double zdot = 1e6; // [m/s]
	
	const double ds = 1e-4; // [m]
	printf("s\ttheta\n");
	for (int n = 0; n <= 10; n++) {
		double s = ds*n;
		printf("%e\t%e\n", s, Shoot(s, 0., z, zdot, false));
	}
}
