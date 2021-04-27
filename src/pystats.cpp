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

	REGISTER_DISTRIBUTION(Bernoulli);
	REGISTER_DISTRIBUTION(Beta);
	REGISTER_DISTRIBUTION(Normal);
	REGISTER_DISTRIBUTION(Uniform);
	REGISTER_DISTRIBUTION(Weibull);

/*
	m.def("dbinom", static_cast<double(*)(int64_t, int64_t, double, bool)>(&stats::dbinom), D_DOC("Binomial"), py::arg("x"), py::arg("n_trials"), py::arg("prob"), py::arg("log") = false);
	m.def("pbinom", static_cast<double(*)(int64_t, int64_t, double, bool)>(&stats::pbinom), P_DOC("Binomial"), py::arg("x"), py::arg("n_trials"), py::arg("prob"), py::arg("log") = false);
	m.def("qbinom", static_cast<double(*)(double , int64_t, double      )>(&stats::qbinom), Q_DOC("Binomial"), py::arg("p"), py::arg("n_trials"), py::arg("prob"));
	m.def("rbinom", [](size_t  n, int64_t n_trials, double prob) { return stats::rbinom<vector>(1, n, n_trials, prob); }, R_DOC("Binomial"), py::arg("n") = 1, py::arg("n_trials"), py::arg("prob"));

	m.def("dcauchy", static_cast<double(*)(double, double, double, bool)>(&stats::dcauchy), D_DOC("Cauchy"), py::arg("x"), py::arg("location"), py::arg("scale"), py::arg("log") = false);
	m.def("pcauchy", static_cast<double(*)(double, double, double, bool)>(&stats::pcauchy), P_DOC("Cauchy"), py::arg("x"), py::arg("location"), py::arg("scale"), py::arg("log") = false);
	m.def("qcauchy", static_cast<double(*)(double, double, double      )>(&stats::qcauchy), Q_DOC("Cauchy"), py::arg("p"), py::arg("location"), py::arg("scale"));
	m.def("rcauchy", [](size_t n, double mu, double sigma) { return stats::rcauchy<vector>(1, n, mu, sigma); }, R_DOC("Cauchy"), py::arg("n") = 1, py::arg("location"), py::arg("scale"));

	m.def("dchisq", static_cast<double(*)(double, double, bool)>(&stats::dchisq), D_DOC("Chi-squared"), py::arg("x"), py::arg("dof"), py::arg("log") = false);
	m.def("pchisq", static_cast<double(*)(double, double, bool)>(&stats::pchisq), P_DOC("Chi-squared"), py::arg("x"), py::arg("dof"), py::arg("log") = false);
	m.def("qchisq", static_cast<double(*)(double, double      )>(&stats::qchisq), Q_DOC("Chi-squared"), py::arg("p"), py::arg("dof"));
	m.def("rchisq", [](size_t n, double dof) { return stats::rchisq<vector>(1, n, dof); }, R_DOC("Chi-squared"), py::arg("n") = 1, py::arg("dof"));

	m.def("dexp", static_cast<double(*)(double, double, bool)>(&stats::dexp), D_DOC("Exponential"), py::arg("x"), py::arg("rate"), py::arg("log") = false);
	m.def("pexp", static_cast<double(*)(double, double, bool)>(&stats::pexp), P_DOC("Exponential"), py::arg("x"), py::arg("rate"), py::arg("log") = false);
	m.def("qexp", static_cast<double(*)(double, double      )>(&stats::qexp), Q_DOC("Exponential"), py::arg("p"), py::arg("rate"));
	m.def("rexp", [](size_t n, double rate) { return stats::rexp<vector>(1, n, rate); }, R_DOC("Exponential"), py::arg("n") = 1, py::arg("rate"));

	m.def("df", static_cast<double(*)(double, double, double, bool)>(&stats::df), D_DOC("F"), py::arg("x"), py::arg("df1"), py::arg("df2"), py::arg("log") = false);
	m.def("pf", static_cast<double(*)(double, double, double, bool)>(&stats::pf), P_DOC("F"), py::arg("x"), py::arg("df1"), py::arg("df2"), py::arg("log") = false);
	m.def("qf", static_cast<double(*)(double, double, double      )>(&stats::qf), Q_DOC("F"), py::arg("p"), py::arg("df1"), py::arg("df2"));
	m.def("rf", [](size_t n, double df1, double df2) { return stats::rf<vector>(1, n, df1, df2); }, R_DOC("F"), py::arg("n"), py::arg("df1"), py::arg("df2"));
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

double Stats::dpois(size_t x, double rate_par) { return stats::dpois(x, rate_par); }
double Stats::ppois(size_t x, double rate_par) { return stats::ppois(x, rate_par); }
double Stats::qpois(double p, double rate_par) { return stats::qpois(p, rate_par); }
vector Stats::rpois(size_t n, double rate_par) { return stats::rpois<vector>(1, n, rate_par); }

double Stats::dt(double x, double dof_par) { return stats::dt(x, dof_par); }
double Stats::pt(double x, double dof_par) { return stats::pt(x, dof_par); }
double Stats::qt(double p, double dof_par) { return stats::qt(p, dof_par); }
vector Stats::rt(size_t n, double dof_par) { return stats::rt<vector>(1, n, dof_par); }
*/
}
