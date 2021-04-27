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

	REGISTER_DISTRIBUTION(Bernoulli);
	REGISTER_DISTRIBUTION(Beta);
//	REGISTER_DISTRIBUTION(Binomial);
	REGISTER_DISTRIBUTION(Cauchy);
//	REGISTER_DISTRIBUTION(ChiSquared);
	REGISTER_DISTRIBUTION(Exponential);
	REGISTER_DISTRIBUTION(F);
//	REGISTER_DISTRIBUTION(Gamma);
//	REGISTER_DISTRIBUTION(InvGamma);
//	REGISTER_DISTRIBUTION(Laplace);
//	REGISTER_DISTRIBUTION(Logistic);
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

	m.def("dchisq", static_cast<double(*)(double, double, bool)>(&stats::dchisq), D_DOC("Chi-squared"), py::arg("x"), py::arg("dof"), py::arg("log") = false);
	m.def("pchisq", static_cast<double(*)(double, double, bool)>(&stats::pchisq), P_DOC("Chi-squared"), py::arg("x"), py::arg("dof"), py::arg("log") = false);
	m.def("qchisq", static_cast<double(*)(double, double      )>(&stats::qchisq), Q_DOC("Chi-squared"), py::arg("p"), py::arg("dof"));
	m.def("rchisq", [](size_t n, double dof) { return stats::rchisq<vector>(1, n, dof); }, R_DOC("Chi-squared"), py::arg("n") = 1, py::arg("dof"));
*/
/*
double Stats::dgamma(double x, double shape_par, double scale_par) { return stats::dgamma(x, shape_par, scale_par); }
double Stats::pgamma(double x, double shape_par, double scale_par) { return stats::pgamma(x, shape_par, scale_par); }
double Stats::qgamma(double p, double shape_par, double scale_par) { return stats::qgamma(p, shape_par, scale_par); }
vector Stats::rgamma(size_t n, double shape_par, double scale_par) { return stats::rgamma<vector>(1, n, shape_par, scale_par); }

double Stats::dinvgamma(double x, double shape_par, double rate_par) { return stats::dinvgamma(x, shape_par, rate_par); }
double Stats::pinvgamma(double x, double shape_par, double rate_par) { return stats::pinvgamma(x, shape_par, rate_par); }
double Stats::qinvgamma(double p, double shape_par, double rate_par) { return stats::qinvgamma(p, shape_par, rate_par); }
vector Stats::rinvgamma(size_t n, double shape_par, double rate_par) { return stats::rinvgamma<vector>(1, n, shape_par, rate_par); }

double Stats::dlaplace(double x, double mu_par, double sigma_par) { return stats::dlaplace(x, mu_par, sigma_par); }
double Stats::plaplace(double x, double mu_par, double sigma_par) { return stats::plaplace(x, mu_par, sigma_par); }
double Stats::qlaplace(double p, double mu_par, double sigma_par) { return stats::qlaplace(p, mu_par, sigma_par); }
vector Stats::rlaplace(size_t n, double mu_par, double sigma_par) { return stats::rlaplace<vector>(1, n, mu_par, sigma_par); }

double Stats::dlogis(double x, double mu_par, double sigma_par) { return stats::dlogis(x, mu_par, sigma_par); }
double Stats::plogis(double x, double mu_par, double sigma_par) { return stats::plogis(x, mu_par, sigma_par); }
double Stats::qlogis(double p, double mu_par, double sigma_par) { return stats::qlogis(p, mu_par, sigma_par); }
vector Stats::rlogis(size_t n, double mu_par, double sigma_par) { return stats::rlogis<vector>(1, n, mu_par, sigma_par); }
*/
}
