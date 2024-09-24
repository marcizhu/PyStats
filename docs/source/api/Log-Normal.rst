.. Copyright (c) 2021-2024 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Log-Normal Distribution
=======================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the log-Normal distribution:

.. math::

   f(x; \mu, \sigma) = \frac{1}{x} \frac{1}{\sqrt{2 \pi} \sigma} \exp \left( - \frac{(\ln x-\mu)^2}{2 \sigma^2} \right)

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dlnorm-func-ref1:
.. autofunction:: pystats.dlnorm(x: float, mean: float = 0.0, sd: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _dlnorm-func-ref2:
.. autofunction:: pystats.dlnorm(x: List[float], mean: float = 0.0, sd: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function (CDF) of the log-Normal distribution:

.. math::

   F(x; \mu, \sigma) = \int_0^x f(z; \mu, \sigma) dz = \frac{1}{2} + \frac{1}{2} \times \text{erf} \left( \frac{\ln (x) - \mu}{\sigma} \right)

where :math:`\text{erf}(\cdot)` denotes the Gaussian error function.

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _plnorm-func-ref1:
.. autofunction:: pystats.plnorm(p: float, mean: float = 0.0, sd: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _plnorm-func-ref2:
.. autofunction:: pystats.plnorm(p: List[float], mean: float = 0.0, sd: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Quantile Function
-----------------

The quantile function of the log-Normal distribution:

.. math::

   q(p; \mu, \sigma) = \exp \left( \mu + \sqrt{2} \sigma \times \text{erf}^{-1} \left( 2 p - 1 \right) \right)

where :math:`\text{erf}^{-1}(\cdot)` denotes the inverse Gaussian error function.

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qlnorm-func-ref1:
.. autofunction:: pystats.qlnorm(q: float, mean: float = 0.0, sd: float = 1.0) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _qlnorm-func-ref2:
.. autofunction:: pystats.qlnorm(q: List[float], mean: float = 0.0, sd: float = 1.0) -> List[float]
   :noindex:

----

Random Sampling
---------------

Random sampling for the log-Normal distribution is achieved by simulating :math:`X \sim N(\mu, \sigma^2)`, then returning

.. math::

   Z = \exp( X ) \sim \text{Lognormal} (\mu, \sigma^2)

Scalar Output
~~~~~~~~~~~~~

.. _rlnorm-func-ref1:
.. autofunction:: pystats.rlnorm(mean: float = 0.0, sd: float = 1.0) -> float
   :noindex:

List Output
~~~~~~~~~~~

.. _rlnorm-func-ref2:
.. autofunction:: pystats.rlnorm(n: int, mean: float = 0.0, sd: float = 1.0) -> List[float]
   :noindex:
