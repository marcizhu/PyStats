#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#define STATS_ENABLE_STDVEC_WRAPPERS
#include "stats.hpp"

namespace py = pybind11;

void Uniform(py::module& m)
{
	// Scalar input
	m.def("dunif", static_cast<double(*)(double, double, double, bool)>(&stats::dunif),
		py::arg("x"), py::arg("min") = 0.0, py::arg("max") = 1.0, py::arg("log") = false,
		"Density function of the Uniform distribution.\n\n"

		"Args:\n"
		"    x (float): A real-valued input.\n"
		"    min (float): The lower limit of the distribution, a real-valued input.\n"
		"    max (float): The upper limit of the distribution, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("punif", static_cast<double(*)(double, double, double, bool)>(&stats::punif),
		py::arg("p"), py::arg("min") = 0.0, py::arg("max") = 1.0, py::arg("log") = false,
		"Distribution function of the Uniform distribution.\n\n"

		"Args:\n"
		"    p (float): A real-valued input.\n"
		"    min (float): The lower limit of the distribution, a real-valued input.\n"
		"    max (float): The upper limit of the distribution, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qunif", static_cast<double(*)(double, double, double)>(&stats::qunif),
		py::arg("q"), py::arg("min") = 0.0, py::arg("max") = 1.0,
		"Quantile function of the Uniform distribution.\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    min (float): The lower limit of the distribution, a real-valued input.\n"
		"    max (float): The upper limit of the distribution, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("runif", [](double min, double max) { return stats::runif(min, max); },
		py::arg("min") = 0.0, py::arg("max") = 1.0,
		"Random sampling function for the Uniform distribution.\n\n"

		"Args:\n"
		"    min (float): The lower limit of the distribution, a real-valued input.\n"
		"    max (float): The upper limit of the distribution, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Uniform distribution.");

	m.def("runif", [](size_t n, double min, double max) { return stats::runif<std::vector<double>>(1, n, min, max); },
		py::arg("n"), py::arg("min") = 0.0, py::arg("max") = 1.0,
		"Random sampling function for the Uniform distribution.\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    min (float): The lower limit of the distribution, a real-valued input.\n"
		"    max (float): The upper limit of the distribution, a real-valued input.\n\n"

		"Returns:\n"
		"    A vector of pseudo-random draws from the Uniform distribution.");

	// Vector input
	m.def("dunif", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::dunif),
		py::arg("x"), py::arg("min") = 0.0, py::arg("max") = 1.0, py::arg("log") = false,
		"Density function of the Uniform distribution.\n\n"

		"Args:\n"
		"    x (List[float]): A standard vector input.\n"
		"    min (float): The lower limit of the distribution, a real-valued input.\n"
		"    max (float): The upper limit of the distribution, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A vector of density values corresponding to the elements of `x`.");

	m.def("punif", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::punif),
		py::arg("p"), py::arg("min") = 0.0, py::arg("max") = 1.0, py::arg("log") = false,
		"Distribution function of the Uniform distribution.\n\n"

		"Args:\n"
		"    p (List[float]): A standard vector input.\n"
		"    min (float): The lower limit of the distribution, a real-valued input.\n"
		"    max (float): The upper limit of the distribution, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A vector of CDF values corresponding to the elements of `p`.");

	m.def("qunif", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double)>(&stats::qunif),
		py::arg("q"), py::arg("min") = 0.0, py::arg("max") = 1.0,
		"Quantile function of the Uniform distribution.\n\n"

		"Args:\n"
		"    q (List[float]): A standard vector input.\n"
		"    min (float): The lower limit of the distribution, a real-valued input.\n"
		"    max (float): The upper limit of the distribution, a real-valued input.\n\n"

		"Returns:\n"
		"    A vector of quantiles values corresponding to the elements of `q`.");
}
