#pragma once

#include "pybind11/pybind11.h"

namespace py = pybind11;

#define REGISTER_DISTRIBUTION(dist) dist(m)

void Bernoulli(py::module& m);
void Beta(py::module& m);
void Normal(py::module& m);
void Uniform(py::module& m);
void Weibull(py::module& m);
