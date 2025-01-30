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
   logger
   errors
