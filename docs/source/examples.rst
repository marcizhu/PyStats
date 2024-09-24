.. Copyright (c) 2021-2024 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Examples
========

.. code:: python

   # Evaluate the normal PDF at x = 1, mu = 0, sigma = 1
   dval_1 = pystats.dnorm(1.0, 0.0, 1.0)

   # Evaluate the normal PDF at x = 1, mu = 0, sigma = 1, and return the log value
   dval_2 = pystats.dnorm(1.0, 0.0, 1.0, True)

   # Same as above, but using default values and named parameters
   dval_3 = pystats.dnorm(1.0, log=True)

   # Evaluate the normal CDF at x = 1, mu = 0, sigma = 1
   pval = pystats.pnorm(1.0, 0.0, 1.0)

   # Evaluate the Laplacian quantile at q = 0.1, mu = 0, sigma = 1
   qval = pystats.qlaplace(0.1, 0.0, 1.0)

   # Draw from a t-distribution with dof = 30
   rval = pystats.rt(dof=30)

   # List output
   beta_rvs = pystats.rbeta(100, 3.0, 2.0)

   # List input
   beta_cdf_vals = pystats.pbeta(beta_rvs, 3.0, 2.0)
