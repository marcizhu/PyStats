.. Copyright (c) 2021 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Weibull Distribution
====================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Weibull distribution:

.. math::

   f(x; k, \theta) = \frac{k}{\theta} \left( \frac{x}{\theta} \right)^{k-1} \exp \left( - \left( \frac{x}{\theta} \right)^k \right) \times \mathbf{1}[ x \geq 0 ]

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dweibull-func-ref1:
.. autofunction:: pystats.dweibull(x: float, alpha: float = 1.0, sigma: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _dweibull-func-ref2:
.. autofunction:: pystats.dweibull(x: List[float], alpha: float = 1.0, sigma: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function (CDF) of the Weibull distribution:

.. math::

   F(x; k, \theta) = \int_0^x f(z; k, \theta) dz = 1 - \exp \left( - \left( \frac{x}{\theta} \right)^k \times \mathbf{1}[x \geq 0] \right)

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pweibull-func-ref1:
.. autofunction:: pystats.pweibull(p: float, alpha: float = 1.0, sigma: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _pweibull-func-ref2:
.. autofunction:: pystats.pweibull(p: List[float], alpha: float = 1.0, sigma: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Quantile Function
-----------------

The quantile function of the Weibull distribution:

.. math::

   q(p; k, \theta) = \lambda \times (- \ln(1 - p))^{1/k}

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qweibull-func-ref1:
.. autofunction:: pystats.qweibull(q: float, alpha: float = 1.0, sigma: float = 1.0) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _qweibull-func-ref2:
.. autofunction:: pystats.qweibull(q: List[float], alpha: float = 1.0, sigma: float = 1.0) -> List[float]
   :noindex:

----

Random Sampling
---------------

Random sampling for the Weibull distribution is achieved via the inverse probability integral transform.

Scalar Output
~~~~~~~~~~~~~

.. _rweibull-func-ref1:
.. autofunction:: pystats.rweibull(alpha: float = 1.0, sigma: float = 1.0) -> float
   :noindex:

List Output
~~~~~~~~~~~

.. _rweibull-func-ref2:
.. autofunction:: pystats.rweibull(n: int, alpha: float = 1.0, sigma: float = 1.0) -> List[float]
   :noindex:
