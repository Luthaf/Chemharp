.. _overview:

Chemfiles features overview
===========================

This figure represent how the basic classs of chemfiles are arganised and how they
interact together. The only classs a chemfiles user should worry about are the
``Trajectory``, ``Frame``, ``Topology``, ``Atom``, ``UnitCell`` and ``Selection``.
All of these are described in this section.

They are various way of interacting with these classes, all of them being described
in the :ref:`classes-reference` section for the C++ interface.

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

The ``Atom`` class contains basic information about the atoms in the system:
the name (if it is disponible), mass, kind of atom and so on. Atoms are not
limited to plain chemical elements. Four types of atoms are defined: *Element*
are Atoms from the periodic classification; *coarse grained* atoms are particles
taking together more than one element (*CH4* or *H2O* are examples); *Dummy*
atoms are fictitous points associated with some data, like the fourth site in
the TIP4P model of water; and *Undefined* atoms are all the other atoms types.

.. _overview-cell:

UnitCell: wrapping the atoms together
-------------------------------------

The ``UnitCell`` class describe the boundary conditions of the system: where are
the boundaries, and what is the periodicity of theses boundaries. An unit cell
can be of three types: *Infinite*, *Orthorombic* or *Triclinic*. Inifinite cells
does not have any boundaries. Orthorombic cells are defined by three orthogonals
vectors, and Triclinic cells are defined by three vectors without any constrains.

.. _overview-selection:

Selections: selecting groups of atoms
-------------------------------------

Chemfiles provides a :ref:`selection language <selection-language>`, implemented in
the ``Selection`` class. This selection language allow the users to select a group of
atoms using a simple string. Examples of selections are ``"name H"`` and ``"(x < 45
and name O) or name C"``. 
