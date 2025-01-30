.. _c-api:

C interface reference
=====================

The C interface is define in the ``chemfiles.h`` header, which should be included in
all the programs using chemfiles. All the functions and enums have a ``chfl_``
prefix indicating the provenance of the functions. The types are defined as
opaque pointer types, in all caps. The following types are defined:

* :ref:`CHFL_TRAJECTORY <capi-trajectory>` maps to the :ref:`Trajectory <overview-trajectory>` class;
* :ref:`CHFL_FRAME <capi-frame>` maps to the :ref:`Frame  <overview-frame>` class;
* :ref:`CHFL_ATOM <capi-atom>` maps to the :ref:`Atom  <overview-atom>` class;
* :ref:`CHFL_CELL <capi-cell>` maps to the :ref:`UnitCell  <overview-cell>` class;
* :ref:`CHFL_TOPOLOGY <capi-topology>` maps to the :ref:`Topology  <overview-topology>` class.

The user is reponsible for memory management when using these types. Constructors
functions (functions returning pointers to types defined above) return freshly
allocated memory, and calling the ``chfl_*_free`` functions return the corresponding
memory to the operating system.

In addition to the functions below, the :ref:`same macro <exported-macro>` as in the C++
interface are defined, and the ``chfl_version`` function allow to access the version of
the Chemfiles library.

.. doxygenfunction:: chfl_version

Functions for errors handling
-----------------------------

Apart from the *constructor* functions (the functions returning pointers to the
types defined above); all the functions return a status code, which is 0 if
nothing went wrong, and another value in case of error. The following function
allow for error handling from the C side.

.. doxygenfunction:: chfl_strerror

.. doxygenfunction:: chfl_last_error

.. doxygenenum:: CHFL_LOG_LEVEL

.. doxygenfunction:: chfl_loglevel

.. doxygenfunction:: chfl_set_loglevel

.. doxygenfunction:: chfl_logfile

.. doxygenfunction:: chfl_log_stderr

The return values for this status code correspond to the following macros:

.. doxygendefine:: CHFL_SUCCESS

.. doxygendefine:: CHFL_MEMORY_ERROR

.. doxygendefine:: CHFL_FILE_ERROR

.. doxygendefine:: CHFL_FORMAT_ERROR

.. doxygendefine:: CHFL_GENERIC_ERROR

.. doxygendefine:: CHFL_CXX_ERROR

.. _capi-trajectory:

Function manipulating ``CHFL_TRAJECTORY``
-----------------------------------------

The Trajectory type is the main entry point when using chemfiles. A trajectory
behave a bit like a ``FILE*`` pointer, and the ``chfl_close`` free the memory
associated with the file.

.. doxygenfunction:: chfl_trajectory_open

.. doxygenfunction:: chfl_trajectory_with_format

.. doxygenfunction:: chfl_trajectory_read

.. doxygenfunction:: chfl_trajectory_read_step

.. doxygenfunction:: chfl_trajectory_write

.. doxygenfunction:: chfl_trajectory_set_topology

.. doxygenfunction:: chfl_trajectory_set_topology_file

.. doxygenfunction:: chfl_trajectory_nsteps

.. doxygenfunction:: chfl_trajectory_close

.. _capi-frame:

Function manipulating ``CHFL_FRAME``
------------------------------------

.. doxygenfunction:: chfl_frame

.. doxygenfunction:: chfl_frame_atoms_count

.. doxygenfunction:: chfl_frame_resize

.. doxygenfunction:: chfl_frame_positions

.. doxygenfunction:: chfl_frame_velocities

.. doxygenfunction:: chfl_frame_has_velocities

.. doxygenfunction:: chfl_frame_add_velocities

.. doxygenfunction:: chfl_frame_set_cell

.. doxygenfunction:: chfl_frame_set_topology

.. doxygenfunction:: chfl_frame_step

.. doxygenfunction:: chfl_frame_set_step

.. doxygenfunction:: chfl_frame_guess_topology

.. doxygenfunction:: chfl_frame_selection

.. doxygenfunction:: chfl_frame_free

.. _capi-cell:

Function manipulating ``CHFL_CELL``
-----------------------------------

.. doxygenfunction:: chfl_cell

.. doxygenfunction:: chfl_cell_from_frame

.. doxygenfunction:: chfl_cell_lengths

.. doxygenfunction:: chfl_cell_set_lengths

.. doxygenfunction:: chfl_cell_angles

.. doxygenfunction:: chfl_cell_set_angles

.. doxygenfunction:: chfl_cell_matrix

.. doxygenenum:: CHFL_CELL_TYPES

.. doxygenfunction:: chfl_cell_type

.. doxygenfunction:: chfl_cell_set_type

.. doxygenfunction:: chfl_cell_free

.. _capi-topology:

Function manipulating ``CHFL_TOPOLOGY``
---------------------------------------

.. doxygenfunction:: chfl_topology

.. doxygenfunction:: chfl_topology_from_frame

.. doxygenfunction:: chfl_topology_atoms_count

.. doxygenfunction:: chfl_topology_append

.. doxygenfunction:: chfl_topology_remove

.. doxygenfunction:: chfl_topology_isbond

.. doxygenfunction:: chfl_topology_isangle

.. doxygenfunction:: chfl_topology_isdihedral

.. doxygenfunction:: chfl_topology_bonds_count

.. doxygenfunction:: chfl_topology_angles_count

.. doxygenfunction:: chfl_topology_dihedrals_count

.. doxygenfunction:: chfl_topology_bonds

.. doxygenfunction:: chfl_topology_angles

.. doxygenfunction:: chfl_topology_dihedrals

.. doxygenfunction:: chfl_topology_add_bond

.. doxygenfunction:: chfl_topology_remove_bond

.. doxygenfunction:: chfl_topology_free

.. _capi-atom:

Function manipulating ``CHFL_ATOM``
-----------------------------------

.. doxygenfunction:: chfl_atom

.. doxygenfunction:: chfl_atom_from_frame

.. doxygenfunction:: chfl_atom_from_topology

.. doxygenfunction:: chfl_atom_mass

.. doxygenfunction:: chfl_atom_set_mass

.. doxygenfunction:: chfl_atom_charge

.. doxygenfunction:: chfl_atom_set_charge

.. doxygenfunction:: chfl_atom_name

.. doxygenfunction:: chfl_atom_set_name

.. doxygenfunction:: chfl_atom_full_name

.. doxygenfunction:: chfl_atom_vdw_radius

.. doxygenfunction:: chfl_atom_covalent_radius

.. doxygenfunction:: chfl_atom_atomic_number

.. doxygenenum:: CHFL_ATOM_TYPES

.. doxygenfunction:: chfl_atom_type

.. doxygenfunction:: chfl_atom_set_type

.. doxygenfunction:: chfl_atom_free
