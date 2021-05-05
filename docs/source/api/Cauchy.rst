.. Copyright (c) 2021 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Cauchy Distribution
===================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Cauchy distribution:

.. math::

   f(x; \mu, \sigma) = \dfrac{1}{\pi \sigma \left[ 1 + \left( \frac{x - \mu}{\sigma} \right)^2 \right]}

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dcauchy-func-ref1:
.. autofunction:: pystats.dcauchy(x: float, mu: float = 0.0, sigma: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _dcauchy-func-ref2:
.. autofunction:: pystats.dcauchy(x: List[float], mu: float = 0.0, sigma: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function (CDF) of the Cauchy distribution:

.. math::

   F(x; \mu, \sigma) = \int_{-\infty}^x f(z; \mu, \sigma) dz = 0.5 + \dfrac{1}{\pi} \text{arctan}\left( \frac{x - \mu}{\sigma} \right)

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pcauchy-func-ref1:
.. autofunction:: pystats.pcauchy(p: float, mu: float = 0.0, sigma: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _pcauchy-func-ref2:
.. autofunction:: pystats.pcauchy(p: List[float], mu: float = 0.0, sigma: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Quantile Function
-----------------

The quantile function of the Cauchy distribution:

.. math::

   q(p; \mu, \sigma) = \mu + \gamma \text{tan} \left( \pi (p - 0.5) \right)

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qcauchy-func-ref1:
.. autofunction:: pystats.qcauchy(q: float, mu: float = 0.0, sigma: float = 1.0) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _qcauchy-func-ref2:
.. autofunction:: pystats.qcauchy(q: List[float], mu: float = 0.0, sigma: float = 1.0) -> List[float]
   :noindex:

----

Random Sampling
---------------

Random sampling for the Cauchy distribution is achieved via the inverse probability integral transform.

Scalar Output
~~~~~~~~~~~~~

.. _rcauchy-func-ref1:
.. autofunction:: pystats.rcauchy(mu: float = 0.0, sigma: float = 1.0) -> float
   :noindex:

List Output
~~~~~~~~~~~

.. _rcauchy-func-ref2:
.. autofunction:: pystats.rcauchy(n: int, mu: float = 0.0, sigma: float = 1.0) -> List[float]
   :noindex:
