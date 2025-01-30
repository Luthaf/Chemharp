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

.. doxygenfunction:: chfl_trajectory_set_topology_with_format

.. doxygenfunction:: chfl_trajectory_nsteps

.. doxygenfunction:: chfl_trajectory_close
