#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#define STATS_ENABLE_STDVEC_WRAPPERS
#include "stats.hpp"

namespace py = pybind11;

void F(py::module& m)
{
	// Scalar input
	m.def("df", static_cast<double(*)(double, double, double, bool)>(&stats::df),
		py::arg("x"), py::arg("df1") = 1.0, py::arg("df2") = 1.0, py::arg("log") = false,
		"Density function of the F-distribution distribution.\n\n"

		"Example:\n"
		"    >>> pystats.df(1.5, 10.0, 12.0)\n"
		"    0.3426270538333347\n\n"

		"Args:\n"
		"    x (float): A real-valued input.\n"
		"    df1 (float): A degrees of freedom parameter, a real-valued input.\n"
		"    df2 (float): A degrees of freedom parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("pf", static_cast<double(*)(double, double, double, bool)>(&stats::pf),
		py::arg("p"), py::arg("df1") = 1.0, py::arg("df2") = 1.0, py::arg("log") = false,
		"Distribution function of the F-distribution distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pf(1.5, 10.0, 12.0)\n"
		"    0.7501297253279772\n\n"

		"Args:\n"
		"    p (float): A real-valued input.\n"
		"    df1 (float): A degrees of freedom parameter, a real-valued input.\n"
		"    df2 (float): A degrees of freedom parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qf", static_cast<double(*)(double, double, double)>(&stats::qf),
		py::arg("q"), py::arg("df1") = 1.0, py::arg("df2") = 1.0,
		"Quantile function of the F-distribution distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qf(0.5, 10.0, 12.0)\n"
		"    0.9885595669294069\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    df1 (float): A degrees of freedom parameter, a real-valued input.\n"
		"    df2 (float): A degrees of freedom parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rf", [](double df1, double df2) { return stats::rf(df1, df2); },
		py::arg("df1") = 1.0, py::arg("df2") = 1.0,
		"Random sampling function for the F-distribution distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rf(10.0, 12.0)\n"
		"    2.646874442851056\n\n"

		"Args:\n"
		"    df1 (float): A degrees of freedom parameter, a real-valued input.\n"
		"    df2 (float): A degrees of freedom parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the F-distribution distribution.");

	m.def("rf", [](size_t n, double df1, double df2) { return stats::rf<std::vector<double>>(1, n, df1, df2); },
		py::arg("n"), py::arg("df1") = 1.0, py::arg("df2") = 1.0,
		"Random sampling function for the F-distribution distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rf(3, 10.0, 12.0)\n"
		"    [0.4932413364221738, 0.2827026830899671, 2.750316525821291]\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    df1 (float): A degrees of freedom parameter, a real-valued input.\n"
		"    df2 (float): A degrees of freedom parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of pseudo-random draws from the F-distribution distribution.");

	// Vector input
	m.def("df", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::df),
		py::arg("x"), py::arg("df1") = 1.0, py::arg("df2") = 1.0, py::arg("log") = false,
		"Density function of the F-distribution distribution.\n\n"

		"Example:\n"
		"    >>> pystats.df([0.3, 0.5, 0.9], 10.0, 12.0)\n"
		"    [0.3523215359999982, 0.6861197229627093, 0.7047187344898975]\n\n"

		"Args:\n"
		"    x (List[float]): A standard list input.\n"
		"    df1 (float): A degrees of freedom parameter, a real-valued input.\n"
		"    df2 (float): A degrees of freedom parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of density values corresponding to the elements of `x`.");

	m.def("pf", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::pf),
		py::arg("p"), py::arg("df1") = 1.0, py::arg("df2") = 1.0, py::arg("log") = false,
		"Distribution function of the F-distribution distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pf([0.3, 0.5, 0.9], 10.0, 12.0)\n"
		"    [0.03279349759999985, 0.14036282082102308, 0.43990811032084115]\n\n"

		"Args:\n"
		"    p (List[float]): A standard list input.\n"
		"    df1 (float): A degrees of freedom parameter, a real-valued input.\n"
		"    df2 (float): A degrees of freedom parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of CDF values corresponding to the elements of `p`.");

	m.def("qf", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double)>(&stats::qf),
		py::arg("q"), py::arg("df1") = 1.0, py::arg("df2") = 1.0,
		"Quantile function of the F-distribution distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qf([0.3, 0.5, 0.9], 10.0, 12.0)\n"
		"    [0.7125992144145168, 0.9885595669294069, 2.1877640788750874]\n\n"

		"Args:\n"
		"    q (List[float]): A standard list input.\n"
		"    df1 (float): A degrees of freedom parameter, a real-valued input.\n"
		"    df2 (float): A degrees of freedom parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of quantiles values corresponding to the elements of `q`.");
}
