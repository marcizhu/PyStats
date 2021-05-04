# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
# import os
# import sys
# sys.path.insert(0, os.path.abspath('../../build/'))


# -- Project information -----------------------------------------------------

project = 'PyStats'
copyright = '2021, Marc Izquierdo'
author = 'Marc Izquierdo'

# The full version, including alpha/beta/rc tags
release = '0.0.1 alpha'


# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
	'sphinx.ext.autodoc',
	'sphinx.ext.napoleon'
]

# Napoleon settings
napoleon_google_docstring = True
napoleon_numpy_docstring = False
napoleon_include_init_with_doc = False
napoleon_include_private_with_doc = False
napoleon_include_special_with_doc = True
napoleon_use_admonition_for_examples = False
napoleon_use_admonition_for_notes = False
napoleon_use_admonition_for_references = False
napoleon_use_ivar = True
napoleon_use_param = True
napoleon_use_rtype = True
napoleon_preprocess_types = False
napoleon_type_aliases = None
napoleon_attr_annotations = True

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = []


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'default'

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']

from collections import defaultdict

def process_overloaded_items(app, what, name, obj, options, lines):
	if not "Overloaded function" in lines[1]:
		return

	index = app.doc_dict[name]
	first = next((lines.index(l) for l in lines if l.startswith(str(index + 0) + ".")))
	last  = next((lines.index(l) for l in lines if l.startswith(str(index + 1) + ".")), len(lines))

	del lines[0:first+1]
	del lines[last-first-1:]

	app.doc_dict[name] += 1

def setup(app):
	app.doc_dict = defaultdict(lambda: 1)
	app.connect('autodoc-process-docstring', process_overloaded_items)
