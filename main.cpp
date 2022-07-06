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

	VectorXd third_variable(12);
	third_variable << 7, 1, 9, 8, 4, 1, 2, 7, 4, 6, 2, 1;

	// Normalize, set mean to 0, and variance to 1
	//normalize_mean0_var1(efficacy);
	//normalize_mean0_var1(position);
	//normalize_mean0_var1(third_variable);

	vector<VectorXd> v { efficacy, position, third_variable };

	MatrixXd m = get_var_covar_matrix(v);

	cout << m << endl;

	return 0;
}