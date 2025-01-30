Overview
========

The figure below represents how the basic classes of chemfiles are organized and
how they interact together. Chemfiles is organized around a handful of public
classes: :cpp:class:`Trajectory <chemfiles::Trajectory>`, :cpp:class:`Frame
<chemfiles::Frame>`, :cpp:class:`Topology <chemfiles::Topology>`,
:cpp:class:`Residue <chemfiles::Residue>`, :cpp:class:`Atom <chemfiles::Atom>`,
:cpp:class:`UnitCell <chemfiles::UnitCell>` and :cpp:class:`Selection
<chemfiles::Selection>`, all of which are presented here.

.. image:: ../static/img/classes.*
    :align: center
    :width: 500px

A :cpp:class:`trajectory <chemfiles::Trajectory>` is the main entry point of
chemfiles. It reads one or many :cpp:class:`frames <chemfiles::Frame>` from a
file on the disk using a specific format. The file type and the format are
automatically determined from the extension.

A :cpp:class:`frame <chemfiles::Frame>` holds data for one step of a simulation,
consisting in the positions for all the atoms; optionally the velocities for all
the atoms; the :cpp:class:`topology <chemfiles::Topology>` and the
:cpp:class:`unit cell <chemfiles::UnitCell>` of the system.

The :cpp:class:`topology <chemfiles::Topology>` describes the organization of
the particles in the system. It contains a list of :cpp:class:`atoms
<chemfiles::Atom>` in the system, and information about which atoms are bonded
together. A :cpp:class:`residue <chemfiles::Residue>` is a group of atoms bonded
together, which may or may not corresponds to molecules. When working with
bio-molecules and specifically proteins from the PDB data bank, the residues
should correspond to amino-acids in the protein.

The :cpp:class:`Atom <chemfiles::Atom>` class contains basic information about
the atoms in the system: the name (if it is available), mass, kind of atom and
so on. Atoms are not limited to plain chemical elements.

The :cpp:class:`UnitCell <chemfiles::UnitCell>` class describes the boundary
conditions of the system: where are the boundaries, and what is the periodicity
of theses boundaries. An unit cell can be of three types: *Infinite*,
*Orthorhombic* or *Triclinic*. Infinite cells do not have any boundaries.
Orthorhombic cells are defined by three orthogonal vectors, and triclinic cells
are defined by three vectors without any constrain.

The :cpp:class:`Property <chemfiles::Property>` class store additional data or
metadata associated with :cpp:class:`frames <chemfiles::Frame>`,
:cpp:class:`residues <chemfiles::Residue>` or :cpp:class:`atoms
<chemfiles::Atom>`. Properties can store string values, numeric values, Boolean
values or vector values.

Chemfiles also provides a :ref:`selection language <selection-language>`,
implemented in the :cpp:class:`Selection <chemfiles::Selection>` class. This
selection language allows the users to select a group of atoms from a
:cpp:class:`frame <chemfiles::Frame>` using a selection string such as ``"(x <
45 and name O) or name C"``.
