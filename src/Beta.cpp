#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#define STATS_ENABLE_STDVEC_WRAPPERS
#include "stats.hpp"

namespace py = pybind11;

void Beta(py::module& m)
{
	// Scalar input
	m.def("dbeta", static_cast<double(*)(double, double, double, bool)>(&stats::dbeta),
		py::arg("x"), py::arg("shape1"), py::arg("shape2"), py::arg("log") = false,
		"Density function of the Beta distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dbeta(0.5, 3.0, 2.0)\n"
		"    1.5\n\n"

		"Args:\n"
		"    x (float): A real-valued input.\n"
		"    shape1 (float): A real-valued shape parameter.\n"
		"    shape2 (float): A real-valued shape parameter.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("pbeta", static_cast<double(*)(double, double, double, bool)>(&stats::pbeta),
		py::arg("p"), py::arg("shape1"), py::arg("shape2"), py::arg("log") = false,
		"Distribution function of the Beta distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pbeta(0.5, 3.0, 2.0)\n"
		"    0.3125\n\n"

		"Args:\n"
		"    p (float): A real-valued input.\n"
		"    shape1 (float): A real-valued shape parameter.\n"
		"    shape2 (float): A real-valued shape parameter.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qbeta", static_cast<double(*)(double, double, double)>(&stats::qbeta),
		py::arg("q"), py::arg("shape1"), py::arg("shape2"),
		"Quantile function of the Beta distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qbeta(0.5, 3.0, 2.0)\n"
		"    0.61427243186\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    shape1 (float): A real-valued shape parameter.\n"
		"    shape2 (float): A real-valued shape parameter.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rbeta", [](double shape1, double shape2) { return stats::rbeta(shape1, shape2); },
		py::arg("shape1"), py::arg("shape2"),
		"Random sampling function for the Beta distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rbeta(3.0, 2.0)\n"
		"    0.3102933967927699\n\n"

		"Args:\n"
		"    shape1 (float): A real-valued shape parameter.\n"
		"    shape2 (float): A real-valued shape parameter.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Beta distribution.");

	m.def("rbeta", [](size_t n, double shape1, double shape2) { return stats::rbeta<std::vector<double>>(1, n, shape1, shape2); },
		py::arg("n"), py::arg("shape1"), py::arg("shape2"),
		"Random sampling function for the Beta distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rbeta(5, 3.0, 2.0)\n"
		"    [0.2098009340766354, 0.483502928842804, 0.5101449459492882, 0.46683636135288137, 0.791214142230094]\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    shape1 (float): A real-valued shape parameter.\n"
		"    shape2 (float): A real-valued shape parameter.\n\n"

		"Returns:\n"
		"    A list of pseudo-random draws from the Beta distribution.");

	// Vector input
	m.def("dbeta", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::dbeta),
		py::arg("x"), py::arg("shape1"), py::arg("shape2"), py::arg("log") = false,
		"Density function of the Beta distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dbeta([0.3, 0.5, 0.9], 3.0, 2.0)\n"
		"    [0.756, 1.5, 0.972]\n\n"

		"Args:\n"
		"    x (List[float]): A standard list input.\n"
		"    shape1 (float): A real-valued shape parameter.\n"
		"    shape2 (float): A real-valued shape parameter.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of density values corresponding to the elements of `x`.");

	m.def("pbeta", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::pbeta),
		py::arg("p"), py::arg("shape1"), py::arg("shape2"), py::arg("log") = false,
		"Distribution function of the Beta distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pbeta([0.3, 0.5, 0.9], 3.0, 2.0)\n"
		"    [0.0837, 0.3125, 0.9477]\n\n"

		"Args:\n"
		"    p (List[float]): A standard list input.\n"
		"    shape1 (float): A real-valued shape parameter.\n"
		"    shape2 (float): A real-valued shape parameter.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of CDF values corresponding to the elements of `p`.");

	m.def("qbeta", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double)>(&stats::qbeta),
		py::arg("q"), py::arg("shape1"), py::arg("shape2"),
		"Quantile function of the Beta distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qbeta([0.3, 0.5, 0.9], 3.0, 2.0)\n"
		"    [0.4915952451274149, 0.6142724318676113, 0.8574406832899696]\n\n"

		"Args:\n"
		"    q (List[float]): A standard list input.\n"
		"    shape1 (float): A real-valued shape parameter.\n"
		"    shape2 (float): A real-valued shape parameter.\n\n"

		"Returns:\n"
		"    A list of quantiles values corresponding to the elements of `q`.");
}
