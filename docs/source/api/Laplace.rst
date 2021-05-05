.. Copyright (c) 2021 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Laplace Distribution
====================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Laplace distribution:

.. math::

   f(x; \mu, \sigma) = \frac{1}{2 \sigma} \exp \left( - \frac{|x-\mu|}{\sigma} \right)

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dlaplace-func-ref1:
.. autofunction:: pystats.dlaplace(x: float, mu: float = 0.0, sigma: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _dlaplace-func-ref2:
.. autofunction:: pystats.dlaplace(x: List[float], mu: float = 0.0, sigma: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function (CDF) of the Laplace distribution:

.. math::

   F(x; \mu, \sigma) = \int_{-\infty}^x f(z; \mu, \sigma) dz = \frac{1}{2} + \frac{1}{2} \times \text{sign} ( x - \mu ) \times \left( 1 - \exp \left( - \frac{|x - \mu|}{\sigma} \right) \right)

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _plaplace-func-ref1:
.. autofunction:: pystats.plaplace(p: float, mu: float = 0.0, sigma: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _plaplace-func-ref2:
.. autofunction:: pystats.plaplace(p: List[float], mu: float = 0.0, sigma: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Quantile Function
-----------------

The quantile function of the Laplace distribution:

.. math::

   q(p; \mu, \sigma) = \mu - \sigma \times \text{sign}(p - 0.5) \times \ln(1 - 2 | p - 0.5 |)

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qlaplace-func-ref1:
.. autofunction:: pystats.qlaplace(q: float, mu: float = 0.0, sigma: float = 1.0) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _qlaplace-func-ref2:
.. autofunction:: pystats.qlaplace(q: List[float], mu: float = 0.0, sigma: float = 1.0) -> List[float]
   :noindex:

----

Random Sampling
---------------

Random sampling for the Laplace distribution is achieved via the inverse probability integral transform.

Scalar Output
~~~~~~~~~~~~~

.. _rlaplace-func-ref1:
.. autofunction:: pystats.rlaplace(mu: float = 0.0, sigma: float = 1.0) -> float
   :noindex:

List Output
~~~~~~~~~~~

.. _rlaplace-func-ref2:
.. autofunction:: pystats.rlaplace(n: int, mu: float = 0.0, sigma: float = 1.0) -> List[float]
   :noindex:
