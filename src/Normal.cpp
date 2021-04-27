#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#define STATS_ENABLE_STDVEC_WRAPPERS
#include "stats.hpp"

namespace py = pybind11;

void Normal(py::module& m)
{
	// Scalar input
	m.def("dnorm", static_cast<double(*)(double, double, double, bool)>(&stats::dnorm),
		py::arg("x"), py::arg("mean") = 0.0, py::arg("sd") = 1.0, py::arg("log") = false,
		"Density function of the Normal distribution.\n\n"

		"Args:\n"
		"    x (float): A real-valued input.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("pnorm", static_cast<double(*)(double, double, double, bool)>(&stats::pnorm),
		py::arg("p"), py::arg("mean") = 0.0, py::arg("sd") = 1.0, py::arg("log") = false,
		"Distribution function of the Normal distribution.\n\n"

		"Args:\n"
		"    p (float): A real-valued input.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qnorm", static_cast<double(*)(double, double, double)>(&stats::qnorm),
		py::arg("q"), py::arg("mean") = 0.0, py::arg("sd") = 1.0,
		"Quantile function of the Normal distribution.\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rnorm", [](double mean, double sd) { return stats::rnorm(mean, sd); },
		py::arg("mean") = 0.0, py::arg("sd") = 1.0,
		"Random sampling function for the Normal distribution.\n\n"

		"Args:\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Normal distribution.");

	m.def("rnorm", [](size_t n, double mean, double sd) { return stats::rnorm<std::vector<double>>(1, n, mean, sd); },
		py::arg("n"), py::arg("mean") = 0.0, py::arg("sd") = 1.0,
		"Random sampling function for the Normal distribution.\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A vector of pseudo-random draws from the Normal distribution.");

	// Vector input
	m.def("dnorm", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::dnorm),
		py::arg("x"), py::arg("mean") = 0.0, py::arg("sd") = 1.0, py::arg("log") = false,
		"Density function of the Normal distribution.\n\n"

		"Args:\n"
		"    x (List[float]): A standard vector input.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A vector of density values corresponding to the elements of `x`.");

	m.def("pnorm", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::pnorm),
		py::arg("p"), py::arg("mean") = 0.0, py::arg("sd") = 1.0, py::arg("log") = false,
		"Distribution function of the Normal distribution.\n\n"

		"Args:\n"
		"    p (List[float]): A standard vector input.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A vector of CDF values corresponding to the elements of `p`.");

	m.def("qnorm", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double)>(&stats::qnorm),
		py::arg("q"), py::arg("mean") = 0.0, py::arg("sd") = 1.0,
		"Quantile function of the Normal distribution.\n\n"

		"Args:\n"
		"    q (List[float]): A standard vector input.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A vector of quantiles values corresponding to the elements of `q`.");
}
