#pragma once

#include "pybind11/pybind11.h"

namespace py = pybind11;

#define REGISTER_DISTRIBUTION(dist) dist(m)

void Bernoulli(py::module& m);
void Beta(py::module& m);
void Cauchy(py::module& m);
void Exponential(py::module& m);
void F(py::module& m);
void Normal(py::module& m);
void Poisson(py::module& m);
void StudentT(py::module& m);
void Uniform(py::module& m);
void Weibull(py::module& m);
