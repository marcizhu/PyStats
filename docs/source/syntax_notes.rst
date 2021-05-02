.. Copyright (c) 2021 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Syntax
======

Functions are called using an **R**-like syntax. Some general rules:

- Density functions: ``pystats.d*``. For example, the Normal (Gaussian) density is called using

.. code:: python

    pystats.dnorm(<value>, <mean parameter>, <standard deviation>)

- Cumulative distribution functions: ``pystats.p*``. For example, the Gamma CDF is called using

.. code:: python

    pystats.pgamma(<value>, <shape parameter>, <scale parameter>)

- Quantile functions: ``pystats.q*``. For example, the Beta quantile is called using

.. code:: python

    pystats.qbeta(<value>, <a parameter>, <b parameter>)

- random sampling: ``pystats.r*``. For example, to generate a single draw from the Logistic distribution:

.. code:: python

    pystats.rlogis(<location parameter>, <scale parameter>)

The library also supports lists as input/output:

- The pdf, cdf, and quantile functions can take list arguments. For example,

.. code:: python

    norm_pdf_vals = pystats.dnorm([x / 10 for x in range(-10, 10, 1)], 1.0, 2.0)

- The randomization functions (``r*``) can output random lists of arbitrary size. For example, the following
code will generate a 100-item list of iid draws from a Gamma(3,2) distribution:

.. code:: python

    gamma_rvs = pystats.rgamma(100, 3.0, 2.0)


Additionally, most parameters have defaults to most common values and named parameters are also supported. For example, to generate a single draw from a Normal(0, 2) the following can be used:

.. code:: python

    norm_draw = pystats.rnorm(sd=2.0)
