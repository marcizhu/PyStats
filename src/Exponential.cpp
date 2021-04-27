#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#define STATS_ENABLE_STDVEC_WRAPPERS
#include "stats.hpp"

namespace py = pybind11;

void Exponential(py::module& m)
{
	// Scalar input
	m.def("dexp", static_cast<double(*)(double, double, bool)>(&stats::dexp),
		py::arg("x"), py::arg("rate") = 1.0, py::arg("log") = false,
		"Density function of the Exponential distribution.\n\n"

		"Args:\n"
		"    x (float): A real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("pexp", static_cast<double(*)(double, double, bool)>(&stats::pexp),
		py::arg("p"), py::arg("rate") = 1.0, py::arg("log") = false,
		"Distribution function of the Exponential distribution.\n\n"

		"Args:\n"
		"    p (float): A real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qexp", static_cast<double(*)(double, double)>(&stats::qexp),
		py::arg("q"), py::arg("rate") = 1.0,
		"Quantile function of the Exponential distribution.\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rexp", [](double rate) { return stats::rexp(rate); },
		py::arg("rate") = 1.0,
		"Random sampling function for the Exponential distribution.\n\n"

		"Args:\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Exponential distribution.");

	m.def("rexp", [](size_t n, double rate) { return stats::rexp<std::vector<double>>(1, n, rate); },
		py::arg("n"), py::arg("rate") = 1.0,
		"Random sampling function for the Exponential distribution.\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A vector of pseudo-random draws from the Exponential distribution.");

	// Vector input
	m.def("dexp", static_cast<std::vector<double>(*)(const std::vector<double>&, double, bool)>(&stats::dexp),
		py::arg("x"), py::arg("rate") = 1.0, py::arg("log") = false,
		"Density function of the Exponential distribution.\n\n"

		"Args:\n"
		"    x (List[float]): A standard vector input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A vector of density values corresponding to the elements of `x`.");

	m.def("pexp", static_cast<std::vector<double>(*)(const std::vector<double>&, double, bool)>(&stats::pexp),
		py::arg("p"), py::arg("rate") = 1.0, py::arg("log") = false,
		"Distribution function of the Exponential distribution.\n\n"

		"Args:\n"
		"    p (List[float]): A standard vector input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A vector of CDF values corresponding to the elements of `p`.");

	m.def("qexp", static_cast<std::vector<double>(*)(const std::vector<double>&, double)>(&stats::qexp),
		py::arg("q"), py::arg("rate") = 1.0,
		"Quantile function of the Exponential distribution.\n\n"

		"Args:\n"
		"    q (List[float]): A standard vector input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A vector of quantiles values corresponding to the elements of `q`.");
}
