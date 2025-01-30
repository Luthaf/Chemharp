.. _selection-language:

Selection language
==================

Overview
^^^^^^^^

Chemfiles implements a rich selection language that allows finding the atoms
matching a set of constraints in a :cpp:class:`Frame <chemfiles::Frame>`.  For
example, ``atom: name == H and x > 15`` would select all atoms with a name equal
to "H" and x cartesian coordinate bigger than 15. Here, ``name == H`` and ``x >
15`` are individual constraints, and they are combined with ``and``, meaning
both of them must be true for an atom to match to full selection.

Chemfiles atomic selection language differs from other atomic selection
languages (such as the ones in `VMD`_, `MDAnalysis`_, and many others) by the
fact that it is possible to formulate constraints not only on single atoms, but
also on pairs, triplets, and quadruplets of atoms. For example, ``angles:
name(#2) O and mass(#3) < 1.5`` will select all sets of three bonded atoms
forming an angle such that the name of the second atom is O and the mass of the
third atom is less than 1.5. Here, the first atom is left unconstrained.  Where
evaluating simple selections yields a list of matching atomic indexes,
evaluating triplet selection will return a list of triplets of atomic indexes
(and correspondingly for pairs and quadruplets).

.. _VMD: https://www.ks.uiuc.edu/Research/vmd/current/ug/node89.html
.. _MDAnalysis: https://www.mdanalysis.org/docs/documentation_pages/selections.html

The number of atoms to select together is indicated in chemfiles by a context,
separated from the main selection by a colon. Seven contexts are available:
``atoms`` is the default context, matching single atoms. ``two``, ``three``, and
``four`` match arbitrary pairs, triplets and quadruplets of atoms respectively.
``bonds``, ``angles``, and ``dihedrals`` match pairs, triplets and quadruplets
of atoms bonded together to form the corresponding connectivity element.

Expressing the constraints
--------------------------

Selections are built by assembling simple constraints with the Boolean operators
``and``, ``or`` and ``not``. They follow the usual interpretation of logic: ``A
and B`` will be true only if both A and B are true, ``A or B`` will be true if
one of A or B is, and ``not A`` will be true is A is false. You can use three
types of constraints in your selections: Boolean constraints, string constraints,
and numeric constraints.

String constraints check text values, such as the atomic ``name`` or atomic
``type``, comparing it to either a fixed string (``name(#1) == Fe``) or another
string value (``type(#1) != type(#3)``). When using a selection with more than
one atom, constraints are applied to different atoms using ``#1``, ``#2``,
``#3`` or ``#4`` to refer to a specific atom: ``angles: name(#3) Co`` will check
the name of the third atom of the angles, and so on.

Numeric constraints check numeric values such as the position of the atoms
(``x``, ``y``, and ``z``), the atomic ``mass``, the ``index`` of an atom in the
frame, *etc.* Numeric values can be combined with the usual mathematical
operations: ``x^2 + y^2 + z^2 < 10^2`` will check for atoms inside the sphere
with a radius of 10 Å centered on the origin. The usual ``+``, ``-``, ``*`` and
``/`` operators are supported, as well as ``^`` for exponentiation and ``%`` for
modulo (remainder of Euclidean division). These operations follow the standard
priority rules: ``1 + 2 * 3`` is 7, not 9. Numeric values are then compared with
one of ``==`` (equal), ``!=`` (not equal), ``<`` (less than),
``<=`` (less or equal), ``>`` (more than), or ``>=`` (more or equal).

Finally, Boolean constraints directly evaluate to either ``true`` or ``false``
for a given set of atoms. For example, ``is_bonded(i, j)`` will check if atoms i
and j are bonded together. Here, ``i`` and ``j`` can either be one of the atoms
currently being matched (``#1 / #2 / #3 / #4``) or another selection (called
sub-selection). In the latter case, all the atoms in the sub-selection are
checked to see if any of them verify the selection. This makes ``is_bonded(#1,
name O)`` select all atoms bonded to an oxygen; and ``is_angle(type C, #1, name
O)`` select all atoms in the middle of a C-X-O angle.

Constraints on atomic properties
--------------------------------

It is possible to use atomic :cpp:class:`properties <chemfiles::Property>`
(unfortunately not frame or residue properties) in constraints, with the
``[<property>]`` syntax. ``<property>`` should be replaced by the property name:
``[is_hetatm]``, possibly using quotes around the property name if it contains
spaces: ``["my own property"]``. Depending on the context, a Boolean, string or
numeric property will be searched. If none can be found, or if the property type
does not match, a default value will be used instead.

Selection language reference
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Here is the list of currently implemented constraints. Additional ideas are welcome!

Boolean constraints
-------------------

- ``all``: always matches any atom and returns ``true``;
- ``none``: never matches an atom and returns ``false``;
- ``is_bonded(i, j)``: check if atoms i and j are bonded together. If i and j
  refers to the same atom, this returns false;
- ``is_angle(i, j, k)``: check if atoms i, j and k are bonded together to form
  an angle, *i.e.* that i is bonded to j and j is bonded to k. If any of i, j or
  k refer to the same atom, this returns false;
- ``is_dihedral(i, j, k, m)``: check if atoms i, j, k and m are bonded together
  to form a dihedral angle, *i.e.* that i is bonded to  j, j is bonded to k, and
  k is bonded to m.  If any of i, j, k or m refer to the same atom, this returns
  false;
- ``is_improper(i, j, k, m)``: check if atoms i, j, k and m are bonded together
  to form a dihedral angle, *i.e.* that all of i, k, and m are bonded to j. If
  any of i, j, k or m refer to the same atom, this returns false;
- ``[<property>]``: check if atoms have a Boolean property named `'property'`
  set, and that this property is true. This will return false if the property
  is not set;

String properties
-----------------

- ``type``: gives the atomic type;
- ``name``: gives the atomic name. Some formats store both an atomic name (H3)
  and an atom type (H), this is why you can use two different selectors
  depending on the actual data;
- ``resname``: gives the residue name. If an atom is not in a residue, this
  return the empty string;
- ``[<property>]``: gives the value of the string property named `'property'`
  for the atom. This will return an empty string (`""`) if the property is not
  set;

Numeric properties
------------------

Most of the numeric properties only apply to a single atom:

- ``index``: gives the atomic index in the frame;
- ``mass``: gives the atomic mass;
- ``x``, ``y`` and ``z``: gives the atomic position  in cartesian coordinates;
- ``vx``, ``vy`` and ``vz``: gives the atomic velocity in cartesian coordinates;
- ``resid``: gives the atomic residue index. If an atom is not in a residue,
  this return -1;
- ``[<property>]``: gives the value of the numeric property named `'property'`
  for the atom. This will return 0 if the property is not set;

But some properties apply to multiple atoms, and as such are only usable when
selecting multiple atoms:

- ``distance(i, j)``: gives the distance in Ångströms between atoms i and j,
  accounting for periodic boundary conditions.
- ``angle(i, j, k)``: gives the angle between atoms i, j and k in radians,
  accounting for periodic boundary conditions. The atoms do not need to be
  bonded together.
- ``dihedral(i, j, k, m)``: gives the dihedral angle between atoms i, j, k and m
  in radians, accounting for periodic boundary conditions. The atoms do not need
  to be bonded together.
- ``out_of_plane(i, j, k, m)``: gives the distance in Ångströms between the
  plane formed by the three atoms i, k, and m; and the atom j, accounting for
  periodic boundary conditions.

.. note::

    The ``angle`` and ``dihedral`` selectors are different from the ``is_angle``
    and ``is_dihedral`` selectors. The firsts returns a number that can then be
    used in mathematical expressions, while the second returns directly ``true``
    or ``false``.

One can also use mathematical function to transform a number to another value.
Currently supported functions are: ``deg2rad`` and ``rad2deg`` functions for
transforming radians to degrees and respectively; ``sin``, ``cos``, ``tan`` for
the trigonometric functions; ``asin`` and ``acos`` inverse trigonometric
functions and ``sqrt``. Adding new functions is easy, open an issue about the
one you need on the chemfiles repository.

.. note::

    Numeric selection operate on double precision floating point number, and as
    such are subject to the same limitations. In particular, while ``1 + 2 ==
    3`` will match all atoms, since this relation is always true, ``0.1 + 0.2 ==
    0.3`` will not, since ``0.1 + 0.2 == 0.30000000000000004`` when using
    floating point arithmetic.

Elisions
--------

This selection language is very explicit but it can be too verbose in some
cases. The following rules allow to omit some parts of the selection when the
meaning is clear:

- First, in the ``atoms`` context, the ``#1`` variable is optional, and ``atoms:
  name(#1) == H`` is equivalent to ``atoms: name == H``.
- Then, if no context is given, the ``atoms`` context is used. This make ``atoms:
  name == H`` equivalent to ``name == H``.
- Then if no comparison operator is given, ``==`` is used by default. This means
  that we can write ``name H`` instead of ``name == H``.
- Then, multiple values are interpreted as multiple choices. A selection like
  ``name H O C`` is expanded into ``name H or name O or name C``.

At the end, using all these elisions rules, ``atom: name(#1) == H or name(#1) ==
O`` is equivalent to ``name H O``. A more complex example can be ``bonds:
name(#1) O C and index(#2) 23 55 69``, which is equivalent to ``bonds:
(name(#1) == O or name(#1) == C) and (index(#2) == 23 or index(#2) == 55 or
index(#2) == 69)``
