#include <vector>
#include <cmath>

double mean(const std::vector<double>& data, bool na_rm)
{
	double res = 0.0;

	for(double x : data)
	{
		if(!std::isnan(x) || !na_rm)
			res += x;
	}

	return res / (double)data.size();
}

double sd(const std::vector<double>& data, bool na_rm)
{
	const double mu = mean(data, na_rm);
	double var = 0.0;

	for(double x : data)
		var += (x - mu) * (x - mu);

	return std::sqrt(var / (double)data.size());
}
