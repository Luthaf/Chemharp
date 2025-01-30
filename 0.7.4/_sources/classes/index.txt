.. _cpp-api:

C++ interface reference
=======================


The full public C++ interface is contained in the ``chemfiles.hpp`` header, which
should be included in all the programs using chemfiles. All the classes are in the
``chemfiles`` namespace, so you may want to use ``using namespace chemfiles;`` at the
begining of your program in order to bring all the class in the main namespace.

.. toctree::
   :maxdepth: 2

   trajectory
   frame
   topology
   atom
   unitcell
   selection
   residue
   errors

.. _exported-macro:

Exported macro
--------------

In addition to these functions and classes, chemfiles header also export some macro, using
the ``CHEMFILES_`` prefix. The following macro are defined:

.. doxygendefine:: CHEMFILES_VERSION_MAJOR

.. doxygendefine:: CHEMFILES_VERSION_MINOR

.. doxygendefine:: CHEMFILES_VERSION_PATCH

.. doxygendefine:: CHEMFILES_VERSION
