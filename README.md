# PyStats

PyStats is a Python 3 library of statistical analysis and distribution functions with simple **R**-like syntax, scalar/list input/output with OpenMP parallelization.

### Contents
- [Distributions](#distributions)
- [Installation](#installation)
- [Documentation](#documentation)
- [Syntax and Examples](#syntax-and-examples)
- [Credits](#credits)
- [License](#license)

## Distributions
Functions to compute the cdf, pdf, quantile, as well as random sampling methods, are available for the following distributions:

- Bernoulli
- Beta
- Binomial
- Cauchy
- Chi-squared
- Exponential
- F
- Gamma
- Inverse-Gamma
- Laplace
- Logistic
- Log-Normal
- Normal (Gaussian)
- Poisson
- Student's t
- Uniform
- Weibull


## Installation
You can use pip to install this library:

```sh
pip3 install pystats
```

Alternatively, you can also clone this repository and install the plugin manually using `pip`:

```sh
$ git clone git@github.com:marcizhu/PyStats.git
$ pip3 install ./PyStats
```

After that, you can just `import pystats` (or do `from pystats import *` if you don't want to type `pystats.` before all functions) and you're ready to go.


## Documentation
Full documentation is available online:

[![Documentation Status](https://readthedocs.org/projects/pystats/badge/?version=latest)](https://pystats.readthedocs.io/en/latest/?badge=latest)

A PDF version of the documentation is available [here](https://buildmedia.readthedocs.org/media/pdf/pystats/latest/pystats.pdf).


## Syntax and Examples
Functions are called using an **R**-like syntax. Some general rules:

- Density functions: `pystats.d*`. For example, the Normal (Gaussian) density is called using
```python3
pystats.dnorm(<value>, <mean>, <standard deviation>)
```

- Cumulative distribution functions: `pystats.p*`. For example, the Gamma CDF is called using
```python3
pystats.pgamma(<value>, <shape parameter>, <scale parameter>)
```

- Quantile functions: `pystats.q*`. For example, the Beta quantile is called using
```python3
pystats.qbeta(<value>, <a parameter>, <b parameter>)
```

- Random sampling: `pystats.r*`. For example, to generate a single draw from the Logistic distribution:
```python3
pystats.rlogis(<location parameter>, <scale parameter>)
```

The library also supports lists as input/output:
- The pdf, cdf and quantile functions can take list arguments. For example:
```python3
norm_pdf_vals = pystats.dnorm([x / 10 for x in range(-10, 10, 1)], 1.0, 2.0)
```

- The randomization functions (`r*`) can output lists of arbitrary size. For example, the following code will generate a 100-item list of iid draws from a Gamma(3,2) distribution:
```python3
gamma_rvs = pystats.rgamma(100, 3.0, 2.0)
```

Additionally, most parameters have defaults to most common values and named parameters are also supported. For example, to generate a single draw from a Normal(0, 2) the following can be used:
```python3
norm_draw = pystats.rnorm(sd=2.0)
```


### Examples
More examples with code:
```python3
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
```

For more information on default values, parameter names and other examples, check the [documentation](#documentation).


## Credits
This library uses [kthohr/stats](https://github.com/kthohr/stats) for the statistical distribution functions, [kthohr/gcem](https://github.com/kthohr/gcem) (a dependency of the previous library) and [pybind/pybind11](https://github.com/pybind/pybind11) to generate the binding code.


## License
Copyright (c) Marc Izquierdo 2021-2024  
This library is licensed under the [MIT License](https://choosealicense.com/licenses/mit/). See
[LICENSE](https://github.com/marcizhu/pystats/blob/master/LICENSE) for more details.
