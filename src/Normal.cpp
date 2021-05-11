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

		"Example:\n"
		"    >>> pystats.dnorm(1.645, 0.0, 1.0)\n"
		"    0.10311081109198143\n\n"

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

		"Example:\n"
		"    >>> pystats.pnorm(1.645, 0.0, 1.0)\n"
		"    0.9500150944608786\n\n"

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

		"Example:\n"
		"    >>> pystats.qnorm(0.95, 0.0, 1.0)\n"
		"    1.6448536269514706\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rnorm", [](double mean, double sd) { return stats::rnorm(mean, sd); },
		py::arg("mean") = 0.0, py::arg("sd") = 1.0,
		"Random sampling function for the Normal distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rnorm(0.0, 1.0)\n"
		"    0.2772437359624193\n\n"

		"Args:\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Normal distribution.");

	m.def("rnorm", [](size_t n, double mean, double sd) { return stats::rnorm<std::vector<double>>(1, n, mean, sd); },
		py::arg("n"), py::arg("mean") = 0.0, py::arg("sd") = 1.0,
		"Random sampling function for the Normal distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rnorm(3, 0.0, 1.0)\n"
		"    [-0.04796221296447198, -2.165514623383353, 0.7219224921308472]\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of pseudo-random draws from the Normal distribution.");

	// Vector input
	m.def("dnorm", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::dnorm),
		py::arg("x"), py::arg("mean") = 0.0, py::arg("sd") = 1.0, py::arg("log") = false,
		"Density function of the Normal distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dnorm([-1.0, 0.0, 2.0], 0.0, 1.0)\n"
		"    [0.24197072451914342, 0.39894228040143265, 0.05399096651318805]\n\n"

		"Args:\n"
		"    x (List[float]): A standard list input.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of density values corresponding to the elements of `x`.");

	m.def("pnorm", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::pnorm),
		py::arg("p"), py::arg("mean") = 0.0, py::arg("sd") = 1.0, py::arg("log") = false,
		"Distribution function of the Normal distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pnorm([-1.0, 0.0, 2.0], 0.0, 1.0)\n"
		"    [0.15865525393145705, 0.5, 0.9772498680518208]\n\n"

		"Args:\n"
		"    p (List[float]): A standard list input.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of CDF values corresponding to the elements of `p`.");

	m.def("qnorm", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double)>(&stats::qnorm),
		py::arg("q"), py::arg("mean") = 0.0, py::arg("sd") = 1.0,
		"Quantile function of the Normal distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qnorm([0.3, 0.5, 0.95], 0.0, 1.0)\n"
		"    [-0.5244005127080409, 0.0, 1.6448536269514706]\n\n"

		"Args:\n"
		"    q (List[float]): A standard list input.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of quantiles values corresponding to the elements of `q`.");
}
