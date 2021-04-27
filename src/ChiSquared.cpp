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

		"Args:\n"
		"    x (float): A real-valued input.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("pchisq", static_cast<double(*)(double, double, bool)>(&stats::pchisq),
		py::arg("p"), py::arg("dof") = 1.0, py::arg("log") = false,
		"Distribution function of the Chi-squared distribution.\n\n"

		"Args:\n"
		"    p (float): A real-valued input.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qchisq", static_cast<double(*)(double, double)>(&stats::qchisq),
		py::arg("q"), py::arg("dof") = 1.0,
		"Quantile function of the Chi-squared distribution.\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rchisq", [](double dof) { return stats::rchisq(dof); },
		py::arg("dof") = 1.0,
		"Random sampling function for the Chi-squared distribution.\n\n"

		"Args:\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Chi-squared distribution.");

	m.def("rchisq", [](size_t n, double dof) { return stats::rchisq<std::vector<double>>(1, n, dof); },
		py::arg("n"), py::arg("dof") = 1.0,
		"Random sampling function for the Chi-squared distribution.\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A vector of pseudo-random draws from the Chi-squared distribution.");

	// Vector input
	m.def("dchisq", static_cast<std::vector<double>(*)(const std::vector<double>&, double, bool)>(&stats::dchisq),
		py::arg("x"), py::arg("dof") = 1.0, py::arg("log") = false,
		"Density function of the Chi-squared distribution.\n\n"

		"Args:\n"
		"    x (List[float]): A standard vector input.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A vector of density values corresponding to the elements of `x`.");

	m.def("pchisq", static_cast<std::vector<double>(*)(const std::vector<double>&, double, bool)>(&stats::pchisq),
		py::arg("p"), py::arg("dof") = 1.0, py::arg("log") = false,
		"Distribution function of the Chi-squared distribution.\n\n"

		"Args:\n"
		"    p (List[float]): A standard vector input.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A vector of CDF values corresponding to the elements of `p`.");

	m.def("qchisq", static_cast<std::vector<double>(*)(const std::vector<double>&, double)>(&stats::qchisq),
		py::arg("q"), py::arg("dof") = 1.0,
		"Quantile function of the Chi-squared distribution.\n\n"

		"Args:\n"
		"    q (List[float]): A standard vector input.\n"
		"    dof (float): The degrees of freedom parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A vector of quantiles values corresponding to the elements of `q`.");
}
