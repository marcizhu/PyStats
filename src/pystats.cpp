#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "Utils.h"
#include "Distributions.h"

namespace py = pybind11;

PYBIND11_MODULE(pystats, m)
{
	m.doc() = "R-like statistical functions and distributions for Python 3";

	m.def("mean", &mean, py::arg("x"), py::arg("nan_rm") = false);
	m.def("sd",   &sd,   py::arg("x"), py::arg("nan_rm") = false);
//	m.def("var",  &var,  py::arg("x"), py::arg("nan_rm") = false);
//	m.def("IQR",  &IQR,  py::arg("x"), py::arg("nan_rm") = false, py::arg("type") = 7); //https://www.rdocumentation.org/packages/stats/versions/3.6.2/topics/IQR

	REGISTER_DISTRIBUTION(Bernoulli);
	REGISTER_DISTRIBUTION(Beta);
//	REGISTER_DISTRIBUTION(Binomial);
	REGISTER_DISTRIBUTION(Cauchy);
	REGISTER_DISTRIBUTION(ChiSquared);
	REGISTER_DISTRIBUTION(Exponential);
	REGISTER_DISTRIBUTION(F);
	REGISTER_DISTRIBUTION(Gamma);
	REGISTER_DISTRIBUTION(InvGamma);
	REGISTER_DISTRIBUTION(Laplace);
	REGISTER_DISTRIBUTION(LogNormal);
	REGISTER_DISTRIBUTION(Logistic);
	REGISTER_DISTRIBUTION(Normal);
	REGISTER_DISTRIBUTION(Poisson);
	REGISTER_DISTRIBUTION(StudentT);
	REGISTER_DISTRIBUTION(Uniform);
	REGISTER_DISTRIBUTION(Weibull);

/*
	m.def("dbinom", static_cast<double(*)(int64_t, int64_t, double, bool)>(&stats::dbinom), D_DOC("Binomial"), py::arg("x"), py::arg("n_trials"), py::arg("prob"), py::arg("log") = false);
	m.def("pbinom", static_cast<double(*)(int64_t, int64_t, double, bool)>(&stats::pbinom), P_DOC("Binomial"), py::arg("x"), py::arg("n_trials"), py::arg("prob"), py::arg("log") = false);
	m.def("qbinom", static_cast<double(*)(double , int64_t, double      )>(&stats::qbinom), Q_DOC("Binomial"), py::arg("p"), py::arg("n_trials"), py::arg("prob"));
	m.def("rbinom", [](size_t  n, int64_t n_trials, double prob) { return stats::rbinom<vector>(1, n, n_trials, prob); }, R_DOC("Binomial"), py::arg("n") = 1, py::arg("n_trials"), py::arg("prob"));
*/
}
