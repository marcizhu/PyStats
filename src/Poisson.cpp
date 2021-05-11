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

		"Example:\n"
		"    >>> pystats.dpois(8, 10.0)\n"
		"    0.11259903214902026\n\n"

		"Args:\n"
		"    x (float): A real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("ppois", static_cast<double(*)(stats::llint_t, double, bool)>(&stats::ppois),
		py::arg("p"), py::arg("rate"), py::arg("log") = false,
		"Distribution function of the Poisson distribution.\n\n"

		"Example:\n"
		"    >>> pystats.ppois(8, 10.0)\n"
		"    0.3328196787507189\n\n"

		"Args:\n"
		"    p (float): A real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qpois", static_cast<double(*)(double, double)>(&stats::qpois),
		py::arg("q"), py::arg("rate"),
		"Quantile function of the Poisson distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qpois(0.9, 10.0)\n"
		"    14.0\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rpois", [](double rate) { return stats::rpois(rate); },
		py::arg("rate"),
		"Random sampling function for the Poisson distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rpois(10.0)\n"
		"    7.0\n\n"

		"Args:\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Poisson distribution.");

	m.def("rpois", [](size_t n, double rate) { return stats::rpois<std::vector<double>>(1, n, rate); },
		py::arg("n"), py::arg("rate"),
		"Random sampling function for the Poisson distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rpois(4, 10.0)\n"
		"    [11.0, 8.0, 8.0, 9.0]\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of pseudo-random draws from the Poisson distribution.");

	// Vector input
	m.def("dpois", static_cast<std::vector<double>(*)(const std::vector<int64_t>&, double, bool)>(&stats::dpois),
		py::arg("x"), py::arg("rate"), py::arg("log") = false,
		"Density function of the Poisson distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dpois([2, 3, 4], 10.0)\n"
		"    [0.0022699964881242435, 0.007566654960414158, 0.01891663740103532]\n\n"

		"Args:\n"
		"    x (List[float]): A standard list input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of density values corresponding to the elements of `x`.");

	m.def("ppois", static_cast<std::vector<double>(*)(const std::vector<int64_t>&, double, bool)>(&stats::ppois),
		py::arg("p"), py::arg("rate"), py::arg("log") = false,
		"Distribution function of the Poisson distribution.\n\n"

		"Example:\n"
		"    >>> pystats.ppois([2, 3, 4], 10.0)\n"
		"    [0.0027693957155115762, 0.010336050675925718, 0.029252688076961075]\n\n"

		"Args:\n"
		"    p (List[float]): A standard list input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of CDF values corresponding to the elements of `p`.");

	m.def("qpois", static_cast<std::vector<double>(*)(const std::vector<double>&, double)>(&stats::qpois),
		py::arg("q"), py::arg("rate"),
		"Quantile function of the Poisson distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qpois([0.3, 0.5, 0.8], 10.0)\n"
		"    [8.0, 10.0, 13.0]\n\n"

		"Args:\n"
		"    q (List[float]): A standard list input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of quantiles values corresponding to the elements of `q`.");
}
