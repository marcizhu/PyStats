#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#define STATS_ENABLE_STDVEC_WRAPPERS
#include "stats.hpp"

namespace py = pybind11;

void Bernoulli(py::module& m)
{
	// Scalar input
	m.def("dbern", static_cast<double(*)(stats::llint_t, double, bool)>(&stats::dbern),
		py::arg("x"), py::arg("prob"), py::arg("log") = false,
		"Density function of the Bernoulli distribution.\n\n"

		"Args:\n"
		"    x (int): An integral-valued input, equal to 0 or 1.\n"
		"    prob (float): The probability parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("pbern", static_cast<double(*)(stats::llint_t, double, bool)>(&stats::pbern),
		py::arg("p"), py::arg("prob"), py::arg("log") = false,
		"Distribution function of the Bernoulli distribution.\n\n"

		"Args:\n"
		"    p (int): A value equal to 0 or 1.\n"
		"    prob (float): The probability parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qbern", static_cast<double(*)(double, double)>(&stats::qbern),
		py::arg("q"), py::arg("prob"),
		"Quantile function of the Bernoulli distribution.\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rbern", [](double prob) { return stats::rbern(prob); },
		py::arg("prob"),
		"Random sampling function for the Bernoulli distribution.\n\n"

		"Args:\n"
		"    prob (float): The probability parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Bernoulli distribution.");

	m.def("rbern", [](size_t n, double prob) { return stats::rbern<std::vector<double>>(1, n, prob); },
		py::arg("n"), py::arg("prob"),
		"Random sampling function for the Bernoulli distribution.\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    prob (float): The probability parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of pseudo-random draws from the Bernoulli distribution.");

	// Vector input
	m.def("dbern", static_cast<std::vector<double>(*)(const std::vector<int64_t>&, double, bool)>(&stats::dbern),
		py::arg("x"), py::arg("prob"), py::arg("log") = false,
		"Density function of the Bernoulli distribution.\n\n"

		"Args:\n"
		"    x (List[int]): A standard list input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of density values corresponding to the elements of `x`.");

	m.def("pbern", static_cast<std::vector<double>(*)(const std::vector<int64_t>&, double, bool)>(&stats::pbern),
		py::arg("p"), py::arg("prob"), py::arg("log") = false,
		"Distribution function of the Bernoulli distribution.\n\n"

		"Args:\n"
		"    p (List[int]): A standard list input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of CDF values corresponding to the elements of `p`.");

	m.def("qbern", static_cast<std::vector<double>(*)(const std::vector<double>&, double)>(&stats::qbern),
		py::arg("q"), py::arg("prob"),
		"Quantile function of the Bernoulli distribution.\n\n"

		"Args:\n"
		"    q (List[float]): A standard list input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of quantiles values corresponding to the elements of `q`.");
}
