.. Copyright (c) 2021 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Normal Distribution
===================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Normal (Gaussian) distribution:

.. math::

   f(x; \mu, \sigma) = \frac{1}{\sqrt{2 \pi} \sigma} \exp \left( - \frac{(x-\mu)^2}{2 \sigma^2} \right)

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dnorm-func-ref1:
.. autofunction:: pystats.dnorm(x: float, mean: float = 0.0, sd: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _dnorm-func-ref2:
.. autofunction:: pystats.dnorm(x: List[float], mean: float = 0.0, sd: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function (CDF) of the Normal (Gaussian) distribution:

.. math::

   F(x; \mu, \sigma) = \int_{-\infty}^x f(z; \mu, \sigma) dz = \frac{1}{2} \times \left( 1 +  \text{erf} \left( \frac{x - \mu}{\sqrt{2} \sigma} \right) \right)

where :math:`\text{erf}(\cdot)` denotes the Gaussian error function.

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pnorm-func-ref1:
.. autofunction:: pystats.pnorm(p: float, mean: float = 0.0, sd: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _pnorm-func-ref2:
.. autofunction:: pystats.pnorm(p: List[float], mean: float = 0.0, sd: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Quantile Function
-----------------

The quantile function of the log-Normal distribution:

.. math::

   q(p; \mu, \sigma) = \mu + \sqrt{2} \sigma \times \text{erf}^{-1} \left( 2 p - 1 \right)

where :math:`\text{erf}^{-1}(\cdot)` denotes the inverse Gaussian error function.

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qnorm-func-ref1:
.. autofunction:: pystats.qnorm(q: float, mean: float = 0.0, sd: float = 1.0) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _qnorm-func-ref2:
.. autofunction:: pystats.qnorm(q: List[float], mean: float = 0.0, sd: float = 1.0) -> List[float]
   :noindex:

----

Random Sampling
---------------

Random sampling for the Normal distribution is achieved via the ``normal_distribution`` class from the C++ standard library, imported from ``<random>``.

Scalar Output
~~~~~~~~~~~~~

.. _rnorm-func-ref1:
.. autofunction:: pystats.rnorm(mean: float = 0.0, sd: float = 1.0) -> float
   :noindex:

List Output
~~~~~~~~~~~

.. _rnorm-func-ref2:
.. autofunction:: pystats.rnorm(n: int, mean: float = 0.0, sd: float = 1.0) -> List[float]
   :noindex:
