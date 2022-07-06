#pragma once

#include <vector>
using namespace std;


float mean(const VectorXf& src)
{
	float m = 0;

	for (long signed int i = 0; i < src.size(); i++)
		m += src[i];

	m /= src.size();

	return m;
}

float standard_deviation(const VectorXf& src)
{
	float m = mean(src);

	float sq_diff = 0;

	for (long signed int i = 0; i < src.size(); i++)
	{
		float diff = src[i] - m;
		sq_diff += diff * diff;
	}

	sq_diff /= src.size();

	return sqrt(sq_diff);
}

float variance(const VectorXf& src)
{
	float x = standard_deviation(src);
	return x * x;
}

void normalize_mean0_var1(VectorXf &src)
{
	float max_val = 0;

	for (long signed int i = 0; i < src.size(); i++)
	{
		float val = fabsf(src[i]);

		if (val > max_val)
			max_val = val;
	}

	// Normalize
	for (long signed int i = 0; i < src.size(); i++)
		src[i] /= max_val;

	// Mean 0
	float m = mean(src);

	for (long signed int i = 0; i < src.size(); i++)
		src[i] -= m;

	// Variance 1
	float v = variance(src);

	for (long signed int i = 0; i < src.size(); i++)
		src[i] /= sqrt(v);
}

float covariance(const VectorXf& src_x, const VectorXf& src_y)
{
	float x_mean = 0;
	float y_mean = 0;

	for (long signed int i = 0; i < src_x.size(); i++)
	{
		x_mean += src_x[i];
		y_mean += src_y[i];
	}

	x_mean /= src_x.size();
	y_mean /= src_y.size();

	float covariance = 0;

	for (long signed int i = 0; i < src_x.size(); i++)
		covariance += (src_x[i] - x_mean) * (src_y[i] - y_mean);

	covariance /= src_x.size();

	return covariance;
}

MatrixXf get_var_covar_matrix(vector<VectorXf>& v)
{
	size_t v_size = v.size();

	MatrixXf m(v_size, v_size);

	for (size_t i = 0; i < v_size; i++)
	{
		m(i, i) = variance(v[i]);

		for (size_t j = i + 1; j < v_size; j++)
			m(j, i) = covariance(v[j], v[i]);
	}

	return m;
}