#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#define STATS_ENABLE_STDVEC_WRAPPERS
#include "stats.hpp"

namespace py = pybind11;

void Cauchy(py::module& m)
{
	// Scalar input
	m.def("dcauchy", static_cast<double(*)(double, double, double, bool)>(&stats::dcauchy),
		py::arg("x"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0, py::arg("log") = false,
		"Density function of the Cauchy distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dcauchy(2.5, 1.0, 3.0)\n"
		"    0.084883\n\n"

		"Args:\n"
		"    x (float): A real-valued input.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("pcauchy", static_cast<double(*)(double, double, double, bool)>(&stats::pcauchy),
		py::arg("p"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0, py::arg("log") = false,
		"Distribution function of the Cauchy distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pcauchy(2.5, 1.0, 3.0)\n"
		"    0.647584\n\n"

		"Args:\n"
		"    p (float): A real-valued input.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qcauchy", static_cast<double(*)(double, double, double)>(&stats::qcauchy),
		py::arg("q"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0,
		"Quantile function of the Cauchy distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qcauchy(0.5, 1, 3.0)\n"
		"    0.647584\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rcauchy", [](double mu, double sigma) { return stats::rcauchy(mu, sigma); },
		py::arg("mu") = 0.0, py::arg("sigma") = 1.0,
		"Random sampling function for the Cauchy distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rcauchy(1.0, 2.0)\n"
		"    9.93054237677352\n\n"

		"Args:\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Cauchy distribution.");

	m.def("rcauchy", [](size_t n, double mu, double sigma) { return stats::rcauchy<std::vector<double>>(1, n, mu, sigma); },
		py::arg("n"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0,
		"Random sampling function for the Cauchy distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rcauchy(1.0, 2.0)\n"
		"    [-2.383182638662492, 1.0766564460128407, -20.367599105297693, -0.9512379893292959, -0.17185207327053853]\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of pseudo-random draws from the Cauchy distribution.");

	// Vector input
	m.def("dcauchy", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::dcauchy),
		py::arg("x"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0, py::arg("log") = false,
		"Density function of the Cauchy distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dcauchy([0.0, 1.0, 2.0], 1.0, 2.0)\n"
		"    [0.12732395447351627, 0.15915494309189535, 0.12732395447351627]\n\n"

		"Args:\n"
		"    x (List[float]): A standard list input.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of density values corresponding to the elements of `x`.");

	m.def("pcauchy", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::pcauchy),
		py::arg("p"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0, py::arg("log") = false,
		"Distribution function of the Cauchy distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pcauchy([0.0, 1.0, 2.0], 1.0, 2.0)\n"
		"    [0.35241638234956674, 0.5, 0.6475836176504333]\n\n"

		"Args:\n"
		"    p (List[float]): A standard list input.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of CDF values corresponding to the elements of `p`.");

	m.def("qcauchy", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double)>(&stats::qcauchy),
		py::arg("q"), py::arg("mu") = 0.0, py::arg("sigma") = 1.0,
		"Quantile function of the Cauchy distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qcauchy([0.1, 0.3, 0.7], 1.0, 2.0)\n"
		"    [-5.155367074350508, -0.45308505601072185, 2.453085056010721]\n\n"

		"Args:\n"
		"    q (List[float]): A standard list input.\n"
		"    mu (float): The location parameter, a real-valued input.\n"
		"    sigma (float): The scale parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of quantiles values corresponding to the elements of `q`.");
}
