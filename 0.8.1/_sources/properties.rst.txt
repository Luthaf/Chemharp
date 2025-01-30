Properties
==========

When reading files, chemfiles read multiple kind of data: positions, velocities,
atomic informations (name, type, mass, charge, ...), bonds and other
connectivity elements. This model allow to read the most commonly available data
in various formats. But sometimes, a format defines additional information.
Instead of adding a new field/function for every kind of data there can be in a
file, chemfiles defines a generic interface to read and store this additional
data. These additional data are stored inside properties.

A property has a name and a value. The value can either be a real number, a
string, a boolean value (true/false) or a 3 dimmensional vector. A property is
either stored inside an atom, and associated with this atom (for example the
total atomic force), or stored in and associated with a frame. The later case is
used for general properties, such as the temperature of the system, or the
author of the file.

This section documents which format set and use properties.

Atomic properties
-----------------

- **is_hetatm** (boolean): set and used by the PDB format. On reading, this
  property is set to ``true`` when an atom is defined with a ``HETATM`` record,
  and ``false`` when the atom is defined with an ``ATOM`` record. On writing,
  this property is used to determine whether to emit an ``HETATM`` or an
  ``ATOM`` record. If the property is not set, ``HETATM`` is used.


Frame properties
-----------------

No property on frame is used by the format reader and writers yet.
