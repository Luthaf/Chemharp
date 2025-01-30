.. _selection-language:

Selection language
==================

Introduction
^^^^^^^^^^^^

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
.. _MDAnalysis: https://docs.mdanalysis.org/stable/documentation_pages/selections.html

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
``type``, comparing it to a fixed value: ``name(#1) == Fe``. When using a
selection with more than one atom, constraints are applied to different atoms
using ``#1``, ``#2``, ``#3`` or ``#4`` to refer to a specific atom: ``angles:
name(#3) Co`` will check the name of the third atom of the angles, and so on.

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

Constraints on atomic or residue properties
-------------------------------------------

It is possible to use atomic :cpp:class:`properties <chemfiles::Property>`
(unfortunately not frame properties) in constraints, with the ``[<property>]``
syntax. ``<property>`` should be replaced by the property name: ``[is_hetatm]``,
possibly using quotes around the property name if it contains spaces: ``["my own
property"]``. Depending on the context, a Boolean, string or numeric property
will be searched. If an atomic property with a given name cannot be found,
residue properties are searched instead, however, atomic properties take
precedence. If none can be found, or if the property type does not match, a
default value will be used instead: ``false`` for Boolean properties, ``""``
(empty string) for string properties, and ``NaN`` for numeric properties.

Selection language reference
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Here is the list of currently implemented constraints. Additional ideas are welcome!

Boolean constraints
-------------------

Boolean constraints directly evaluate to ``true`` or ``false``, and can be
combined with other constraints with ``and``, ``or`` and ``not``.

.. chemfiles-selection:: ``all``

    Matches any atom and always evaluate to ``true``


.. chemfiles-selection:: ``none``

    Never matches an atom and always evaluate to ``false``


.. chemfiles-selection:: ``is_bonded(i, j)``

    Check if atoms i and j are bonded together.

    i and j can either be one of the atoms currently being matched (i.e. ``#1 /
    #2 / #3 / #4``); or a sub-selection (e.g. ``is_bonded(#1, name O)``). In the
    latter case, the constrain will be checked for all atoms returned by the
    sub-selection, and evaluate to ``true`` if any of them matches.

    If i and j refers to the same atom, this evaluates to ``false``.


.. chemfiles-selection:: ``is_angle(i, j, k)``

    Check if atoms i, j and k are bonded together to form an angle, *i.e.* that
    i is bonded to j and j is bonded to k.

    i, j, and k can either be one of the atoms currently being matched (i.e.
    ``#1 / #2 / #3 / #4``); or a sub-selection (with the same behavior as
    ``is_bonded``).

    If any of i, j or k refer to the same atom, ``is_angle`` evaluate to
    ``false``.


.. chemfiles-selection::  ``is_dihedral(i, j, k, m)``

    Check if atoms i, j, k and m are bonded together to form a dihedral angle,
    *i.e.* that i is bonded to  j, j is bonded to k, and k is bonded to m.

    i, j, k, and m can either be one of the atoms currently being matched (i.e.
    ``#1 / #2 / #3 / #4``); or a sub-selection (with the same behavior as
    ``is_bonded``).

    If any of i, j, k or m refer to the same atom, ``is_dihedral`` evaluate to
    ``false``.


.. chemfiles-selection:: ``is_improper(i, j, k, m)``

    Check if atoms i, j, k and m are bonded together to form a dihedral angle,
    *i.e.* that all of i, k, and m are bonded to j.

    If any of i, j, k or m refer to the same atom, ``is_improper`` evaluate to
    ``false``.

.. |multiple-atoms-#i| replace::

    If multiple atoms are being matched simultaneously, the one to check can be
    specified by setting ``#i`` to one of ``#1 / #2 / #3 / #4``. If ``#i`` is
    not specified, ``#1`` is checked by default.


.. chemfiles-selection:: ``[<property>]`` / ``[<property>](#i)``

    Check if atoms or residues they belong to have a Boolean property named
    ``'property'``, and that this property is set to ``true``.

    This will evaluate to ``false`` if the property does not exist.

    |multiple-atoms-#i|

String constraints
------------------

String constraints are compared to a literal value for either equality with
``constrain == value``, or inequality with ``constrain != value``. Values
without spaces, starting with an ASCII letter and using only ASCII letters and
numbers can be written directly (``type == Fe``, ``resname != ALA``), other
values must be surrounded by quotation marks: ``name == "17"``, ``resname != "a
long name"``.

For string selectors, ``constrain value`` is equivalent to ``constrain ==
value``, and ``constrain value1 value2 value3`` is equivalent to ``constrain ==
value1 or constrain == value2 or constrain == value3``. This simplifies common
selections, such as ``name H O C N``.

.. chemfiles-selection:: ``type`` / ``type(#i)``

    Evaluates to the atomic type of the atom being checked.

    |multiple-atoms-#i|

.. chemfiles-selection:: ``name`` / ``name(#i)``

    Evaluates to the atomic name of the atom being checked. Some formats store
    both an atomic name (e.g. H3) and an atom type (e.g. H), this is why you can
    use two different selectors depending on the actual data;

    |multiple-atoms-#i|

.. chemfiles-selection:: ``resname`` / ``resname(#i)``

    Evaluates to the name of the :cpp:class:`chemfiles::Residue` containing the
    atom being checked. If an atom is not in a residue, this evaluates to the
    empty string.

    |multiple-atoms-#i|

.. chemfiles-selection:: ``[<property>]`` / ``[<property>](#i)``

    If the atom being matched or the residue it belongs to (if any) have a
    string property named ``'property'``, this evaluates to the value of the
    property.  Else this evaluates to an empty string (``""``).

    |multiple-atoms-#i|

Numeric constraints
-------------------

Numeric constraints can be combined using all of the usual numeric operations:
``+``, ``-``, ``*``, ``/``; as well as ``^`` for exponentiation and ``%`` for
modulo (remainder of Euclidean division). Parenthesis can be used for grouping
operations.

Additionally, mathematical functions are available to transform a number to
another value. Currently supported functions are: ``deg2rad`` and ``rad2deg``
functions for transforming radians to degrees and respectively; ``sin``,
``cos``, ``tan`` for the trigonometric functions (taking radians as input);
``asin`` and ``acos`` inverse trigonometric functions (giving output in
radians); ``sqrt`` for square root; ``exp`` for base *e* exponential; ``log``
for the natural or base *e* logarithm; ``log2`` for the base 2 logarithm and
``log10`` for the base 10 logarithm. If you need another of such mathematical
function, `open an issue`_ in the chemfiles repository!

.. _open an issue: https://github.com/chemfiles/chemfiles/issues/new/choose

Numeric values are finally compared using one of ``==`` (equal), ``!=`` (not
equal), ``>`` (greater), ``>=`` (greater or equal), ``<`` (lesser), or ``<=``
(lesser or equal). They can be compared with one another (``(x^2 + z) > y``) or
with literal values (``z <= 1.24e-1``).

.. note::

    Numeric selection operate on double precision floating point number, and as
    such are subject to the same limitations. In particular, while ``1 + 2 ==
    3`` will match all atoms, since this relation is always true, ``0.1 + 0.2 ==
    0.3`` will match no atoms, since ``0.1 + 0.2 == 0.30000000000000004`` when
    using floating point arithmetic.

Here are all the available numeric values

.. chemfiles-selection:: ``index`` / ``index(#i)``

    Evaluates to the atomic index of the atom being matched.

    |multiple-atoms-#i|

.. chemfiles-selection:: ``mass`` / ``mass(#i)``

    Evaluates to the mass of the atom being matched. For atoms with a type from
    the periodic table, the element mass is used as default. The atom mass can
    also be set manually, either directly with
    :cpp:func:`chemfiles::Atom::set_mass`, or using a :ref:`configuration file
    <configuration>`.

    |multiple-atoms-#i|

.. chemfiles-selection:: ``x`` / ``y`` / ``z`` / ``x(#i)`` / ``y(#i)`` / ``z(#i)``

    Evaluates to the cartesian component of the position of the atom being
    matched, in Ångströms.

    |multiple-atoms-#i|

.. chemfiles-selection:: ``vx`` / ``vy`` / ``vz`` / ``vx(#i)`` / ``vy(#i)`` / ``vz(#i)``

    Evaluates to the cartesian component of the velocity of the atom being
    matched. If velocities are not defined in the :cpp:class:`chemfiles::Frame`
    being matched, this evaluates to `NaN`_.

    |multiple-atoms-#i|

.. chemfiles-selection:: ``resid`` / ``resid(#i)``

    Evaluates to the id of the :cpp:class:`chemfiles::Residue` containing the
    atom being checked. If an atom is not in a residue, or if the residue do not
    have an id, this evaluates to -1.

    |multiple-atoms-#i|

.. chemfiles-selection:: ``[<property>]`` / ``[<property>](#i)``

    If the atom being matched or the residue it belongs to (if any) have a
    numeric property named ``'property'``, this evaluates to the value of the
    property. Else this evaluates to `NaN`_.

    |multiple-atoms-#i|

.. _NaN: https://en.wikipedia.org/wiki/Na


.. chemfiles-selection:: ``distance(i, j)``

    Evaluates to the distance in Ångströms between atoms i and j, accounting
    for periodic boundary conditions.

    i and j can either be one of the atoms currently being matched (i.e. ``#1 /
    #2 / #3 / #4``); or a sub-selection (``distance(#1, name O)``). In the case
    of a sub-selection, the distance will be evaluated for all atoms matching
    the sub-selection, and then propagated through mathematical operations. In
    the end, the atoms will be considered a match if **any** of the values is a
    match. So ``distance(#1, name O) + 3 < 5`` will return all atoms at less
    than 2Å from **any** atom with name O.


.. chemfiles-selection:: ``angle(i, j, k)``

    Evaluates to the angle between atoms i, j and k in radians, accounting for
    periodic boundary conditions. The atoms do not need to be bonded together.

    i, j, and k can either be one of the atoms currently being matched (i.e.
    ``#1 / #2 / #3 / #4``); or a sub-selections. In the latter case,
    mathematical operations are combined as for ``distance(i, j)``.


.. chemfiles-selection:: ``dihedral(i, j, k, m)``

    Evaluates to the dihedral angle between atoms i, j, k and m in radians,
    accounting for periodic boundary conditions. The atoms do not need to be
    bonded together.

    i, j, k and m can either be one of the atoms currently being matched (i.e.
    ``#1 / #2 / #3 / #4``); or a sub-selections. In the latter case,
    mathematical operations are combined as for ``distance(i, j)``.


.. chemfiles-selection:: ``out_of_plane(i, j, k, m)``

    Evaluates to  the distance in Ångströms between the plane formed by the three
    atoms i, k, and m; and the atom j, accounting for periodic boundary
    conditions.

    i, j, k and m can either be one of the atoms currently being matched (i.e.
    ``#1 / #2 / #3 / #4``); or a sub-selections. In the latter case,
    mathematical operations are combined as for ``distance(i, j)``.


.. note::

    ``angle`` and ``dihedral`` constraints are different from the ``is_angle``
    and ``is_dihedral``. The firsts returns a number that can then be used in
    mathematical expressions, and can be used even if the atoms are not bonded
    together in the corresponding topology elements.

    The seconds directly evaluate to ``true`` or ``false``, and only check if
    the atoms are bonded together in the corresponding topology elements.
