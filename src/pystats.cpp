#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "Utils.h"
#include "Distributions.h"

namespace py = pybind11;

PYBIND11_MODULE(pystats, m)
{
	m.doc() = "R-like statistical functions and distributions for Python 3";

	m.attr("__version__") = "0.1.dev1";

	m.def("mean", &mean, py::arg("x"),
		"Compute the mean of the given data\n\n"

		"Example:\n"
		"    >>> pystats.mean([1,2,3,4,5])\n"
		"    3.0\n\n"

		"Args:\n"
		"    x (List[float]): A standard list input.\n\n"

		"Returns:\n"
		"    The mean of the values in `x`.");

	m.def("sd", &sd, py::arg("x"),
		"Compute the standard deviation of the given data\n\n"

		"Example:\n"
		"    >>> pystats.sd([1,2,3,4,5])\n"
		"    1.581138\n\n"

		"Args:\n"
		"    x (List[float]): A standard list input.\n\n"

		"Returns:\n"
		"    The standard deviation (unbiased) of the values in `x`.");

	m.def("var", &var, py::arg("x"),
		"Compute the variance of the given data\n\n"

		"Example:\n"
		"    >>> pystats.var([1,2,3,4,5])\n"
		"    2.5\n\n"

		"Args:\n"
		"    x (List[float]): A standard list input.\n\n"

		"Returns:\n"
		"    The variance (unbiased) of the values in `x`.");

	REGISTER_DISTRIBUTION(Bernoulli);
	REGISTER_DISTRIBUTION(Beta);
	REGISTER_DISTRIBUTION(Binomial);
	REGISTER_DISTRIBUTION(Cauchy);
	REGISTER_DISTRIBUTION(ChiSquared);
	REGISTER_DISTRIBUTION(Exponential);
	REGISTER_DISTRIBUTION(F);
	REGISTER_DISTRIBUTION(Gamma);
	REGISTER_DISTRIBUTION(InvGamma);
	REGISTER_DISTRIBUTION(Laplace);
	REGISTER_DISTRIBUTION(LogNormal);
	REGISTER_DISTRIBUTION(Logistic);
	REGISTER_DISTRIBUTION(Normal);
	REGISTER_DISTRIBUTION(Poisson);
	REGISTER_DISTRIBUTION(StudentT);
	REGISTER_DISTRIBUTION(Uniform);
	REGISTER_DISTRIBUTION(Weibull);
}
