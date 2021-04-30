#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#define STATS_ENABLE_STDVEC_WRAPPERS
#include "stats.hpp"

namespace py = pybind11;

void Binomial(py::module& m)
{
	// Scalar input
	m.def("dbinom", static_cast<double(*)(int64_t, int64_t, double, bool)>(&stats::dbinom),
		py::arg("x"), py::arg("n_trials"), py::arg("prob"), py::arg("log") = false,
		"Density function of the Binomial distribution.\n\n"

		"Args:\n"
		"    x (int): An integral-valued input, equal to 0 or 1.\n"
		"    n_trials (int): The number of trials, a non-negative integral-valued input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("pbinom", static_cast<double(*)(int64_t, int64_t, double, bool)>(&stats::pbinom),
		py::arg("p"), py::arg("n_trials"), py::arg("prob"), py::arg("log") = false,
		"Distribution function of the Binomial distribution.\n\n"

		"Args:\n"
		"    p (float): A value equal to 0 or 1.\n"
		"    n_trials (int): The number of trials, a non-negative integral-valued input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qbinom", static_cast<double(*)(double, int64_t, double)>(&stats::qbinom),
		py::arg("q"), py::arg("n_trials"), py::arg("prob"),
		"Quantile function of the Binomial distribution.\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    n_trials (int): The number of trials, a non-negative integral-valued input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rbinom", [](int64_t n_trials, double prob) { return stats::rbinom(n_trials, prob); },
		py::arg("n_trials"), py::arg("prob"),
		"Random sampling function for the Binomial distribution.\n\n"

		"Args:\n"
		"    n_trials (int): The number of trials, a non-negative integral-valued input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Binomial distribution.");

	m.def("rbinom", [](size_t n, int64_t n_trials, double prob) { return stats::rbinom<std::vector<double>>(1, n, n_trials, prob); },
		py::arg("n"), py::arg("n_trials"), py::arg("prob"),
		"Random sampling function for the Binomial distribution.\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    n_trials (int): The number of trials, a non-negative integral-valued input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A vector of pseudo-random draws from the Binomial distribution.");

	// Vector input
	m.def("dbinom", static_cast<std::vector<double>(*)(const std::vector<int64_t>&, int64_t, double, bool)>(&stats::dbinom),
		py::arg("x"), py::arg("n_trials"), py::arg("prob"), py::arg("log") = false,
		"Density function of the Binomial distribution.\n\n"

		"Args:\n"
		"    x (List[int]): A standard vector input.\n"
		"    n_trials (int): The number of trials, a non-negative integral-valued input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A vector of density values corresponding to the elements of `x`.");

	m.def("pbinom", static_cast<std::vector<double>(*)(const std::vector<double>&, int64_t, double, bool)>(&stats::pbinom),
		py::arg("p"), py::arg("n_trials"), py::arg("prob"), py::arg("log") = false,
		"Distribution function of the Binomial distribution.\n\n"

		"Args:\n"
		"    p (List[float]): A standard vector input.\n"
		"    n_trials (int): The number of trials, a non-negative integral-valued input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A vector of CDF values corresponding to the elements of `p`.");

	m.def("qbinom", static_cast<std::vector<double>(*)(const std::vector<double>&, int64_t, double)>(&stats::qbinom),
		py::arg("q"), py::arg("n_trials"), py::arg("prob"),
		"Quantile function of the Binomial distribution.\n\n"

		"Args:\n"
		"    q (List[float]): A standard vector input.\n"
		"    n_trials (int): The number of trials, a non-negative integral-valued input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A vector of quantiles values corresponding to the elements of `q`.");
}
