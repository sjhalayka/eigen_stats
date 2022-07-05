#pragma once

#include <vector>
using namespace std;


float mean(const VectorXd& src)
{
	float m = 0;

	for (long signed int i = 0; i < src.size(); i++)
		m += static_cast<float>(src[i]);

	m /= src.size();

	return m;
}

float standard_deviation(const VectorXd& src)
{
	float m = mean(src);

	float sq_diff = 0;

	for (long signed int i = 0; i < src.size(); i++)
	{
		float diff = static_cast<float>(src[i]) - m;
		sq_diff += diff * diff;
	}

	sq_diff /= src.size();

	return sqrt(sq_diff);
}

float variance(const VectorXd& src)
{
	float x = standard_deviation(src);
	return x * x;
}

void mean0_var1(VectorXd &src)
{
	float m = mean(src);

	for (long signed int i = 0; i < src.size(); i++)
		src[i] -= m;

	float v = variance(src);

	for (long signed int i = 0; i < src.size(); i++)
		src[i] /= sqrt(v);
}

float covariance(const VectorXd& src_x, const VectorXd& src_y)
{
	float x_mean = 0;
	float y_mean = 0;

	for (long signed int i = 0; i < src_x.size(); i++)
	{
		x_mean += static_cast<float>(src_x[i]);
		y_mean += static_cast<float>(src_y[i]);
	}

	x_mean /= src_x.size();
	y_mean /= src_y.size();

	float covariance = 0;

	for (long signed int i = 0; i < src_x.size(); i++)
	{
		float z = static_cast<float>(src_x[i]) - x_mean;
		covariance += z * (static_cast<float>(src_y[i]) - y_mean);
	}

	covariance /= src_x.size();

	return covariance;
}

MatrixXd get_var_covar_matrix(vector<VectorXd>& v)
{
	size_t v_size = v.size();

	MatrixXd m(v_size, v_size);

	for (size_t i = 0; i < v_size; i++)
	{
		m(i, i) = variance(v[i]);

		for (size_t j = i + 1; j < v_size; j++)
			m(j, i) = covariance(v[j], v[i]);
	}

	return m;
}