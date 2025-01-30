.. _c-api:

C interface reference
=====================

The C interface is define in the ``chemfiles.h`` header, which should be
included in all the programs using chemfiles. All the functions and enums have a
``chfl_`` prefix indicating the provenance of the functions. The types are
defined as opaque pointer types, in all caps. The following types are defined:

* :ref:`CHFL_TRAJECTORY <capi-trajectory>` maps to the :ref:`Trajectory <overview-trajectory>` class;
* :ref:`CHFL_FRAME <capi-frame>` maps to the :ref:`Frame  <overview-frame>` class;
* :ref:`CHFL_ATOM <capi-atom>` maps to the :ref:`Atom  <overview-atom>` class;
* :ref:`CHFL_CELL <capi-cell>` maps to the :ref:`UnitCell  <overview-cell>` class;
* :ref:`CHFL_TOPOLOGY <capi-topology>` maps to the :ref:`Topology  <overview-topology>` class.
* :ref:`CHFL_SELECTION <capi-selection>` maps to the :ref:`Selection  <overview-selection>` class.

The user is reponsible for memory management when using these types.
Constructors functions (functions returning pointers to types defined above)
return freshly allocated memory, and calling the ``chfl_*_free`` functions
return the corresponding memory to the operating system.

In addition to the functions below, the :ref:`same macro <exported-macro>` as in
the C++ interface are defined, and the ``chfl_version`` function allow to access
the version of the Chemfiles library.

.. doxygenfunction:: chfl_version

.. toctree::
    :maxdepth: 2

    chfl_trajectory
    chfl_frame
    chfl_atom
    chfl_cell
    chfl_topology
    chfl_selection
    errors
