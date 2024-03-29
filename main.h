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
	const float m = mean(src);

	float sq_diff = 0;

	for (long signed int i = 0; i < src.size(); i++)
	{
		float diff = src[i] - m;
		sq_diff += diff * diff;
	}

	sq_diff /= src.size() - 1;

	return sqrtf(sq_diff);
}

float variance(const VectorXf& src)
{
	const float x = standard_deviation(src);
	return x * x;
}

void normalize(VectorXf& src)
{
	float max_val = -FLT_MAX;
	float min_val = FLT_MAX;

	for (long signed int i = 0; i < src.size(); i++)
	{
		const float val = src[i];

		if (val > max_val)
			max_val = val;

		if (val < min_val)
			min_val = val;
	}

	// Normalize to [0, 1]
	for (long signed int i = 0; i < src.size(); i++)
	{
		src[i] -= min_val;
		src[i] /= max_val - min_val;
	}
}

void mean0_var1(VectorXf &src)	
{
	// Mean 0
	const float m = mean(src);

	for (long signed int i = 0; i < src.size(); i++)
		src[i] -= m;

	// Variance 1
	const float v = variance(src);
	const float sqrt_v = sqrtf(v);
	
	for (long signed int i = 0; i < src.size(); i++)
		src[i] /= sqrt_v;
}

float covariance(const VectorXf& src_x, const VectorXf& src_y)
{
	float x_mean = mean(src_x);
	float y_mean = mean(src_y);

	float covariance = 0;

	for (long signed int i = 0; i < src_x.size(); i++)
		covariance += (src_x[i] - x_mean) * (src_y[i] - y_mean);

	covariance /= src_x.size() - 1;

	return covariance;
}

MatrixXf get_var_covar_matrix(vector<VectorXf>& v)
{
	// Get number of variables
	const size_t v_size = v.size();

	MatrixXf m(v_size, v_size);

	for (size_t i = 0; i < v_size; i++)
	{
		m(i, i) = variance(v[i]);

		for (size_t j = i + 1; j < v_size; j++)
			m(j, i) = covariance(v[j], v[i]);
	}

	return m;
}