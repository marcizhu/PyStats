#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#define STATS_ENABLE_STDVEC_WRAPPERS
#include "stats.hpp"

namespace py = pybind11;

void Binomial(py::module& m)
{
	// Scalar input
	m.def("dbinom", static_cast<double(*)(stats::llint_t, stats::llint_t, double, bool)>(&stats::dbinom),
		py::arg("x"), py::arg("n_trials"), py::arg("prob"), py::arg("log") = false,
		"Density function of the Binomial distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dbinom(2, 4, 0.4)\n"
		"    0.3456\n\n"

		"Args:\n"
		"    x (int): An integral-valued input, equal to 0 or 1.\n"
		"    n_trials (int): The number of trials, a non-negative integral-valued input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The density function evaluated at `x`.");

	m.def("pbinom", static_cast<double(*)(stats::llint_t, stats::llint_t, double, bool)>(&stats::pbinom),
		py::arg("p"), py::arg("n_trials"), py::arg("prob"), py::arg("log") = false,
		"Distribution function of the Binomial distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pbinom(2, 4, 0.4)\n"
		"    0.8208\n\n"

		"Args:\n"
		"    p (float): A value equal to 0 or 1.\n"
		"    n_trials (int): The number of trials, a non-negative integral-valued input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    The cumulative distribution function evaluated at `p`.");

	m.def("qbinom", static_cast<double(*)(double, stats::llint_t, double)>(&stats::qbinom),
		py::arg("q"), py::arg("n_trials"), py::arg("prob"),
		"Quantile function of the Binomial distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qbinom(0.5, 4, 0.4)\n"
		"    2\n\n"

		"Args:\n"
		"    q (float): A real-valued input.\n"
		"    n_trials (int): The number of trials, a non-negative integral-valued input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    The quantile function evaluated at `q`.");

	m.def("rbinom", [](stats::llint_t n_trials, double prob) { return stats::rbinom(n_trials, prob); },
		py::arg("n_trials"), py::arg("prob"),
		"Random sampling function for the Binomial distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rbinom(4, 0.4)\n"
		"    2\n\n"

		"Args:\n"
		"    n_trials (int): The number of trials, a non-negative integral-valued input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A pseudo-random draw from the Binomial distribution.");

	m.def("rbinom", [](size_t n, stats::llint_t n_trials, double prob) { return stats::rbinom<std::vector<double>>(1, n, n_trials, prob); },
		py::arg("n"), py::arg("n_trials"), py::arg("prob"),
		"Random sampling function for the Binomial distribution.\n\n"

		"Example:\n"
		"    >>> pystats.rbinom(10, 4, 0.4)\n"
		"    [1, 4, 0, 2, 3, 2, 2, 2, 2, 1]\n\n"

		"Args:\n"
		"    n (int): The number of output values.\n"
		"    n_trials (int): The number of trials, a non-negative integral-valued input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of pseudo-random draws from the Binomial distribution.");

	// Vector input
	m.def("dbinom", static_cast<std::vector<double>(*)(const std::vector<stats::llint_t>&, stats::llint_t, double, bool)>(&stats::dbinom),
		py::arg("x"), py::arg("n_trials"), py::arg("prob"), py::arg("log") = false,
		"Density function of the Binomial distribution.\n\n"

		"Example:\n"
		"    >>> pystats.dbinom([2, 3, 4], 5, 0.4)\n"
		"    [0.3456, 0.2304, 0.0768]\n\n"

		"Args:\n"
		"    x (List[int]): A standard list input.\n"
		"    n_trials (int): The number of trials, a non-negative integral-valued input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of density values corresponding to the elements of `x`.");

	m.def("pbinom", static_cast<std::vector<double>(*)(const std::vector<double>&, stats::llint_t, double, bool)>(&stats::pbinom),
		py::arg("p"), py::arg("n_trials"), py::arg("prob"), py::arg("log") = false,
		"Distribution function of the Binomial distribution.\n\n"

		"Example:\n"
		"    >>> pystats.pbinom([2, 3, 4], 5, 0.4)\n"
		"    [0.68256, 0.91296, 0.98976]\n\n"

		"Args:\n"
		"    p (List[float]): A standard list input.\n"
		"    n_trials (int): The number of trials, a non-negative integral-valued input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n"
		"    log (bool): Return the log-density or the true form.\n\n"

		"Returns:\n"
		"    A list of CDF values corresponding to the elements of `p`.");

	m.def("qbinom", static_cast<std::vector<double>(*)(const std::vector<double>&, stats::llint_t, double)>(&stats::qbinom),
		py::arg("q"), py::arg("n_trials"), py::arg("prob"),
		"Quantile function of the Binomial distribution.\n\n"

		"Example:\n"
		"    >>> pystats.qbinom([0.2, 0.4, 0.8], 5, 0.4)\n"
		"    [1, 2, 3]\n\n"

		"Args:\n"
		"    q (List[float]): A standard list input.\n"
		"    n_trials (int): The number of trials, a non-negative integral-valued input.\n"
		"    prob (float): The probability parameter, a real-valued input.\n\n"

		"Returns:\n"
		"    A list of quantiles values corresponding to the elements of `q`.");
}
