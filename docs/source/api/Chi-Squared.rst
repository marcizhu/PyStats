.. Copyright (c) 2021-2024 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Chi-squared Distribution
========================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Chi-squared distribution:

.. math::

   f(x; k) = \dfrac{x^{k/2 - 1} \exp(-x/2)}{ 2^{k/2} \Gamma(k/2)} \times \mathbf{1}[ x \geq 0]

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dchisq-func-ref1:
.. autofunction:: pystats.dchisq(x: float, dof: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _dchisq-func-ref2:
.. autofunction:: pystats.dchisq(x: List[float], dof: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function (CDF) of the Chi-squared distribution:

.. math::

   F(x; k) = \int_0^x f(z; k) dz = \frac{\gamma(k/2,x/2)}{\Gamma (k/2)}

where :math:`\Gamma(\cdot)` denotes the gamma function and :math:`\gamma(\cdot, \cdot)` denotes the incomplete gamma function.

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pchisq-func-ref1:
.. autofunction:: pystats.pchisq(p: float, dof: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _pchisq-func-ref2:
.. autofunction:: pystats.pchisq(p: List[float], dof: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Quantile Function
-----------------

The quantile function of the Chi-squared distribution:

.. math::

   q(p; k) = \inf \left\{ x : p \leq \gamma(k/2,x/2) / \Gamma (k/2) \right\}

where :math:`\Gamma(\cdot)` denotes the gamma function and :math:`\gamma(\cdot, \cdot)` denotes the incomplete gamma function.

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qchisq-func-ref1:
.. autofunction:: pystats.qchisq(q: float, dof: float = 1.0) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _qchisq-func-ref2:
.. autofunction:: pystats.qchisq(q: List[float], dof: float = 1.0) -> List[float]
   :noindex:

----

Random Sampling
---------------

Scalar Output
~~~~~~~~~~~~~

.. _rchisq-func-ref1:
.. autofunction:: pystats.rchisq(dof: float = 1.0) -> float
   :noindex:

List Output
~~~~~~~~~~~

.. _rchisq-func-ref2:
.. autofunction:: pystats.rchisq(n: int, dof: float = 1.0) -> List[float]
   :noindex:
