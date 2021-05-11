#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#define STATS_ENABLE_STDVEC_WRAPPERS
#include "stats.hpp"

namespace py = pybind11;

void InvGamma(py::module& m)
{
	// Scalar input
	m.def("dinvgamma", static_cast<double(*)(double, double, double, bool)>(&stats::dinvgamma),
		py::arg("x"), py::arg("shape") = 1.0, py::arg("rate") = 1.0, py::arg("log") = false,
		"Density function of the inverse-Gamma distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dinvgamma(1.5, 2, 1)\n"
		"    0.15212359082447174\n\n"

		"Args:\n"
		"    x (float): A real-valued input.\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("pinvgamma", static_cast<double(*)(double, double, double, bool)>(&stats::pinvgamma),
		py::arg("p"), py::arg("shape") = 1.0, py::arg("rate") = 1.0, py::arg("log") = false,
		"Distribution function of the inverse-Gamma distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pinvgamma(1.5, 2, 1)\n"
		"    0.8556951983876534\n\n"

		"Args:\n"
		"    p (float): A real-valued input.\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qinvgamma", static_cast<double(*)(double, double, double)>(&stats::qinvgamma),
		py::arg("q"), py::arg("shape") = 1.0, py::arg("rate") = 1.0,
		"Quantile function of the inverse-Gamma distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qinvgamma(0.95, 2, 1)\n"
		"    2.8140357632821265\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rinvgamma", [](double shape, double rate) { return stats::rinvgamma(shape, rate); },
		py::arg("shape") = 1.0, py::arg("rate") = 1.0,
		"Random sampling function for the inverse-Gamma distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rinvgamma(2, 1)\n"
		"    0.29563080448131196\n\n"

		"Args:\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the inverse-Gamma distribution.");

	m.def("rinvgamma", [](size_t n, double shape, double rate) { return stats::rinvgamma<std::vector<double>>(1, n, shape, rate); },
		py::arg("n"), py::arg("shape") = 1.0, py::arg("rate") = 1.0,
		"Random sampling function for the inverse-Gamma distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rinvgamma(3, 2, 1)\n"
		"    [0.31841204990923705, 0.47383794440642224, 0.4720582119984054]\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of pseudo-random draws from the inverse-Gamma distribution.");

	// Vector input
	m.def("dinvgamma", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::dinvgamma),
		py::arg("x"), py::arg("shape") = 1.0, py::arg("rate") = 1.0, py::arg("log") = false,
		"Density function of the inverse-Gamma distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dinvgamma([1.8, 0.7, 4.2], 3, 2)\n"
		"    [0.12543552347504414, 0.9568116496062874, 0.007984650912112904]\n\n"

		"Args:\n"
		"    x (List[float]): A standard list input.\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of density values corresponding to the elements of `x`.");

	m.def("pinvgamma", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double, bool)>(&stats::pinvgamma),
		py::arg("p"), py::arg("shape") = 1.0, py::arg("rate") = 1.0, py::arg("log") = false,
		"Distribution function of the inverse-Gamma distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pinvgamma([1.8, 0.7, 4.2], 3, 2)\n"
		"    [0.8981685222907052, 0.4559446713286356, 0.9873531870485975]\n\n"

		"Args:\n"
		"    p (List[float]): A standard list input.\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of CDF values corresponding to the elements of `p`.");

	m.def("qinvgamma", static_cast<std::vector<double>(*)(const std::vector<double>&, double, double)>(&stats::qinvgamma),
		py::arg("q"), py::arg("shape") = 1.0, py::arg("rate") = 1.0,
		"Quantile function of the inverse-Gamma distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qinvgamma([0.3, 0.5, 0.6], 3, 2)\n"
		"    [0.5531634821501723, 0.7479262863802247, 0.8752440657450371]\n\n"

		"Args:\n"
		"    q (List[float]): A standard list input.\n"
		"    shape (float): The shape parameter, a real-valued input.\n"
		"    rate (float): The rate parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of quantiles values corresponding to the elements of `q`.");
}
