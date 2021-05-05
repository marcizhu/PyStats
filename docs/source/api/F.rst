.. Copyright (c) 2021 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

F-Distribution
==============

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the F distribution:

.. math::

   f(x; d_1, d_2) = \frac{1}{\mathcal{B} \left( \frac{d_1}{2}, \frac{d_2}{2} \right)} \left( \frac{d_1}{d_2} \right)^{\frac{d_1}{2}} x^{d_1/2 - 1} \left(1 + \frac{d_1}{d_2} x \right)^{- \frac{d_1+d_2}{2}} \times \mathbf{1} [x \geq 0]

where :math:`\mathcal{B}(a,b)` denotes the Beta function.

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _df-func-ref1:
.. autofunction:: pystats.df(x: float, df1: float = 1.0, df2: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _df-func-ref2:
.. autofunction:: pystats.df(x: List[float], df1: float = 1.0, df2: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function (CDF) of the F distribution:

.. math::

   F(x; d_1, d_2) = \int_0^x f(z; d_1, d_2) dz = I_{\frac{d_1 x}{d_2 + d_1 x}} (d_1 / 2, d_2 / 2)

where :math:`I_x (a,b)` denotes the regularized incomplete Beta function.

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pf-func-ref1:
.. autofunction:: pystats.pf(p: float, df1: float = 1.0, df2: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _pf-func-ref2:
.. autofunction:: pystats.pf(p: List[float], df1: float = 1.0, df2: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Quantile Function
-----------------

The quantile function of the F distribution:

.. math::

   q(p; a,b) = \inf \left\{ x : p \leq I_{\frac{d_1 x}{d_2 + d_1 x}} (d_1 / 2, d_2 / 2) \right\}

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qf-func-ref1:
.. autofunction:: pystats.qf(q: float, df1: float = 1.0, df2: float = 1.0) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _qf-func-ref2:
.. autofunction:: pystats.qf(q: List[float], df1: float = 1.0, df2: float = 1.0) -> List[float]
   :noindex:

----

Random Sampling
---------------

Random sampling for the Beta distribution is achieved by simulating two independent :math:`\chi^2`-distributed random variables, :math:`X \sim \chi^2(d_1), Y \sim \chi^2(d_2)`, then returning:

.. math::

   Z = \frac{d_1}{d_2} \frac{X}{Y}

Scalar Output
~~~~~~~~~~~~~

.. _rf-func-ref1:
.. autofunction:: pystats.rf(df1: float = 1.0, df2: float = 1.0) -> float
   :noindex:

List Output
~~~~~~~~~~~

.. _rf-func-ref2:
.. autofunction:: pystats.rf(n: int, df1: float = 1.0, df2: float = 1.0) -> List[float]
   :noindex:
