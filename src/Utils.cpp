#include <vector>
#include <cmath>

inline double accu(const std::vector<double>& X)
{
	double sum_val = double(0);
	for (auto x : X)
		sum_val += x;
	return sum_val;
}

inline double sqaccu(const std::vector<double>& X)
{
	double sum_val = double(0);
	for (auto& x : X)
		sum_val += x*x;
	return sum_val;
}

double mean(const std::vector<double>& X)
{
	return accu(X) / static_cast<double>(X.size());
}

double sd(const std::vector<double>& X)
{
	double mean_val = mean(X);
	double sq_val = sqaccu(X) / static_cast<double>(X.size() - 1);
	return std::sqrt(sq_val - (static_cast<double>(X.size()) / static_cast<double>(X.size() - 1)) * mean_val * mean_val);
}

double var(const std::vector<double>& X)
{
	double mean_val = mean(X);
	double sq_val = sqaccu(X) / static_cast<double>(X.size() - 1);
	return sq_val - (static_cast<double>(X.size()) / static_cast<double>(X.size() - 1)) * mean_val * mean_val;
}
