.. _selection-language:

Selection language
==================

Chemfiles selection language allows to select some atoms in a :ref:`Frame
<class-Frame>` matching a set of constraints. For examples, ``atom: name H
and x > 15`` would select all *single atoms* whose name is ``H`` and x
coordinate is bigger than 15.

Chemfiles selections differs from the well-known `VMD`_ selections by the fact
that they are *multiple selections*: we can select more than one atom at once.
All selections starts with a context, indicating the number of atoms we are
selecting, and the relation between these atoms. Existing contextes are
``atoms`` or ``one``, ``pairs`` or ``two``, ``three`` and ``four``  to select
one, two, three or four independent atoms; and ``bonds``, ``angles`` and
``dihedrals`` for two, three or four bonded atoms.

.. _VMD: http://www.ks.uiuc.edu/Research/vmd/

A selection is built using a context and a set of constraints separated by a
colon. For example, ``atoms: name == H`` will select all atoms whose name is
``H``. ``angles: name(#2) == O and mass(#3) < 1.5`` will select all sets of
three bonded atoms forming an angle such that the name of the second atom is
``O`` and the mass of the third atom is less than 1.5.

These constraints are created using *selectors*. Selectors are small functions
that are evaluated for each atom, and return either ``true`` if the atom
matches, or ``false`` if it does not. There are three kinds of selectors:

- boolean selectors returns either ``true`` or ``false`` for a given set of atoms;
- string selectors compare string values with one of ``==`` (equal) or ``!=``
  (not equal). One can either compare two atomic properties (``name(#1) ==
  type(#2)``) or atomic properties to literal strings (``name(#1) != He``);
- numeric selectors compare two numeric values with either ``==``, ``!=``, ``<``
  (less than), ``<=`` (less or equal), ``>`` (more than), and ``>=`` (more or
  equal)

Numeric values are produced by numeric selectors (``x``; ``mass``, ...) or
literal values (``5.2``, ``22.21e-2``). They can also be combined together using
mathematical operations: the usual ``+``, ``-``, ``*`` and ``/`` operators are
supported, as well as ``^`` for exponentiation and ``%`` for modulo (remainder
of Euclidean division). These operations follow the usual priority rules:
``1 + 2 * 3`` is 7, not 9.

When using a selection with more than one atom, selectors must refer to the
different atoms with ``#1``, ``#2``, ``#3`` or ``#4`` variables: ``name(#3)``
will give the name of the third atom, and so on.

Finally, constraints are combined with boolean operators. The ``and`` operator
is true if both side of the expression are true; the ``or`` operator is true if
either side of the expression is true; and the ``not`` operator reverse true to
false and false to true. ``name(#1) == H and not x(#1) < 5.0`` and ``(z(#2) < 45
and name(#4) == O) or name(#1) == C`` are complex selections using booleans
operators.

List of implemented selectors
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Here is the list of currently implemented selectors. Additional ideas are welcome!

Boolean selectors
-----------------

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
- ``[<property>]``: check if atoms have a boolean property named `'property'`
  set, and that this property is true. This will return false if the property
  is not set;

For boolean selectors taking arguments, ``i/j/k/m`` can either be one of the
atoms currently being matched (``#1 / #2 / #3 / #4``) or another selection
(called sub-selection). In the latter case, all the atoms in the sub-selection
are checked to see if any of them verify the selection. This makes
``is_bonded(#1, name O)`` select all atoms bonded to an oxygen; and
``is_angle(type C, #1, name O)`` select all atoms in the midle of a C-X-O angle.

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

Elisions
^^^^^^^^

This multiple selection language can be a bit verbose for simpler cases, so it
is sometimes allowed to remove parts of the selection. The following rules allow
simpler selections:

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
