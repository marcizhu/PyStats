#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#define STATS_ENABLE_STDVEC_WRAPPERS
#include "stats.hpp"

namespace py = pybind11;

void Laplace(py::module& m)
{
	// Scalar input
	m.def("dlaplace", static_cast<double(*)(double, double, double, bool)>(&stats::dlaplace),
		py::arg("x"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0, py::arg("log") = false,
		"Density function of the Laplace distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dlaplace(0.7, 1.0, 2.0)\n"
		"    0.21517699410626442\n\n"

		"Args:\n"
		"    x (float): A real-valued input.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("plaplace", static_cast<double(*)(double, double, double, bool)>(&stats::plaplace),
		py::arg("p"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0, py::arg("log") = false,
		"Distribution function of the Laplace distribution.\n\n"

		"Example:\n"
		"    >>> pystats.plaplace(0.7, 1.0, 2.0)\n"
		"    0.4303539882125289\n\n"

		"Args:\n"
		"    p (float): A real-valued input.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qlaplace", static_cast<double(*)(double, double, double)>(&stats::qlaplace),
		py::arg("q"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0,
		"Quantile function of the Laplace distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qlaplace(0.5, 1.0, 2.0)\n"
		"    1.0\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rlaplace", [](double mu, double sigma) { return stats::rlaplace(mu, sigma); },
		py::arg("mu") = 0.0, py::arg("sigma") = 1.0,
		"Random sampling function for the Laplace distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rlaplace(1.0, 2.0)\n"
		"    -0.06931476521956581\n\n"

		"Args:\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Laplace distribution.");

	m.def("rlaplace", [](size_t n, double mu, double sigma) { return stats::rlaplace<std::vector<double>>(1, n, mu, sigma); },
		py::arg("n"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0,
		"Random sampling function for the Laplace distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rlaplace(3, 1.0, 2.0)\n"
		"    [0.7785860236771809, 0.14724988410675632, 3.0446760367044163]\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of pseudo-random draws from the Laplace distribution.");

	// Vector input
	m.def("dlaplace", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::dlaplace),
		py::arg("x"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0, py::arg("log") = false,
		"Density function of the Laplace distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dlaplace([0.0, 1.0, 2.0], 1.0, 2.0)\n"
		"    [0.15163266492815836, 0.25, 0.15163266492815836]\n\n"

		"Args:\n"
		"    x (List[float]): A standard list input.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of density values corresponding to the elements of `x`.");

	m.def("plaplace", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::plaplace),
		py::arg("p"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0, py::arg("log") = false,
		"Distribution function of the Laplace distribution.\n\n"

		"Example:\n"
		"    >>> pystats.plaplace([0.0, 1.0, 2.0], 1.0, 2.0)\n"
		"    [0.3032653298563167, 0.5, 0.6967346701436833]\n\n"

		"Args:\n"
		"    p (List[float]): A standard list input.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of CDF values corresponding to the elements of `p`.");

	m.def("qlaplace", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double)>(&stats::qlaplace),
		py::arg("q"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0,
		"Quantile function of the Laplace distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qlaplace([0.1, 0.6, 0.9], 1.0, 2.0)\n"
		"    [-2.218875824868202, 1.4462871026284194, 4.218875824868202]\n\n"

		"Args:\n"
		"    q (List[float]): A standard list input.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of quantiles values corresponding to the elements of `q`.");
}
