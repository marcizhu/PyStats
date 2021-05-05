.. Copyright (c) 2021 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Uniform Distribution
====================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Uniform distribution:

.. math::

   f(x; a, b) = \frac{1}{b-a} \times \mathbf{1}[ a \leq x \leq b]

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dunif-func-ref1:
.. autofunction:: pystats.dunif(x: float, min: float = 0.0, max: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _dunif-func-ref2:
.. autofunction:: pystats.dunif(x: List[float], min: float = 0.0, max: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function (CDF) of the Uniform distribution:

.. math::

   F(x; a, b) = \int_{a}^x f(z; a, b) dz = \frac{x - a}{b-a} \times \mathbf{1}[ a \leq x \leq b] + \times \mathbf{1}[x > b]

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _punif-func-ref1:
.. autofunction:: pystats.punif(p: float, min: float = 0.0, max: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _punif-func-ref2:
.. autofunction:: pystats.punif(p: List[float], min: float = 0.0, max: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Quantile Function
-----------------

The quantile function of the Uniform distribution:

.. math::

   q(p; a, b) = a + p(b-a)

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qunif-func-ref1:
.. autofunction:: pystats.qunif(q: float, min: float = 0.0, max: float = 1.0) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _qunif-func-ref2:
.. autofunction:: pystats.qunif(q: List[float], min: float = 0.0, max: float = 1.0) -> List[float]
   :noindex:

----

Random Sampling
---------------

Random sampling for the Uniform distribution is achieved via the ``uniform_real_distribution`` class from the C++ standard library, imported from ``<random>``.

Scalar Output
~~~~~~~~~~~~~

.. _runif-func-ref1:
.. autofunction:: pystats.runif(min: float = 0.0, max: float = 1.0) -> float
   :noindex:

List Output
~~~~~~~~~~~

.. _runif-func-ref2:
.. autofunction:: pystats.runif(n: int, min: float = 0.0, max: float = 1.0) -> List[float]
   :noindex:
