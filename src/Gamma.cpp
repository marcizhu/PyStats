#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#define STATS_ENABLE_STDVEC_WRAPPERS
#include "stats.hpp"

namespace py = pybind11;

void Gamma(py::module& m)
{
	// Scalar input
	m.def("dgamma", static_cast<double(*)(double, double, double, bool)>(&stats::dgamma),
		py::arg("x"), py::arg("shape") = 1.0, py::arg("scale") = 1.0, py::arg("log") = false,
		"Density function of the Gamma distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dgamma(2, 2, 3)\n"
		"    0.1140926931183538\n\n"

		"Args:\n"
		"    x (float): A real-valued input.\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    scale (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("pgamma", static_cast<double(*)(double, double, double, bool)>(&stats::pgamma),
		py::arg("p"), py::arg("shape") = 1.0, py::arg("scale") = 1.0, py::arg("log") = false,
		"Distribution function of the Gamma distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pgamma(2, 2, 3)\n"
		"    0.14430480161234657\n\n"

		"Args:\n"
		"    p (float): A real-valued input.\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    scale (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qgamma", static_cast<double(*)(double, double, double)>(&stats::qgamma),
		py::arg("q"), py::arg("shape") = 1.0, py::arg("scale") = 1.0,
		"Quantile function of the Gamma distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qgamma(0.15, 2, 3)\n"
		"    2.0497158392128205\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    scale (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rgamma", [](double shape, double scale) { return stats::rgamma(shape, scale); },
		py::arg("shape") = 1.0, py::arg("scale") = 1.0,
		"Random sampling function for the Gamma distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rgamma(2, 3)\n"
		"    2.5950379008163194\n\n"

		"Args:\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    scale (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Gamma distribution.");

	m.def("rgamma", [](size_t n, double shape, double scale) { return stats::rgamma<std::vector<double>>(1, n, shape, scale); },
		py::arg("n"), py::arg("shape") = 1.0, py::arg("scale") = 1.0,
		"Random sampling function for the Gamma distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rgamma(3, 2, 3)\n"
		"    [8.584541442906463, 4.491138145011711, 4.904685252957054]\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    scale (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of pseudo-random draws from the Gamma distribution.");

	// Vector input
	m.def("dgamma", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::dgamma),
		py::arg("x"), py::arg("shape") = 1.0, py::arg("scale") = 1.0, py::arg("log") = false,
		"Density function of the Gamma distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dgamma([1.8, 0.7, 4.2], 2, 3)\n"
		"    [0.1097623272188053, 0.061591410715083, 0.11507858317274963]\n\n"

		"Args:\n"
		"    x (List[float]): A standard list input.\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    scale (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of density values corresponding to the elements of `x`.");

	m.def("pgamma", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::pgamma),
		py::arg("p"), py::arg("shape") = 1.0, py::arg("scale") = 1.0, py::arg("log") = false,
		"Distribution function of the Gamma distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pgamma([1.8, 0.7, 4.2], 2, 3)\n"
		"    [0.12190138224955768, 0.023336201517969262, 0.4081672865401445]\n\n"

		"Args:\n"
		"    p (List[float]): A standard list input.\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    scale (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of CDF values corresponding to the elements of `p`.");

	m.def("qgamma", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double)>(&stats::qgamma),
		py::arg("q"), py::arg("shape") = 1.0, py::arg("scale") = 1.0,
		"Quantile function of the Gamma distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qgamma([0.1, 0.2, 0.7], 2, 3)\n"
		"    [1.5954348251688362, 2.473164927098954, 7.317649449840613]\n\n"

		"Args:\n"
		"    q (List[float]): A standard list input.\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    scale (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of quantiles values corresponding to the elements of `q`.");
}
