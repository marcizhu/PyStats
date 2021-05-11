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

		"Example:\n"
		"    >>> pystats.dlnorm(2.0, 1.0, 2.0)\n"
		"    0.0985685803440131\n\n"

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

		"Example:\n"
		"    >>> pystats.plnorm(2.0, 1.0, 2.0)\n"
		"    0.43903100974768944\n\n"

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

		"Example:\n"
		"    >>> pystats.qlnorm(0.95, 1.0, 2.0)\n"
		"    72.94511097708158\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rlnorm", [](double mean, double sd) { return stats::rlnorm(mean, sd); },
		py::arg("mean") = 0.0, py::arg("sd") = 1.0,
		"Random sampling function for the Log-Normal distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rlnorm(1.0, 2.0)\n"
		"    0.7961734447160091\n\n"

		"Args:\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Log-Normal distribution.");

	m.def("rlnorm", [](size_t n, double mean, double sd) { return stats::rlnorm<std::vector<double>>(1, n, mean, sd); },
		py::arg("n"), py::arg("mean") = 0.0, py::arg("sd") = 1.0,
		"Random sampling function for the Log-Normal distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rlnorm(3, 1.0, 2.0)\n"
		"    [0.7889982649469498, 0.060477695435514324, 0.09150040197067903]\n\n"

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

		"Example:\n"
		"    >>> pystats.dlnorm([0.0, 1.0, 2.0], 1.0, 2.0)\n"
		"    [0.0, 0.17603266338214968, 0.0985685803440131]\n\n"

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

		"Example:\n"
		"    >>> pystats.plnorm([0.0, 1.0, 2.0], 1.0, 2.0)\n"
		"    [0.0, 0.3085375387259869, 0.43903100974768944]\n\n"

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

		"Example:\n"
		"    >>> pystats.qlnorm([0.1, 0.5, 0.9], 1.0, 2.0)\n"
		"    [0.20948500212405705, 2.718281828459045, 35.27248263126183]\n\n"

		"Args:\n"
		"    q (List[float]): A standard list input.\n"
		"    mean (float): The mean parameter, a real-valued input.\n"
		"    sd (float): The standard deviation parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of quantiles values corresponding to the elements of `q`.");
}
