.. _overview:

Chemfiles features overview
===========================

This figure represent how the basic types of chemfiles are arganised and how they
interact together. The only types a chemfiles user should worry about are the
``Trajectory``, ``Frame``, ``Topology``, ``Atom`` and ``UnitCell`` types. All of
these are described in this section.

.. image:: static/img/classes.*
    :align: center

They are various way of interacting with these types, all of them being described
in the :ref:`classes-reference` section for the C++ interface. All the bindings may not
provide all the functionalities, so if something is missing, just
`ask for it! <https://github.com/chemfiles/chemfiles/issues/new>`_

.. _overview-trajectory:

Trajectory: the main entry point
--------------------------------

A ``Trajectory`` uses a file and a format together to read simulation data from
the file. It can read and write one or many ``Frame`` to this file. The file
type and the format are automatically determined from the extention.

.. _overview-frame:

Frame: data from a simulation step
----------------------------------

A ``Frame`` holds data for one step of a simulation. As not all formats provides
all the types of informations, some fields may be initialized to a default value.

A ``Frame`` may contains the following data:

* Positions for all the atoms in the system;
* Velocities for all the atoms in the system;
* The ``Topology`` of the system;
* The ``UnitCell`` of the system.

.. _overview-topology:

Topology: how are the atoms organised
-------------------------------------

A ``Topology`` describes the organisation of the particles in the system.
What are they names, how are they bonded together, … A topology is mainly a list
of ``Atom`` in the system.

.. _overview-atom:

Atom: building blocks for simulations
-------------------------------------

The ``Atom`` type contains basic information about the atoms in the system:
the name (if it is disponible), mass, kind of atom and so on. Atoms are not
limited to plain chemical elements. Four types of atoms are defined: *Element*
are Atoms from the periodic classification; *Corse grained* atoms are particles
taking together more than one element (*CH4* or *H2O* are examples); *Dummy*
atoms are fictitous points associated with some data, like the fourth site in
the TIP4P model of water; and *Undefined* atoms are all the other atoms types.

.. _overview-cell:

UnitCell: wrapping the atoms together
-------------------------------------

The ``UnitCell`` type describe the boundary conditions of the system: where are
the boundaries, and what is the periodicity of theses boundaries. An unit cell
can be of three types: *Infinite*, *Orthorombic* or *Triclinic*. Inifinite cells
does not have any boundaries. Orthorombic cells are defined by three orthogonals
vectors, and Triclinic cells are defined by three vectors without any constrains.
