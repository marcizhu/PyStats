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

		"Example:\n"
		"    >>> pystats.dexp(1.0, 2.0)\n"
		"    0.2706705664732254\n\n"

		"Args:\n"
		"    x (float): A real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("pexp", static_cast<double(*)(double, double, bool)>(&stats::pexp),
		py::arg("p"), py::arg("rate") = 1.0, py::arg("log") = false,
		"Distribution function of the Exponential distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pexp(1.0, 2.0)\n"
		"    0.8646647167633873\n\n"

		"Args:\n"
		"    p (float): A real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qexp", static_cast<double(*)(double, double)>(&stats::qexp),
		py::arg("q"), py::arg("rate") = 1.0,
		"Quantile function of the Exponential distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qexp(0.5, 2.0)\n"
		"    0.3465735902799726\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rexp", [](double rate) { return stats::rexp(rate); },
		py::arg("rate") = 1.0,
		"Random sampling function for the Exponential distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rexp(2.0)\n"
		"    0.8337215251612762\n\n"

		"Args:\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Exponential distribution.");

	m.def("rexp", [](size_t n, double rate) { return stats::rexp<std::vector<double>>(1, n, rate); },
		py::arg("n"), py::arg("rate") = 1.0,
		"Random sampling function for the Exponential distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rexp(3, 2.0)\n"
		"    [0.006095192297017023, 0.552560396122137, 0.8185248559121117]\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of pseudo-random draws from the Exponential distribution.");

	// Vector input
	m.def("dexp", static_cast<std::vector<double>(*)(const std::vector<double>&, double, bool)>(&stats::dexp),
		py::arg("x"), py::arg("rate") = 1.0, py::arg("log") = false,
		"Density function of the Exponential distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dexp([1.8, 0.7, 4.2], 4.0)\n"
		"    [0.0029863432335067172, 0.24324025050087195, 2.022612539334209e-07]\n\n"

		"Args:\n"
		"    x (List[float]): A standard list input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of density values corresponding to the elements of `x`.");

	m.def("pexp", static_cast<std::vector<double>(*)(const std::vector<double>&, double, bool)>(&stats::pexp),
		py::arg("p"), py::arg("rate") = 1.0, py::arg("log") = false,
		"Distribution function of the Exponential distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pexp([1.8, 0.7, 4.2], 4.0)\n"
		"    [0.9992534141916233, 0.9391899373747821, 0.9999999494346865]\n\n"

		"Args:\n"
		"    p (List[float]): A standard list input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of CDF values corresponding to the elements of `p`.");

	m.def("qexp", static_cast<std::vector<double>(*)(const std::vector<double>&, double)>(&stats::qexp),
		py::arg("q"), py::arg("rate") = 1.0,
		"Quantile function of the Exponential distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qexp([0.3, 0.5, 0.8], 4.0)\n"
		"    [0.08916873598468311, 0.1732867951399863, 0.40235947810852524]\n\n"

		"Args:\n"
		"    q (List[float]): A standard list input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of quantiles values corresponding to the elements of `q`.");
}
