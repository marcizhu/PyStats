#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#define STATS_ENABLE_STDVEC_WRAPPERS
#include "stats.hpp"

namespace py = pybind11;

void ChiSquared(py::module& m)
{
	// Scalar input
	m.def("dchisq", static_cast<double(*)(double, double, bool)>(&stats::dchisq),
		py::arg("x"), py::arg("dof") = 1.0, py::arg("log") = false,
		"Density function of the Chi-squared distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dchisq(4.0, 5)\n"
		"    0.1439759107018347\n\n"

		"Args:\n"
		"    x (float): A real-valued input.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("pchisq", static_cast<double(*)(double, double, bool)>(&stats::pchisq),
		py::arg("p"), py::arg("dof") = 1.0, py::arg("log") = false,
		"Distribution function of the Chi-squared distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pchisq(4.0, 5)\n"
		"    0.45058404864721946\n\n"

		"Args:\n"
		"    p (float): A real-valued input.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qchisq", static_cast<double(*)(double, double)>(&stats::qchisq),
		py::arg("q"), py::arg("dof") = 1.0,
		"Quantile function of the Chi-squared distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qchisq(0.5, 5)\n"
		"    4.351460191095529\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rchisq", [](double dof) { return stats::rchisq(dof); },
		py::arg("dof") = 1.0,
		"Random sampling function for the Chi-squared distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rchisq(dof=5)\n"
		"    7.088454619471778\n\n"

		"Args:\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Chi-squared distribution.");

	m.def("rchisq", [](size_t n, double dof) { return stats::rchisq<std::vector<double>>(1, n, dof); },
		py::arg("n"), py::arg("dof") = 1.0,
		"Random sampling function for the Chi-squared distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rchisq(5, 5)\n"
		"    [2.3284093401299866, 9.215161276152928, 6.904990781549569, 8.257146493760509, 4.299710184814277]\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of pseudo-random draws from the Chi-squared distribution.");

	// Vector input
	m.def("dchisq", static_cast<std::vector<double>(*)(const std::vector<double>&, double, bool)>(&stats::dchisq),
		py::arg("x"), py::arg("dof") = 1.0, py::arg("log") = false,
		"Density function of the Chi-squared distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dchisq([1.8, 0.7, 4.2], 4)\n"
		"    [0.18295634688326964, 0.12332041570077489, 0.12857924966563097]\n\n"

		"Args:\n"
		"    x (List[float]): A standard list input.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of density values corresponding to the elements of `x`.");

	m.def("pchisq", static_cast<std::vector<double>(*)(const std::vector<double>&, double, bool)>(&stats::pchisq),
		py::arg("p"), py::arg("dof") = 1.0, py::arg("log") = false,
		"Distribution function of the Chi-squared distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pchisq([1.8, 0.7, 4.2], 4)\n"
		"    [0.22751764649286174, 0.048671078879736845, 0.620385072415756]\n\n"

		"Args:\n"
		"    p (List[float]): A standard list input.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of CDF values corresponding to the elements of `p`.");

	m.def("qchisq", static_cast<std::vector<double>(*)(const std::vector<double>&, double)>(&stats::qchisq),
		py::arg("q"), py::arg("dof") = 1.0,
		"Quantile function of the Chi-squared distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qchisq([1.8, 0.7, 4.2], 4)\n"
		"    [2.194698421406983, 3.356693980033322, 5.988616694004245]\n\n"

		"Args:\n"
		"    q (List[float]): A standard list input.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of quantiles values corresponding to the elements of `q`.");
}
