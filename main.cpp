#include <iostream>
#include <vector>
using namespace std;

#include "Eigen/Dense"
using namespace Eigen;

#include "main.h"

int main(void)
{
	// Brown, table 3.8
	VectorXf efficacy(12);
	efficacy << 1, 9, 1, 5, 6, 8, 2, 4, 2, 8, 7, 7;

	VectorXf position(12);
	position << 3, 8, 2, 8, 5, 9, 4, 5, 2, 4, 2, 6;

	VectorXf third_variable(12);
	third_variable << 7, 1, 9, 8, 4, 1, 2, 7, 4, 6, 2, 1;

	// Normalize, set mean to 0, and variance to 1
	mean0_var1(efficacy);
	mean0_var1(position);
	mean0_var1(third_variable);

	// Get variance-covariance matrix
	vector<VectorXf> v { efficacy, position, third_variable };

	MatrixXf m = get_var_covar_matrix(v);

	cout << m << endl;

	return 0;
}