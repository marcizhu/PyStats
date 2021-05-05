#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#define STATS_ENABLE_STDVEC_WRAPPERS
#include "stats.hpp"

namespace py = pybind11;

void LogNormal(py::module& m)
{
	// Scalar input
	m.def("dlnorm", static_cast<double(*)(double, double, double, bool)>(&stats::dlnorm),
		py::arg("x"), py::arg("mean") = 0.0, py::arg("sd") = 1.0, py::arg("log") = false,
		"Density function of the Log-Normal distribution.\n\n"

		"Args:\n"
		"    x (float): A real-valued input.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("plnorm", static_cast<double(*)(double, double, double, bool)>(&stats::plnorm),
		py::arg("p"), py::arg("mean") = 0.0, py::arg("sd") = 1.0, py::arg("log") = false,
		"Distribution function of the Log-Normal distribution.\n\n"

		"Args:\n"
		"    p (float): A real-valued input.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qlnorm", static_cast<double(*)(double, double, double)>(&stats::qlnorm),
		py::arg("q"), py::arg("mean") = 0.0, py::arg("sd") = 1.0,
		"Quantile function of the Log-Normal distribution.\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rlnorm", [](double mean, double sd) { return stats::rlnorm(mean, sd); },
		py::arg("mean") = 0.0, py::arg("sd") = 1.0,
		"Random sampling function for the Log-Normal distribution.\n\n"

		"Args:\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Log-Normal distribution.");

	m.def("rlnorm", [](size_t n, double mean, double sd) { return stats::rlnorm<std::vector<double>>(1, n, mean, sd); },
		py::arg("n"), py::arg("mean") = 0.0, py::arg("sd") = 1.0,
		"Random sampling function for the Log-Normal distribution.\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of pseudo-random draws from the Log-Normal distribution.");

	// Vector input
	m.def("dlnorm", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::dlnorm),
		py::arg("x"), py::arg("mean") = 0.0, py::arg("sd") = 1.0, py::arg("log") = false,
		"Density function of the Log-Normal distribution.\n\n"

		"Args:\n"
		"    x (List[float]): A standard list input.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of density values corresponding to the elements of `x`.");

	m.def("plnorm", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::plnorm),
		py::arg("p"), py::arg("mean") = 0.0, py::arg("sd") = 1.0, py::arg("log") = false,
		"Distribution function of the Log-Normal distribution.\n\n"

		"Args:\n"
		"    p (List[float]): A standard list input.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of CDF values corresponding to the elements of `p`.");

	m.def("qlnorm", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double)>(&stats::qlnorm),
		py::arg("q"), py::arg("mean") = 0.0, py::arg("sd") = 1.0,
		"Quantile function of the Log-Normal distribution.\n\n"

		"Args:\n"
		"    q (List[float]): A standard list input.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of quantiles values corresponding to the elements of `q`.");
}
