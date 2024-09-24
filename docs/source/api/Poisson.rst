.. Copyright (c) 2021-2024 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Poisson Distribution
====================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Poisson distribution:

.. math::

   f(x; \lambda) = \dfrac{\lambda^x \exp(-\lambda)}{x!} \times \mathbf{1}[ x \geq 0]

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dpois-func-ref1:
.. autofunction:: pystats.dpois(x: float, rate: float, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _dpois-func-ref2:
.. autofunction:: pystats.dpois(x: List[float], rate: float, log: bool = False) -> List[float]
   :noindex:

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function (CDF) of the Poisson distribution:

.. math::

   F(x; \lambda) = \sum_{z \leq x} f(z; \lambda) = \exp(-\lambda) \sum_{z \leq x} \dfrac{\lambda^z}{z!} \times \mathbf{1}[ z \geq 0]

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _ppois-func-ref1:
.. autofunction:: pystats.ppois(p: float, rate: float, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _ppois-func-ref2:
.. autofunction:: pystats.ppois(p: List[float], rate: float, log: bool = False) -> List[float]
   :noindex:

----

Quantile Function
-----------------

The quantile function of the Poisson distribution:

.. math::

   q(p; \lambda) = \inf \left\{ x : p \leq F(x; \lambda) \right\}

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qpois-func-ref1:
.. autofunction:: pystats.qpois(q: float, rate: float) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _qpois-func-ref2:
.. autofunction:: pystats.qpois(q: List[float], rate: float) -> List[float]
   :noindex:

----

Random Sampling
---------------

Scalar Output
~~~~~~~~~~~~~

.. _rpois-func-ref1:
.. autofunction:: pystats.rpois(rate: float) -> float
   :noindex:

List Output
~~~~~~~~~~~

.. _rpois-func-ref2:
.. autofunction:: pystats.rpois(n: int, rate: float) -> List[float]
   :noindex:
