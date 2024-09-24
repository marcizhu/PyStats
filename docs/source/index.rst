.. Copyright (c) 2021-2024 Marc Izquierdo

   Distributed under the terms of the MIT License.

   The full license is in the file LICENSE, distributed with this software.

Introduction
============

PyStats is a Python 3 library of statistical analysis and distribution functions with simple **R**-like syntax, scalar/list
input/output with OpenMP parallelization.

Author: Marc Izquierdo

License: MIT License

----

Installation
------------

You can use pip to install this library:

.. code:: none

   pip install pystats

Alternatively, you can also clone this repository and install the plugin manually using `pip`:

.. code:: none

   $ git clone git@github.com:marcizhu/PyStats.git
   $ pip3 install ./PyStats

After that, you can just ``import pystats`` (or do ``from pystats import *`` if you don't want to type ``pystats.`` before all
functions) and you're ready to go.

----

Contents
--------

.. toctree::
   :caption: Guide
   :maxdepth: 2

   syntax_notes
   examples

.. toctree::
   :caption: API
   :maxdepth: 2

   api/index_dist
   api/index_other
