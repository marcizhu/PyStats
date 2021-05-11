#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#define STATS_ENABLE_STDVEC_WRAPPERS
#include "stats.hpp"

namespace py = pybind11;

void StudentT(py::module& m)
{
	// Scalar input
	m.def("dt", static_cast<double(*)(double, double, bool)>(&stats::dt),
		py::arg("x"), py::arg("dof") = 1.0, py::arg("log") = false,
		"Density function of the t-distribution distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dt(0.37, 11)\n"
		"    0.362095719673348\n\n"

		"Args:\n"
		"    x (float): A real-valued input.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("pt", static_cast<double(*)(double, double, bool)>(&stats::pt),
		py::arg("p"), py::arg("dof") = 1.0, py::arg("log") = false,
		"Distribution function of the t-distribution distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pt(0.37, 11)\n"
		"    0.6407962382848924\n\n"

		"Args:\n"
		"    p (float): A real-valued input.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qt", static_cast<double(*)(double, double)>(&stats::qt),
		py::arg("q"), py::arg("dof") = 1.0,
		"Quantile function of the t-distribution distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qt(0.5, 11)\n"
		"    0.0\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rt", [](double dof) { return stats::rt(dof); },
		py::arg("dof") = 1.0,
		"Random sampling function for the t-distribution distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rt(dof=11)\n"
		"    0.30585871954611826\n\n"

		"Args:\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the t-distribution distribution.");

	m.def("rt", [](size_t n, double dof) { return stats::rt<std::vector<double>>(1, n, dof); },
		py::arg("n"), py::arg("dof") = 1.0,
		"Random sampling function for the t-distribution distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rt(3, 11)\n"
		"    [2.781125786671334, -0.7090818248684807, -0.3220992876319297]\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of pseudo-random draws from the t-distribution distribution.");

	// Vector input
	m.def("dt", static_cast<std::vector<double>(*)(const std::vector<double>&, double, bool)>(&stats::dt),
		py::arg("x"), py::arg("dof") = 1.0, py::arg("log") = false,
		"Density function of the t-distribution distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dt([1.8, 0.7, 4.2], 11)\n"
		"    [0.08286084841281988, 0.3002542334010353, 0.0012519045841828374]\n\n"

		"Args:\n"
		"    x (List[float]): A standard list input.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of density values corresponding to the elements of `x`.");

	m.def("pt", static_cast<std::vector<double>(*)(const std::vector<double>&, double, bool)>(&stats::pt),
		py::arg("p"), py::arg("dof") = 1.0, py::arg("log") = false,
		"Distribution function of the t-distribution distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pt([1.8, 0.7, 4.2], 11)\n"
		"    [0.9503420534306152, 0.7507677671528026, 0.9992572076935229]\n\n"

		"Args:\n"
		"    p (List[float]): A standard list input.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of CDF values corresponding to the elements of `p`.");

	m.def("qt", static_cast<std::vector<double>(*)(const std::vector<double>&, double)>(&stats::qt),
		py::arg("q"), py::arg("dof") = 1.0,
		"Quantile function of the t-distribution distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qt([0.3, 0.5, 0.8], 11)\n"
		"    [-0.5399378774105429, 0.0, 0.8755299114635708]\n\n"

		"Args:\n"
		"    q (List[float]): A standard list input.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of quantiles values corresponding to the elements of `q`.");
}
