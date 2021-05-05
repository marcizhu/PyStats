.. Copyright (c) 2021 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Bernoulli Distribution
======================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Bernoulli distribution:

.. math::

   f(x; p) = p^x (1-p)^{1-x} \times \mathbf{1}[x \in \{0,1\}]

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dbern-func-ref1:
.. autofunction:: pystats.dbern(x: int, prob: float, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _dbern-func-ref2:
.. autofunction:: pystats.dbern(x: List[int], prob: float, log: bool = False) -> float
   :noindex:

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function (CDF) of the Bernoulli distribution:

.. math::

   F(x; p) = \sum_{z \leq x} f(z; p) = \begin{cases} 0 & \text{ if } x < 0 \\ 1-p & \text{ if } 0 \leq x < 1 \\ 1 & \text{ if } x \geq 1 \end{cases}

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pbern-func-ref1:
.. autofunction:: pystats.pbern(p: int, prob: float, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _pbern-func-ref2:
.. autofunction:: pystats.pbern(p: List[int], prob: float, log: bool = False) -> float
   :noindex:

----

Quantile Function
-----------------

The quantile function of the Bernoulli distribution:

.. math::

   q(r; p) = \begin{cases} 0 & \text{ if } r \leq 1 - p \\ 1 & \text{ else } \end{cases}

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qbern-func-ref1:
.. autofunction:: pystats.qbern(q: float, prob: float) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _qbern-func-ref2:
.. autofunction:: pystats.qbern(q: List[float], prob: float) -> float
   :noindex:

----

Random Sampling
---------------

Random sampling for the Bernoulli distribution is achieved via the inverse probability integral transform.

Scalar Output
~~~~~~~~~~~~~

.. _rbern-func-ref1:
.. autofunction:: pystats.rbern(prob: float) -> float
   :noindex:

List Output
~~~~~~~~~~~

.. _rbern-func-ref2:
.. autofunction:: pystats.rbern(n: int, prob: float) -> float
   :noindex:
