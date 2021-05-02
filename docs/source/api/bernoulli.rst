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

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dbern-func-ref1:
.. autofunction:: pystats.dbern(x : int, prob : float, log : bool = False) -> float

----

List Input
~~~~~~~~~~

.. _dbern-func-ref2:
.. autofunction:: pystats.dbern(x : List[int], prob : float, log : bool)

----
