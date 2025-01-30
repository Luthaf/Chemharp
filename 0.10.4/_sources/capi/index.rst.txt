.. _c-api:

C interface reference
=====================

The C interface is define in the ``chemfiles.h``, in which all the functions and
enums have a ``chfl_`` prefix for namespacing. Main chemfiles types are the
following opaque pointer types:

* :ref:`CHFL_TRAJECTORY <capi-trajectory>` maps to the :ref:`Trajectory <class-Trajectory>` class;
* :ref:`CHFL_FRAME <capi-frame>` maps to the :ref:`Frame <class-Frame>` class;
* :ref:`CHFL_ATOM <capi-atom>` maps to the :ref:`Atom <class-Atom>` class;
* :ref:`CHFL_CELL <capi-cell>` maps to the :ref:`UnitCell <class-UnitCell>` class;
* :ref:`CHFL_TOPOLOGY <capi-topology>` maps to the :ref:`Topology <class-Topology>` class.
* :ref:`CHFL_RESIDUE <capi-residue>` maps to the :ref:`Residue <class-Residue>` class.
* :ref:`CHFL_SELECTION <capi-selection>` maps to the :ref:`Selection <class-Selection>` class.
* :ref:`CHFL_PROPERTY <capi-property>` maps to the :ref:`Property <class-Property>` class.

The user is reponsible for memory management when using these types.
Constructors functions (functions returning pointers to types defined above)
return freshly allocated memory, and calling the :cpp:func:`chfl_free` function
return the corresponding memory to the operating system.

.. doxygenfunction:: chfl_free

.. doxygentypedef:: chfl_vector3d

``chemfiles.h`` also exports the :ref:`same macro <exported-macro>` as in the
C++ interface, and the ``chfl_version`` function allow to access the version of
the Chemfiles library.

.. doxygenfunction:: chfl_version

.. toctree::
    :maxdepth: 2

    chfl_trajectory
    chfl_frame
    chfl_topology
    chfl_residue
    chfl_atom
    chfl_cell
    chfl_selection
    chfl_property
    misc
