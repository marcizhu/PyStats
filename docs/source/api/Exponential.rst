.. Copyright (c) 2021 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Exponential Distribution
========================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Exponential distribution:

.. math::

   f(x; \lambda) = \lambda \exp(-\lambda x) \times \mathbf{1}[ x \geq 0]

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dexp-func-ref1:
.. autofunction:: pystats.dexp(x: float, rate: float = 1.0, log: bool = False) -> float

List Input
~~~~~~~~~~

.. _dexp-func-ref2:
.. autofunction:: pystats.dexp(x: List[float], rate: float = 1.0, log: bool = False) -> List[float]

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function (CDF) of the Exponential distribution:

.. math::

   \int_0^x f(z; \lambda) dz = 1 - \exp(-\lambda x \times \mathbf{1}[ x \geq 0])

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pexp-func-ref1:
.. autofunction:: pystats.pexp(p: float, rate: float = 1.0, log: bool = False) -> float

List Input
~~~~~~~~~~

.. _pexp-func-ref2:
.. autofunction:: pystats.pexp(p: List[float], rate: float = 1.0, log: bool = False) -> List[float]

----

Quantile Function
-----------------

The quantile function of the Exponential distribution:

.. math::

   q(p; \lambda) = - \ln (1 - p) / \lambda

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qexp-func-ref1:
.. autofunction:: pystats.qexp(q: float, rate: float = 1.0) -> float

List Input
~~~~~~~~~~

.. _qexp-func-ref2:
.. autofunction:: pystats.qexp(q: List[float], rate: float = 1.0) -> List[float]

----

Random Sampling
---------------

Random sampling for the Cauchy distribution is achieved via the inverse probability integral transform.

Scalar Output
~~~~~~~~~~~~~

.. _rexp-func-ref1:
.. autofunction:: pystats.rexp(rate: float = 1.0) -> float

List Output
~~~~~~~~~~~

.. _rexp-func-ref2:
.. autofunction:: pystats.rexp(n: int, rate: float = 1.0) -> List[float]
