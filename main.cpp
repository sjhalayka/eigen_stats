#include <iostream>
#include <vector>
using namespace std;

#include "Eigen/Dense"
using namespace Eigen;

#include "main.h"

int main(void)
{
	// Brown, table 3.8
	VectorXd efficacy(12);
	efficacy << 1, 9, 1, 5, 6, 8, 2, 4, 2, 8, 7, 7;

	VectorXd position(12);
	position << 3, 8, 2, 8, 5, 9, 4, 5, 2, 4, 2, 6;

	// Make mean = 0, variance = 1
	mean0_var1(efficacy);
	mean0_var1(position);

	// Print out basic properties
	cout << mean(efficacy) << endl;
	cout << variance(efficacy) << endl;
	cout << mean(position) << endl;
	cout << variance(position) << endl;
	cout << covariance(efficacy, position) << endl;

	return 0;
}