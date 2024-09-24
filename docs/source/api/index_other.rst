.. Copyright (c) 2021-2024 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Other statistical functions
===========================

**Table of contents**

.. contents:: :local:

----

Mean
----

The mean of the input data is calculated using:

.. math::

   \overline{x}=\frac{\sum_{i=1}^{n}{x_i}}{n}

.. autofunction:: pystats.mean(x: List[float]) -> float
   :noindex:

----

Standard deviation
------------------

The standard deviation of the input data is calculated using:

.. math::

   s=\sqrt{\frac{\sum_{i=1}^{n}{(x_i - \overline{x})^2}}{n-1}}

This function returns the standard deviation of the sample; that is, it returns the unbiased standard deviation.

.. autofunction:: pystats.sd(x: List[float]) -> float
   :noindex:

----

Variance
--------

The variance of the input data is calculated using:

.. math::

   s^2=\frac{\sum_{i=1}^{n}{(x_i - \overline{x})^2}}{n-1}

This function returns the variance of the sample; that is, it returns the unbiased variance.

.. autofunction:: pystats.var(x: List[float]) -> float
   :noindex:
