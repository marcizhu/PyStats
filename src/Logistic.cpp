#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#define STATS_ENABLE_STDVEC_WRAPPERS
#include "stats.hpp"

namespace py = pybind11;

void Logistic(py::module& m)
{
	// Scalar input
	m.def("dlogis", static_cast<double(*)(double, double, double, bool)>(&stats::dlogis),
		py::arg("x"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0, py::arg("log") = false,
		"Density function of the Logistic distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dlogis(2.0, 1.0, 2.0)\n"
		"    0.11750185610079714\n\n"

		"Args:\n"
		"    x (float): A real-valued input.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("plogis", static_cast<double(*)(double, double, double, bool)>(&stats::plogis),
		py::arg("p"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0, py::arg("log") = false,
		"Distribution function of the Logistic distribution.\n\n"

		"Example:\n"
		"    >>> pystats.plogis(2.0, 1.0, 2.0)\n"
		"    0.6224593312018546\n\n"

		"Args:\n"
		"    p (float): A real-valued input.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qlogis", static_cast<double(*)(double, double, double)>(&stats::qlogis),
		py::arg("q"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0,
		"Quantile function of the Logistic distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qlogis(0.75, 1.0, 2.0)\n"
		"    3.1972245773362196\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rlogis", [](double mu, double sigma) { return stats::rlogis(mu, sigma); },
		py::arg("mu") = 0.0, py::arg("sigma") = 1.0,
		"Random sampling function for the Logistic distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rlogis(1.0, 2.0)\n"
		"    -2.0430312686217516\n\n"

		"Args:\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Logistic distribution.");

	m.def("rlogis", [](size_t n, double mu, double sigma) { return stats::rlogis<std::vector<double>>(1, n, mu, sigma); },
		py::arg("n"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0,
		"Random sampling function for the Logistic distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rlogis(3, 1.0, 2.0)\n"
		"    [7.012051380112511, 1.4135266403017916, -1.3985463825344762]\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of pseudo-random draws from the Logistic distribution.");

	// Vector input
	m.def("dlogis", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::dlogis),
		py::arg("x"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0, py::arg("log") = false,
		"Density function of the Logistic distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dlogis([0.0, 1.0, 2.0], 1.0, 2.0)\n"
		"    [0.11750185610079714, 0.125, 0.11750185610079714]\n\n"

		"Args:\n"
		"    x (List[float]): A standard list input.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of density values corresponding to the elements of `x`.");

	m.def("plogis", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::plogis),
		py::arg("p"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0, py::arg("log") = false,
		"Distribution function of the Logistic distribution.\n\n"

		"Example:\n"
		"    >>> pystats.plogis([0.0, 1.0, 2.0], 1.0, 2.0)\n"
		"    [0.37754066879814546, 0.5, 0.6224593312018546]\n\n"

		"Args:\n"
		"    p (List[float]): A standard list input.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of CDF values corresponding to the elements of `p`.");

	m.def("qlogis", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double)>(&stats::qlogis),
		py::arg("q"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0,
		"Quantile function of the Logistic distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qlogis([0.1, 0.3, 0.7], 1.0, 2.0)\n"
		"    [-3.394449154672439, -0.6945957207744073, 2.694595720774407]\n\n"

		"Args:\n"
		"    q (List[float]): A standard list input.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of quantiles values corresponding to the elements of `q`.");
}
