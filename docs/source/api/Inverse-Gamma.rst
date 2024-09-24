.. Copyright (c) 2021-2024 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Inverse-Gamma Distribution
==========================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the inverse-Gamma distribution:

.. math::

   f(x; \alpha, \beta) = \dfrac{\beta^{\alpha}}{\Gamma(\alpha)} x^{-\alpha-1} \exp\left(-\frac{\beta}{x}\right) \times \mathbf{1}[ x \geq 0 ]

where :math:`\Gamma(\cdot)` denotes the Gamma function, :math:`\alpha` is the shape parameter, and :math:`\beta` is the rate parameter.

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dinvgamma-func-ref1:
.. autofunction:: pystats.dinvgamma(x: float, shape: float = 1.0, rate: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _dinvgamma-func-ref2:
.. autofunction:: pystats.dinvgamma(x: List[float], shape: float = 1.0, rate: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function (CDF) of the inverse-Gamma distribution:

.. math::

   F(x; \alpha, \beta) = \int_0^x f(z; \alpha, \beta) dz = 1 - \frac{\gamma(1/x,\beta/x)}{\Gamma (\alpha)}

where :math:`\Gamma(\cdot)` denotes the gamma function and :math:`\gamma(\cdot, \cdot)` denotes the incomplete gamma function.

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pinvgamma-func-ref1:
.. autofunction:: pystats.pinvgamma(p: float, shape: float = 1.0, rate: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _pinvgamma-func-ref2:
.. autofunction:: pystats.pinvgamma(p: List[float], shape: float = 1.0, rate: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Quantile Function
-----------------

The quantile function of the inverse-Gamma distribution:

.. math::

   q(p; \alpha, \beta) = \inf \left\{ x : p \leq 1 - \frac{\gamma(1/x,\beta/x)}{\Gamma (\alpha)} \right\}

where :math:`\Gamma(\cdot)` denotes the gamma function and :math:`\gamma(\cdot, \cdot)` denotes the incomplete gamma function.

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qinvgamma-func-ref1:
.. autofunction:: pystats.qinvgamma(q: float, shape: float = 1.0, rate: float = 1.0) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _qinvgamma-func-ref2:
.. autofunction:: pystats.qinvgamma(q: List[float], shape: float = 1.0, rate: float = 1.0) -> List[float]
   :noindex:

----

Random Sampling
---------------

Random sampling for the inverse-Gamma distribution is achieved by simulating :math:`X \sim G(\alpha, 1/\beta)`, then returning

.. math::

   Z = \frac{1}{X} \sim \text{IG}(\alpha,\beta)


Scalar Output
~~~~~~~~~~~~~

.. _rinvgamma-func-ref1:
.. autofunction:: pystats.rinvgamma(shape: float = 1.0, rate: float = 1.0) -> float
   :noindex:

List Output
~~~~~~~~~~~

.. _rinvgamma-func-ref2:
.. autofunction:: pystats.rinvgamma(n: int, shape: float = 1.0, rate: float = 1.0) -> List[float]
   :noindex:
