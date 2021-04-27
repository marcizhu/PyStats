#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#define STATS_ENABLE_STDVEC_WRAPPERS
#include "stats.hpp"

namespace py = pybind11;

void Weibull(py::module& m)
{
	// Scalar input
	m.def("dweibull", static_cast<double(*)(double, double, double, bool)>(&stats::dweibull),
		py::arg("x"), py::arg("alpha") = 1.0, py::arg("sigma") = 1.0, py::arg("log") = false,
		"Density function of the Weibull distribution.\n\n"

		"Args:\n"
		"    x (float): A real-valued input.\n"
		"    alpha (float): The shape parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("pweibull", static_cast<double(*)(double, double, double, bool)>(&stats::pweibull),
		py::arg("p"), py::arg("alpha") = 1.0, py::arg("sigma") = 1.0, py::arg("log") = false,
		"Distribution function of the Weibull distribution.\n\n"

		"Args:\n"
		"    p (float): A real-valued input.\n"
		"    alpha (float): The shape parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qweibull", static_cast<double(*)(double, double, double)>(&stats::qweibull),
		py::arg("q"), py::arg("alpha") = 1.0, py::arg("sigma") = 1.0,
		"Quantile function of the Weibull distribution.\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    alpha (float): The shape parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rweibull", [](double alpha, double sigma) { return stats::rweibull(alpha, sigma); },
		py::arg("alpha") = 1.0, py::arg("sigma") = 1.0,
		"Random sampling function for the Weibull distribution.\n\n"

		"Args:\n"
		"    alpha (float): The shape parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Weibull distribution.");

	m.def("rweibull", [](size_t n, double alpha, double sigma) { return stats::rweibull<std::vector<double>>(1, n, alpha, sigma); },
		py::arg("n"), py::arg("alpha") = 1.0, py::arg("sigma") = 1.0,
		"Random sampling function for the Weibull distribution.\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    alpha (float): The shape parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A vector of pseudo-random draws from the Weibull distribution.");

	// Vector input
	m.def("dweibull", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::dweibull),
		py::arg("x"), py::arg("alpha") = 1.0, py::arg("sigma") = 1.0, py::arg("log") = false,
		"Density function of the Weibull distribution.\n\n"

		"Args:\n"
		"    x (List[float]): A standard vector input.\n"
		"    alpha (float): The shape parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A vector of density values corresponding to the elements of `x`.");

	m.def("pweibull", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::pweibull),
		py::arg("p"), py::arg("alpha") = 1.0, py::arg("sigma") = 1.0, py::arg("log") = false,
		"Distribution function of the Weibull distribution.\n\n"

		"Args:\n"
		"    p (List[float]): A standard vector input.\n"
		"    alpha (float): The shape parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A vector of CDF values corresponding to the elements of `p`.");

	m.def("qweibull", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double)>(&stats::qweibull),
		py::arg("q"), py::arg("alpha") = 1.0, py::arg("sigma") = 1.0,
		"Quantile function of the Weibull distribution.\n\n"

		"Args:\n"
		"    q (List[float]): A standard vector input.\n"
		"    alpha (float): The shape parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A vector of quantiles values corresponding to the elements of `q`.");
}
