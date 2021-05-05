.. Copyright (c) 2021 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Logistic Distribution
=====================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Logistic distribution:

.. math::

   f(x; \mu, \sigma) = \dfrac{\exp\left( - \frac{x-\mu}{\sigma} \right)}{\sigma \left( 1 + \exp\left( - \frac{x-\mu}{\sigma} \right) \right)^2 }

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dlogis-func-ref1:
.. autofunction:: pystats.dlogis(x: float, mu: float = 0.0, sigma: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _dlogis-func-ref2:
.. autofunction:: pystats.dlogis(x: List[float], mu: float = 0.0, sigma: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the Logistic distribution:

.. math::

   F(x; \mu, \sigma) = \int_{-\infty}^x f(z; \mu, \sigma) dz  = \dfrac{1}{1 + \exp \left( - \frac{x-\mu}{\sigma} \right) }

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _plogis-func-ref1:
.. autofunction:: pystats.plogis(p: float, mu: float = 0.0, sigma: float = 1.0, log: bool = False) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _plogis-func-ref2:
.. autofunction:: pystats.plogis(p: List[float], mu: float = 0.0, sigma: float = 1.0, log: bool = False) -> List[float]
   :noindex:

----

Quantile Function
-----------------

The quantile function of the Logistic distribution:

.. math::

   q(p; \mu, \sigma) = \mu + \sigma \times \ln \left( \frac{p}{1-p} \right) 

Methods for scalar input, as well as for list input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qlogis-func-ref1:
.. autofunction:: pystats.qlogis(q: float, mu: float = 0.0, sigma: float = 1.0) -> float
   :noindex:

List Input
~~~~~~~~~~

.. _qlogis-func-ref2:
.. autofunction:: pystats.qlogis(q: List[float], mu: float = 0.0, sigma: float = 1.0) -> List[float]
   :noindex:

----

Random Sampling
---------------

Random sampling for the Logistic distribution is achieved via the inverse probability integral transform.

Scalar Output
~~~~~~~~~~~~~

.. _rlogis-func-ref1:
.. autofunction:: pystats.rlogis(mu: float = 0.0, sigma: float = 1.0) -> float
   :noindex:

List Output
~~~~~~~~~~~

.. _rlogis-func-ref2:
.. autofunction:: pystats.rlogis(n: int, mu: float = 0.0, sigma: float = 1.0) -> List[float]
   :noindex:
