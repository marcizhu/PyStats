.. Copyright (c) 2021 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Student's t-Distribution
========================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Student's t distribution:

.. math::

   f(x; \nu) = \dfrac{\Gamma \left( \frac{\nu + 1}{2} \right)}{ \sqrt{\nu \pi} \Gamma \left( \frac{\nu}{2} \right)} \left( 1 + \frac{x^2}{\nu} \right)^{- \frac{\nu+1}{2}}

where :math:`\Gamma(\cdot)` denotes the gamma function.

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dt-func-ref1:
.. autofunction:: pystats.dt(x: float, dof: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _dt-func-ref2:
.. autofunction:: pystats.dt(x: List[float], dof: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function (CDF) of the Student's t distribution:

.. math::

   F(x; \nu) = \int_{-\infty}^x f(z; \nu) dz = \frac{1}{2} + x \Gamma \left( \frac{\nu + 1}{2} \right) + \dfrac{ {}_2 F_1 \left( \frac{1}{2}, \frac{\nu+1}{2}; \frac{3}{\nu}; - \frac{x^2}{\nu} \right) }{ \sqrt{\nu \pi} \Gamma \left( \frac{\nu}{2} \right)}

where :math:`\Gamma(\cdot)` denotes the gamma function and :math:`{}_2 F_1` denotes the hypergeometric function.

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pt-func-ref1:
.. autofunction:: pystats.pt(p: float, dof: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _pt-func-ref2:
.. autofunction:: pystats.pt(p: List[float], dof: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Quantile Function
-----------------

The quantile function of the Student's t distribution:

.. math::

   q(p; \nu) = \inf \left\{ x : p \leq F(x; \nu) \right\}

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qt-func-ref1:
.. autofunction:: pystats.qt(q: float, dof: float = 1.0) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _qt-func-ref2:
.. autofunction:: pystats.qt(q: List[float], dof: float = 1.0) -> List[float]
   :noindex:

----

Random Sampling
---------------

Scalar Output
~~~~~~~~~~~~~

.. _rt-func-ref1:
.. autofunction:: pystats.rt(dof: float = 1.0) -> float
   :noindex:

List Output
~~~~~~~~~~~

.. _rt-func-ref2:
.. autofunction:: pystats.rt(n: int, dof: float = 1.0) -> List[float]
   :noindex:
