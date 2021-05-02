#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#define STATS_ENABLE_STDVEC_WRAPPERS
#include "stats.hpp"

namespace py = pybind11;

void Poisson(py::module& m)
{
	// Scalar input
	m.def("dpois", static_cast<double(*)(stats::llint_t, double, bool)>(&stats::dpois),
		py::arg("x"), py::arg("rate"), py::arg("log") = false,
		"Density function of the Poisson distribution.\n\n"

		"Args:\n"
		"    x (float): A real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("ppois", static_cast<double(*)(stats::llint_t, double, bool)>(&stats::ppois),
		py::arg("p"), py::arg("rate"), py::arg("log") = false,
		"Distribution function of the Poisson distribution.\n\n"

		"Args:\n"
		"    p (float): A real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qpois", static_cast<double(*)(double, double)>(&stats::qpois),
		py::arg("q"), py::arg("rate"),
		"Quantile function of the Poisson distribution.\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rpois", [](double rate) { return stats::rpois(rate); },
		py::arg("rate"),
		"Random sampling function for the Poisson distribution.\n\n"

		"Args:\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Poisson distribution.");

	m.def("rpois", [](size_t n, double rate) { return stats::rpois<std::vector<double>>(1, n, rate); },
		py::arg("n"), py::arg("rate"),
		"Random sampling function for the Poisson distribution.\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A vector of pseudo-random draws from the Poisson distribution.");

	// Vector input
	m.def("dpois", static_cast<std::vector<int64_t>(*)(const std::vector<int64_t>&, double, bool)>(&stats::dpois),
		py::arg("x"), py::arg("rate"), py::arg("log") = false,
		"Density function of the Poisson distribution.\n\n"

		"Args:\n"
		"    x (List[float]): A standard vector input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A vector of density values corresponding to the elements of `x`.");

	m.def("ppois", static_cast<std::vector<int64_t>(*)(const std::vector<int64_t>&, double, bool)>(&stats::ppois),
		py::arg("p"), py::arg("rate"), py::arg("log") = false,
		"Distribution function of the Poisson distribution.\n\n"

		"Args:\n"
		"    p (List[float]): A standard vector input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A vector of CDF values corresponding to the elements of `p`.");

	m.def("qpois", static_cast<std::vector<double>(*)(const std::vector<double>&, double)>(&stats::qpois),
		py::arg("q"), py::arg("rate"),
		"Quantile function of the Poisson distribution.\n\n"

		"Args:\n"
		"    q (List[float]): A standard vector input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A vector of quantiles values corresponding to the elements of `q`.");
}
