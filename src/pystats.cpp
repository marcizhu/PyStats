#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "Utils.h"
#include "Distributions.h"

namespace py = pybind11;

PYBIND11_MODULE(pystats, m)
{
	m.doc() = "R-like statistical functions and distributions for Python 3";

	m.attr("__version__") = "0.0.1";

	m.def("mean", &mean, py::arg("x"), "Compute the mean of the given data");
	m.def("sd",   &sd,   py::arg("x"), "Compute the standard deviation of the given data");
	m.def("var",  &var,  py::arg("x"), "Compute the variance of the given data");

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
