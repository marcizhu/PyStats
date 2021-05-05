.. Copyright (c) 2021 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Binomial Distribution
=====================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Binomial distribution:

.. math::

   f(x; n, p) = \binom{n}{x} p^x (1-p)^{n-x} \times \mathbf{1}[x \in \{0,\ldots,n\}]

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dbinom-func-ref1:
.. autofunction:: pystats.dbinom(x: float, n_trials: int, prob: float, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _dbinom-func-ref2:
.. autofunction:: pystats.dbinom(x: List[float], n_trials: int, prob: float, log: bool = False) -> List[float]
   :noindex:

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function (CDF) of the Binomial distribution:

.. math::

   F(x; n, p) = \sum_{z \leq x} f(z; n, p)

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pbinom-func-ref1:
.. autofunction:: pystats.pbinom(p: float, n_trials: int, prob: float, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _pbinom-func-ref2:
.. autofunction:: pystats.pbinom(p: List[float], n_trials: int, prob: float, log: bool = False) -> List[float]
   :noindex:

----

Quantile Function
-----------------

The quantile function of the Binomial distribution:

.. math::

   q(r; n, p) = \inf \left\{ x : r \leq F(x; n, p) \right\}

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qbinom-func-ref1:
.. autofunction:: pystats.qbinom(q: float, n_trials: int, prob: float) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _qbinom-func-ref2:
.. autofunction:: pystats.qbinom(q: List[float], n_trials: int, prob: float) -> List[float]
   :noindex:

----

Random Sampling
---------------

Random sampling for the Binomial distribution is achieved by summing the results of simulating `n` Bernoulli-distributed random variables.

Scalar Output
~~~~~~~~~~~~~

.. _rbinom-func-ref1:
.. autofunction:: pystats.rbinom(n_trials: int, prob: float) -> float
   :noindex:

List Output
~~~~~~~~~~~

.. _rbinom-func-ref2:
.. autofunction:: pystats.rbinom(n: int, n_trials: int, prob: float) -> List[float]
   :noindex:
