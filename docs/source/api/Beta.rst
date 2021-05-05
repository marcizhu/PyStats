.. Copyright (c) 2021 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Beta Distribution
=================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Beta distribution:

.. math::

   f(x; a,b) = \frac{1}{\mathcal{B}(a,b)} x^{a-1} (1-x)^{b-1} \times \mathbf{1}[0 \leq x \leq 1]

where :math:`\mathcal{B}(a,b)` denotes the Beta function.

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dbeta-func-ref1:
.. autofunction:: pystats.dbeta(x: float, shape1: float, shape2: float, log: bool = False) -> float

List Input
~~~~~~~~~~

.. _dbeta-func-ref2:
.. autofunction:: pystats.dbeta(x: List[float], shape1: float, shape2: float, log: bool = False) -> List[float]s

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function (CDF) of the Beta distribution:

.. math::

   F(x; a, b) = \int_0^x f(z; a,b) dz = I_x (a,b)

where :math:`I_x (a,b)` denotes the regularized incomplete Beta function.

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pbeta-func-ref1:
.. autofunction:: pystats.pbeta(p: float, shape1: float, shape2: float, log: bool = False) -> float

List Input
~~~~~~~~~~

.. _pbeta-func-ref2:
.. autofunction:: pystats.pbeta(p: List[float], shape1: float, shape2: float, log: bool = False) -> List[float]

----

Quantile Function
-----------------

The quantile function of the Beta distribution:

.. math::

   q(p; a,b) = \inf \left\{ x : p \leq I_x (a,b) \right\}

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qbeta-func-ref1:
.. autofunction:: pystats.qbeta(q: float, shape1: float, shape2: float) -> float

List Input
~~~~~~~~~~

.. _qbeta-func-ref2:
.. autofunction:: pystats.qbeta(q: List[float], shape1: float, shape2: float) -> List[float]

----

Random Sampling
---------------

Random sampling for the Beta distribution is achieved by simulating two independent gamma-distributed random variables, :math:`X \sim G(a,1), Y \sim G(a,1)`, then returning:

.. math::

   Z = \frac{X}{X+Y} \sim B(a,b)

Scalar Output
~~~~~~~~~~~~~

.. _rbeta-func-ref1:
.. autofunction:: pystats.rbeta(shape1: float, shape2: float) -> float

List Output
~~~~~~~~~~~

.. _rbeta-func-ref3:
.. autofunction:: pystats.rbeta(n: int, shape1: float, shape2: float) -> List[float]

