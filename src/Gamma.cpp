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

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    scale (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rgamma", [](double shape, double scale) { return stats::rgamma(shape, scale); },
		py::arg("shape") = 1.0, py::arg("scale") = 1.0,
		"Random sampling function for the Gamma distribution.\n\n"

		"Args:\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    scale (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Gamma distribution.");

	m.def("rgamma", [](size_t n, double shape, double scale) { return stats::rgamma<std::vector<double>>(1, n, shape, scale); },
		py::arg("n"), py::arg("shape") = 1.0, py::arg("scale") = 1.0,
		"Random sampling function for the Gamma distribution.\n\n"

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

		"Args:\n"
		"    q (List[float]): A standard list input.\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    scale (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of quantiles values corresponding to the elements of `q`.");
}
