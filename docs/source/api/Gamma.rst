.. Copyright (c) 2021 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Gamma Distribution
==================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Gamma distribution:

.. math::

   f(x; k, \theta) = \dfrac{x^{k-1}\exp(-x/\theta)}{\theta^k \Gamma(k)} \times \mathbf{1}[ x \geq 0 ]

where :math:`\Gamma(\cdot)` denotes the Gamma function, :math:`k` is the shape parameter, and :math:`\theta` is the scale parameter.

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dgamma-func-ref1:
.. autofunction:: pystats.dgamma(x: float, shape: float = 1.0, scale: float = 1.0, log: bool = False) -> float

List Input
~~~~~~~~~~

.. _dgamma-func-ref2:
.. autofunction:: pystats.dgamma(x: List[float], shape: float = 1.0, scale: float = 1.0, log: bool = False) -> List[float]

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function (CDF) of the Gamma distribution:

.. math::

   F(x; k, \theta) = \int_0^x f(z; k, \theta) dz = \frac{\gamma(k,x\theta)}{\Gamma (k)}

where :math:`\Gamma(\cdot)` denotes the gamma function and :math:`\gamma(\cdot, \cdot)` denotes the incomplete gamma function.

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pgamma-func-ref1:
.. autofunction:: pystats.pgamma(p: float, shape: float = 1.0, scale: float = 1.0, log: bool = False) -> float

List Input
~~~~~~~~~~

.. _pgamma-func-ref2:
.. autofunction:: pystats.pgamma(p: List[float], shape: float = 1.0, scale: float = 1.0, log: bool = False) -> List[float]

----

Quantile Function
-----------------

The quantile function of the Gamma distribution:

.. math::

   q(p; k, \theta) = \inf \left\{ x : p \leq \frac{\gamma(k,x\theta)}{\Gamma (k)} \right\}

where :math:`\Gamma(\cdot)` denotes the gamma function and :math:`\gamma(\cdot, \cdot)` denotes the incomplete gamma function.

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qgamma-func-ref1:
.. autofunction:: pystats.qgamma(q: float, shape: float = 1.0, scale: float = 1.0) -> float

List Input
~~~~~~~~~~

.. _qgamma-func-ref2:
.. autofunction:: pystats.qgamma(q: List[float], shape: float = 1.0, scale: float = 1.0) -> List[float]

----

Random Sampling
---------------

Random sampling for the Gamma distribution is achieved via the Ziggurat method of Marsaglia and Tsang (2000).

Scalar Output
~~~~~~~~~~~~~

.. _rgamma-func-ref1:
.. autofunction:: pystats.rgamma(shape: float = 1.0, scale: float = 1.0) -> float

List Output
~~~~~~~~~~~

.. _rgamma-func-ref2:
.. autofunction:: pystats.rgamma(n: int, shape: float = 1.0, scale: float = 1.0) -> List[float]
